#include <QtGui>
#include <QDebug>
#include <iostream>
#include <fstream>
// #include <QIcon>
#include "GraphicsView.h"
// #include "entertranscodedialog.h"
#include "setNodeInfo.h"
#include "node.h"
#include "modeTable.pb.h"
#include "link.h"
#include "propertiesdialog.h"
#include "setNodeInfo.h"
#include "audioPlayWidget.h"
#include <QDockWidget>
#include "mainWindow.h"

GraphicsView::GraphicsView(QWidget * parent):QGraphicsView(parent)
{
	action = new QAction(this);
	action->setCheckable(true);

	connect(action , SIGNAL(triggered()), this , SLOT(show()));
	connect(action , SIGNAL(triggered()), this , SLOT(setFocus()));

	isUntitled =true;
	firstOpened = false;
    QGraphicsScene * newScene = new QGraphicsScene;
    setScene(newScene);

    /** 用户的可选模式 圈选 */
    setDragMode(QGraphicsView::RubberBandDrag);
    setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    /** 上下文的菜当选项 */
    setContextMenuPolicy(Qt::ActionsContextMenu);

	/**  如果view里面的任何东西改变了，那么就触发该信号 */
	connect( scene(), SIGNAL(changed(const QList<QRectF> &)),\
			 this , SLOT(documentWasModified(const QList<QRectF> &)));
	connect( scene(), SIGNAL(changed(const QList<QRectF> &)),\
			 this , SLOT(updateScene(const QList<QRectF> &)));

	/**
	 * 选中的项发生改变,要及时更新DockerWidget
	 */
	connect(scene() , SIGNAL(selectionChanged()),\
			this , SLOT(selectedChanged()));
	setWindowIcon(QIcon(":/images/document.png"));
	setWindowTitle("[*]");
	setAttribute(Qt::WA_DeleteOnClose);

	minZ=0;
	maxZ=0;
	seqNumber=0;
	curMode = NormalMode;
	mouserPos = QPointF();
}

/**
 * 创建一个新mode table
 */
void GraphicsView::newFile()
{
	static int documentNumber = 1;
	curFile = tr("document%1.mt").arg(documentNumber);
	setWindowTitle(curFile+"[*]");
	action->setText(curFile);
	isUntitled = true;
	++documentNumber;
}

GraphicsView * GraphicsView::open(QWidget * parent)
{
	QString filename = QFileDialog::getOpenFileName(parent , \
													tr("Open mode table"),\
													".",\
													tr("mode table files(*.mt)"));
	if(filename.isEmpty())
		return 0;
	return openFile(filename ,parent);
}

GraphicsView * GraphicsView::openFile(const QString & filename , QWidget * parent)
{
	GraphicsView * view = new GraphicsView(parent);
	if(view->readFile(filename))
	{
		view->setCurrentFile(filename);
		return view;
	}
	else
	{
		delete view;
		return 0;
	}
	return 0;
}

bool GraphicsView::save()
{
	if(isUntitled)
		return saveAs();
	else
		return saveFile(curFile);
}


bool GraphicsView::saveAs()
{
	QString filename = QFileDialog::getSaveFileName(this ,\
		tr("Save md table"),\
		"~/",\
		tr("mode table files (*.mt)"));
	if(filename.mid(filename.count()-3) != QString(".mt"))
		filename+=".mt";
	if(filename.isEmpty())
		return false;
	return saveFile(filename);
}

void GraphicsView::closeEvent(QCloseEvent * event)
{
	if(okToContinue())
	{
		curMode = NormalMode;
		event->accept();
	}
	else
		event->ignore();
}

void GraphicsView::setCurrentFile(const QString & filename)
{
	curFile = filename;
	isUntitled = false;
	action->setText(strippedName(curFile));

	setWindowTitle(strippedName(curFile)+"[*]");
	this->setWindowModified(false);
	firstOpened = true;
}

QString GraphicsView::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}


bool GraphicsView::okToContinue()
{
    if (isWindowModified()) {
        int r = QMessageBox::warning(this, tr("ddBook assitant"),
                        tr("The document has been modified.\n"
                           "Do you want to save your changes?"),
                        QMessageBox::Yes | QMessageBox::No
                        | QMessageBox::Cancel);
        if (r == QMessageBox::Yes) {
            return save();
        } else if (r == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}


bool GraphicsView::saveFile(const QString & filename)
{
	if(!writeFile(filename))
	{
		QMessageBox::critical(0 , "Saving canceled" , "!!!!Save file failed!!!",QMessageBox::Yes);
	}
	setCurrentFile(filename);//保存的时候名字可能会被更改了
	return true;
}

void GraphicsView::documentWasModified(const QList<QRectF> &)
{
	//第一次打开就不会提示保存
	if(!firstOpened)
	{
		this->setWindowModified(true);
	}
	else
	{
		firstOpened = false;
	}
}

/**
 * 用protobuf来存储当前的mode table信息
 * @return 成功返回 true
 */
bool GraphicsView::writeFile(const QString & filename)
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	modeTable::MTFile mtFile;
	QList<QGraphicsItem *> itemList = scene()->items();
	foreach(QGraphicsItem * item , itemList)
	{
		//表明是node
		Node * nodeItem = dynamic_cast<Node*>(item);
		if(nodeItem)
		{
			//得到节点信息
			modeTable::Node * newNode =mtFile.add_nodelist();
			//写入节点位置
			newNode->set_xpos(nodeItem->pos().x());
			newNode->set_ypos(nodeItem->pos().y());
			//写入节点外观
			newNode->set_nodename(qPrintable(nodeItem->getText()));
			newNode->set_textcolor(qPrintable(nodeItem->getTextColor().name()));
			newNode->set_outlinecolor(qPrintable(nodeItem->getOutlineColor().name()));
			newNode->set_backgroundcolor(qPrintable(nodeItem->getBackgroundColor().name()));
			//写入节点信息
			newNode->set_startaudio(qPrintable(nodeItem->getStartAudio()));
			newNode->set_endaudio(qPrintable(nodeItem->getEndAudio()));
			QStringList deafultList = nodeItem->getDefaultAudioList();
			foreach(QString defaultAudio , deafultList)
			{
				newNode->add_defaultaudio(qPrintable(defaultAudio));
			}
			//写入节点ID
			newNode->set_nodeid(qPrintable(nodeItem->getNodeID()));
			
		}
		else //就是Link
		{
			Link * linkItem = dynamic_cast<Link *>(item);
			if(linkItem)
			{
				modeTable::Link * newLink = mtFile.add_linklist();
				// newLink->set_transcode(linkItem->getTransCode());
				newLink->set_fromnodeid(qPrintable(linkItem->getFromNode()->getNodeID()));
				newLink->set_tonodeid(qPrintable(linkItem->getToNode()->getNodeID()));
			}
		}
	}

	////////////////////
	//下面开始将信息写入到文件中去 //
	////////////////////
	/** 移除文件 */
	QFile::remove(filename);
    {
	    // Write the new address book back to disk.
	    std::fstream output(qPrintable(filename), std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);
	    if (!mtFile.SerializeToOstream(&output)) {
			std::cerr << "Failed to write address book." << std::endl;
		    return false;
		}
    }
    // Optional:  Delete all global objects allocated by libprotobuf.
    // 
    return true;
}

bool GraphicsView::readFile(const QString & filename)
{
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	modeTable::MTFile mtFile;
	{
	    // Read the existing address book.
	    std::fstream input(qPrintable(filename), std::ifstream::in | std::ifstream::binary);
	    if (!mtFile.ParseFromIstream(&input)) {
	      std::cerr << "Failed to parse address book." << std::endl;
	      return false;
	    }
  	}
	  ////////////////////////
  	//下面开始读取文件信息，创建items //
	  ////////////////////////
	/** 读取节点信息,并会画出来 */
	QList<Node *> nodes;

	for (int i = 0; i <mtFile.nodelist_size() ; ++i)
	{
		modeTable::Node node  = mtFile.nodelist(i);
		/** 这里需要后面的实现接口才能实现，主要是创建节点工作 */
		Node * newNode = new Node;
		if(!newNode)
		{
			foreach(Node * node , nodes)
			{
				delete node;//释放之前的申请节点
			}
			return false;
		}
		//  设置外观
		newNode->setPos(QPointF(node.xpos() , node.ypos()));
		newNode->setText(node.nodename().c_str());
		newNode->setTextColor(QColor(node.textcolor().c_str()));
		newNode->setOutlineColor(QColor(node.outlinecolor().c_str()));
		newNode->setBackgroundColor(QColor(node.backgroundcolor().c_str()));
		// 设置节点信息
		newNode->setStartAudio(node.startaudio().c_str());
		newNode->setEndAudio(node.endaudio().c_str());
		QStringList defaultList;
		for (int i = 0; i < node.defaultaudio_size(); ++i)
		{
			defaultList.push_back(node.defaultaudio(i).c_str());
		}
		newNode->setDefaultAudioList(defaultList);
		newNode->setNodeID(node.nodeid().c_str());
		scene()->addItem(newNode);
		nodes.push_back(newNode);
	}

	for (int i = 0; i < mtFile.linklist_size(); ++i)
	{
		modeTable::Link link = mtFile.linklist(i);
		/** 构建线段的工作 */
		QString fromNodeID = link.fromnodeid().c_str(); 
		QString toNodeID = link.tonodeid().c_str();
		Node * fromNode=0;
		Node * toNode=0;
		foreach(Node * node , nodes)
		{
			if(node->getNodeID() == fromNodeID)
				fromNode = node;
			else if(node->getNodeID() == toNodeID)
				toNode = node;
			if(fromNode && toNode)
				break;
		}
		createLink(fromNode , toNode);
		// newLink->setTransCode(link.transcode());
	}

	// google::protobuf::ShutdownProtobufLibrary();
	return true;
}



/** 这个createNode是按照固定的位置来创建node的 */
void GraphicsView::createNode()
{
	Node * node = new Node;
	node->setText(tr("Node %1").arg(seqNumber+1));
	setupNode(node);//把节点放在合适的位置
}

/** 主要用在文件读取的时候或者是鼠标直接右键创建Node是采用 */
Node * GraphicsView::createNode(const QPointF & pos)
{
	Node * node = new Node;
	node->setText(tr("Node %1").arg(seqNumber+1));
	node->setPos(pos);
	++seqNumber;

	scene()->addItem(node);
	scene()->clearSelection();
	node->setSelected(true);
	bringToFront();
	return node;
}

void GraphicsView::setupNode(Node * node)
{
	node->setPos(QPoint(80+(100*(seqNumber%10)),\
						80+(50*((seqNumber/10)%12))));
	scene()->addItem(node);
	++seqNumber;

	scene()->clearSelection();
	node->setSelected(true);
	bringToFront();
}

void GraphicsView::bringToFront()
{
	++maxZ;
	setZValue(maxZ);
}


void GraphicsView::sendToBack()
{
	--minZ;
	setZValue(minZ);
}

void GraphicsView::setZValue(int z)
{
	Node * node = selectedNode();
	if(node)
		node->setZValue(z);
}

Node * GraphicsView::selectedNode() const
{
	QList<QGraphicsItem *> items = scene()->selectedItems();
	if(items.count()==1)
		return dynamic_cast<Node *>(items.first());
	else
		return 0;
}

/** 返回选中的多个节点 */
QList<Node *> GraphicsView::selectedNodes() const
{	
	QList<QGraphicsItem *> items = scene()->selectedItems();
	QList<Node *> nodes;
	foreach(QGraphicsItem * item , items)
	{
		Node * node = dynamic_cast<Node *>(item);

		if(node != NULL)
			nodes.push_back(node);
	}
	return nodes;
}

void GraphicsView::alignHorizontal(QList<Node *> nodes)
{
	//水平对齐的话是以y为标准
	if(nodes.count() <=1)
		return;
	//得到最左边的那个item
	Node * basicNode=nodes.first();
	foreach(Node * node , nodes)
	{
		if(node->pos().x() < basicNode->pos().x())
			basicNode = node;
	}
	// 全都以basicitem的y坐标对齐
	double y = basicNode->pos().y();
	foreach(Node * node , nodes)
	{
		node->setPos(QPointF(node->pos().x() , y));//横向已对齐
	}
}

void GraphicsView::alignVertical(QList<Node * > nodes)
{
	if(nodes.count() <=1)
		return;
	Node * basicnNode = nodes.first();
	// 以最上边的那个node对齐
	foreach(Node * node , nodes)
	{
		if(node->pos().y() < basicnNode->pos().y())
			basicnNode = node;
	}
	//得到x坐标
	double x = basicnNode->pos().x();
	foreach(Node  * node , nodes)
	{
		node->setPos(QPointF(x  , node->pos().y()));
	}
}

void GraphicsView::addChildNode(Node * fatherNode)
{
	//在fatherNode上面添加一个孩子节点
	// 得到fatherNode的位置信息，使得孩子节点的位置在fatherNode的右下一定距离
	QPointF childNodePos = fatherNode->pos();
	childNodePos.rx()+=100;
	childNodePos.ry()+=50;
	Node * childNode = createNode(childNodePos);
	//然后连线
	createLink(fatherNode , childNode);
}

/** 设置外观 */
void GraphicsView::nodeSurfacceProperties(Node * node)
{
	PropertiesDialog * dialog = new PropertiesDialog(scene() , node);//现在就可以修改外观了
	dialog->show();
	if(dialog->exec() == QDialog::Accepted)
	{
		node->setPos(QPointF(dialog->xValue() , dialog->yValue()));
		node->setTextColor(dialog->getTextColor());
		node->setOutlineColor(dialog->getOutlineColor());
		node->setBackgroundColor(dialog->getBackgroundColor());
		node->setTransCodeTextColor(dialog->getTransCodeTextColor());
		node->setTransCodeBackgroundColor(dialog->getTransCodeBackgroundColor());
		node->setText(dialog->getText());
		node->setTransCode(dialog->getTransCodeText());
	}
}

/** 批量修改节点外观 */
void GraphicsView::nodesSurfacceProperties(QList<Node *> nodes)
{
	//采取第一个节点的信息
	PropertiesDialog * dialog = new PropertiesDialog(scene() , nodes[0]);
	dialog->show();
	//把设置节点位置关闭
	dialog->disableSetPosName();
	if(dialog->exec() == QDialog::Accepted)
	{
		foreach(Node * node , nodes)
		{
			node->setTextColor(dialog->getTextColor());
			node->setOutlineColor(dialog->getOutlineColor());
			node->setBackgroundColor(dialog->getBackgroundColor());
			node->setTransCodeTextColor(dialog->getTransCodeTextColor());
			node->setTransCodeBackgroundColor(dialog->getTransCodeBackgroundColor());
		}
	}
}

/** 设置节点信息 */
void GraphicsView::infoProperties(Node * node)
{
	SetNodeInfo * setDialog = new SetNodeInfo(node);
	if(setDialog->exec()==QDialog::Accepted)
	{
		// setDialog->syncData();
		// node->setStartAudio(setDialog->getStartAudio());
		// node->setEndAudio(setDialog->getEndAudio());
		// node->setDefaultAudioList(setDialog->getBeforeDefaultAudioList());
		// node->setAfterdefaultAudioList(setDialog->getAfterDefaultAudioList());
		// node->setText(setDialog->getNodeName());
		// node->setPicture(setDialog->getPictureName());
		// node->setTransCode(setDialog->getTransCode());

		// node->setSameFlag(setDialog->getSameFlag());

		// QList<QPair<QString , QString> > tempList1 = setDialog->getBeforeGivenAudioTable(); 
		// QList<QPair<QString , QString> > tempList2 = setDialog->getAfterGivenTableAudio(); 
		// givenAudioTable.clear();
		// afterGivenAudioTable.clear();

		// /** 设置第一个表的内容 */
		// for(QList<QPair<QString , QString> >::iterator iter = tempList1.begin() ; iter != tempList1.end();
		// 				++iter)
		// {
		// 	givenAudioTable[iter->first] = iter->second;
		// }
		// /** 如果前后状态相同 */
		// if(isBeforeSameAsAfter())
		// 	return;
		// for(QList<QPair<QString , QString> >::iterator iter = tempList2.begin() ; iter != tempList2.end();
		// 				++iter)
		// {
		// 	afterGivenAudioTable[iter->first] = iter->second;
		// }
	}
}


/////////////////
////////////// //
//link的相应接口 // //
////////////// //
/////////////////

void GraphicsView::createLink()
{
	NodePair nodes = selectedNodePair();
	if(nodes == NodePair())
		return;
	Link * link = new Link(nodes.first , nodes.second);
	scene()->addItem(link);
}

Link * GraphicsView::createLink(Node * fatherNode , Node * childNode) 
{
	Link * link = new Link(fatherNode  , childNode);
	scene()->addItem(link);
	return link;
}


/** 返回选中的节点对 */
GraphicsView::NodePair GraphicsView::selectedNodePair() const
{
	QList<QGraphicsItem * > items =scene()->selectedItems();
	if(items.count() >= 2)
	{
		Node * first =NULL;
		Node * second =NULL;
		QList<Node *> nodes;
		foreach(QGraphicsItem * item , items)
		{
			Node * node = dynamic_cast<Node *>(item);
			if(node)
				nodes.push_back(node);
		}
		if(nodes.count() != 2)
			return NodePair();
		first = nodes.first();
		second = nodes.last();
		return NodePair(first , second);
	}
	return NodePair();
}

/** 返回一个view里面的全部信息 */
QList<Node *> GraphicsView::allNodes()
{
	QList<QGraphicsItem *> items =scene()->items();
	QList<Node *> nodes;
	foreach(QGraphicsItem * item , items)
	{
		Node * node = dynamic_cast<Node *>(item);
		if(node)
			nodes.push_back(node);
	}
	return nodes;
}

/** 从fatherNode连接到一个新的childNode */
void GraphicsView::linkToChildNode(Node * fatherNode)
{
	// 等待选择孩子节点
	Node * childNode = chooseANode(fatherNode);
	// 新建父节点指向孩子节点的链接
	if(childNode == NULL)
		return ;
	createLink(fatherNode , childNode);
	scene()->clearSelection();
}

/** 从childNode连接到一个父节点 */
void GraphicsView::linkToFatherNode(Node * childNode)
{
	// 等待选择父亲节点
	Node * fatherNode =chooseANode(childNode);
	// 新建孩子节点被父亲节点的指向链接
	if(fatherNode == NULL)
		return ;
	createLink(fatherNode , childNode);
	scene()->clearSelection();
}

Node * GraphicsView::chooseANode(Node * node)
{
	curMode = ChooseNodeMode;
	//是选择chooseNode状态
	while(curMode == ChooseNodeMode)
	{
		// 避免未响应
		qApp->processEvents();
		//一直都是选中状态
		node->setSelected(true);
		QList<QGraphicsItem *> items = scene()->selectedItems();//得到选中的items
		if(items.count() != 2)
			continue;
		// 判断选中的是否都是Node类型的节点
		Node * node1 = dynamic_cast<Node *>(items.first());
		Node * node2 = dynamic_cast<Node *>(items.last());
		if(node1 && node2)
		{
			curMode = NormalMode;
			//选中的两个都是节点
			if(node1 == node)
				return node2;
			else
				return node1;
			for (int i = 0; i < 10000; ++i)
			{
				for(int j=0;j<1;++j);
					qApp->processEvents();
			}
			scene()->clearSelection();
		}
	}
	return 0;
}

//这是在不断连线的模式
void GraphicsView::linkMode()
{
	curMode = ChooseNodePairMode;
	while(curMode == ChooseNodePairMode)
	{
		Node * fatherNode = 0;
		// 避免未响应
		// qApp->processEvents();
		//一直在等到选择节点
		QList<QGraphicsItem *> items = scene()->selectedItems();		
		//首先需要得到父节点
		if(items.count() == 1)
		{
			qApp->processEvents();
			fatherNode = dynamic_cast<Node *>(items.first());
			if(fatherNode)//选中的是一个节点
			{
				//需要选择一个新的孩子节点
				while(curMode == ChooseNodePairMode)
				{
					qApp->processEvents();
					fatherNode->setSelected(true);
					QList<QGraphicsItem *> items1 = scene()->selectedItems();
					/** father node 的选中状态 */
					if(items1.count() == 2)//新选择了一个
					{
						Node * node1 = dynamic_cast<Node *>(items1.first());
						Node * node2 = dynamic_cast<Node *>(items1.last());
						qApp->processEvents();
						if(node1 && node2)
						{

							if(node1 == fatherNode)
								createLink(node1 , node2);
							else
								createLink(node2 , node1);
							scene()->clearSelection();
							qApp->processEvents();
							for (int i = 0; i < 10000; ++i)
							{
								for(int j=0;j<1;++j);
									qApp->processEvents();
							}
							break;//退出循环,重新选择父节点
						}
					}
				}
				//一定要清空所有选择
				while(scene()->selectedItems().count() !=0)
					scene()->clearSelection();
			}
			while(scene()->selectedItems().count() !=0)
			{
				scene()->clearSelection();
				qApp->processEvents();
			}
		}
		qApp->processEvents();
	}
	scene()->clearSelection();
}


void GraphicsView::keyPressEvent(QKeyEvent * keyEvent)
{

    /////////////////////////
    //按下esc ,那么就回归normal模式 //
    /////////////////////////
	int key = keyEvent->key();
    if(key == Qt::Key_Escape)
    {
    	//恢复到正常模式
    	if(curMode == ChooseNodeMode || curMode == ChooseNodePairMode || curMode == DebugMode)
    	{
    		if(curMode == DebugMode)
    			stopDebug();
    		curMode = NormalMode;
    	}
    	else
    		QGraphicsView::keyPressEvent(keyEvent);
    }
    else if((keyEvent->key() == Qt::Key_Space && (keyEvent->modifiers() & Qt::ControlModifier)))
    {
    	//ctrl + space 调换节点父子关系
    	NodePair nodePair = selectedNodePair();
    	if(nodePair == NodePair())
    		QGraphicsView::keyPressEvent(keyEvent);
    	else
    	{
    		//搜寻之间的父子关系
    		QList<QGraphicsItem * > items = scene()->items();
    		foreach(QGraphicsItem * item  , items)
    		{
    			Link * link = dynamic_cast<Link *>(item);
    			if(link)
    			{
    				if(link->getFromNode() == nodePair.first && link->getToNode() == nodePair.second)
    				{

    					//开始改变
    					createLink(nodePair.second , nodePair.first);
    					scene()->removeItem(link);
    					return;
    				}
    				else
    				{
    					if(link->getFromNode() == nodePair.second && link->getToNode() == nodePair.first)
    					{
	    					createLink(nodePair.first , nodePair.second);
	    					scene()->removeItem(link);
	    					return;
    					}
    				}
    			}
    		}
    	}
    }
    else
    {
    	QGraphicsView::keyPressEvent(keyEvent);
    }
}


Link * GraphicsView::selectedLink() const
{
	QList<QGraphicsItem *> items = scene()->selectedItems();
	if(items.count()==1)
	{
		return dynamic_cast<Link *>(items.first());
	}
	return 0;
}

// void GraphicsView::transCode(Link * link)
// {
// 	EnterTransCodeDialog * transCodeDialog = new EnterTransCodeDialog(link);
// 	if(transCodeDialog -> exec() == QDialog::Accepted)
// 	{
// 		link->setTransCode(transCodeDialog->getTransCode());
// 	}
// }

void GraphicsView::linkSurfacceProperties(Link * /*link*/)
{
	/** 占时不实现,以后拓展时可以实现 */
}


void GraphicsView::deleteobjs()
{
	QList<QGraphicsItem * > items = scene()->selectedItems();
	QMutableListIterator<QGraphicsItem *> iter(items);
	while(iter.hasNext())
	{
		Link * link = dynamic_cast<Link * >(iter.next());
		if(link)
		{
			delete link;
			iter.remove();
		}
	}
	qDeleteAll(items);
}


void GraphicsView::cut()
{
	Node * node = selectedNode();
	if(!node)
		return;
	copy();
	delete node;
}


void GraphicsView::copy()
{
	Node * node = selectedNode();
	if(!node)
		return;
	// node 文本颜色 外线颜色 背景色 开始音频 结束音频 默认音频1+默认音频2+...  文本内容
	QString surfaceStr = QString("Node %1 %2 %3 %4 %5 ").\
								  arg(node->getTextColor().name()).\
								  arg(node->getOutlineColor().name()).\
								  arg(node->getBackgroundColor().name()).\
								  arg(node->getTransCodeTextColor().name()).\
								  arg(node->getTransCodeBackgroundColor().name());
    /** 得到所有的given node pair */
    QMap<QString , QString> givenAudioMap = node->getAllGivenTableAudio();
    QStringList givenAudiosList;
    for(QMap<QString, QString>::iterator iter = givenAudioMap.begin();\
    	iter!=givenAudioMap.end() ; ++iter)
    {
    	QString tempStr = QString("<%1,%2>").arg(iter.key()).arg(iter.value());
    	givenAudiosList<<tempStr;
    }
	QString infoStr=QString("%1 %2 %3 %4 %5 %6").\
							 arg(node->getStartAudio()).\
							 arg(node->getEndAudio()).\
							 arg(node->getTransCode()).\
							 arg(node->getPicture()).\
							 arg(givenAudiosList.join("!+!")).\
							 arg(node->getText());
    QString sumData = surfaceStr+infoStr;
    QApplication::clipboard()->setText(sumData);
}

void GraphicsView::paste()
{
	QString str = QApplication::clipboard()->text();
	QStringList parts = str.split(" ");
	if(parts.count() >=12 && parts.first() == "Node")
	{
		Node * node = new Node;
		//设置外观
		node->setText(QStringList(parts.mid(11)).join(" "));
		node->setTextColor(QColor(parts[1]));
		node->setOutlineColor(QColor(parts[2]));
		node->setBackgroundColor(QColor(parts[3]));
		node->setTransCodeTextColor(QColor(parts[4]));
		node->setTransCodeBackgroundColor(QColor(parts[5]));
		//设置节点信息
		node->setStartAudio(parts[6]);
		node->setEndAudio(parts[7]);
		node->setTransCode(parts[8]);
		node->setPicture(parts[9]);
		QStringList givenAudiosList = parts[10].split("!+!");
		foreach(QString str , givenAudiosList)
		{
			// 移除括号
			str.remove(QChar('<'),Qt::CaseInsensitive);
			str.remove(QChar('>'),Qt::CaseInsensitive);
			QStringList mapStr = str.split(",");
			if(mapStr.size()>=2)
				node->addGivenTableAudio(mapStr[0],mapStr[1]);
		}

		//现在需要获得鼠标位置,才好放置节点
		setupNode(node);
		//如果是鼠标点击添加节点
		if(!mouserPos.isNull())
			node->setPos(mouserPos);
		mouserPos = QPointF();
	}
}

void GraphicsView::mousePressEvent(QMouseEvent * mouseEvent)
{
	switch(mouseEvent->button())
	{
		case Qt::RightButton:
			mouserPos = mouseEvent->posF();
			QGraphicsView::mousePressEvent(mouseEvent);
			break;
		default:
			QGraphicsView::mousePressEvent(mouseEvent);
	}
}


QSize GraphicsView::sizeHint() const
{
	return QSize(72 * fontMetrics().width('x'),\
				 25 * fontMetrics().lineSpacing());
}



void GraphicsView::startToDebug(QDockWidget * dockWidget)
{
	if(dockWidget == NULL)
		return;
	AudioPlayWidget * audioPlayWidget = dynamic_cast<AudioPlayWidget*>(dockWidget->widget());
	if(audioPlayWidget == NULL)
		return;
	curMode = DebugMode;
	//每个view都可以拥有一个dockWidget,而且为了方便删除
	this->dockWidget = dockWidget;
	while(curMode == DebugMode)
	{
		audioPlayWidget->playStartAudio();//播放入口音乐
	begin:
		/** 选中当前调试中的节点 */
		scene()->clearSelection();
		audioPlayWidget->getNode()->setSelected(true);
		/** 得到curNode相关的链接 */
		QList<QGraphicsItem *> items = scene()->items();
		QList<Link *> links ;
		foreach(QGraphicsItem * item , items)
		{
			Link * link = dynamic_cast<Link *>(item);
			if(link && link->getFromNode() == audioPlayWidget->getNode())
				links.push_back(link);
		}
		/** 下面进入循环等待用户输入转移码 */
		while(curMode == DebugMode)
		{
			qApp->processEvents();
			//现在等待用户的输入
			int inputTransCode=0;
			while(curMode == DebugMode && audioPlayWidget->waitForInput())
				qApp->processEvents();
			/** 以防用户退出非调试状态 */
			if(curMode != DebugMode)
				return;
			/** 重置等待状态 */
			audioPlayWidget->resetWaitStatus();
			inputTransCode =audioPlayWidget->getInput();
			/** 判断输入的转移码有没有相应的链接符合 */
			foreach(Link * link , links)
			{	
				// if(link->getTransCode() == inputTransCode)
				{
					/** 开始转移至新的节点 */
					audioPlayWidget->playEndAudio();
					audioPlayWidget->transToNewNode(link->getToNode());
					audioPlayWidget->enqueueStartAudio();
					goto begin;
				}
			}			
			/** 不能转移,播放默认的音频之一 */
			audioPlayWidget->playDefaultAudio();
			qApp->processEvents();		
		}
		qApp->processEvents();
	}
}


void GraphicsView::stopDebug()
{
	curMode = NormalMode;
	if(dockWidget != NULL)
	{
		delete dockWidget ;
		dockWidget = NULL;
	}
}

void GraphicsView::selectedChanged()
{
	QList<Node *> nodes = selectedNodes();
	if(nodes.count() != 1) 
		MainWindow::updateDockWidget(NULL);
	else
		MainWindow::updateDockWidget(nodes[0]);
}




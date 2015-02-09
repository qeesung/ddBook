#include <QtGui>
#include <QDebug>
#include <iostream>
#include <fstream>
// #include <QIcon>
#include "GraphicsView.h"
#include "entertranscodedialog.h"
#include "setNodeInfo.h"
#include "node.h"
#include "modeTable.pb.h"
#include "link.h"
#include "propertiesdialog.h"
#include "setNodeInfo.h"


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
		event->accept();
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
				newLink->set_transcode(linkItem->getTransCode());
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
		Link * newLink = createLink(fromNode , toNode);
		newLink->setTransCode(link.transcode());
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
		node->setText(dialog->getText());
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
		}
	}
}

/** 设置节点信息 */
void GraphicsView::infoProperties(Node * node)
{
	SetNodeInfo * setDialog = new SetNodeInfo(node);
	if(setDialog->exec()==QDialog::Accepted)
	{
		node->setStartAudio(setDialog->getStartAudio());
		node->setEndAudio(setDialog->getEndAudio());
		node->setDefaultAudioList(setDialog->getDefaultAudioList());
		node->setText(setDialog->getNodeName());
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
	if(items.count() == 2)
	{
		Node * first = dynamic_cast<Node *>(items.first());
		Node * second = dynamic_cast<Node *>(items.last());
		if(first && second)
			return NodePair(first , second);
	}
	return NodePair();
}

/** 从fatherNode连接到一个新的childNode */
void GraphicsView::linkToChildNode(Node * fatherNode)
{
	// 等待选择孩子节点
	Node * childNode = chooseANode(fatherNode);
	// 新建父节点指向孩子节点的链接
	createLink(fatherNode , childNode);
}

/** 从childNode连接到一个父节点 */
void GraphicsView::linkToFatherNode(Node * childNode)
{
	// 等待选择父亲节点
	Node * fatherNode =chooseANode(childNode);
	// 新建孩子节点被父亲节点的指向链接
	createLink(fatherNode , childNode);
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
		}
	}
	return 0;
}

//这是在不断连线的模式
void GraphicsView::linkMode()
{
	curMode = ChooseNodePairMode;
	QList<Node *> selectedNodes;
	while(curMode == ChooseNodePairMode)
	{
		Node * fatherNode = 0;
		// 避免未响应
		qApp->processEvents();
		//一直在等到选择节点
		QList<QGraphicsItem *> items = scene()->selectedItems();		
		//首先需要得到父节点
		if(items.count() == 1)
		{
			fatherNode = dynamic_cast<Node *>(items.first());
			if(fatherNode)//选中的是一个节点
				linkToChildNode(fatherNode);//再需要链接一个子节点
			//还原当前的模式
			curMode = ChooseNodePairMode;
		}
		scene()->clearSelection();
	}
}


void GraphicsView::keyPressEvent(QKeyEvent * keyEvent)
{

    //按下esc ,那么就回归normal模式
    switch(keyEvent->key())
    {
    	case Qt::Key_Escape:
    		if(curMode == ChooseNodeMode || curMode == ChooseNodePairMode)
	    		curMode = NormalMode;
	    	else
	    		QGraphicsView::keyPressEvent(keyEvent);
    		break;
    	default://那么就按照原来的进行
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

void GraphicsView::transCode(Link * link)
{
	EnterTransCodeDialog * transCodeDialog = new EnterTransCodeDialog(link);
	if(transCodeDialog -> exec() == QDialog::Accepted)
	{
		link->setTransCode(transCodeDialog->getTransCode());
	}
}

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
	QString surfaceStr = QString("Node %1 %2 %3 ").\
								  arg(node->getTextColor().name()).\
								  arg(node->getOutlineColor().name()).\
								  arg(node->getBackgroundColor().name());
	QString infoStr=QString("%1 %2 %3 %4").\
							 arg(node->getStartAudio()).\
							 arg(node->getEndAudio()).\
							 arg(node->getDefaultAudioList().join("!+!")).\
							 arg(node->getText());
    QString sumData = surfaceStr+infoStr;
    QApplication::clipboard()->setText(sumData);
}

void GraphicsView::paste()
{
	QString str = QApplication::clipboard()->text();
	QStringList parts = str.split(" ");
	if(parts.count() >=8 && parts.first() == "Node")
	{
		Node * node = new Node;
		//设置外观
		node->setText(QStringList(parts.mid(7)).join(" "));
		node->setTextColor(QColor(parts[1]));
		node->setOutlineColor(QColor(parts[2]));
		node->setBackgroundColor(QColor(parts[3]));
		//设置节点信息
		node->setStartAudio(parts[4]);
		node->setEndAudio(parts[5]);
		QStringList defaultList = parts[6].split("!+!");
		node->setDefaultAudioList(defaultList);

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







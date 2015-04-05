#include "setNodeInfo.h"
#include "selectCodeDialog.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QFileDialog>

extern QString cpFileName="cpData";//这个是预先编辑好的code : picture对应的对文件名字

SetNodeInfo::SetNodeInfo(const Node * node,QWidget * parent):QDialog(parent)
{
	////////////////
	// 设置节点的基本信息 //
	////////////////
	setupUi(this);
	label_6->setVisible(false);
	frame->setVisible(false);
	/** 使得表可以自由伸展 */
	givenAudioTableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	// startAudioTableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
	// endAudioTableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
	// givenAudioTableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);

	/** 在启动dialog时候自动载入节点信息 */
	nodeNameLineEdit->setText(node->getText());
	nodeNameLineEdit->selectAll();//选中全部的Node名字

	/** 这里采用文件的形式保存全局code : picture 信息 */
	/** 文件名字用日期信息保存 */
	/** 这里读取设置cpMap信息 */
	QFile cpFile(cpFileName);
	if(!cpFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox * mBox = new QMessageBox;
		mBox->setText(QString("Open file %1 failed\n file is destoried or is not existed\n").arg(cpFileName));
	}
	QTextStream cpPairInput(&cpFile);
	QString lineStr;
	while(!cpPairInput.atEnd())
	{
		lineStr = cpPairInput.readLine();//读取到文件的一行数据
		/** 一行数据的格式　code-Y(^_^)Y-picture */
		QStringList cpTemp = lineStr.split(QString("-Y(^_^)Y-"));
		cpMap[cpTemp[0]] = cpTemp[1];//码制和图片对应
	}

	/** transCodelineEdit的内容 */
	transCodeLineEdit->setDisabled(true);
	if(node->getTransCode() == QString("None"))
	{
		transCodeLineEdit->setText("None");
		QPixmap pixmap(":/images/about.png");
		QPixmap fitpixmap=pixmap.scaled(100,100, Qt::KeepAspectRatio);  
		pictureLabel->setPixmap(fitpixmap);
	}
	else
	{
		transCodeLineEdit->setText(node->getTransCode());
		if(cpMap.count(node->getTransCode()) == 0 )//表明码值不存在
			pictureLabel->setText(QString("<h2><i><font color=red>invalid Code</font></i></h2>"));
		else//设置图片信息
		{
			QPixmap pixmap(cpMap[node->getTransCode()]);
			QPixmap fitpixmap=pixmap.scaled(100,100, Qt::KeepAspectRatio);  
			if(fitpixmap.isNull())
				pictureLabel->setText(QString("<h2><i><font color=red>invalid Code</font></i></h2>"));
			else
				pictureLabel->setPixmap(fitpixmap);
		}
	}
	

	startAudioLineEdit->setText(node->getStartAudio());
	endAudioLineEdit->setText(node->getEndAudio());
	
	////////////////
	// 设置节点的附加信息 //
	////////////////
	///
	/** 首先判断是否是状态前状态后一样的 */
	bool sameFlag = node->isBeforeSameAsAfter();
	sameFlagCheckBox->setChecked(!sameFlag);
	beforeRadioButton->setVisible(!sameFlag);
	afterRadioButton->setVisible(!sameFlag);
	beforeRadioButton->setChecked(true);

	/**　显示相应的数据*/
	QStringList filenames = node->getDefaultAudioList();
	beforeDefaultAudioList = filenames;
	foreach(QString filename , filenames)
	{
		QListWidgetItem * tempItem = new QListWidgetItem(filename);
		defaultAudiotListWidget->addItem(tempItem);
	}

	unsigned int i = 0;
	/** 得到given table的值 */
	QMap<QString , QString> givenAudioTableMap = node->getAllGivenTableAudio();
	for(QMap<QString , QString>::const_iterator iter = givenAudioTableMap.constBegin() ;\
											   iter != givenAudioTableMap.constEnd() ; ++iter , ++i)
	{
		QTableWidgetItem * item1 = new QTableWidgetItem(iter.key());
		QTableWidgetItem * item2 = new QTableWidgetItem(iter.value());
		givenAudioTableWidget->insertRow(i);
		givenAudioTableWidget->setItem(i,0 ,item1);
		givenAudioTableWidget->setItem(i,1 ,item2);
		beforeGivenAudioList.push_back(QPair<QString , QString>(iter.key() , iter.value()));
	}
	/** 不管sameFlag怎么样,都读入全部数据 */
	afterDefaultAudioList = node->getAfterDefaultAudioList();
	givenAudioTableMap = node->getAllAfterGivenTableAudio();
	for(QMap<QString , QString>::const_iterator iter = givenAudioTableMap.constBegin() ;\
											   iter != givenAudioTableMap.constEnd() ; ++iter , ++i)
	{
		afterGivenAudioList.push_back(QPair<QString , QString>(iter.key() , iter.value()));
	}


	//将表设置为多选选项
	defaultAudiotListWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	givenAudioTableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	//ok按钮为默认的按钮
	okPushButton->setDefault(true);

	connect(startAudioPushButton , SIGNAL(clicked()),\

		    this , SLOT(startAudioView()));
	connect(endAudioPushButton , SIGNAL(clicked()),\
		    this , SLOT(endAudioView()));

	connect(defaultAudioAddPushButton, SIGNAL(clicked()),\
		    this , SLOT(addDefaultAudio()));
	connect(defaultAudioDeletePushButton , SIGNAL(clicked()),\
			this , SLOT(deleteDefaultAudio()));

	connect(givenAudioAddPushButton, SIGNAL(clicked()),\
		    this , SLOT(addGivenTableAudio()));
	connect(givenAudioDeletePushButton , SIGNAL(clicked()),\
			this , SLOT(deleteGivenTableAudio()));

	connect(beforeRadioButton , SIGNAL(toggled(bool)),\
			this , SLOT(beforeRadioToggled(bool)));
	connect(afterRadioButton , SIGNAL(toggled(bool)),\
			this , SLOT(afterRadioToggled(bool)));

	connect(transCodeLineEdit , SIGNAL(textChanged(const QString &)),\
			this , SLOT(updateNodePic(const QString &)));

	connect(transCodeViewButton , SIGNAL(clicked()),\
			this , SLOT(selectTransCode()));
}

void SetNodeInfo::startAudioView()
{
	QFileDialog * fileDialog = new QFileDialog;
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	fileDialog->setNameFilter(QString("audio file(*.mp3 *.wmv)"));
	fileDialog->setViewMode(QFileDialog::List);
	fileDialog->setDirectory("../../res/");
	fileDialog->setWindowTitle("Choose a start audio file");
	if(fileDialog->exec()==QDialog::Accepted)
	{
		QString filename = fileDialog->selectedFiles()[0];
		startAudioLineEdit->setText(filename);
	}
}

void SetNodeInfo::endAudioView()
{
	QFileDialog * fileDialog = new QFileDialog;
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	fileDialog->setNameFilter(QString("audio file(*.mp3 *.wmv)"));
	fileDialog->setViewMode(QFileDialog::List);
	fileDialog->setDirectory("../../res/");
	fileDialog->setWindowTitle("Choose a end audio file");
	if(fileDialog->exec()==QDialog::Accepted)
	{
		QString filename = fileDialog->selectedFiles()[0];
		endAudioLineEdit->setText(filename);
	}
}

void SetNodeInfo::addDefaultAudio()
{
	QFileDialog * fileDialog = new QFileDialog;
	fileDialog->setFileMode(QFileDialog::ExistingFiles);
	fileDialog->setNameFilter(QString("audio file(*.mp3 *.wmv)"));
	fileDialog->setViewMode(QFileDialog::List);
	fileDialog->setDirectory("../../res/");
	fileDialog->setWindowTitle("Choose a default audio file");
	if(fileDialog->exec()==QDialog::Accepted)
	{
		QStringList filenames = fileDialog->selectedFiles();
		foreach(QString filename , filenames)
		{
			QListWidgetItem * newItem= new QListWidgetItem(filename);
			defaultAudiotListWidget->addItem(newItem);
		}
	}
}

void SetNodeInfo::deleteDefaultAudio()
{
	QList<QListWidgetItem * > selectedItems = defaultAudiotListWidget->selectedItems();
	foreach(QListWidgetItem * item , selectedItems)
	{
		defaultAudiotListWidget->removeItemWidget(item);
		delete item;
	}
}


void SetNodeInfo::addGivenTableAudio()
{
	GetTablePairDialog * dialog = new GetTablePairDialog;
	dialog->setWindowTitle("GivenCode --- AudioFile");
	if(dialog->exec() == QDialog::Accepted)
	{
		QTableWidgetItem * item1 = new QTableWidgetItem(dialog->getCode());
		QTableWidgetItem * item2 = new QTableWidgetItem(dialog->getFile());
		unsigned int rowCount = givenAudioTableWidget->rowCount();
		givenAudioTableWidget->insertRow(rowCount);
		givenAudioTableWidget->setItem(rowCount , 0 , item1);
		givenAudioTableWidget->setItem(rowCount , 1 , item2);
	}
}
void SetNodeInfo::deleteGivenTableAudio()
{
	QList<QTableWidgetItem *> selectedItems = givenAudioTableWidget->selectedItems();
	foreach(QTableWidgetItem * item , selectedItems)
	{
		givenAudioTableWidget->removeRow(givenAudioTableWidget->row(item));
	}
}


void SetNodeInfo::beforeRadioToggled(bool state)
{
	if(!state)
		return;
	/** 马上保存after编辑的数据 */
	saveData(afterGivenAudioList , afterDefaultAudioList);
	/** 重现显示before的数据 */
	showData(beforeGivenAudioList , beforeDefaultAudioList);
}

void SetNodeInfo::afterRadioToggled(bool state)
{
	if(!state)
		return;
	/** 马上保存before编辑的数据 */
	saveData(beforeGivenAudioList , beforeDefaultAudioList);
	/** 重现显示after的数据 */
	showData(afterGivenAudioList , afterDefaultAudioList);
}


void SetNodeInfo::saveData(QList<QPair<QString, QString> > & givenList ,\
					QStringList & defaultList)
{
	defaultList.clear();
	//////////////
	//更新默认列表信息 //
	//////////////
	size_t listCount = defaultAudiotListWidget->count();
	for (size_t i = 0; i < listCount; ++i)
	{
		QListWidgetItem * tempItem = defaultAudiotListWidget->item(i);
		defaultList.push_back(tempItem->text());
	}
	///////////////
	// 更新给定列表信息 //
	///////////////
	givenList.clear();
	size_t tableCount = givenAudioTableWidget->rowCount();
	for (size_t i = 0; i < tableCount; ++i)
	{
		QTableWidgetItem * item1 = givenAudioTableWidget->item(i,0);
		QTableWidgetItem * item2 = givenAudioTableWidget->item(i,1);
		givenList.push_back(QPair<QString , QString>(item1->text() , item2->text()));
	}
}


void SetNodeInfo::showData(QList<QPair<QString, QString> > & givenList,\
					QStringList & defaultList)
{
	defaultAudiotListWidget->clear();
	//////////////
	//更新默认列表Widget //
	//////////////
	size_t listCount = defaultList.count();
	for (size_t i = 0; i < listCount; ++i)
	{
		QListWidgetItem * tempItem = new QListWidgetItem(defaultList[i]);
		defaultAudiotListWidget->insertItem(i,tempItem);
	}
	///////////////
	// 更新给定列表Widget //
	///////////////
	while(givenAudioTableWidget->rowCount() !=0)
		givenAudioTableWidget->removeRow(0);
	size_t tableCount = givenList.count();
	for (size_t i = 0; i < tableCount; ++i)
	{
		QTableWidgetItem * item1 = new QTableWidgetItem(givenList[i].first);
		QTableWidgetItem * item2 = new QTableWidgetItem(givenList[i].second);
		givenAudioTableWidget->insertRow(i);
		givenAudioTableWidget->setItem(i,0,item1);
		givenAudioTableWidget->setItem(i,1,item2);
	}
}

void SetNodeInfo::updateNodePic(const QString & text)
{
	if(cpMap.count(text) == 0)
	{
		pictureLabel->setText("<h2><i><font color=red>invalid Code</font></i></h2>");
		return;
	}
	QPixmap pixmap(cpMap[text]);
	QPixmap fitpixmap=pixmap.scaled(100,100, Qt::KeepAspectRatio);  
	if(fitpixmap.isNull())
		pictureLabel->setText("<h2><i><font color=red>invalid Code</font></i></h2>");
	else
		pictureLabel->setPixmap(fitpixmap);
}

void SetNodeInfo::selectTransCode()
{
	SelectCodeDialog * dialog = new SelectCodeDialog();
	if(dialog->exec() == QDialog::Accepted)
	{
		transCodeLineEdit->setText(dialog->getTransCode());
	}
}
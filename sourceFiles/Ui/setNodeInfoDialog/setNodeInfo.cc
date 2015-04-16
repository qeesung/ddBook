#include "setNodeInfo.h"
#include "selectCodeDialog.h"
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include <QFileDialog>

extern QString cpFileName;//这个是预先编辑好的code : picture对应的对文件名字

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
	updateCpMap();

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
	}

	//将表设置为多选选项
	givenAudioTableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	//ok按钮为默认的按钮
	okPushButton->setDefault(true);

	connect(startAudioPushButton , SIGNAL(clicked()),\

		    this , SLOT(startAudioView()));
	connect(endAudioPushButton , SIGNAL(clicked()),\
		    this , SLOT(endAudioView()));

	connect(givenAudioAddPushButton, SIGNAL(clicked()),\
		    this , SLOT(addGivenTableAudio()));
	connect(givenAudioDeletePushButton , SIGNAL(clicked()),\
			this , SLOT(deleteGivenTableAudio()));

	// connect(transCodeLineEdit , SIGNAL(textChanged(const QString &)),\
	// 		this , SLOT(updateNodePic(const QString &)));

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
	updateCpMap();//更新cpMap
	if(dialog->exec() == QDialog::Accepted)
	{
		transCodeLineEdit->setText(dialog->getTransCode());
		QPixmap pixmap(dialog->getPicture());
		QPixmap fitpixmap=pixmap.scaled(100,100, Qt::KeepAspectRatio);  
		if(fitpixmap.isNull())
			pictureLabel->setText("<h2><i><font color=red>invalid Code</font></i></h2>");
		else
			pictureLabel->setPixmap(fitpixmap);
	}
}

void SetNodeInfo::updateCpMap()
{
	// cpMap.clear();
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
}
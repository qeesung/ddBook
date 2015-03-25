#include "setNodeInfo.h"
#include <QDebug>
#include <QFileDialog>

SetNodeInfo::SetNodeInfo(const Node * node,QWidget * parent):QDialog(parent)
{
	setupUi(this);
	/** 使得表可以自由伸展 */
	startAudioTableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	endAudioTableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	givenAudioTableWidget->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
	// startAudioTableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
	// endAudioTableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);
	// givenAudioTableWidget->verticalHeader()->setResizeMode(QHeaderView::Stretch);

	/** 在启动dialog时候自动载入节点信息 */
	nodeNameLineEdit->setText(node->getText());
	nodeNameLineEdit->selectAll();//选中全部的Node名字

	transCodeLineEdit->setText(node->getTransCode());

	pictureLineEdit->setText(node->getPicture());

	startAudioLineEdit->setText(node->getStartAudio());
	endAudioLineEdit->setText(node->getEndAudio());
	
	QStringList filenames = node->getDefaultAudioList();
	foreach(QString filename , filenames)
	{
		QListWidgetItem * tempItem = new QListWidgetItem(filename);
		defaultAudiotListWidget->addItem(tempItem);
	}

	/** 得到start table的值 */
	QMap<QString , QString> startAudioTableMap = node->getAllStartTableAudio();
	unsigned int i = 0;
	for(QMap<QString , QString>::const_iterator iter = startAudioTableMap.constBegin() ;\
											   iter != startAudioTableMap.constEnd() ; ++iter , ++i)
	{
		QTableWidgetItem * item1 = new QTableWidgetItem(iter.key());
		QTableWidgetItem * item2 = new QTableWidgetItem(iter.value());
		startAudioTableWidget->insertRow(i);
		startAudioTableWidget->setItem(i,0 ,item1);
		startAudioTableWidget->setItem(i,1 ,item2);
	}
	/** 得到end table的值 */
	QMap<QString , QString> endAudioTableMap = node->getAllEndTableAudio();
	i=0;
	for(QMap<QString , QString>::const_iterator iter = endAudioTableMap.constBegin() ;\
											   iter != endAudioTableMap.constEnd() ; ++iter , ++i)
	{
		QTableWidgetItem * item1 = new QTableWidgetItem(iter.key());
		QTableWidgetItem * item2 = new QTableWidgetItem(iter.value());
		endAudioTableWidget->insertRow(i);
		endAudioTableWidget->setItem(i,0 ,item1);
		endAudioTableWidget->setItem(i,1 ,item2);
	}
	/** 得到given table的值 */
	i=0;
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
	defaultAudiotListWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	startAudioTableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	endAudioTableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	givenAudioTableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	//ok按钮为默认的按钮
	okPushButton->setDefault(true);

	connect(startAudioPushButton , SIGNAL(clicked()),\

		    this , SLOT(startAudioView()));
	connect(endAudioPushButton , SIGNAL(clicked()),\
		    this , SLOT(endAudioView()));

	connect(picturePushButton , SIGNAL(clicked()),\
		    this , SLOT(pictureView()));

	connect(defaultAudioAddPushButton, SIGNAL(clicked()),\
		    this , SLOT(addDefaultAudio()));
	connect(defaultAudioDeletePushButton , SIGNAL(clicked()),\
			this , SLOT(deleteDefaultAudio()));

	connect(startAudioAddPushButton, SIGNAL(clicked()),\
		    this , SLOT(addStartTableAudio()));
	connect(startAudioDeletePushButton , SIGNAL(clicked()),\
			this , SLOT(deleteStartTableAudio()));

	connect(endAudioAddPushButton, SIGNAL(clicked()),\
		    this , SLOT(addEndTableAudio()));
	connect(endAudioDeletePushButton , SIGNAL(clicked()),\
			this , SLOT(deleteEndTableAudio()));

	connect(givenAudioAddPushButton, SIGNAL(clicked()),\
		    this , SLOT(addGivenTableAudio()));
	connect(givenAudioDeletePushButton , SIGNAL(clicked()),\
			this , SLOT(deleteGivenTableAudio()));

	connect(okPushButton , SIGNAL(clicked()),\
		    this , SLOT(accept()));
	connect(cancelPushButton , SIGNAL(clicked()),\
		    this , SLOT(reject()));
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


void SetNodeInfo::pictureView()
{
	QFileDialog * fileDialog = new QFileDialog;
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	fileDialog->setNameFilter(QString("picture file(*.jpg *.png)"));
	fileDialog->setViewMode(QFileDialog::List);
	fileDialog->setDirectory("../../res/");
	fileDialog->setWindowTitle("Choose a node picture");
	if(fileDialog->exec()==QDialog::Accepted)
	{
		QString filename = fileDialog->selectedFiles()[0];
		pictureLineEdit->setText(filename);
	}
}

void SetNodeInfo::addStartTableAudio()
{
	GetTablePairDialog * dialog = new GetTablePairDialog;
	dialog->setWindowTitle("FromCode --- AudioFile");
	if(dialog->exec() == QDialog::Accepted)
	{
		QTableWidgetItem * item1 = new QTableWidgetItem(dialog->getCode());
		QTableWidgetItem * item2 = new QTableWidgetItem(dialog->getFile());
		unsigned int rowCount = startAudioTableWidget->rowCount();
		startAudioTableWidget->insertRow(rowCount);
		startAudioTableWidget->setItem(rowCount , 0 , item1);
		startAudioTableWidget->setItem(rowCount , 1 , item2);
	}
}

void SetNodeInfo::deleteStartTableAudio()
{
	QList<QTableWidgetItem *> selectedItems = startAudioTableWidget->selectedItems();
	foreach(QTableWidgetItem * item , selectedItems)
	{
		startAudioTableWidget->removeRow(startAudioTableWidget->row(item));
	}
}

void SetNodeInfo::addEndTableAudio()
{
	GetTablePairDialog * dialog = new GetTablePairDialog;
	dialog->setWindowTitle("ToCode --- AudioFile");
	if(dialog->exec() == QDialog::Accepted)
	{
		QTableWidgetItem * item1 = new QTableWidgetItem(dialog->getCode());
		QTableWidgetItem * item2 = new QTableWidgetItem(dialog->getFile());
		unsigned int rowCount = endAudioTableWidget->rowCount();
		endAudioTableWidget->insertRow(rowCount);
		endAudioTableWidget->setItem(rowCount , 0 , item1);
		endAudioTableWidget->setItem(rowCount , 1 , item2);
	}
}
void SetNodeInfo::deleteEndTableAudio()
{
	QList<QTableWidgetItem *> selectedItems = endAudioTableWidget->selectedItems();
	foreach(QTableWidgetItem * item , selectedItems)
	{
		endAudioTableWidget->removeRow(endAudioTableWidget->row(item));
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

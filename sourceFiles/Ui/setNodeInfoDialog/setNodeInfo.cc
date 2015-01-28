#include "setNodeInfo.h"
#include <QFileDialog>

SetNodeInfo::SetNodeInfo(const QString & nodeName,QWidget * parent):QDialog(parent)
{
	setupUi(this);

	nodeNameLineEdit->setText(nodeName);
	nodeNameLineEdit->selectAll();//选中全部的Node名字
	defaultAudioListWidget->setSelectionMode(QAbstractItemView::MultiSelection);
	connect(startAudioPushButton , SIGNAL(clicked()),\
		    this , SLOT(startAudioView()));
	connect(endAudioPushButton , SIGNAL(clicked()),\
		    this , SLOT(endAudioView()));

	connect(addPushButton, SIGNAL(clicked()),\
		    this , SLOT(addDefaultAudio()));
	connect(deletePushButton , SIGNAL(clicked()),\
			this , SLOT(deleteDefaultAudio()));

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
			defaultAudioListWidget->addItem(newItem);
		}
	}
}

void SetNodeInfo::deleteDefaultAudio()
{
	QList<QListWidgetItem * > selectedItems = defaultAudioListWidget->selectedItems();
	foreach(QListWidgetItem * item , selectedItems)
	{
		defaultAudioListWidget->removeItemWidget(item);
		delete item;
	}
}

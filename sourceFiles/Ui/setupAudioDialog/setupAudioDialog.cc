#include "setupAudioDialog.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
extern QString alFileName;

SetupAudioDialog::SetupAudioDialog(QWidget * parent):QDialog(parent)
{
	setupUi(this);
	/** set the dialog basic info */
	delPushButton->setEnabled(false);
	alFilenameLabel->setText(alFileName);
	/** 多选模式 */
	audioListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

	connect(addPushButton , SIGNAL(clicked()) ,\
		this , SLOT(addAudios()));
	connect(delPushButton , SIGNAL(clicked()),\
		this , SLOT(delAduios()));
	connect(savePushButton ,SIGNAL(clicked()) , \
		this , SLOT(saveAlFile()));
	connect(audioListWidget , SIGNAL(itemClicked(QListWidgetItem *)) ,\
		this , SLOT(enableDelPushButton()));
	/** 把数据文件的内容读出来 */
	loadAlFile();
}


/**  增加audio的槽 */
void SetupAudioDialog::addAudios()
{
	QFileDialog * fileDialog = new QFileDialog;
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	fileDialog->setNameFilter(QString("audio file(*.mp3 *.wmv)"));
	fileDialog->setViewMode(QFileDialog::List);
	fileDialog->setDirectory("../../res/");
	fileDialog->setWindowTitle("Choose audio files");
	fileDialog->setFileMode(QFileDialog::ExistingFiles);//文件的多选
	if(fileDialog->exec()==QDialog::Accepted)
	{
		QStringList fileList = fileDialog->selectedFiles();
		foreach(QString file , fileList)
		{
			size_t row = audioListWidget->count();
			QListWidgetItem * item = NULL;
			if(!audioIsExist(file , item))
				audioListWidget->insertItem(row , file);
			else
				item->setSelected(true);

		}
	}
}

/** 删除audio选项 */
void SetupAudioDialog::delAduios()
{	
	QList<QListWidgetItem *> selectedItems = audioListWidget->selectedItems();
	foreach(QListWidgetItem * item , selectedItems)
	{
		delete item;// 删除选中项
	}
}

/** 保存到列表的槽 */
void SetupAudioDialog::saveAlFile()
{
	/** 移除al文件 */
	QFile::remove(alFileName);
	/** 现在将数据保存到alFileName里面 */
	QFile file(alFileName);  
	//方式：Append为追加，WriteOnly，ReadOnly  
	if (!file.open(QIODevice::WriteOnly|QIODevice::Text)) {    
	    QMessageBox::critical(NULL, "warning", "can not save file");  
	    return;    
	}    
	QTextStream out(&file); 
	/** 将所有的item取出 ，存入到文件里面*/
	size_t count = audioListWidget->count();
	for (size_t i = 0; i < count; ++i)
	{
		QListWidgetItem * item = audioListWidget->item(i);
		out<<QString("%1\n").arg(item->text());
	}
	file.close();
}


/** 使能删除按钮的槽 */
void SetupAudioDialog::enableDelPushButton()
{
	if(audioListWidget->selectedItems().count() == 0)
		delPushButton->setEnabled(false);
	else
		delPushButton->setEnabled(true);
}


void SetupAudioDialog::loadAlFile()
{
		/** 把alFile里面的东西读出来,保存下载 */
	QFile alFile(alFileName);
	if(!alFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox * mBox = new QMessageBox;
		mBox->setText(QString("Open file %1 failed\n file is destoried or is not existed\n").arg(alFileName));
	}
	QTextStream alInput(&alFile);
	QString lineStr;
	while(!alInput.atEnd())
	{
		lineStr = alInput.readLine();//读取到文件的一行数据
		/** 一行数据的格式　code-Y(^_^)Y-picture */
		QListWidgetItem * item = new QListWidgetItem(lineStr, audioListWidget);
		// QFont font;
		// font.setBold(true);
		// font.setPointSize(15);
		// item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		// item->setFont(font);
	}
}

bool SetupAudioDialog::audioIsExist(const QString & audioFileName, QListWidgetItem * &item)
{
	QList<QListWidgetItem *> foundItems =  audioListWidget->findItems(audioFileName , Qt::MatchFixedString);
	if(foundItems.count() == 0)
		return false;
	else
	{
		item = foundItems[0];
		return true;
	}
}

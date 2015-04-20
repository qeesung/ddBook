#include "setupDefaultAudioDialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

extern QString cpFileName;
extern QString cdFileName;

SetupDefaultAudioDialog::SetupDefaultAudioDialog(QWidget * parent):QDialog(parent)
{
	setupUi(this);

	/** 只可以单选 */
	treeWidget->setSelectionMode(QAbstractItemView::SingleSelection);
	treeWidget->setColumnCount(1);
	/** 将add按钮 ， delete按钮设为unable */
	addPushButton->setEnabled(false);
	delPushButton->setEnabled(true);

	savePushButton->setDefault(true);

	// 下面开始读入cpfile里面的内容来构建code对应的item
	cpMapData = MainWindow::getCpData();
	cdMapData = MainWindow::getCdData();

	// 现在开始在treeWidget里面进行构建
	QTreeWidgetItem * root = treeWidget->invisibleRootItem();
	for(QMap<QString , QString >::iterator iter = cpMapData.begin() ; iter!=cpMapData.end();\
					++iter) 
	{
		QTreeWidgetItem * item = new QTreeWidgetItem(root);
		item->setText(0 , iter.key());
		item->setIcon(0 , QIcon(iter.value()));
		/** 基于item基础上构建默认音频 */
		if(cdMapData.count(iter.key()) == 0)
			continue;
		QStringList defaultAudioList = cdMapData[iter.key()];
		foreach(QString str , defaultAudioList)
		{
			QTreeWidgetItem * childItem = new QTreeWidgetItem(item);
			childItem->setText(0 , str);
		}
	}

	defaultBrush = QBrush(QColor("#C0FF3E"));
	defaultChildBrush = QBrush(QColor("#C1FFC1"));
	setAllDefaultColor();
	setAllChildDefaultColor();
	treeWidget->expandAll();

	/** 下面开始链接信号和槽 */
	connect(addPushButton , SIGNAL(clicked()),\
		this , SLOT(addDefaultAudio()));
	connect(delPushButton , SIGNAL(clicked()),\
		this , SLOT(deleteDefaultAudio()));
	connect(savePushButton , SIGNAL(clicked()) ,\
		this , SLOT(saveDefaultAudio()));
	connect(searchLineEdit , SIGNAL(textChanged(const QString &)),\
		this , SLOT(searchCode(const QString &)));
	connect(treeWidget , SIGNAL(itemClicked(QTreeWidgetItem *  , int)) , \
		this , SLOT(updateButton(QTreeWidgetItem * , int)));
}

void SetupDefaultAudioDialog::addDefaultAudio()
{
	QList<QTreeWidgetItem *> selectedItem = treeWidget->selectedItems();
	if(selectedItem.count() == 0)
		return;
	QTreeWidgetItem * item = selectedItem[0];
	// 只有在code下面add才是enabled
	QFileDialog * fileDialog = new QFileDialog;
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	fileDialog->setNameFilter(QString("mp3 file(*.mp3)"));
	fileDialog->setViewMode(QFileDialog::List);
	fileDialog->setDirectory("../../res");
	fileDialog->setWindowTitle("Choose a default audio file");
	if(fileDialog->exec()==QDialog::Accepted)
	{
		QString filename = fileDialog->selectedFiles()[0];
		QTreeWidgetItem * childItem = new QTreeWidgetItem(item , 0);
		childItem->setText(0,filename);
		childItem->setBackground(0,defaultChildBrush);
	}
}	

void SetupDefaultAudioDialog::deleteDefaultAudio()
{
	QList<QTreeWidgetItem *> selectedItem = treeWidget->selectedItems();
	if(selectedItem.count() == 0)
		return;
	QTreeWidgetItem * item = selectedItem[0];
	// 那么就将全部孩子删掉
	if(item->parent() == NULL)
	{
		item->takeChildren();
	}
	else// 只删除当前选中的item
	{
		QTreeWidgetItem * parent = item->parent();
		parent->removeChild(item);
	}
}

/**
 * 保存数据到cdFile里面去
 */
void SetupDefaultAudioDialog::saveDefaultAudio()
{
	// open the file first
	QFile::remove(cdFileName);
	/** 现在将数据保存到cdFileName里面 */
	QFile file(cdFileName);  
	//方式：Append为追加，WriteOnly，ReadOnly  
	if (!file.open(QIODevice::WriteOnly|QIODevice::Text)) {     
	    QMessageBox::critical(NULL, "warning", "can not save file");  
	    return;    
	}    
	QTextStream out(&file); 
	int topLevelItemsCount = treeWidget->topLevelItemCount();
	for (int i = 0; i < topLevelItemsCount; ++i)
	{
		QTreeWidgetItem * item = treeWidget->topLevelItem(i);
		out<<QString("%1%2").arg(item->text(0)).arg("\n");
		// get item all children
		int childCount = item->childCount();
		for(int k = 0 ; k < childCount ; ++k)
		{	
			QTreeWidgetItem * childItem = item->child(k);
			out<<QString("%1%2").arg(childItem->text(0)).arg("\n");
		}
		out<<"-Y(^_^)Y-\n";
	}
	file.close();
	MainWindow::loadCdData();
}

void SetupDefaultAudioDialog::searchCode(const QString & code)
{
	// find code throught code
	setAllDefaultColor();
	if(code.isEmpty())
		return;
	QList<QTreeWidgetItem *> foundItems = \
				treeWidget->findItems(QString("[A-Za-z0-9]{0,}%1[A-Za-z0-9]{0,}").arg(code),Qt::MatchRegExp);
	foreach(QTreeWidgetItem * item , foundItems)
	{
		QBrush brush(QColor("#B23AEE"));
		item->setBackground(0 , brush);
	}
	if(foundItems.count() != 0 )
		treeWidget->setCurrentItem(foundItems[0]);
}

void SetupDefaultAudioDialog::updateButton(QTreeWidgetItem * item, int)
{
	if(item == NULL)
		return;
	if(item->parent() == NULL)
		addPushButton->setEnabled(true);
	else
		addPushButton->setEnabled(false);
}


void SetupDefaultAudioDialog::setAllDefaultColor()
{
	int topLevelItemsCount = treeWidget->topLevelItemCount();
	for (int i = 0; i < topLevelItemsCount; ++i)
	{
		QTreeWidgetItem * item = treeWidget->topLevelItem(i);
		item->setBackground(0 , defaultBrush);
	}
}

void SetupDefaultAudioDialog::setAllChildDefaultColor()
{
	int topLevelItemsCount = treeWidget->topLevelItemCount();
	for (int i = 0; i < topLevelItemsCount; ++i)
	{
		QTreeWidgetItem * item = treeWidget->topLevelItem(i);
		int childCount = item->childCount();
		for(int k = 0 ; k < childCount ; ++k)
		{	
			QTreeWidgetItem * childItem = item->child(k);
			childItem->setBackground(0,defaultChildBrush);
		}
	}
}
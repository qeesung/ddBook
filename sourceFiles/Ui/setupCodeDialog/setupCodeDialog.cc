#include "setupCodeDialog.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include "createCodeDialog.h"
#include "mainWindow.h"

extern QString cpFileName;//这个是预先编辑好的code : picture对应的对文件名字

SetupCodeDialog::SetupCodeDialog(QWidget * parent):QDialog(parent)
{	
	setupUi(this);
	delPushButton->setEnabled(false);
	// savePushButton->setEnabled(false);

	connect(newPushButton , SIGNAL(clicked()),\
		this , SLOT(addNewCode()));
	connect(delPushButton , SIGNAL(clicked()),\
		this , SLOT(removeCode()));
	connect(savePushButton , SIGNAL(clicked()),\
		this , SLOT(saveCodes()));
		/** 双击设置码值信息 */
	connect(codeListWidget , SIGNAL(doubleClicked(const QModelIndex & )),\
		this , SLOT(setCodeInfo(const QModelIndex & )));
		/** 保存按钮的使能 */
	connect(codeListWidget , SIGNAL(itemSelectionChanged()) ,\
		this , SLOT(updateSaveButton()));
	loadCodes();
}

void SetupCodeDialog::addNewCode()
{
	CreateCodeDialog * dialog = new CreateCodeDialog();
	if(dialog->exec() == QDialog::Accepted)
	{
		QListWidgetItem * item = new QListWidgetItem(dialog->getTransCode() , codeListWidget);
		item->setData(Qt::UserRole , dialog->getPicturePath());
		item->setIcon(QIcon(dialog->getPicturePath()));
		QFont font;
		font.setBold(true);
		font.setPointSize(15);
		item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		item->setFont(font);
	}
}

void SetupCodeDialog::removeCode()
{
	int row = codeListWidget->currentRow();
	codeListWidget->takeItem(row);
}

void SetupCodeDialog::saveCodes()
{
	QFile::remove(cpFileName);
	/** 现在将数据保存到cpFileName里面 */
	QFile file(cpFileName);  
	//方式：Append为追加，WriteOnly，ReadOnly  
	if (!file.open(QIODevice::WriteOnly|QIODevice::Text)) {    
	    QMessageBox::critical(NULL, "warning", "can not save file");  
	    return;    
	}    
	QTextStream out(&file); 
	/** 将所有的item取出 ，存入到文件里面*/
	int i =0;
	while(codeListWidget->count() > i)
	{
		QListWidgetItem * item = codeListWidget->item(i++);
		QString lineData = QString("%1-Y(^_^)Y-%2\n").arg(item->text()).arg(item->data(Qt::UserRole).toString());
		out<<lineData;
	}
	file.close();
	// 在主窗口里面重新加载这个全局数据
	MainWindow::loadCpData();
	MainWindow::updateAllNodesInfo();
	MainWindow::updateDockWidget();
	setWindowModified(false);
}

void SetupCodeDialog::setCodeInfo(const QModelIndex & index)
{
	QListWidgetItem * item = codeListWidget->item(index.row());
	CreateCodeDialog * dialog = new CreateCodeDialog(item,this);
	if(dialog->exec() == QDialog::Accepted)
	{
		item->setText(dialog->getTransCode());
		item->setIcon(QIcon(dialog->getPicturePath()));
		item->setData(Qt::UserRole , dialog->getPicturePath());
	}
}


void SetupCodeDialog::updateSaveButton()
{
	/*if(isWindowModified())
	{
		savePushButton->setEnabled(true);
	}
	else
		savePushButton->setEnabled(false);*/
	if(codeListWidget->selectedItems().count() == 0)
		delPushButton->setEnabled(false);
	else
		delPushButton->setEnabled(true);
}

void SetupCodeDialog::loadCodes()
{
	/** 把cpFile里面的东西读出来,保存下载 */
	QMap<QString , QString> cpMapData = MainWindow::getCpData();
	for(QMap<QString , QString>::iterator iter = cpMapData.begin(); iter!= cpMapData.end() ; ++iter)
	{
		QListWidgetItem * item = new QListWidgetItem(iter.key(), codeListWidget);
		item->setIcon(QIcon(iter.value()));
		item->setData(Qt::UserRole , iter.value());
		QFont font;
		font.setBold(true);
		font.setPointSize(15);
		item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		item->setFont(font);
	}
}

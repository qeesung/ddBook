#include "selectCodeDialog.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include "createCodeDialog.h"

extern QString cpFileName;//这个是预先编辑好的code : picture对应的对文件名字

SelectCodeDialog::SelectCodeDialog(QWidget * parent):QDialog(parent)
{
	setupUi(this);

	okPushButton->setEnabled(false);
	delPushButton->setEnabled(false);
	codeListWidget->setIconSize(QSize(80,80));
	searchLineEdit->setFocus();
	connect(newPushButton , SIGNAL(clicked()),\
		this , SLOT(createCode()));

	connect(delPushButton , SIGNAL(clicked()),\
		this , SLOT(removeCode()));

	/** 使能ok del 按钮 */
	connect(codeListWidget , SIGNAL(itemClicked(QListWidgetItem * )),\
		this , SLOT(enableButtons()));

	/** 双击设置码值信息 */
	connect(codeListWidget , SIGNAL(doubleClicked(const QModelIndex & )),\
		this , SLOT(setCodeInfo(const QModelIndex & )));

	/** 搜索码值 */
	connect(searchLineEdit , SIGNAL(textChanged(const QString &)),\
		this , SLOT(searchCode(const QString &)));

	/**　读取cp文件的内容，插入倒listWidget里面 */
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
		QListWidgetItem * item = new QListWidgetItem(cpTemp[0], codeListWidget);
		item->setIcon(QIcon(cpTemp[1]));
		item->setData(Qt::UserRole , cpTemp[1]);
	}
}

/** 创建一个新的 */
void SelectCodeDialog::createCode()
{
	CreateCodeDialog * dialog = new CreateCodeDialog();
	if(dialog->exec() == QDialog::Accepted)
	{
		QListWidgetItem * item = new QListWidgetItem(dialog->getTransCode() , codeListWidget);
		item->setIcon(QIcon(dialog->getPicturePath()));
	}
}

/** 移除一个code */
void SelectCodeDialog::removeCode()
{
	int row = codeListWidget->currentRow();
	codeListWidget->takeItem(row);
}

void SelectCodeDialog::enableButtons()
{
	if(codeListWidget->selectedItems().count() == 0)
	{
		delPushButton->setEnabled(false);
		okPushButton->setEnabled(false);
		return;
	}

	delPushButton->setEnabled(true);
	if(codeListWidget->selectedItems().count() == 1)
	{
		okPushButton->setEnabled(true);
		return;
	}
	if(codeListWidget->selectedItems().count() >1)
		okPushButton->setEnabled(false);		
}

void SelectCodeDialog::setCodeInfo(const QModelIndex & index)
{
	QListWidgetItem * item = codeListWidget->item(index.row());
	CreateCodeDialog * dialog = new CreateCodeDialog(item,this);
	if(dialog->exec() == QDialog::Accepted)
	{
		item->setText(dialog->getTransCode());
		item->setIcon(QIcon(dialog->getPicturePath()));
	}
}

/** 在codelistWidget里面搜索对应符合码值的选项 */
void SelectCodeDialog::searchCode(const QString & codeStr)
{
	QList<QListWidgetItem *> matchItems = codeListWidget->findItems(QString("%1%2%3").\
		arg("[A-Za-z0-9]{0,}").arg(codeStr).arg("[A-Za-z0-9]{0,}") , Qt::MatchRegExp);
	if(matchItems.count() !=0)
		codeListWidget->setCurrentItem(matchItems[0]);
}

/** 设置按钮事件 */
void SelectCodeDialog::keyPressEvent(QKeyEvent * event)
{
	if(event->key() == Qt::Key_F)
	{
		QListWidgetItem *item = codeListWidget->currentItem();
		QString tempStr = searchLineEdit->text();
		searchLineEdit->setText(item->text());
		searchLineEdit->setText(tempStr);
	}
	else
		QDialog::keyPressEvent(event);
}

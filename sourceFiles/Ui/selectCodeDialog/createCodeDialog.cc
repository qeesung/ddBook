#include "createCodeDialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

CreateCodeDialog::CreateCodeDialog(QWidget * parent):QDialog(parent)
{
	setupUi(this);
	okPushButton->setEnabled(false);
	/** 两颗按钮的动作 */
	connect(recordPushButton , SIGNAL(clicked()),\
		this , SLOT(recordCode()));
	connect(pictureViewButton , SIGNAL(clicked()),\
		this , SLOT(viewPicture()));
	/** 显示图片 */
	connect(pictureLineEdit , SIGNAL(textChanged(const QString &)),\
		this , SLOT(showPicture(const QString &)));
	/** 检测输入是否合理 */
	connect(pictureLineEdit , SIGNAL(textChanged(const QString &)),\
		this , SLOT(isValidInput()));
	connect(codeLineEdit , SIGNAL(textChanged(const QString &)),\
		this , SLOT(isValidInput()));
}

CreateCodeDialog::CreateCodeDialog(QListWidgetItem * item , QWidget * parent):QDialog(parent)
{
	setupUi(this);
	okPushButton->setEnabled(false);
	/** 两颗按钮的动作 */
	connect(recordPushButton , SIGNAL(clicked()),\
		this , SLOT(recordCode()));
	connect(pictureViewButton , SIGNAL(clicked()),\
		this , SLOT(viewPicture()));
	/** 显示图片 */
	connect(pictureLineEdit , SIGNAL(textChanged(const QString &)),\
		this , SLOT(showPicture(const QString &)));
	/** 检测输入是否合理 */
	connect(pictureLineEdit , SIGNAL(textChanged(const QString &)),\
		this , SLOT(isValidInput()));
	connect(codeLineEdit , SIGNAL(textChanged(const QString &)),\
		this , SLOT(isValidInput()));

	codeLineEdit->setText(item->text());
	QString picPath = item->data(Qt::UserRole).toString();
	pictureLineEdit->setText(picPath);
	QPixmap pixmap = item->icon().pixmap(QSize(50,50));
	QPixmap fitpixmap=pixmap.scaled(50,50, Qt::KeepAspectRatio);  
	if(fitpixmap.isNull())
		pictureLabel->setText(QString("<h2><i><font color=red>invalid Code</font></i></h2>"));
	else
		pictureLabel->setPixmap(fitpixmap);
}

/** 从串口开始录入码值 */
void CreateCodeDialog::recordCode()
{
	QMessageBox * mBox = new QMessageBox;
	mBox->setText("Please connect serial port first");
	mBox->exec();
}

/** 选择一个图片 */
void CreateCodeDialog::viewPicture()
{
	QFileDialog * fileDialog = new QFileDialog;
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	fileDialog->setNameFilter(QString("picture(*.png *.jpg)"));
	fileDialog->setViewMode(QFileDialog::List);
	fileDialog->setDirectory("../../res/");
	fileDialog->setWindowTitle("Choose a code picture");
	if(fileDialog->exec()==QDialog::Accepted)
	{
		QString filename = fileDialog->selectedFiles()[0];
		pictureLineEdit->setText(filename);
	}
}

/** 检测是否两个lineedit都有数据 */
void CreateCodeDialog::isValidInput()
{
	if(codeLineEdit->text().isEmpty() || pictureLineEdit->text().isEmpty())
		okPushButton->setEnabled(false);
	okPushButton->setEnabled(true);
}

void CreateCodeDialog::showPicture(const QString & pictureName)
{
	QPixmap pixmap(pictureName);
	QPixmap fitpixmap=pixmap.scaled(50,50, Qt::KeepAspectRatio);  
	if(fitpixmap.isNull())
		pictureLabel->setText(QString("<h2><i><font color=red>invalid Code</font></i></h2>"));
	else
		pictureLabel->setPixmap(fitpixmap);
}

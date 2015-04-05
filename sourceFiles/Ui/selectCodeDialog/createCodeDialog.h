#ifndef CREATECODEDIALOG_H
#define CREATECODEDIALOG_H

#include "ui_createCodeDialog.h"
#include <QDialog>
#include <QListWidgetItem>

class CreateCodeDialog : public QDialog , public Ui::CreateCodeDialog
{
	Q_OBJECT	
public:
	CreateCodeDialog(QWidget * parent=NULL);
	CreateCodeDialog(QListWidgetItem * item , QWidget * parent =NULL);
	/** 得到输入的内容 */
	QString getTransCode() const{
		return codeLineEdit->text();
	}

	QString getPicturePath() const{
		return pictureLineEdit->text();
	}

private slots:
	void recordCode();
	void viewPicture();
	void isValidInput();
	void showPicture(const QString &);
};


#endif
#ifndef CHOOSECPALDIALOG_H
#define CHOOSECPALDIALOG_H

#include <QDialog>
#include "ui_chooseCpAlDialog.h"

class ChooseCpAlDialog : public QDialog , public Ui::ChooseCpAlDialog
{
	Q_OBJECT
public:
	ChooseCpAlDialog(QWidget * parent = NULL);
private slots:
	void enableOkPushButton();
	void chooseCpFile();
	void chooseAlFile();
	void setFilename();
};


#endif
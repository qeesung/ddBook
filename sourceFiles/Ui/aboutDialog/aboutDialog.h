#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include "ui_aboutDialog.h"
#include <QDialog>

class AboutDialog : public QDialog , public Ui::AboutDialog
{
	Q_OBJECT
public:
	AboutDialog()
	{
		setupUi(this);
	}
};


#endif
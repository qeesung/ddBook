#ifndef GETTABLEPAIR_H
#define GETTABLEPAIR_H

#include <QDialog>
#include "getTablePairDialog.h"

class GetTablePairDialog : public QDialog , public Ui::getTablePairDialog
{
	Q_OBJECT
public:
	GetTablePairDialog(QWidget * parent=NULL);
	QString getCode(){return codeLineEdit->text();}
	QString getFile(){return fileLineEdit->text();}
private slots:
	void viewFile();
	void enableOkButton();
	void selectTransCode();
};	

#endif
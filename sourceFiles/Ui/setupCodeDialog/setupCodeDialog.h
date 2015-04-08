#ifndef SETUPCODEDIALOG_H
#define SETUPCODEDIALOG_H

#include "ui_setupCodeDialog.h"
#include <QDialog>

class SetupCodeDialog : public QDialog , public Ui::SetupCodeDialog
{
	Q_OBJECT
public:
	SetupCodeDialog(QWidget * parent=NULL);
private slots:
	void addNewCode();
	void removeCode();
	void saveCodes();
	void setCodeInfo(const QModelIndex & );
	void updateSaveButton();
private:
	void loadCodes();
};

#endif




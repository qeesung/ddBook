#ifndef ENTERTRANSCODEDIALOG_H
#define ENTERTRANSCODEDIALOG_H

#include <QDialog>
#include "link.h"
class QLabel;
class QLineEdit;
class QPushButton;

class EnterTransCodeDialog : public QDialog
{
	Q_OBJECT
public:
	EnterTransCodeDialog(Link * link , QWidget * parent=0);
	int getTransCode() const;
private slots:
	void contentChanged(const QString & str);
private:
	QLabel * label;
	QLineEdit * lineEdit;
	QPushButton * okButton;
	QPushButton * cancelButton;
};


#endif
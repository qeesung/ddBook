#include "entertranscodedialog.h"
#include <QRegExp>
#include <QRegExpValidator>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

EnterTransCodeDialog::EnterTransCodeDialog(Link * link , QWidget * parent):QDialog(parent)
{
	label = new QLabel("Enter the transCode:(only number)");
	lineEdit = new QLineEdit;
	lineEdit->setText(QString("%1").arg(link->getTransCode()));
	lineEdit->setSelection(0,text().count());
	okButton = new QPushButton("  Ok  ");
	okButton->setEnabled(false);
	cancelButton = new QPushButton("Cancel");

	QHBoxLayout * downLayout = new QHBoxLayout;
	downLayout->addStretch();
	downLayout->addWidget(okButton);
	downLayout->addWidget(cancelButton);

	QHBoxLayout * upLayout = new QHBoxLayout;
	upLayout->addWidget(label);
	upLayout->addWidget(lineEdit);

	QVBoxLayout * mainlayout = new QVBoxLayout;
	mainlayout->addLayout(upLayout);
	mainlayout->addLayout(downLayout);

	setLayout(mainlayout);

	//创建正则表达式来限制窗口的输入
	QRegExp regExp("[0-9]*");
	lineEdit->setValidator(new QRegExpValidator(regExp , this));

	connect(okButton, SIGNAL(clicked()) , this , SLOT(accept()));
	connect(cancelButton , SIGNAL(clicked()) , this , SLOT(reject()));
	connect(lineEdit , SIGNAL(textChanged(const QString &)) , this , SLOT(contentChanged(const QString &)));
}


void EnterTransCodeDialog::contentChanged(const QString & str)
{
	if(!str.isEmpty())
		okButton->setEnabled(true);
	else
		okButton->setEnabled(false);
}

int EnterTransCodeDialog::getTransCode() const
{
	if(lineEdit->text().isEmpty())
		return -1;
	else
		return lineEdit->text().toInt();
}
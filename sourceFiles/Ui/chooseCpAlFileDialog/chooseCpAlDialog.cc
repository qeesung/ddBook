#include "chooseCpAlDialog.h"
#include <QFile>
#include <QFileDialog>

QString cpFileName = "cpData.cp";
QString alFileName = "alData.al";
QString cdFileName = "cdData.cd";

ChooseCpAlDialog::ChooseCpAlDialog(QWidget * parent):QDialog(parent)
{	
	setupUi(this);

	cpFileLineEdit->setText(cpFileName);
	alFileLineEdit->setText(alFileName);
	cdFileLineEdit->setText(cdFileName);

	connect(cpFilePushButton , SIGNAL(clicked()),\
		this , SLOT(chooseCpFile()));
	connect(alFilePushButton , SIGNAL(clicked()),\
		this , SLOT(chooseAlFile()));
	connect(cdFilePushButton , SIGNAL(clicked()),\
		this , SLOT(chooseCdFile()));
	connect(cpFileLineEdit , SIGNAL(textChanged(const QString &)),\
		this , SLOT(enableOkPushButton()));
	connect(alFileLineEdit , SIGNAL(textChanged(const QString &)),\
		this , SLOT(enableOkPushButton()));
	connect(cdFileLineEdit , SIGNAL(textChanged(const QString &)),\
		this , SLOT(enableOkPushButton()));
	connect(okPushButton , SIGNAL(clicked()) , \
		this , SLOT(setFilename()));
}


void ChooseCpAlDialog::enableOkPushButton()
{
	if(cpFileLineEdit->text().isEmpty() ||\
	   alFileLineEdit->text().isEmpty() ||\
	   cdFileLineEdit->text().isEmpty())
		okPushButton->setEnabled(false);
	else
		okPushButton->setEnabled(true);
}

void ChooseCpAlDialog::chooseCpFile()
{
	QFileDialog * fileDialog = new QFileDialog;
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	fileDialog->setNameFilter(QString("cp file(*.cp)"));
	fileDialog->setViewMode(QFileDialog::List);
	fileDialog->setDirectory("./");
	fileDialog->setWindowTitle("Choose a cp file");
	if(fileDialog->exec()==QDialog::Accepted)
	{
		QString filename = fileDialog->selectedFiles()[0];
		cpFileLineEdit->setText(filename);
	}
}

void ChooseCpAlDialog::chooseAlFile()
{
	QFileDialog * fileDialog = new QFileDialog;
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	fileDialog->setNameFilter(QString("al file(*.al)"));
	fileDialog->setViewMode(QFileDialog::List);
	fileDialog->setDirectory("./");
	fileDialog->setWindowTitle("Choose a al file");
	if(fileDialog->exec()==QDialog::Accepted)
	{
		QString filename = fileDialog->selectedFiles()[0];
		alFileLineEdit->setText(filename);
	}
}


void ChooseCpAlDialog::chooseCdFile()
{
	QFileDialog * fileDialog = new QFileDialog;
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	fileDialog->setNameFilter(QString("cd file(*.cd)"));
	fileDialog->setViewMode(QFileDialog::List);
	fileDialog->setDirectory("./");
	fileDialog->setWindowTitle("Choose a cd file");
	if(fileDialog->exec()==QDialog::Accepted)
	{
		QString filename = fileDialog->selectedFiles()[0];
		cdFileLineEdit->setText(filename);
	}
}

void ChooseCpAlDialog::setFilename()
{
	cpFileName = cpFileLineEdit->text();
	alFileName = alFileLineEdit->text();
	cdFileName = cdFileLineEdit->text();	
}







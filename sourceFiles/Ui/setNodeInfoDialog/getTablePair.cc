#include "getTablePair.h"
#include <QFileDialog>

GetTablePairDialog::GetTablePairDialog(QWidget * parent):QDialog(parent)
{
	setupUi(this);
	okPushButton->setEnabled(false);
	connect(viewFilePushButton, SIGNAL(clicked()) , this , SLOT(viewFile()));
	connect(codeLineEdit , SIGNAL(textChanged(const QString & )) , this , SLOT(enableOkButton()));
	connect(fileLineEdit , SIGNAL(textChanged(const QString & )) , this , SLOT(enableOkButton()));
}

void GetTablePairDialog::viewFile()
{
	QFileDialog * fileDialog = new QFileDialog;
	fileDialog->setFileMode(QFileDialog::ExistingFile);
	fileDialog->setNameFilter(QString("source file(*.*)"));
	fileDialog->setViewMode(QFileDialog::List);
	fileDialog->setDirectory("../../res/");
	fileDialog->setWindowTitle("Choose a source file");
	if(fileDialog->exec()==QDialog::Accepted)
	{
		QString filename = fileDialog->selectedFiles()[0];
		fileLineEdit->setText(filename);
	}
}


void GetTablePairDialog::enableOkButton()
{
	bool codeIsEmpty = codeLineEdit->text().isEmpty();
	bool fileIsEmpty = fileLineEdit->text().isEmpty();
	if(codeIsEmpty && fileIsEmpty)
		return;
	okPushButton->setEnabled(true);
}
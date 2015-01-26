#include <QApplication>
#include "entertranscodedialog.h"


int main(int argc, char *argv[])
{
	QApplication app(argc , argv);

	EnterTransCodeDialog * dialog = new EnterTransCodeDialog;
	dialog->show();
	return app.exec();
}
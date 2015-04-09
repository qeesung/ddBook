#include <QApplication>
#include "mainWindow.h"
#include "chooseCpAlDialog.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	MainWindow * mainwindow = new MainWindow;
	mainwindow->show();
    /** 选择基础数据文件 */
    ChooseCpAlDialog * cpAlDialog = new ChooseCpAlDialog();
    cpAlDialog->exec();
	return app.exec();
}
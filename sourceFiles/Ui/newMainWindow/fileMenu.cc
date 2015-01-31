#include "mainWindow.h"

/**
 * 这个文件实现文件菜单的相应功能
 */


/**
 * 新建模式文件
 */
void MainWindow::newModeFile()
{
	/** 这里创建的ModeFile就是创建一个场景scene */
	QGraphicsScene * scene = new QGraphicsScene;
	GraphicsView * view = new QGraphicsView;
	view->setScene(scene);
	/** 用户的可选模式 圈选 */
	view->setDragMode(QGraphicsView::RubberBandDrag);
	view->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	/** 上下文的菜当选项 */
	view->setContextMenuPolicy(Qt::ActionsContextMenu);

	//添加view到mdiArea里面去
	addView(view);
}

/**
 * 打开一个模式文件
 */
void MainWindow::openModeFiles()
{
	GraphicsView * view = GraphicsView::open(this);
	if(view)
		addView(view);
}


/**
 * 添加view到主窗口中
 * @param view 欲添加的view
 */
void MainWindow::addView(GraphicsView * view)
{
	connect(view , SIGNAL(copyAvailable(bool)),\
			cutAction , SLOT(setEnabled(bool)));
	connect(view ,SIGNAL(copyAvailable(bool)),\
			copyAction , SLOT(setEnabled(bool)));
	QMdiSubWindow * subWindow = mdiArea->addSubWindow(view);
	windowsMenu->addAction(view->windowMenuAction());
	windowActionGroup->addAction(view->windowMenuAction());
	subWindow->show();
}


/**
 * 保存一个模式文件
 */
void MainWindow::saveFile()
{	
	if(activeView())
		activeView()->save();
}

void MainWindow::saveAsFile()
{
	if(activeView())
		activeView()->saveAs();
}
/**
 * 返回当前的活动窗口
 * @return 返回的窗口
 */
void MainWindow::activeView()
{
	QMdiSubWindow * subWindow = mdiArea->activeSubWindow();
	if(subWindow)
		return qobject_cast<GraphicsView *>(subWindow->widget());
	return 0;
}

void MainWindow::cut()
{
	if(activeView())
		activeView()->cut();
}





#include "mainWindow.h"
#include <QtGui>

/**
 * 这个文件只是建立主要UI的外观
 * 具体的各项菜单menu的实现分布在相应的"menu".cc里面
 */

 MainWindow::MainWindow()
 {
 	mdiArea = new QMdiArea;
 	setCentralWidget(mdiArea);

 	/** 马上得到当前的活动窗口，更新各actions */
 	connect(mdiArea , SIGNAL(subWindowActivated(QMdiSubWindow *)),\
 		  	this , SLOT(updateActions()));

 	createActions();
 	createMenus();
 	createToolBars();
 	createStatusBar();
 }

 void MainWindow::createActions()
 {
	 //////////////////
 	//file actions //
	 //////////////////
 	newFileAction = new QAction(tr("&New"), this);
    newFileAction->setIcon(QIcon(":/images/new.png"));
    newFileAction->setShortcut(QKeySequence::New);
    newFileAction->setStatusTip(tr("Create a mode file table"));
    connect(newFileAction , SIGNAL(triggered()), this , SLOT(newModeFile()));

    openFileAction = new QAction(tr("&Open") , this);
 	openFileAction->setIcon(QIcon(":images/open.png"));
 	openFileAction->setShortcut(QKeySequence::Open);
 	openFileAction->setStatusTip(tr("Open exsist mode file[s]"));
 	connect(openFileAction , SIGNAL(triggered()), this , SLOT(openModeFiles()));

 	saveFileAction = new QAction(tr("&Save"), this);
 	saveFileAction->setIcon(QIcon(":images/save.png"));
 	saveFileAction->setShortcut(QKeySequence::Save);
 	saveFileAction->setStatusTip(tr("Save the mode file"));
 	connect(saveFileAction , SIGNAL(triggered()), this , SLOT(saveFile()));

 	saveAsFileAction = new QAction(tr("Save &As"), this);
 	saveAsFileAction->setIcon(QIcon(":images/saveas.png"));
 	saveAsFileAction->setShortcut(QKeySequence::SaveAs);
 	saveAsFileAction->setStatusTip(tr("Save the mode file as ..."));
	connect(saveAsFileAction , SIGNAL(triggered()), this , SLOT(saveAsFile()));

	exitAction = new QAction(tr("E&xit"), this);
	exitAction->setIcon(QIcon(":images/exit.png"));
	exitAction->setShortcut(tr("Ctrl+Q"));
	exitAction->setStatusTip(tr("Exit..."));
	connect(exitAction , SIGNAL(triggered()), this , SLOT(close()));

	//////////////////
	//edit actions //
	//////////////////
	cutAction = new QAction(tr("Cu&t"), this);
	cutAction->setIcon(QIcon(":images/cut.png"));
	cutAction->setShortcut(QKeySequence::Cut);
	cutAction->setStatusTip(tr("Cut the selection"));
	connect(cutAction , SIGNAL(triggered()), this , SLOT(cut()));
	
	copyAction = new QAction(tr("&Copy"), this);
	copyAction->setIcon(QIcon(":images/copy.png"));
	copyAction->setShortcut(QKeySequence::Copy);
	copyAction->setStatusTip(tr("Copy the selection"));
	connect(copyAction , SIGNAL(triggered()), this , SLOT(copy()));
	
	pasteAction = new QAction(tr("&Paste"), this);
	pasteAction->setIcon(QIcon(":images/paste.png"));
	pasteAction->setShortcut(QKeySequence::Paste);
	pasteAction->setStatusTip(tr("Paste the selection"));
	connect(pasteAction , SIGNAL(triggered()), this , SLOT(paste()));

	deleteAction = new QAction(tr("&Delete"), this);
	deleteAction->setIcon(QIcon(":images/delete.png"));
	deleteAction->setShortcut(QKeySequence::Delete);
	deleteAction->setStatusTip(tr("Delete the selection"));
	connect(deleteAction , SIGNAL(triggered()), this , SLOT(deleteobjs()));

    bringToFrontAction = new QAction(tr("Bring to &Front"), this);
    bringToFrontAction->setIcon(QIcon(":/images/bringtofront.png"));
    connect(bringToFrontAction, SIGNAL(triggered()),
            this, SLOT(bringToFront()));

    sendToBackAction = new QAction(tr("&Send to Back"), this);
    sendToBackAction->setIcon(QIcon(":/images/sendtoback.png"));
    connect(sendToBackAction, SIGNAL(triggered()),
            this, SLOT(sendToBack()));

    ////////////////////////////
    // create project actions //
    ////////////////////////////
    createProjectAction = new QAction(tr("&New project"), this);
	createProjectAction->setIcon(QIcon(":images/newproject.png"));
	// createProjectAction->setShortcut(tr("Ctrl+N"));
	createProjectAction->setStatusTip(tr("Create a new project"));
	connect(createProjectAction , SIGNAL(triggered()), this , SLOT(createProject()));

    closeProjectAction = new QAction(tr("&Close project"), this);
	closeProjectAction->setIcon(QIcon(":images/closeproject.png"));
	// closeProjectAction->setShortcut(tr("Ctrl+C"));
	closeProjectAction->setStatusTip(tr("Close the project"));
	connect(closeProjectAction , SIGNAL(triggered()), this , SLOT(closeProject()));
	
    openProjectAction = new QAction(tr("&Open project"), this);
	openProjectAction->setIcon(QIcon(":images/openproject.png"));
	// openProjectAction->setShortcut(tr("Ctrl+O"));
	openProjectAction->setStatusTip(tr("open a exists project"));
	connect(openProjectAction , SIGNAL(triggered()), this , SLOT(openProject()));

	//////////////////////
	// windows actions //
	//////////////////////
	closeAction = new QAction(tr("Cl&ose"), this);
    closeAction->setIcon(QIcon(":images/close.png"));
    closeAction->setShortcut(tr("Ctrl+W"));
    closeAction->setStatusTip(tr("Close current window"));
    connect(closeAction , SIGNAL(triggered()), mdiArea , SLOT(closeActiveSubWindow()));

    closeAllAction = new QAction(tr("Close &All"), this);
    closeAllAction->setIcon(QIcon(":images/closeAll.png"));
    closeAllAction->setStatusTip(tr("Close all windows"));
    connect(closeAllAction , SIGNAL(triggered()), mdiArea , SLOT(closeAllSubWindows()));

    tileAction = new QAction(tr("&Tile"), this);
    tileAction->setIcon(QIcon(":images/Tile.png"));
    tileAction->setStatusTip(tr("Show sub window in Tile Mode"));
    connect(tileAction , SIGNAL(triggered()), mdiArea , SLOT(tileSubWindows()));

    cascadeAction = new QAction(tr("&Cascade"), this);
    cascadeAction->setIcon(QIcon(":images/cascade.png"));
    cascadeAction->setStatusTip(tr("Show sub window in Cascade Mode"));
    connect(cascadeAction , SIGNAL(triggered()), mdiArea , SLOT(cascadeSubWindows()));

    nextAction = new QAction(tr("Ne&xt"), this);
    nextAction->setIcon(QIcon(":images/next.png"));
    nextAction->setShortcut(tr("Ctrl+Tab"));
    nextAction->setStatusTip(tr("Focus on next Subwindow"));
    connect(nextAction , SIGNAL(triggered()), mdiArea , SLOT(activateNextSubWindow()));

    previousAction = new QAction(tr("Pre&vious"), this);
    previousAction->setIcon(QIcon(":images/previous.png"));
    previousAction->setShortcut(tr("Ctrl+Shift+Tab"));
    previousAction->setStatusTip(tr("Focus on last Subwindow"));
    connect(previousAction , SIGNAL(triggered()), mdiArea , SLOT(activatePreviousSubWindow()));

    /** 创建一个Action组 方便后面存储打开的文件的actions */
    windowActionGroup = new QActionGroup(this);

    //////////////////
    // node actions //
    //////////////////
    createNodeAction = new QAction(tr("&Create Node"), this);
    createNodeAction->setIcon(QIcon(":images/createnode.png"));
    // createNodeAction->setShortcut(tr("Ctrl+N"));
    createNodeAction->setStatusTip(tr("Create a new Node"));
    connect(createNodeAction , SIGNAL(triggered()), this , SLOT(createNode()));

    hAlignAction = new QAction(tr("Align &Horizontal"), this);
    hAlignAction->setIcon(QIcon(":images/horizontalalign.png"));
    // hAlignAction->setShortcut(tr("Ctrl+H"));
    hAlignAction->setStatusTip(tr("align the selected nodes horizontally"));
    connect(hAlignAction , SIGNAL(triggered()), this , SLOT(alignHorizontal()));

    vAlignAction = new QAction(tr("Align &Vertical"), this);
    vAlignAction->setIcon(QIcon(":images/verticalalign.png"));
    // vAlignAction->setShortcut(tr("Ctrl+V"));
    vAlignAction->setStatusTip(tr("align the selected nodes vertically"));
    connect(vAlignAction , SIGNAL(triggered()), this , SLOT(alignVertical()));

    addChildNodeAction = new QAction(tr("&Add Child Node"), this);
    addChildNodeAction->setIcon(QIcon(":images/addchildnode.png"));
    // addChildNodeAction->setShortcut(tr("Ctrl+"));
    addChildNodeAction->setStatusTip(tr("Add a child node base on selected node"));
    connect(addChildNodeAction , SIGNAL(triggered()), this , SLOT(addChildNode()));

    nodeSurfaccePropertiesAction = new QAction(tr("&Surfacce Properties"), this);
    nodeSurfaccePropertiesAction->setIcon(QIcon(":images/nodesurfaceproperties.png"));
    // nodeSurfaccePropertiesAction->setShortcut(tr("Ctrl+"));
    nodeSurfaccePropertiesAction->setStatusTip(tr("Set node surface"));
    connect(nodeSurfaccePropertiesAction , SIGNAL(triggered()), this , SLOT(nodeSurfacceProperties()));

    infoPropertiesAction = new QAction(tr("&Info Properties"), this);
    infoPropertiesAction->setIcon(QIcon(":images/infoproperties.png"));
    // infoPropertiesAction->setShortcut(tr("Ctrl+"));
    infoPropertiesAction->setStatusTip(tr("Set node info"));
    connect(infoPropertiesAction , SIGNAL(triggered()), this , SLOT(infoProperties()));

    //////////////////
    // link actions //
    //////////////////
    createLinkAction = new QAction(tr("Create &Link"), this);
    createLinkAction->setIcon(QIcon(":images/createlink.png"));
    // createLinkAction->setShortcut(tr("Ctrl+"));
    createLinkAction->setStatusTip(tr("create a new link"));
    connect(createLinkAction , SIGNAL(triggered()), this , SLOT(createLink()));
    
    linkToChildNodeAction = new QAction(tr("Link to &Child "), this);
    linkToChildNodeAction->setIcon(QIcon(":images/linktochild.png"));
    // linkToChildNodeAction->setShortcut(tr("Ctrl+"));
    linkToChildNodeAction->setStatusTip(tr("link to a child node"));
    connect(linkToChildNodeAction , SIGNAL(triggered()), this , SLOT(linkToChildNode()));

    linkToFatherNodeAction = new QAction(tr("Link to &Father "), this);
    linkToFatherNodeAction->setIcon(QIcon(":images/linktofather.png"));
    // linkToFatherNodeAction->setShortcut(tr("Ctrl+"));
    linkToFatherNodeAction->setStatusTip(tr("link to a father node"));
    connect(linkToFatherNodeAction , SIGNAL(triggered()), this , SLOT(linkToFatherNode()));

    linkModeAction = new QAction(tr("Link &Mode "), this);
    linkModeAction->setIcon(QIcon(":images/linkmode.png"));
    // linkModeAction->setShortcut(tr("Ctrl+"));
    linkModeAction->setStatusTip(tr("turn to link mode"));
    connect(linkModeAction , SIGNAL(triggered()), this , SLOT(linkMode()));

    transCodeAction = new QAction(tr("&TransCode"), this);
    transCodeAction->setIcon(QIcon(":images/transcode.png"));
    // transCodeAction->setShortcut(tr("Ctrl+"));
    transCodeAction->setStatusTip(tr("set the transcode in link"));
    connect(transCodeAction , SIGNAL(triggered()), this , SLOT(transCode()));

    linkSurfaccePropertiesAction = new QAction(tr("&Surfacce Properties"), this);
    linkSurfaccePropertiesAction->setIcon(QIcon(":images/linksurfaceproperties.png"));
    // linkSurfaccePropertiesAction->setShortcut(tr("Ctrl+"));
    linkSurfaccePropertiesAction->setStatusTip(tr("set the link surface properties"));
    connect(linkSurfaccePropertiesAction , SIGNAL(triggered()), this , SLOT(linkSurfacceProperties()));

    ///////////////////
    // debug actions //
    ///////////////////

    startDebugAction = new QAction(tr("&Debug"), this);
    startDebugAction->setIcon(QIcon(":images/startdebug.png"));
    // startDebugAction->setShortcut(tr("Ctrl+"));
    startDebugAction->setStatusTip(tr("Debug..."));
    connect(startDebugAction , SIGNAL(triggered()), this , SLOT(startToDebug()));

 	startDebugFromCurNodeAction = new QAction(tr("Debug From &Cur Node"), this);
    startDebugFromCurNodeAction->setIcon(QIcon(":images/debugfromCurNode.png"));
    // startDebugFromCurNodeAction->setShortcut(tr("Ctrl+"));
    startDebugFromCurNodeAction->setStatusTip(tr("start to debug from current node "));
    connect(startDebugFromCurNodeAction , SIGNAL(triggered()), this , SLOT(startToDebugFromCurNode()));

 	stopDebugAction = new QAction(tr("&Stop Debug"), this);
    stopDebugAction->setIcon(QIcon(":images/stopdebug.png"));
    // stopDebugAction->setShortcut(tr("Ctrl+"));
    stopDebugAction->setStatusTip(tr("stop debug"));
    connect(stopDebugAction , SIGNAL(triggered()), this , SLOT(stopDebug()));

    //////////////////
    // help actions //
    //////////////////
    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setIcon(QIcon(":images/about.png"));
    aboutAction->setStatusTip(tr("About the SoftWare"));
    connect(aboutAction , SIGNAL(triggered()), this , SLOT(about()));

    aboutQtAction = new QAction(tr("About &Qt"), this);
    aboutQtAction->setIcon(QIcon(":images/aboutqt.png"));
    aboutQtAction->setStatusTip(tr("About the Qt"));
    connect(aboutQtAction , SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    tutorialAction = new QAction(tr("&Tutorial"), this);
    tutorialAction->setIcon(QIcon(":images/tutorial.png"));
    tutorialAction->setStatusTip(tr("Basic tutorial..."));
    connect(tutorialAction , SIGNAL(triggered()), this , SLOT(tutorial()));

 }


 void MainWindow::createMenus()
 {
	 ///////////
 	// file menu//
	 ///////////
 	QMenu * fileMenu = menuBar()->addMenu(tr("&File"));
 	fileMenu->addAction(newFileAction);
 	fileMenu->addAction(openFileAction);
 	fileMenu->addAction(saveFileAction);
 	fileMenu->addAction(saveAsFileAction);
 	fileMenu->addSeparator();
 	fileMenu->addAction(exitAction);

	 ////////////////
 	// edit menu //
	 ////////////////
 	QMenu * editMenu = menuBar()->addMenu(tr("&Edit"));
 	editMenu->addAction(cutAction);
 	editMenu->addAction(copyAction);
 	editMenu->addAction(pasteAction);
 	editMenu->addAction(deleteAction);
 	editMenu->addSeparator();
 	editMenu->addAction(bringToFrontAction);
 	editMenu->addAction(sendToBackAction);

	 ///////////////////
 	// project menu //
	 ///////////////////
 	QMenu * projMenu = menuBar()->addMenu(tr("&Project"));
 	projMenu->addAction(createProjectAction);
 	projMenu->addAction(openProjectAction);
 	projMenu->addAction(closeProjectAction);

	 ///////////////////
 	// windows menu //
	 ///////////////////
 	QMenu * windowsMenu = menuBar()->addMenu(tr("&Windows"));
 	windowsMenu->addAction(closeAction);
 	windowsMenu->addAction(closeAllAction);
 	windowsMenu->addSeparator();
 	windowsMenu->addAction(tileAction);
 	windowsMenu->addAction(cascadeAction);
 	windowsMenu->addSeparator();
 	windowsMenu->addAction(nextAction);
 	windowsMenu->addAction(previousAction);
 	windowsMenu->addSeparator();

	 ////////////////
 	 // node menu //
	 ////////////////
	QMenu * nodeMenu = menuBar()->addMenu(tr("&Node"));
	nodeMenu->addAction(createNodeAction);
	nodeMenu->addAction(addChildNodeAction);
	nodeMenu->addAction(hAlignAction);
	nodeMenu->addAction(vAlignAction);
	nodeMenu->addSeparator();
	nodeMenu->addAction(nodeSurfaccePropertiesAction);
	nodeMenu->addAction(infoPropertiesAction);

	////////////////
	// link menu //
	////////////////
	QMenu * linkMenu = menuBar()->addMenu(tr("&Link"));
	linkMenu->addAction(createLinkAction);
	linkMenu->addAction(linkToChildNodeAction);
	linkMenu->addAction(linkToFatherNodeAction);
	linkMenu->addAction(linkModeAction);
	linkMenu->addSeparator();
	linkMenu->addAction(transCodeAction);
	linkMenu->addAction(linkSurfaccePropertiesAction);

	/////////////////
	// debug menu //
	/////////////////
	QMenu * debugMenu = menuBar()->addMenu(tr("&Debug"));
	debugMenu->addAction(startDebugAction);
	debugMenu->addAction(startDebugFromCurNodeAction);
	debugMenu->addAction(stopDebugAction);

	//////////////////
	// help action //
	//////////////////
	QMenu * helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(tutorialAction);
	helpMenu->addSeparator();
	helpMenu->addAction(aboutAction);
	helpMenu->addAction(aboutQtAction);
 }


 void MainWindow::createToolBars()
 {
 	QToolBar * fileToolBar = addToolBar(tr("&File"));
 	fileToolBar->addAction(newFileAction);
 	fileToolBar->addAction(openFileAction);
 	fileToolBar->addAction(saveFileAction);
 	fileToolBar->addAction(saveAsFileAction);

 	QToolBar * editToolBar = addToolBar(tr("&Edit"));
 	editToolBar->addAction(cutAction);
 	editToolBar->addAction(copyAction);
 	editToolBar->addAction(pasteAction);
 	editToolBar->addAction(deleteAction);
 	editToolBar->addAction(bringToFrontAction);
 	editToolBar->addAction(sendToBackAction);

 	QToolBar * nodeToolBar = addToolBar(tr("&Node"));
 	nodeToolBar->addAction(createNodeAction);
 	nodeToolBar->addAction(hAlignAction);
 	nodeToolBar->addAction(vAlignAction);
 	nodeToolBar->addAction(addChildNodeAction);
 	nodeToolBar->addAction(nodeSurfaccePropertiesAction);
 	nodeToolBar->addAction(infoPropertiesAction);

 	QToolBar *	linkToolBar = addToolBar(tr("&Link"));
 	linkToolBar->addAction(createLinkAction);
 	linkToolBar->addAction(linkToChildNodeAction);
 	linkToolBar->addAction(linkToFatherNodeAction);
 	linkToolBar->addAction(linkModeAction);
 	linkToolBar->addAction(transCodeAction);
 	linkToolBar->addAction(linkSurfaccePropertiesAction);

 	QToolBar *	debugToolBar = addToolBar(tr("&Debug"));
 	debugToolBar->addAction(startDebugAction);
 	debugToolBar->addAction(startDebugFromCurNodeAction);
 	debugToolBar->addAction(stopDebugAction);
 }

 void MainWindow::createStatusBar()
 {
	QStatusBar * status = statusBar();
 }

void MainWindow::newModeFile(){}
void MainWindow::openModeFiles(){}
void MainWindow::saveFile(){}
void MainWindow::saveAsFile(){}

void MainWindow::copy(){}
void MainWindow::cut(){}
void MainWindow::paste(){}
void MainWindow::deleteobjs(){}
void MainWindow::bringToFront(){}
void MainWindow::sendToBack(){}

void MainWindow::createProject(){}
void MainWindow::closeProject(){}
void MainWindow::openProject(){}

void MainWindow::createNode(){}
void MainWindow::alignHorizontal(){}
void MainWindow::alignVertical(){}
void MainWindow::addChildNode(){}
void MainWindow::nodeSurfacceProperties(){}
void MainWindow::infoProperties(){}

void MainWindow::createLink(){}
void MainWindow::linkToChildNode(){}
void MainWindow::linkToFatherNode(){}
void MainWindow::linkMode(){}
void MainWindow::transCode(){}
void MainWindow::linkSurfacceProperties(){}

void MainWindow::startToDebug(){}
void MainWindow::startToDebugFromCurNode(){}
void MainWindow::stopDebug(){}

void MainWindow::about(){}
void MainWindow::tutorial(){}

void MainWindow::updateActions(){}
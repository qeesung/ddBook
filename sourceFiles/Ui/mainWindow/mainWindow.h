#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/** 定义主窗口 */
#include <QMdiArea>
#include <QMainWindow>
#include "GraphicsView.h"
#include "node.h"
#include "link.h"
// #include "entertranscodedialog.h"
class QAction;
class QActionGroup;
class GraphicsView;//子类化QGraphicsView，添加了文件保存创建等等相关信息
class QMdiArea;
class QMenu;


class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();
	/** 得到基本数据源 */
	static QMap<QString ,QString> getCpData()
	{
		return cpMapData;
	}
	static QStringList getAlData()
	{
		return alListData;
	}
	static QMap<QString , QStringList> getCdData()
	{
		return cdMapData;
	}
	static void updateDockWidget(Node * node);
	static void updateDockWidget();
	static void updateNodeInfo(Node * );
	static void updateAllNodesInfo();// 强制更新已有的所有节点 
	static MainWindow * mainWindowObjectPointer;
protected:
	void closeEvent(QCloseEvent * event);
private slots:
	/////////////////////
	// actions对应的信号和槽 //
	/////////////////////
	void newModeFile();
	void openModeFiles();
	void saveFile();
	void saveAsFile();
	void setupCodeTable();
	void setupAudioList();
	void setupDefaultAudioTree();
	void check();

	void copy();
	void cut();
	void paste();
	void deleteobjs();
	void bringToFront();
	void sendToBack();

	// void createProject();
	// void closeProject();
	// void openProject();

	void createNode();
	void alignHorizontal();
	void alignVertical();
	void addChildNode();
	void nodeSurfacceProperties();
	void infoProperties();
	void showDockWindow(bool);

	void createLink();
	void linkToChildNode();
	void linkToFatherNode();
	void linkMode();
	// void transCode();
	void linkSurfacceProperties();

	void startToDebug();
	// void startToDebugFromCurNode();
	void stopDebug();

	void about();
	void tutorial();

	//////////////
	//其他的一些私有槽 //	
	//////////////
	/**
	 * 更新Actions的enabled状态
	 */
	void updateActions();
private:
	 ///////////////////
	 // 创建对应的actions //
	 ///////////////////

	/** file actions */
	QAction * newFileAction;
	QAction * openFileAction;
	QAction * saveFileAction;
	QAction * saveAsFileAction;
	QAction * setupCodesAction;
	QAction * setupAudioAction;
	QAction * setupDefaultAudioAction;
	QAction * checkAction;
	QAction * exitAction;

	/** 编辑actions */
	QAction * cutAction;
	QAction * copyAction;
	QAction * pasteAction;
	QAction * deleteAction;
	QAction * bringToFrontAction;//将选中的节点移到最顶层
	QAction * sendToBackAction;//将选中节点移到底层

	/** 工程actions */
	// QAction * createProjectAction;
	// QAction * closeProjectAction;
	// QAction * openProjectAction;

	/** 窗口actions */
	QMenu * windowsMenu;
	QAction * closeAction;
	QAction * closeAllAction;
	QAction * tileAction;
	QAction * cascadeAction;//窗口的排列方式
	QAction * nextAction;
	QAction * previousAction;
	QActionGroup * windowActionGroup;

	/** 节点actions */
	QAction * createNodeAction;
	QAction * hAlignAction;//节点的对齐
	QAction * vAlignAction;
	QAction * addChildNodeAction;//添加子节点，添加的时候也自动将其链接起来
	QAction * nodeSurfaccePropertiesAction;//外观设置的action
	QAction * infoPropertiesAction;//节点信息设置的action
	QAction * previewNodeInfoAction;

	/** 链接actions */
	QAction * createLinkAction;//只是单纯的建立链接
	QAction * linkToChildNodeAction;
	QAction * linkToFatherNodeAction;
	QAction * linkModeAction;//链接模式，在此模式下面节点不可拖动，但是可以在节点之间进行拖动连线
	QAction * transCodeAction;//设置转移码的
	QAction * linkSurfaccePropertiesAction;//设置链接外观

	/** 调试模式actions */
	QAction * startDebugAction;
	// QAction * startDebugFromCurNodeAction;//从当前的选中节点来开始调试
	QAction * stopDebugAction;

	/** 帮助actions */
	QAction * aboutAction;
	QAction * aboutQtAction;
	QAction * tutorialAction;

	/////////////////////////////
	//私有函数，创建菜单，工具栏，以及actions //
	/////////////////////////////
	/**
	 * 创建actions
	 */
	void createActions();
	/**
	 * 创建菜单
	 */
	void createMenus();
	/**
	 * 创建工具栏
	 */
	void createToolBars();
	/**
	 * 创建状态栏
	 */
	void createStatusBar();
	/**
	 * 在mdiArea里面添加一个view
	 * @param view 新建的view
	 */
	void addView(GraphicsView * view);
	/**
	 * 返回当前的活动窗口
	 * @return 返回的窗口
	 */
	GraphicsView * activeView();

	/**
	 * 得到所有的views
	 */
	QList<GraphicsView *> allViews();

	///////////////
	//一些必要的窗口部件 //
	///////////////
	QMdiArea * mdiArea;//实现多窗口

	/**
	 * 节点预览靠窗的实现
	 */
	static QDockWidget * nodeInfoDockWidget;
	// void createNodeInfoDockWidget();

	/**
	 * 与project相关
	 */
	// QString projectName;
	// QString projectPath;
	// ProjectTreeWidget * projectTreeWidget;
	// 三个基本数据的处理
	static QMap<QString , QString> cpMapData;
	static QStringList alListData;
	static QMap<QString , QStringList> cdMapData;
public:
	static void loadCpData();
	static void loadAlData();
	static void loadCdData();
};

#endif
#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
class Node;
class Link;


class GraphicsView : public QGraphicsView
{
	Q_OBJECT
public:
	typedef QPair<Node * , Node *> NodePair;//创建一对节点
	GraphicsView(QWidget * parent=0);
	GraphicsView(QGraphicsScene * scene , QWidget * parent=0);

	/**
	 * 对文件的操作
	 * 打开
	 * 新建
	 * 保存
	 * 另存为
	 */
	void newFile();
	bool save();
	bool saveAs();
	static GraphicsView * open(QWidget * parent=0);
	static GraphicsView * openFile(const QString & filename,\
								   QWidget * parent=0);
	/**
	 * 对文件的内容的操作
	 * 剪切
	 * 粘贴
	 * 复制
	 * 删除
	 * 置顶
	 * 置底
	 */
	void cut();
	void copy();
	void paste();
	void deleteobjs();
	void bringToFront();
	void sendToBack();

	/**
	 * 节点相关操作
	 * 添加节点
	 * 横向对齐
	 * 纵向对齐
	 * 增加子节点
	 * 节点外观设置
	 * 节点信息设置
	 */
	void createNode();//按照固定位置创建
	Node * createNode(const QPointF & pos);//按照鼠标位置创建
	void alignHorizontal(QList<Node *> selectedNodes);
	void alignVertical(QList<Node *> selectedNodes); 
	void addChildNode(Node * fatherNode);
	void nodeSurfacceProperties(Node * node);
	void infoProperties(Node * node);

	/**
	 * 链接相关操作
	 * 添加链接
	 * 连接到一个子节点
	 * 连接到一个父节点
	 * 链接模式
	 * 设置转移码
	 * 链接的外观设置
	 */
	void createLink();
	Link * createLink(Node * fatherNode , Node * childNode);
	void linkToChildNode(Node * node);
	void linkToFatherNode(Node * node);
	void linkMode();
	void transCode(Link * link);
	void linkSurfacceProperties(Link * link);


	QSize sizeHint() const;
	QAction * windowMenuAction() const {return action;}
	QPointF getMouserPos() const{return mouserPos;}

	/** 节点操作的相关操作 */
	Node * selectedNode() const;
	Link * selectedLink() const;
	NodePair selectedNodePair() const;
protected:
	void closeEvent(QCloseEvent * event);
	//按键捕捉
	void keyPressEvent(QKeyEvent * event);
	//鼠标位置捕捉
	void mousePressEvent(QMouseEvent * mouseEvent);
	
private slots:
	void documentWasModified(const QList<QRectF> &);
private:
	/** 一般操作 */
	bool okToContinue();
	void setZValue(int z);

	/** 文件的相关私有操作操作 */
	bool saveFile(const QString & filename);
	void setCurrentFile(const QString & filename);
	bool readFile(const QString & filename);
	bool writeFile(const QString & filename);
	QString strippedName(const QString & fullFilename);

	/** 节点操作的相关操作 */
	void setupNode(Node * node);

	/** 链接操作相关 */
	Node * chooseANode(Node * node);


	/** 与bring to front 和 send to back 相关 */
	int minZ;
	int maxZ;

	/** 与文件的具体标示有关 */
	QString curFile;
	bool isUntitled;
	QAction * action;

	/** 与节点位置有关 */
	int seqNumber;

	/** 当前的状态是那一种 */
	enum ViewMode{
		NormalMode=0,//普通模式
		ChooseNodeMode=1,//选择一个节点的模式
		ChooseNodePairMode=2//选择节点对模式
	};
	ViewMode curMode;//随时判断当前在那个模式

	/** 鼠标点击的位置 */
	QPointF mouserPos;

	/** 第一次打开标志位 */
	bool firstOpened;
};


#endif
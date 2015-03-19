#ifndef LINK_H
#define LINK_H

#include <QGraphicsLineItem>
#include "node.h"
#include <QString>
#define LINEZVALUE -100000000000

/**
 * 这里定义的是链接节点之间的线段的类
 */

 class Link : public QGraphicsLineItem
 {
 public:
 	Link(Node * fromNode , Node * toNode);
 	~Link();

	void setFromNode(Node * newFromNode);
	void setToNode(Node * newToNode);

 	Node * getFromNode() const;
 	Node * getToNode() const;

 	void setColor(const QColor & color);
 	QColor getColor() const;

 	// 设置该线段的转移码制
 	// void setTransCode(const int & transCode);
 	// int getTransCode() const;

 	void trackNode();

 	void paint(QPainter * painter ,\
 	      const QStyleOptionGraphicsItem * option,\
 	      QWidget * /*widget*/);//这里重新绘画这条线段，标明是谁指向的谁
    QRectF boundingRect() const;
 protected:
 	/**
 	 * 双击这条线所触发的输入转移码事件
 	 * @param event [description]
 	 */
 	// void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
 private:
 	QPointF getCircleCenter() const;
 	Node * fromNode;
 	Node * toNode;
 	// int transCode;//该线段的转移码
 };


#endif
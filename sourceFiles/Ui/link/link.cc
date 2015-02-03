#include <QPainter>
#include "link.h"
#include <QLineF>
#include "entertranscodedialog.h"
#include <QGraphicsLineItem>
#include <QPen>
#include "node.h"


Link::Link(Node * _fromNode , Node * _toNode)
{
	fromNode = _fromNode;
	toNode = _toNode;
	fromNode->addLink(this);
	toNode->addLink(this);

	setFlags(QGraphicsItem::ItemIsSelectable);
	setZValue(-1);

	setColor(Qt::darkRed);
	setTransCode(-1);
	/** 在创建线段的时候要求用户输入对应的转移码 */
	// EnterTransCodeDialog * transCodeDialog = new EnterTransCodeDialog(this);
	// if(transCodeDialog -> exec() == QDialog::Accepted)
	// {
	// 	setTransCode(transCodeDialog->getTransCode());
	// }
	// trackNode();
}


Link::~Link()
{
	fromNode->removeLink(this);
	toNode->removeLink(this);
}

void Link::setFromNode(Node * fromNode)
{
	this->fromNode->removeLink(this);
	this->fromNode = fromNode;
	fromNode->addLink(this);
}


void Link::setToNode(Node * toNode)
{
	this->toNode->removeLink(this);
	this->toNode = toNode;
	toNode->addLink(this);	
}


Node * Link::getFromNode() const
{
	return fromNode;
}

Node * Link::getToNode() const
{
	return toNode;
}

void Link::setColor(const QColor & color)
{
	setPen(QPen(color, 1.0));
}

QColor Link::getColor() const
{
	return pen().color();
}

void Link::setTransCode(const int & newTransCode)
{
	transCode=newTransCode;
}

int Link::getTransCode() const
{
	return transCode;
}

void Link::trackNode()
{
	setLine(QLineF(fromNode->pos() , toNode->pos()));
}

void Link::paint(QPainter * painter ,\
      const QStyleOptionGraphicsItem * /*option*/,\
      QWidget * /*widget*/)
{
	QPen pen(getColor());
	painter->setPen(pen);
	/** 画出线 */
	painter->drawLine(QLineF(fromNode->pos() , toNode->pos()));
	QPointF centerPoint = getCircleCenter();

	/** 以centerPoint为圆心，画出一个小红点 */
	QBrush brush(QColor(Qt::red));
	painter->setBrush(brush);
	painter->drawEllipse(centerPoint , 5 , 5);
	/** 在线段的中间写上对应的转移码 */
	QPointF lineMidPoint = QPointF((toNode->pos().x()+fromNode->pos().x())/2,\
		                           (toNode->pos().y()+fromNode->pos().y())/2);
	painter->drawText(lineMidPoint , QString("%1").arg(transCode));

	// QString debugMsg = QString("line bound rect width is %1 and height is %2").arg(boundingRect().width()).arg(boundingRect().height());
	// qDebug(qPrintable(debugMsg));
}

QPointF Link::getCircleCenter() const
{
	/////////////////
	//首先得到node的矩形 //
	/////////////////
	QRectF rect = toNode->boundingRect();
	QPointF intersectionPoint;
	QLineF curLine = QLineF(fromNode->pos() , toNode->pos());
	//左边界
	QString str = QString("%1 %2").arg(toNode->pos().x()).arg(toNode->pos().y());
	// qDebug(qPrintable(str));
	QPointF topLeft = toNode->pos();
	topLeft.rx()-=rect.width()/2;
	topLeft.ry()-=rect.height()/2;

	QPointF topRight = toNode->pos();
	topRight.rx()+=rect.width()/2;
	topRight.ry()-=rect.height()/2;
	
	QPointF bottomLeft = toNode->pos();
	bottomLeft.rx()-=rect.width()/2;
	bottomLeft.ry()+=rect.height()/2;

	QPointF bottomRight =toNode->pos();
	bottomRight.rx()+=rect.width()/2;
	bottomRight.ry()+=rect.height()/2;

	QLineF leftBorderLine = QLineF(topLeft , bottomLeft);
	QLineF rightBorderLine = QLineF(topRight , bottomRight);
	QLineF topBorderLine = QLineF(topLeft , topRight);
	QLineF bottomBorderLine = QLineF(bottomLeft , bottomRight);	

	if(curLine.intersect(leftBorderLine , &intersectionPoint) == QLineF::BoundedIntersection)
		return intersectionPoint;
	else if(curLine.intersect(rightBorderLine , &intersectionPoint) == QLineF::BoundedIntersection)
		return intersectionPoint;
	else if(curLine.intersect(topBorderLine , &intersectionPoint) == QLineF::BoundedIntersection)
		return intersectionPoint;
	else if(curLine.intersect(bottomBorderLine , &intersectionPoint) == QLineF::BoundedIntersection)
		return intersectionPoint;
	else
	{
		QString debugMsg = QString("Can not get intersectionPoint ---x:%1  y:%2").\
										arg(intersectionPoint.x()).arg(intersectionPoint.y());
		// qDebug(qPrintable(debugMsg));
		return intersectionPoint;
	}
}


void Link::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * /*event*/)
{
	EnterTransCodeDialog * transCodeDialog = new EnterTransCodeDialog(this);
	if(transCodeDialog -> exec() == QDialog::Accepted)
	{
		setTransCode(transCodeDialog->getTransCode());
	}
}

QRectF Link::boundingRect() const
{
	QLineF curLine = line();
	if(qAbs(curLine.p1().x()-curLine.p2().x()) <100 || qAbs(curLine.p1().y() - curLine.p2().y()) < 100)
		return QGraphicsLineItem::boundingRect().adjusted(-40,-20,+40,+20);
	else
		return QGraphicsLineItem::boundingRect();
}

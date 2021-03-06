#include "node.h"
#include "setNodeInfo.h"
#include "mainWindow.h"
#include <QInputDialog>
#include <QGraphicsSceneMouseEvent>
#include <QLineEdit>
#include <QFontMetricsF>
#include "link.h"
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QPen>
#include <QPainter>

/*	QRectF outlineRect() const;//依据文字的长短大小来返回相应的大小矩形
	int roundness(double size) const;
	QSet<Link *> myLinks;
	QString text;
	QColor textColor;
	QColor outlineColor;
	QColor backgroundColor;*/

Node::Node()
{
	textColor = Qt::white;
	outlineColor = Qt::darkRed;
	backgroundColor = Qt::darkGreen;
	transCodeBackgroundColor = QColor("#7CCD7C");
	transCodeTextColor = Qt::white;

	transCode = QString("None");
	beforeSameAsAfter = true;
	picture = QString("image:about.icon");
	/** 设置唯一标示ID */
	QDateTime time(QDate::currentDate(), QTime::currentTime());
	QString timeStr = QString("%1").arg(time.toMSecsSinceEpoch());
	setNodeID(timeStr);

	this->setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsGeometryChanges);
}

Node::~Node()
{
	foreach(Link * link , myLinks )
		delete link;
}

void Node::addLink( Link * newLink)
{
	myLinks.insert(newLink);
}

void Node::removeLink(Link * oldLink)
{
	myLinks.remove(oldLink);
}


QRectF Node::outlineRect() const
{
	// 填充八个像素
	const int padding = 8;
	QFontMetricsF metrics = qApp->font();
	QRectF rect1 = nodeNameRect();
	QRectF rect2 = nodeTransCodeRect();
	rect1.adjust(-0,-0,+rect2.width(),+0);
	rect1.translate(-rect1.center());
	return rect1;
}

QRectF Node::nodeNameRect() const
{
	// 填充八个像素
	const int padding = 8;
	QFontMetricsF metrics = qApp->font();
	QRectF rect = metrics.boundingRect(text);
	rect.adjust(-padding , -padding , +padding , +padding);
	rect.translate(-rect.center());
	return rect;
}

QRectF Node::nodeTransCodeRect() const
{
	// 填充八个像素
	const int padding = 8;
	QFontMetricsF metrics = qApp->font();
	QRectF rect = metrics.boundingRect(transCode);
	rect.adjust(-padding , -padding , +padding , +padding);
	rect.translate(-rect.center());
	QRectF rectTemp = nodeNameRect();
	rect.translate(rectTemp.width()/2+rect.width()/2,0);
	return rect;
}


QRectF Node::boundingRect() const
{
	// 预留一个大小的边界
	const int margin = 1;
	return outlineRect().adjusted(-margin , -margin , +margin , +margin );
}

QPainterPath Node::shape() const
{
	QRectF rect = outlineRect();
	QPainterPath path;
	path.addRoundRect(rect, roundness(rect.width()),roundness(rect.height()));
	return path;
}

void Node::paint(QPainter * painter ,const QStyleOptionGraphicsItem * option , QWidget * /*widget*/)
{
	QPen pen(getOutlineColor());
	if(option->state & QStyle::State_Selected)
	{
		pen.setStyle(Qt::DotLine);
		pen.setWidth(2);
	}
	QRectF rect1= nodeNameRect();
	QRectF rect2= nodeTransCodeRect();
	rect1.translate(-rect2.width()/2,0);
	rect2.translate(-rect2.width()/2,0);
	// draw the nodeName
	painter->setPen(pen);
	painter->setBrush(backgroundColor);
	painter->drawRoundRect(rect1 , roundness(rect1.width()) , roundness(rect1.height()));

	// draw the node transCode
	painter->setPen(pen);
	painter->setBrush(transCodeBackgroundColor);
	painter->drawRoundRect(rect2 , roundness(rect2.width()) , roundness(rect2.height()));
	
	painter->setPen(textColor);
	painter->drawText(rect1 , Qt::AlignCenter , text);
	painter->setPen(transCodeTextColor);
	painter->drawText(rect2 , Qt::AlignCenter , transCode);
}

QVariant Node::itemChange(GraphicsItemChange change ,const QVariant & value)
{
	if(change == ItemPositionHasChanged)
	{
		foreach(Link * link , myLinks)
			link->trackNode();
	}
	return QGraphicsItem::itemChange(change , value);
}

void Node::mouseDoubleClickEvent(QGraphicsSceneMouseEvent * /*event*/)
{
	SetNodeInfo * setDialog = new SetNodeInfo(this);
	if(setDialog->exec()==QDialog::Accepted)
	{
		setStartAudio(setDialog->getStartAudio());
		setEndAudio(setDialog->getEndAudio());
		setText(setDialog->getNodeName());
		setPicture(setDialog->getPictureName());
		setTransCode(setDialog->getTransCode());

		setSameFlag(true);

		QList<QPair<QString , QString> > tempList1 = setDialog->getGivenAudioTable(); 
		givenAudioTable.clear();

		/** 设置第一个表的内容 */
		for(QList<QPair<QString , QString> >::iterator iter = tempList1.begin() ; iter != tempList1.end();
						++iter)
		{
			givenAudioTable[iter->first] = iter->second;
		}
		MainWindow::updateDockWidget(this);
	}
}

int Node::roundness(double size) const
{
	const int diameter = 12;
	return 100*diameter/int(size);
}

QStringList Node::getDefaultAudioList() const{
	QMap<QString , QStringList> cdMap = MainWindow::getCdData();
	if(cdMap.count(transCode) == 0)
		return QStringList();
	else
		return cdMap[transCode];
}
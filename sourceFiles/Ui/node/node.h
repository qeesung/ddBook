#ifndef _NODE_H
#define _NODE_H

// #include "line.h"
#include <QApplication>
#include <QColor>
#include <QGraphicsItem>
#include <QSet>
#include <QDateTime>
// #include <GraphicsItemChange>
class Link;

class Node : public QGraphicsItem
{
	Q_DECLARE_TR_FUNCTIONS(Node)

public:
	Node();
	~Node();
	void setText(const QString & str){
		prepareGeometryChange();//这里因为会根据字体的长短来设置对应的显示框的大小
		// 所以需要调用这个函数
		text = str;
		update();}
	QString getText() const{return text;}

	void setTextColor(const QColor & color){textColor = color;update();}
	QColor getTextColor()const {return textColor;}

	void setOutlineColor(const QColor & color){ outlineColor = color;update();}
	QColor getOutlineColor() const {return outlineColor;}

	void setBackgroundColor(const QColor & color){backgroundColor = color;update();}
	QColor getBackgroundColor() const {return backgroundColor;}

	void addLink(Link * newLink);
	void removeLink(Link * oldLink);

	QRectF boundingRect() const;//这个函数规定了在哪一个范围里面绘画  
	QPainterPath shape() const;//在boudingRect里面的绘制出来的图形
	void paint(QPainter * painter , const QStyleOptionGraphicsItem * option , QWidget * widget);//真正的绘制函数
	QRectF outlineRect() const;//依据文字的长短大小来返回相应的大小矩形


	/** 设置及获得node属性 */
	void setStartAudio(const QString & audioFilename){startAudio = audioFilename;}
	QString getStartAudio() const{return startAudio;}

	void setEndAudio(const QString & audioFilename){endAudio = audioFilename;}
	QString getEndAudio() const{return endAudio;}

	void setDefaultAudioList(const QStringList & defaultList){defaultAudioList = defaultList;}
	void addDefaultAudio(const QString & audioFilename){defaultAudioList.push_back(audioFilename);}
	void removeDefaultAudio(const QString & audioFilename){defaultAudioList.removeOne(audioFilename);}
	QStringList getDefaultAudioList() const{return defaultAudioList;}

	void setNodeID(const QString & IDStr){nodeID = IDStr;}
	QString getNodeID() const{return nodeID;}

protected:
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
	QVariant itemChange(GraphicsItemChange change , const QVariant & value);

private:
	int roundness(double size) const;
	QSet<Link *> myLinks;
	QString text;
	QColor textColor;
	QColor outlineColor;
	QColor backgroundColor;

	/** node基本属性 */
	QString startAudio;
	QString endAudio;
	QStringList defaultAudioList;

	/** node的唯一ID标示 */
	QString nodeID;

};

#endif
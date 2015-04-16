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

	void setTransCodeBackgroundColor(const QColor & color){transCodeBackgroundColor = color; update();}
	QColor getTransCodeBackgroundColor()const {return transCodeBackgroundColor;}

	void setTransCodeTextColor(const QColor & color){transCodeTextColor = color; update();}
	QColor getTransCodeTextColor()const {return transCodeTextColor;}

	void addLink(Link * newLink);
	void removeLink(Link * oldLink);

	QRectF boundingRect() const;//这个函数规定了在哪一个范围里面绘画  
	QPainterPath shape() const;//在boudingRect里面的绘制出来的图形
	void paint(QPainter * painter , const QStyleOptionGraphicsItem * option , QWidget * widget);//真正的绘制函数
	QRectF outlineRect() const;//依据文字的长短大小来返回相应的大小矩形
	QRectF nodeNameRect() const;//节点名字占用的矩形的大小
	QRectF nodeTransCodeRect() const;//节点转移吗占用的矩形的大小


	/** 设置及获得node属性 */
	void setStartAudio(const QString & audioFilename){startAudio = audioFilename;}
	QString getStartAudio() const{return startAudio;}

	void setEndAudio(const QString & audioFilename){endAudio = audioFilename;}
	QString getEndAudio() const{return endAudio;}

	/** 查询不是转移的点之后,现在要添加上一些给定的默认音频 */
	QString getGivenAudio(QString & code) const
	{
		if(givenAudioTable.count(code) == 0)
			return QString();
		else
			return givenAudioTable[code];
	}

	/** 得到状态前的默认列表 */
	void setDefaultAudioList(const QStringList & defaultList){defaultAudioList = defaultList;}
	QStringList getDefaultAudioList() const;

	/** 得到状态后的默认列表 */
	QStringList getAfterDefaultAudioList() const{return QStringList();}

	/** 得到状态前给定的音频 */
	void setGivenTableAudio(const QString & givenCode , const QString & _givenAudioTable){
		if(givenAudioTable.count(givenCode) == 0)
			return;
		givenAudioTable[givenCode] = _givenAudioTable;
	}
	void addGivenTableAudio(const QString & givenCode , const QString & audioFilename){
		givenAudioTable[givenCode] = audioFilename;
	}
	void removeGivenTableAudio(const QString & givenCode){
		givenAudioTable.remove(givenCode);
	}
	QString getGivenTableAudio(const QString & givenCode) const{
		if(givenAudioTable.count(givenCode) == 0)
			return QString();
		return givenAudioTable[givenCode];
	}
	QMap<QString , QString> getAllGivenTableAudio() const{
		return givenAudioTable;
	}
	/** 得到状态后给定的音频 */
	QMap<QString , QString> getAllAfterGivenTableAudio() const{
		return QMap<QString , QString>();
	}
	/** 一个节点有一个图片 */
	void setPicture(const QString & _picture){picture = _picture;}
	QString getPicture() const{return picture;}

	void setNodeID(const QString & IDStr){nodeID = IDStr;}
	QString getNodeID() const{return nodeID;}

	void setTransCode(const int _transCode){
		prepareGeometryChange();
		transCode = QString("%1").arg(_transCode);
		update();
	}
	void setTransCode(const QString & _transCode){
		prepareGeometryChange();
		transCode = _transCode;
		update();
	}
	QString getTransCode() const{return transCode;}

	/** 判断状态前和状态后的音频是否一样 */
	bool isBeforeSameAsAfter() const
	{
		return true;
	}

	void setSameFlag(bool flag) 
	{
		beforeSameAsAfter = flag;
	}

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
	QColor transCodeBackgroundColor;
	QColor transCodeTextColor;

	/** node基本属性 */
	QString startAudio;
	QString endAudio;
	QStringList defaultAudioList;

	/** 下面两个个是用来存储对应的Node id 和 音频直接的关系 */
	QMap<QString , QString> givenAudioTable;//输入的码制不是转移码,那么就来查找这张表

	/** node的唯一ID标示 */
	QString nodeID;

	/** 为节点增加一个对应的码值 */
	QString transCode;

	/** 一个借点对应一个图片 */
	QString picture;

	/** 状态前和状态后是否相同 */
	bool beforeSameAsAfter;

};

#endif
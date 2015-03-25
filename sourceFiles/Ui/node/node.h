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
	/** code指的是上一个节点的码指 */
	QString getStartAudio(QString  & code) const
	{
		if(startAudioTable.count(code) == 0)
			return startAudio;
		else
			return startAudioTable[code];
	}

	void setEndAudio(const QString & audioFilename){endAudio = audioFilename;}
	QString getEndAudio() const{return endAudio;}
	/** code指的是下一个将要转向的节点的码指 */
	QString getEndAudio(QString & code) const
	{
		if(endAudioTable.count(code) == 0)
			return endAudio;
		else
			return endAudioTable[code];
	}

	/** 查询不是转移的点之后,现在要添加上一些给定的默认音频 */
	QString getGivenAudio(QString & code) const
	{
		if(givenAudioTable.count(code) == 0)
			return QString();
		else
			return givenAudioTable[code];
	}

	void setDefaultAudioList(const QStringList & defaultList){defaultAudioList = defaultList;}
	void addDefaultAudio(const QString & audioFilename){defaultAudioList.push_back(audioFilename);}
	void removeDefaultAudio(const QString & audioFilename){defaultAudioList.removeOne(audioFilename);}
	QStringList getDefaultAudioList() const{return defaultAudioList;}


	/** 设置对应码制对应的音频 */
	void setStartTableAudio(const QString & fromCode , const QString & _startAudioTable){
		if(startAudioTable.count(fromCode) == 0)
			return;
		startAudioTable[fromCode] = _startAudioTable;
	}
	void addStartTableAudio(const QString & fromCode , const QString & audioFilename){
		startAudioTable[fromCode] = audioFilename;
	}
	void removeStartTableAudio(const QString & fromCode){
		startAudioTable.remove(fromCode);
	}
	QString getStartTableAudio(const QString & fromCode) const{
		if(startAudioTable.count(fromCode) == 0)
			return QString();
		return startAudioTable[fromCode];
	}
	QMap<QString , QString> getAllStartTableAudio() const{
		return startAudioTable;
	}
	/** 出口的音频 */
	void setEndTableAudio(const QString & toCode , const QString & _endAudioTable){
		if(endAudioTable.count(toCode) == 0)
			return;
		endAudioTable[toCode] = _endAudioTable;
	}
	void addEndTableAudio(const QString & toCode , const QString & audioFilename){
		endAudioTable[toCode] = audioFilename;
	}
	void removeEndTableAudio(const QString & toCode){
		endAudioTable.remove(toCode);
	}
	QString getEndTableAudio(const QString & toCode) const{
		if(endAudioTable.count(toCode) == 0)
			return QString();
		return endAudioTable[toCode];
	}
	QMap<QString , QString> getAllEndTableAudio() const{
		return endAudioTable;
	}
	/** 给定的音频 */
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

	/** 下面三个是用来存储对应的Node id 和 音频直接的关系 */
	QMap<QString , QString> startAudioTable;// first是上一个节点的code,second是对应的音频文件名字
	QMap<QString , QString> endAudioTable;
	QMap<QString , QString> givenAudioTable;//输入的码制不是转移码,那么就来查找这张表
	/** node的唯一ID标示 */
	QString nodeID;

	/** 为节点增加一个对应的码值 */
	QString transCode;

	/** 一个借点对应一个图片 */
	QString picture;

};

#endif
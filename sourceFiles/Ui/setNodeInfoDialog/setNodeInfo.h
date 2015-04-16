#ifndef SETNODEINFO_H
#define SETNODEINFO_H
#include "setNodeInfoDialog.h"
#include <QDialog>
#include "getTablePair.h"
#include "node.h"

class SetNodeInfo : public QDialog , public Ui::setNodeInfoDialog
{
	Q_OBJECT
public:
	SetNodeInfo(const Node * node,QWidget * parent=0);
	~SetNodeInfo(){}

	QString getNodeName() const{return nodeNameLineEdit->text();}
	QString getStartAudio() const{return startAudioLineEdit->text();}
	QString getEndAudio() const {return endAudioLineEdit->text();}
	QString getTransCode() const {return transCodeLineEdit->text();}
	QString getPictureName() const{
		if(cpMap.count(getTransCode()) == 0)
			return QString(":/images/about.png");
		return cpMap[getTransCode()];
	}

	/**
	 * 得到给定的码制对应默认音乐
	 */
	QList<QPair<QString , QString> > getGivenAudioTable() const
	{
		QList<QPair<QString , QString> > tempList;
		size_t count = givenAudioTableWidget->rowCount();
		for (size_t i = 0; i < count; ++i)
		{
			QTableWidgetItem * item1 = givenAudioTableWidget->item(i,0);
			QTableWidgetItem * item2 = givenAudioTableWidget->item(i,1);
			tempList << QPair<QString , QString>(item1->text() ,item2->text());
		}
		return tempList;
	}

private slots:
	void startAudioView();
	void endAudioView();
	
	void addGivenTableAudio();
	void deleteGivenTableAudio();

	void selectTransCode();

	void updateNodePic(const QString & text);
private:
	/** 保存cp file的内容 */
	QMap<QString , QString> cpMap;

	void updateCpMap();//这里需要重新读取cp文件的内容，更新cpMap
};



#endif
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
	QString getPictureName() const{return pictureLineEdit->text();}
	/**
	 * 得到默认音乐列表
	 * @return 返回列表
	 */
	QStringList getDefaultAudioList() const
	{
		int itemCount = defaultAudiotListWidget->count();
		QStringList defaultList;
		for (int i = 0; i < itemCount; ++i)
		{
			QListWidgetItem * temp = defaultAudiotListWidget->item(i);
			defaultList<<temp->text();
		}
		return defaultList;
	}

	/**
	 *  得到预设好的入口音乐
	 */
	QList<QPair<QString , QString> > getStartAudioTable() const
	{
		unsigned int startAudioPairCount = startAudioTableWidget->rowCount();
		QList<QPair<QString , QString> > retList;
		for (unsigned int i = 0; i < startAudioPairCount; ++i)
		{
			QTableWidgetItem * item1 = startAudioTableWidget->item(i,0);
			QTableWidgetItem * item2 = startAudioTableWidget->item(i,1);
			retList<<QPair<QString , QString>(item1->text() , item2->text());
		}
		return retList;
	}

	/**
	 * 得到预设好的出口音乐
	 */
	QList<QPair<QString , QString> > getEndAudioTable() const
	{
		unsigned int endAudioPairCount = endAudioTableWidget->rowCount();
		QList<QPair<QString , QString> > retList;
		for (unsigned int i = 0; i < endAudioPairCount; ++i)
		{
			QTableWidgetItem * item1 = endAudioTableWidget->item(i,0);
			QTableWidgetItem * item2 = endAudioTableWidget->item(i,1);
			retList<<QPair<QString , QString>(item1->text() , item2->text());
		}
		return retList;
	}

	/**
	 * 得到给定的码制对应默认音乐
	 */
	QList<QPair<QString , QString> > getGivenAudioTable() const
	{
		unsigned int givenAudioPairCount = givenAudioTableWidget->rowCount();
		QList<QPair<QString , QString> > retList;
		for (unsigned int i = 0; i < givenAudioPairCount; ++i)
		{
			QTableWidgetItem * item1 = givenAudioTableWidget->item(i,0);
			QTableWidgetItem * item2 = givenAudioTableWidget->item(i,1);
			retList<<QPair<QString , QString>(item1->text() , item2->text());
		}
		return retList;
	}
private slots:
	void startAudioView();
	void endAudioView();

	void addDefaultAudio();
	void deleteDefaultAudio();

	void pictureView();

	void addStartTableAudio();
	void deleteStartTableAudio();

	void addEndTableAudio();
	void deleteEndTableAudio();

	void addGivenTableAudio();
	void deleteGivenTableAudio();
};



#endif
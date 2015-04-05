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
	bool getSameFlag() const {return !sameFlagCheckBox->isChecked();}
	/**
	 * 得到默认音乐列表
	 * @return 返回列表
	 */
	QStringList getBeforeDefaultAudioList() const
	{
		return beforeDefaultAudioList;
	}

	QStringList getAfterDefaultAudioList() const
	{
		return afterDefaultAudioList;
	}

	/**
	 * 得到给定的码制对应默认音乐
	 */
	QList<QPair<QString , QString> > getBeforeGivenAudioTable() const
	{
		return beforeGivenAudioList;
	}

	QList<QPair<QString , QString> > getAfterGivenAudioTable() const
	{
		return afterGivenAudioList;
	}


	/** 更新一次数据 */
	void syncData()
	{
		/** 状态前和状态后是一样的 */
		if(!sameFlagCheckBox->isChecked())
			saveData(beforeGivenAudioList , beforeDefaultAudioList);
		/** 马上保存after编辑的数据 */
		else if(afterRadioButton->isChecked())
			saveData(afterGivenAudioList , afterDefaultAudioList);
		/** 马上保存before编辑的数据 */
		else if(beforeRadioButton->isChecked())
			saveData(beforeGivenAudioList , beforeDefaultAudioList);
	}
private slots:
	void startAudioView();
	void endAudioView();

	void addDefaultAudio();
	void deleteDefaultAudio();
	
	void addGivenTableAudio();
	void deleteGivenTableAudio();

	void beforeRadioToggled(bool);
	void afterRadioToggled(bool);

	void selectTransCode();

	void updateNodePic(const QString & text);
private:
	/** 应该在ｒａｄｉｏ按钮切换时候要保存对应的信息 */

	/** 保存状态前状态后的给定音频 */
	QList<QPair<QString ,QString> > afterGivenAudioList;
	QList<QPair<QString ,QString> > beforeGivenAudioList;

	/** 保存状态前状态后的默认音频 */
	QStringList beforeDefaultAudioList;
	QStringList afterDefaultAudioList;

	/** 保存cp file的内容 */
	QMap<QString , QString> cpMap;

	//从列表中读取数据保存到对应的list里面
	void saveData(QList<QPair<QString,QString> > & givenList ,\
		QStringList & defaultList);
	void showData(QList<QPair<QString, QString> > & givenList ,\
		QStringList & defaultList);
};



#endif
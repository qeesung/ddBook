#ifndef SETNODEINFO_H
#define SETNODEINFO_H
#include "setNodeInfoDialog.h"
#include <QDialog>
// #include "node.h"

class SetNodeInfo : public QDialog , public Ui::setNodeInfoDialog
{
	Q_OBJECT
public:
	SetNodeInfo(const QString & nodeName,QWidget * parent=0);
	~SetNodeInfo(){}

	QString getNodeName() const{return nodeNameLineEdit->text();}
	QString getStartAudio() const{return startAudioLineEdit->text();}
	QString getEndAudio() const {return endAudioLineEdit->text();}
	QStringList getDefaultAudioList() const
	{
		int itemCount = defaultAudioListWidget->count();
		QStringList defaultList;
		for (int i = 0; i < itemCount; ++i)
		{
			QListWidgetItem * temp = defaultAudioListWidget->item(i);
			defaultList<<temp->text()<<endl;
		}
		return defaultList;
	}
private slots:
	void startAudioView();
	void endAudioView();

	void addDefaultAudio();
	void deleteDefaultAudio();
};



#endif
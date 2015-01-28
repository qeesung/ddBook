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
private slots:
	void startAudioView();
	void endAudioView();

	void addDefaultAudio();
	void deleteDefaultAudio();
};



#endif
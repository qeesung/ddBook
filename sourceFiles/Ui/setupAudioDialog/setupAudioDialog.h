#ifndef SETUPAUDIODIALOG_G
#define SETUPAUDIODIALOG_G

#include <QDialog>
#include "ui_setupAudioDialog.h"

class SetupAudioDialog : public QDialog , public Ui::SetupAudioDialog
{
	Q_OBJECT
public:
	SetupAudioDialog(QWidget * parent=NULL);
private slots:
	/**  增加和删除audio的槽 */
	void addAudios();
	void delAduios();
	/** 保存到列表的槽 */
	void saveAlFile();

	/** 使能删除按钮的槽 */
	void enableDelPushButton();
private:
	/** 加载文件的内容 */
	void loadAlFile();
	/** 检查要添加的内容是否已经在列表里面了 */
	bool audioIsExist(const QString & , QListWidgetItem * &);

};



#endif
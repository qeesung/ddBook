#ifndef CHECKCODEAUDIODIALOG_H
#define CHECKCODEAUDIODIALOG_H

#include <QDialog>
#include "ui_checkCodeAudioDialog.h"
#include "GraphicsView.h"
#include "node.h"
#include <QProgressDialog>

class CheckCodeAudioDialog : public QDialog , public Ui::CheckCodeAudioDialog
{
	Q_OBJECT
public:
	CheckCodeAudioDialog(QList<GraphicsView * > viewList , QWidget * parent=NULL);
	enum CHECK_RESULT
	{
		USED,
		UNUSED,
		UNKNOWN
	};
private slots:
	void startCheck();
	//双击选项的动作
	void codeDoubleClicked(QListWidgetItem *);
	void audioDoubleClicked(QListWidgetItem *);
private:
	/** 保存要check那些view */
	QList<GraphicsView *> viewList;
	/** 检查码值的使用情况 */
	void checkCodeAudio();
	/** 载入文件cp file里面的内容 */
	void loadCpFile();
	void loadAlFile();
	/** 读取在所有的view里面的使用了的code */
	void loadViewCodeAudio();
	/** 在list插件里面显示 */
	void showInCodeWidget();
	void showInAudioWidget();

	/** 保存临时分析的信息 */
	QMap<QString , QStringList> usedCodeResult;//<QString：code码值 , QStringList:那些节点使用了>
	QMap<QString , QStringList> usedAsStartAudioResult;//<QString：audio , QStringList:那些节点使用了>
	QMap<QString , QStringList> usedAsEndAudioResult;//<QString：audio , QStringList:那些节点使用了>
	QMap<QString , QStringList> usedAsGivenAudioResult;//<QString：audio , QStringList:那些节点使用了>
	QMap<QString , QStringList> usedAsDeafultAudioResult;//<QString：audio , QStringList:那些节点使用了>

	/** 保存下对应的状态 */
	QMap<QString , CHECK_RESULT> codeUseState;//码值的使用情况
	QMap<QString , CHECK_RESULT> audioUseState;//音频的使用情况

	/** 保存文件里面的标准数据 */
	QSet<QString> fileCodeSet;
	QSet<QString> fileAudioSet;

	QProgressDialog * pDialog;
};	


#endif
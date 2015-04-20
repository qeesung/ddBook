#ifndef SETUPDEFAULTAUDIODIALOG_H
#define SETUPDEFAULTAUDIODIALOG_H

#include <QDialog>
#include <QMap>
#include <QTreeWidget>
#include "mainWindow.h"
#include "ui_setupDefaultAudioDialog.h"

class SetupDefaultAudioDialog : public QDialog , public Ui::SetupDefaultAudioDialog
{
	Q_OBJECT
public:
	SetupDefaultAudioDialog(QWidget * parent = NULL);
private slots:
	void addDefaultAudio();
	void deleteDefaultAudio();
	void saveDefaultAudio();
	void searchCode(const QString &);
	void updateButton(QTreeWidgetItem * , int);
private:
	QMap<QString , QString> cpMapData;
	QMap<QString , QStringList> cdMapData;
	void setAllDefaultColor();
	void setAllChildDefaultColor();
	QBrush defaultBrush;
	QBrush defaultChildBrush;
};

#endif
#ifndef SELECTCODEDIALOG_H
#define SELECTCODEDIALOG_H

#include "ui_selectCodeDialog.h"
#include <QDialog>
#include <QKeyEvent>

class SelectCodeDialog : public QDialog , public Ui::SelectCodeDialog
{
	Q_OBJECT
public:
	SelectCodeDialog(QWidget * parent = NULL);
	/** 得到基本属性 */
	QString getTransCode() const{
		return codeListWidget->selectedItems()[0]->text();//返回节点码
	}
	QString getPicture() const{
		return codeListWidget->selectedItems()[0]->icon().name();//返回图片名字
	}
protected:
	void keyPressEvent(QKeyEvent * event);
private slots:
	void createCode();
	void removeCode();
	void enableButtons();
	void setCodeInfo(const QModelIndex & );
	void searchCode(const QString & codeStr);
};


#endif
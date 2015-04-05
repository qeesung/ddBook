#ifndef SELECTCODEDIALOG_H
#define SELECTCODEDIALOG_H

#include "ui_selectCodeDialog.h"
#include <QDialog>

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
private slots:
	void createCode();
	void removeCode();
	void enableButtons();
	void setCodeInfo(const QModelIndex & );
};


#endif
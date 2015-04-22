#ifndef PREVIEWNODEWIDGET_H
#define PREVIEWNODEWIDGET_H

#include "ui_previewNodeWidget.h"
#include "node.h"
#include <QWidget>

class PreviewNodeWidget : public QWidget , public Ui::PreviewWidget
{
Q_OBJECT
public:
	PreviewNodeWidget(Node * node , QWidget * parent=NULL);
	void updateNodeInfo(Node * node);
	Node * getCurrentNode(){
		return currentNode;
	}
private:
	Node * currentNode;
};
#endif
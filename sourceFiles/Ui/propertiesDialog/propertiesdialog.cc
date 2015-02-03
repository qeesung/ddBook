#include "propertiesdialog.h"
#include <QPixmap>
#include <QDialog>
#include <QWidget>
#include <QColor>
#include <QString>
#include <QColorDialog>
#include "node.h"
#include "link.h"

PropertiesDialog::PropertiesDialog(QGraphicsScene * scene ,  Node * _node , QWidget * parent):QDialog(parent),node(_node)
{
	setupUi(this);
	//得到基本的信息
	setTextColor(node->getTextColor());
	setOutlineColor(node->getOutlineColor());
	setBackgroundColor(node->getBackgroundColor());
	spinBox->setRange(0,scene->sceneRect().width());
	spinBox_2->setRange(0,scene->sceneRect().height());
/*	setX(node->x());
	setY(node->y());*/
	spinBox->setValue(node->x());
	spinBox_2->setValue(node->y());
	lineEdit->setText(node->getText());

	connect(pushButton , SIGNAL(clicked()),this , SLOT(selectTextColor()));
	connect(pushButton_2 , SIGNAL(clicked()),this , SLOT(selectOutlineColor()));
	connect(pushButton_3 , SIGNAL(clicked()),this , SLOT(selectBackgroundColor()));
	updateColorBar();
}

void PropertiesDialog::selectTextColor()
{
	QColor color = QColorDialog::getColor(getTextColor() , this);
	if(color.isValid())
		setTextColor(color);
	updateColorBar();
}

void PropertiesDialog::selectOutlineColor()
{
	QColor color = QColorDialog::getColor(getOutlineColor() , this);
	if(color.isValid())
		setOutlineColor(color);
	updateColorBar();
}

void PropertiesDialog::selectBackgroundColor()
{
	QColor color = QColorDialog::getColor(getBackgroundColor() , this);
	if(color.isValid())
		setBackgroundColor(color);
	updateColorBar();
}


static void _updateColorBar(const QColor & color , QLabel * label)
{
	QPixmap pixmap(16,16);
	pixmap.fill(color);
	label->setPixmap(pixmap);
}
void PropertiesDialog::updateColorBar()
{
	_updateColorBar(getTextColor(), label_6);
	_updateColorBar(getOutlineColor() , label_7);
	_updateColorBar(getBackgroundColor() , label_8);
}



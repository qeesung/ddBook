#include "propertiesdialog.h"
#include <QPixmap>
#include <QDialog>
#include <QWidget>
#include <QColor>
#include <QString>
#include <QColorDialog>
#include <limits.h>
#include "node.h"
#include "link.h"

PropertiesDialog::PropertiesDialog(QGraphicsScene * scene ,  Node * _node , QWidget * parent):QDialog(parent),node(_node)
{
	setupUi(this);
	//得到基本的信息
	setTextColor(node->getTextColor());
	setOutlineColor(node->getOutlineColor());
	setBackgroundColor(node->getBackgroundColor());
	setTransCodeTextColor(node->getTransCodeTextColor());
	setTransCodeBackgroundColor(node->getTransCodeBackgroundColor());
	spinBox->setRange(INT_MIN,scene->sceneRect().width());
	spinBox_2->setRange(INT_MIN,scene->sceneRect().height());
/*	setX(node->x());
	setY(node->y());*/
	spinBox->setValue(node->scenePos().x());
	spinBox_2->setValue(node->scenePos().y());
	lineEdit->setText(node->getText());
	lineEdit_2->setText(node->getTransCode());

	connect(pushButton , SIGNAL(clicked()),this , SLOT(selectTextColor()));
	connect(pushButton_2 , SIGNAL(clicked()),this , SLOT(selectOutlineColor()));
	connect(pushButton_3 , SIGNAL(clicked()),this , SLOT(selectBackgroundColor()));
	connect(pushButton_5 , SIGNAL(clicked()),this , SLOT(selectTransCodeTextColor()));
	connect(pushButton_4 , SIGNAL(clicked()),this , SLOT(selectTransCodeBackgroundColor()));
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

void PropertiesDialog::selectTransCodeTextColor()
{
	QColor color = QColorDialog::getColor(getBackgroundColor() , this);
	if(color.isValid())
		setTransCodeTextColor(color);
	updateColorBar();
}

void PropertiesDialog::selectTransCodeBackgroundColor()
{
	QColor color = QColorDialog::getColor(getBackgroundColor() , this);
	if(color.isValid())
		setTransCodeBackgroundColor(color);
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
	_updateColorBar(getTransCodeText() , label_13);
	_updateColorBar(getTransCodeBackgroundColor() , label_14);
}



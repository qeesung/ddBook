#ifndef _PROPERTIESDIALOG_H
#define _PROPERTIESDIALOG_H

#include "ui_propertiesdialog.h"
#include <QDialog>
#include <QGraphicsScene>
class QWidget;
class Node;
class QColor;
class QString;

class PropertiesDialog :public QDialog ,  public Ui::Dialog
{
	Q_OBJECT
public:
	PropertiesDialog(QGraphicsScene * scene ,Node * node , QWidget * parent=0);
/*	void setX(const int & x){_x_pos =x;}
	void setY(const int & y){_y_pos =y;}

	int x() const{return _x_pos;}
	int y() const{return _y_pos;}*/

	void setTextColor(const QColor & color) {textColor = color;}
	void setOutlineColor(const QColor & color) {outlineColor = color;}
	void setBackgroundColor(const QColor & color) {backgroundColor = color;}
	// void setText(const QString & str){text = str;}

	QColor getTextColor() const{return textColor;}
	QColor getOutlineColor() const {return outlineColor;}
	QColor getBackgroundColor() const {return backgroundColor;}
	QString getText()const {return lineEdit->text();}

	int xValue() const {return spinBox->value();}
	int yValue() const {return spinBox_2->value();}


	void disableSetPosName()
	{
		spinBox->clear();
		spinBox_2->clear();
		spinBox->setDisabled(true);
		spinBox_2->setDisabled(true);
		lineEdit->setDisabled(true);
		lineEdit->clear();
	}

public slots:
	void selectTextColor();
	void selectOutlineColor();
	void selectBackgroundColor();
private:
	void updateColorBar();
	Node * node;
/*	int _x_pos;
	int _y_pos;*/
	QColor textColor;
	QColor outlineColor;
	QColor backgroundColor;
	// QString text;
};

#endif
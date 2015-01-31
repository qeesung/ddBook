#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

class GraphicsView : public QGraphicsView
{
public:
	GraphicsView(QWidget * parent=0);

	void newFile();
	bool save();
	bool saveAs();
	QSize sizeHint() const;
	QAction * windowMenuAction() const {return action;}

	static GraphicsView * open(QWidget * parent=0);
	static GraphicsView * openFile(const QString & filename,\
								   QWidget * parent=0);
protected:
	void closeEvent(QCloseEvent * event);
private slots:
	void documentWasModified(const QList<QRectF> &));
private:
	bool okToContinue();
	bool saveFile(const QString & filename);
	void setCurrentFile(const QString & filename);
	bool readFile(const QString & filename);
	bool writeFile(const QString & filename);
	QString strippedName(const QString & fullFilename);

	QString curFile;
	bool isUntitled;
	QAction * action;
};


#endif
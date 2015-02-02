#include "GraphicsView.h"

GraphicsView::GraphicsView(QWidget * parent):QGraphicsView(parent)
{
	action = new QAction(this);
	action->setCheckable(true);

	connect(action , SIGNAL(triggered()), this , SLOT(show()));
	connect(action , SIGNAL(triggered()), this , SLOT(setFocus()));

	isUntitled =true;

	/**  如果view里面的任何东西改变了，那么就触发该信号 */
	connect( scene(), SIGNAL(changed(const QList<QRectF> &)) , \
			 this , SLOT(documentWasModified(const QList<QRectF> &))));
	setWindowIcon(QPixMap(":/images/document.png"));
	setWindowTitle("[*]");
	setAttribute(Qt::WA_DeletedOnClose);
}

/**
 * 创建一个新mode table
 */
void GraphicsView::newFile()
{
	static int documentNumber = 1;
	curFile = tr("document%1.mt").arg(documentNumber);
	setWindowTitle(curFile+"[*]");
	action->setText(curFile);
	isUntitled = true;
	++documentNumber;
}

GraphicsView * GraphicsView::open(QWidget * parent)
{
	QString filename = QFileDialog::getOpenFileName(parent , \
													tr("Open mode table"),\
													".",\
													tr("mode table files(*.mt)"));
	if(filename.isEmpty())
		return 0;
	return openFile(filename ,parent);
}

GraphicsView * GraphicsView::openFile(const QString & filename , QWidget * parent)
{
	GraphicsView * view = new GraphicsView(parent);
	if(view->readFile(filename))
	{
		vewi->setCurrentFile(filename);
		return view;
	}
	else
	{
		delete view;
		return 0;
	}
}

bool GraphicsView::save()
{
	if(isUntitled)
		return saveAs();
	else
		return saveFile(curFile);
}


bool GraphicsView::saveAs()
{
	QString filename = QFileDialog::getSaveFileName(this ,
		tr("Save md table"),
		tr("mode table file(*.mt)"));
	if(filename.isEmpty())
		return false;
	return saveFile(filename);
}

void GraphicsView::closeEvent(QCloseEvent * event)
{
	if(okToContinue())
		event->accept();
	else
		event->ignore();
}

void GraphicsView::setCurrentFile(const QString & filename)
{
	curFile = filename;
	isUntitled = false;
	action->setText(strippedName(curFile));

	setWindowTitle(strippedName(curFile)+"[*]");
	setWindowModified(false);
}

QString GraphicsView::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}


bool GraphicsView::okToContinue()
{
    if (isWindowModified()) {
        int r = QMessageBox::warning(this, tr("ddBook assitant"),
                        tr("The document has been modified.\n"
                           "Do you want to save your changes?"),
                        QMessageBox::Yes | QMessageBox::No
                        | QMessageBox::Cancel);
        if (r == QMessageBox::Yes) {
            return save();
        } else if (r == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}


bool GraphicsView::saveFile(const QString & filename)
{
	if(!writeFile(filename))
	{
		QMessageBox::critical(0 , "Saving canceled" , "!!!!Save file failed!!!",QMessageBox::Yes);
	}
	setCurrentFile(filename);//保存的时候名字可能会被更改了
	return true;
}


bool GraphicsView::readFile()
{

}

bool GraphicsView::writeFile()
{

}





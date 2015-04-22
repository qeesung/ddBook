#include "previewNodeWidget.h"
#include <QListWidget>
#include <QTableWidget>

PreviewNodeWidget::PreviewNodeWidget(Node * node , QWidget * parent):QWidget(parent)
{
	setupUi(this);
	givenAudioTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	defaultAudioListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	updateNodeInfo(node);
}


void PreviewNodeWidget::updateNodeInfo(Node * node)
{
	givenAudioTableWidget->horizontalHeader()->setStretchLastSection(true);
	if(node == NULL)
	{
		setEnabled(false);
		return;
	}
	setEnabled(true);
	// get all node data and show them
	/** set node name */
	nodeNameLabel->setText(node->getText());
	/** set trans code */
	transCodeLabel->setText(node->getTransCode());
	/** set start audio */
	startAudioLabel->setText(node->getStartAudio());
	/** set end audio */
	endAudioLabel->setText(node->getEndAudio());
	/** show the picture */
	QPixmap pixmap(node->getPicture());
	if(pixmap.isNull())
		pictureLabel->setText(QString("<h2><i><font color=red>invalid Code</font></i></h2>"));
	else
	{
		QPixmap fitpixmap=pixmap.scaled(100,100, Qt::KeepAspectRatio);  
		pictureLabel->setPixmap(fitpixmap);
	}
	// show the given audio
	QMap<QString , QString> givenAudioTable = node->getAllGivenTableAudio();
	givenAudioTableWidget->setRowCount(givenAudioTable.count());
	unsigned int i =0;
	for(QMap<QString , QString>::iterator iter = givenAudioTable.begin() ;\
					 iter!=givenAudioTable.end() ;++iter)
	{
		QTableWidgetItem * item1 = new QTableWidgetItem(iter.key());
		QTableWidgetItem * item2 = new QTableWidgetItem(iter.value());
		givenAudioTableWidget->setItem(i , 0 , item1);
		givenAudioTableWidget->setItem(i , 1 , item2);
		++i;
	}
	// show default audio
	defaultAudioListWidget->clear();
	QStringList defaultList = node->getDefaultAudioList();
	foreach(QString str, defaultList)
	{
		QListWidgetItem * item = new QListWidgetItem(str);
		defaultAudioListWidget->insertItem(defaultAudioListWidget->count() , item);
	}
}
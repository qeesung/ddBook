#include "checkCodeAudioDialog.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QTextStream>
#include <QProgressDialog>

extern QString cpFileName;
extern QString alFileName;

CheckCodeAudioDialog::CheckCodeAudioDialog(QList<GraphicsView *> _viewList , QWidget * parent):\
QDialog(parent),viewList(_viewList)
{
	setupUi(this);
	connect(startPushButton , SIGNAL(clicked()) , this , SLOT(startCheck()));
	connect(codeReListWidget , SIGNAL(itemDoubleClicked(QListWidgetItem *)),\
		this , SLOT(codeDoubleClicked(QListWidgetItem *)));
	connect(audioReListWidget , SIGNAL(itemDoubleClicked(QListWidgetItem *)),\
		this , SLOT(audioDoubleClicked(QListWidgetItem *)));
}


void CheckCodeAudioDialog::startCheck()
{
	codeReListWidget->clear();
	audioReListWidget->clear();
	pDialog = new QProgressDialog();
	pDialog->setLabelText(QString("Checking..."));
	pDialog->setMinimum(0);
	pDialog->setMaximum(0);
	pDialog->setModal(true);
	pDialog->show();
	loadCpFile();
	loadAlFile();
	loadViewCodeAudio();
	checkCodeAudio();
	showInCodeWidget();
	showInAudioWidget();
	delete pDialog;
}

/**
 * 加载cp文件里面的标准数据
 */
void CheckCodeAudioDialog::loadCpFile()
{
	/** 把cpFile里面的东西读出来 */
	QFile cpFile(cpFileName);
	if(!cpFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox * mBox = new QMessageBox;
		mBox->setText(QString("Open file %1 failed\n file is destoried or is not existed\n").arg(cpFileName));
	}
	QTextStream cpPairInput(&cpFile);
	QString lineStr;
	while(!cpPairInput.atEnd())
	{
		lineStr = cpPairInput.readLine();//读取到文件的一行数据
		/** 一行数据的格式　code-Y(^_^)Y-picture */
		QStringList cpTemp = lineStr.split(QString("-Y(^_^)Y-"));
		QListWidgetItem * item = new QListWidgetItem(cpTemp[0], codeReListWidget);
		fileCodeSet<<cpTemp[0];//保存信息到fileCodelist里面
		item->setIcon(QIcon(cpTemp[1]));
		QFont font;
		font.setBold(true);
		font.setPointSize(15);
		item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
		item->setFont(font);
	}
	cpFile.close();
}

void CheckCodeAudioDialog::loadAlFile()
{
	/** 把alFile里面的东西读出来 */
	QFile alFile(alFileName);
	if(!alFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox * mBox = new QMessageBox;
		mBox->setText(QString("Open file %1 failed\n file is destoried or is not existed\n").arg(alFileName));
	}
	QTextStream alInput(&alFile);
	QString lineStr;
	while(!alInput.atEnd())
	{
		lineStr = alInput.readLine();//读取到文件的一行数据
		/** 一行数据的格式 */
		QListWidgetItem * item = new QListWidgetItem(lineStr, audioReListWidget);
		fileAudioSet<<lineStr;//保存信息到fileCodelist里面
	}
	alFile.close();
}

void CheckCodeAudioDialog::loadViewCodeAudio()
{
	foreach(GraphicsView * view , viewList)
	{
		QList<Node *> nodeList = view->allNodes();
		foreach(Node * node ,nodeList)
		{
			QString transCode = node->getTransCode();//得打转移码制
			/** Unknown 数据 */
			if(fileCodeSet.find(transCode) == fileCodeSet.end())
				codeUseState[transCode] = UNKNOWN;
			else// 被使用了
			{
				codeUseState[transCode] = USED;
				/** 保存被那些节点使用了 */
				usedCodeResult[transCode]<<node->getText();
			}

			QString startAudio = node->getStartAudio();
			QString endAudio = node->getEndAudio();
			QStringList defaultAudioList = node->getDefaultAudioList();
			QStringList afterDefaultAudioList = node->getAfterDefaultAudioList();

			QStringList givenAudioTable;
			{
				QMap<QString , QString> temp1 = node->getAllGivenTableAudio();
				for(QMap<QString , QString>::iterator iter = temp1.begin() ;iter!=temp1.end() ; ++iter)
				{
					givenAudioTable.push_back(iter.value());
				}
			}
			QStringList afterGivenAudioTable;
			{
				QMap<QString , QString> temp1 = node->getAllAfterGivenTableAudio();
				for(QMap<QString , QString>::iterator iter = temp1.begin(); iter != temp1.end() ; ++iter)
				{
					afterGivenAudioTable.push_back(iter.value());
				}
			}

			// start audio 
			if(!fileAudioSet.contains(startAudio))
				audioUseState[startAudio] = UNKNOWN;
			else
			{
				audioUseState[startAudio] = USED;
				usedAsStartAudioResult[startAudio]<<node->getText();
			}

			// end audio
			if(!fileAudioSet.contains(endAudio))
				audioUseState[endAudio] = UNKNOWN;
			else
			{
				audioUseState[endAudio] = USED;
				usedAsEndAudioResult[endAudio]<<node->getText();
			}
			// default audio and after defalt
			QStringList allDefaultList = defaultAudioList+afterDefaultAudioList;
			foreach(QString item , allDefaultList)
			{
				if(!fileAudioSet.contains(item))
					audioUseState[item] = UNKNOWN;
				else
				{
					audioUseState[item] = USED;
					usedAsDeafultAudioResult[item]<<node->getText();
				}
			}
			//given auido
			QStringList allGivenList = givenAudioTable+afterGivenAudioTable;
			foreach(QString item , allGivenList)
			{
				if(!fileAudioSet.contains(item))
					audioUseState[item] = UNKNOWN;
				else
				{
					audioUseState[item] = USED;
					usedAsGivenAudioResult[item]<<node->getText();
				}
			}
		}
	}
}


void CheckCodeAudioDialog::checkCodeAudio()
{
	for(QSet<QString>::iterator iter = fileCodeSet.begin() ; iter!=fileCodeSet.end() ; ++iter)
	{
		if(codeUseState.count(*iter) == 0)
		{
			/** 没有被用过 */
			codeUseState[*iter]= UNUSED;
		}
	}
	for(QSet<QString>::iterator iter = fileAudioSet.begin();iter!=fileAudioSet.end() ; ++iter)
	{
		if(audioUseState.count(*iter) == 0)
		{
			audioUseState[*iter] = UNUSED;
		}
	}
}


void CheckCodeAudioDialog::showInCodeWidget()
{
	size_t count = codeReListWidget->count();
	for (size_t i = 0; i < count; ++i)
	{
		QListWidgetItem * item = codeReListWidget->item(i);
		if(codeUseState[item->text()] == USED)
		{
			QBrush brush(QColor(124, 205, 124));
			item->setBackground(brush);
		}
		else if(codeUseState[item->text()] == UNUSED)
		{
			QBrush brush(QColor(238, 169, 184));
			item->setBackground(brush);			
		}
		item->setData(Qt::UserRole , codeUseState[item->text()]);
	}
	/** 在codeReListWidget最后面追加位置的item */
	for(QMap<QString , CHECK_RESULT>::iterator iter = codeUseState.begin();\
		iter!=codeUseState.end(); ++iter)
	{
		if(iter.value() != UNUSED && iter.value()!=USED)
		{
			QListWidgetItem * item = new QListWidgetItem(iter.key() , codeReListWidget);
			QBrush brush(QColor(191, 62, 255));
			item->setBackground(brush);
			item->setData(Qt::UserRole , UNKNOWN);
			QFont font;
			font.setBold(true);
			font.setPointSize(15);
			item->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
			item->setFont(font);
		}
	}
}

void CheckCodeAudioDialog::showInAudioWidget()
{
	size_t count = audioReListWidget->count();
	for (size_t i = 0; i < count; ++i)
	{
		QListWidgetItem * item = audioReListWidget->item(i);
		if(audioUseState[item->text()] == USED)
		{
			QBrush brush(QColor(124, 205, 124));
			item->setBackground(brush);
		}
		else if(audioUseState[item->text()] == UNUSED)
		{
			QBrush brush(QColor(238, 169, 184));
			item->setBackground(brush);			
		}
		item->setData(Qt::UserRole , audioUseState[item->text()]);
	}
	/** 在audioReListWidget最后面追加位置的item */
	for(QMap<QString , CHECK_RESULT>::iterator iter = audioUseState.begin();\
		iter!=audioUseState.end(); ++iter)
	{
		if(iter.value() != UNUSED && iter.value()!=USED)
		{
			if(iter.key().isEmpty())
				continue;
			QListWidgetItem * item = new QListWidgetItem(iter.key() , audioReListWidget);
			QBrush brush(QColor(191, 62, 255));
			item->setBackground(brush);
			item->setData(Qt::UserRole , UNKNOWN);
		}
	}
}

/** 双击codeReListWidget里面item的触发的事件 */

void CheckCodeAudioDialog::codeDoubleClicked(QListWidgetItem * item)
{
	// QListWidgetItem * item = codeReListWidget->item(index.row());
	CHECK_RESULT result = (CHECK_RESULT)item->data(Qt::UserRole).toInt();
	if(result == USED)
	{
		size_t usedCount = usedCodeResult[item->text()].count();
		QString showLine1 = QString("<b>CODE</b><br>------ %1 used by %2 nodes<br>").\
		arg(item->text()).arg(usedCount);
		QString showLine2("<b>NODES</b>:<br>");
		QStringList nodeList = usedCodeResult[item->text()];
		foreach(QString nodeName , nodeList)
		{
			showLine2 += "------ ";
			showLine2 += "<font color = red>";
			showLine2 += nodeName;
			showLine2 += "</font>";
			showLine2 += "<br>";
		}
		QString showLine = showLine1+showLine2;
		QMessageBox * mBox = new QMessageBox;
		mBox->setText(showLine);
		mBox->exec();
	}
	else if(result == UNUSED)
	{
		QMessageBox * mBox = new QMessageBox();
		mBox->setText(QString("The <b>CODE</b> %1 has not been used<br>").arg(item->text())); 
		mBox->exec();
	}
	else if(result == UNKNOWN)
	{
		QMessageBox * mBox = new QMessageBox();
		mBox->setText(QString("The <b>CODE</b> %1 is not in the list<br>").arg(item->text())); 
		mBox->exec();
	}
}

void CheckCodeAudioDialog::audioDoubleClicked(QListWidgetItem * item)
{
	// QListWidgetItem * item = audioReListWidget->item(index.row());
	CHECK_RESULT result = (CHECK_RESULT)item->data(Qt::UserRole).toInt();
	if(result == USED)
	{
		QString audio = item->text();
		size_t t1 = usedAsStartAudioResult[audio].count();
		size_t t2 = usedAsEndAudioResult[audio].count();
		size_t t3 = usedAsGivenAudioResult[audio].count();
		size_t t4 = usedAsDeafultAudioResult[audio].count();

		QString showLine1 = QString("<b>Audio</b><br>------ <font color = teal>%1 used %2+%3+%4+%5 = %6 times</font><br>").\
		arg(audio).arg(t1).arg(t2).arg(t3).arg(t4).arg(t1+t2+t3+t4);

		// start audio
		QString showLine2 = QString("used as <b>Start Audio</b> %1 times<br>").arg(t1);
		QString tempLine;
		QStringList tempList = usedAsStartAudioResult[audio];
		foreach(QString str , tempList)
		{
			tempLine += "------ ";
			tempLine += "<font color = red>";
			tempLine += str;
			tempLine += "</font>";
			tempLine += "<br>";
		}
		showLine2+=tempLine;
		tempLine = QString();
		// end audio
		QString showLine3 = QString("used as <b>End Audio</b> %1 times<br>").arg(t2);
		tempList = usedAsEndAudioResult[audio];
		foreach(QString str , tempList)
		{
			tempLine += "------ ";
			tempLine += "<font color = blue>";
			tempLine += str;
			tempLine += "</font>";
			tempLine += "<br>";
		}
		showLine3+=tempLine;
		tempLine = QString();
		// given auido
		QString showLine4 = QString("used as <b>Given Audio</b> %1 times<br>").arg(t3);
		tempList = usedAsGivenAudioResult[audio];
		foreach(QString str , tempList)
		{
			tempLine += "------ ";
			tempLine += "<font color = green>";
			tempLine += str;
			tempLine += "</font>";
			tempLine += "<br>";
		}
		showLine4+=tempLine;
		tempLine = QString();
		//default audio
		QString showLine5 = QString("used as <b>Default Audio</b> %1 times<br>").arg(t4);
		tempList = usedAsDeafultAudioResult[audio];
		foreach(QString str , tempList)
		{
			tempLine += "------ ";
			tempLine += "<font color = purple>";
			tempLine += str;
			tempLine += "</font>";
			tempLine += "<br>";
		}
		showLine5+=tempLine;
		tempLine = QString();

		tempLine=showLine1+showLine2+showLine3+showLine4+showLine5;
		QMessageBox * mBox = new QMessageBox;
		mBox->setText(tempLine);
		mBox->exec();
	}
	else if(result == UNUSED)
	{
		QMessageBox * mBox = new QMessageBox();
		mBox->setText(QString("The <b>AUDIO</b> %1 has not been used<br>").arg(item->text())); 
		mBox->exec();
	}
	else if(result == UNKNOWN)
	{
		QMessageBox * mBox = new QMessageBox();
		mBox->setText(QString("The <b>AUDIO</b> %1 is not in the list<br>").arg(item->text())); 
		mBox->exec();
	}
}


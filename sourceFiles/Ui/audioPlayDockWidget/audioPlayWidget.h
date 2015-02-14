#ifndef AUDIOPLAYWIDGET_H
#define AUDIOPLAYWIDGET_H

#include <phonon>
#include <QWidget>
#include "ui_audioPlayWidget.h"
#include "node.h"
#include "link.h"

class AudioPlayWidget : public QWidget , public Ui::AudioPlayWidget
{
	Q_OBJECT
public:
	AudioPlayWidget(Node * node ,  QWidget * parent =0);

	void setNode(Node * node){curNode = node;}
	Node * getNode()const {return curNode;}

	void playStartAudio();
	void playEndAudio();
	void playDefaultAudio();

	void transToNewNode(Node * node)
	{
		setNode(node);
	    startAudio = node->getStartAudio();
	    endAudio = node->getEndAudio();
	    defaultAudioList = node->getDefaultAudioList();
	}

	int getInput(){return lineEdit->text().isEmpty()?0:lineEdit->text().toInt();}
	void resetWaitStatus(){waitEnterStatus =true;}
	bool waitForInput(){return waitEnterStatus;}

	void enqueueStartAudio()
	{
		mediaObject->clearQueue();
		mediaObject->setQueue(QList<Phonon::MediaSource>()<<Phonon::MediaSource(startAudio));
	}

	QList<Phonon::MediaSource> queue() const
	{
		return mediaObject->queue();
	}

	Phonon::State getPlayStatus() const{return mediaObject->state();}

private slots:
	void playOrPauseAudio();
	void enterTransButton();
	void audioChanged(const Phonon::MediaSource &);
	void audioStoped();
private:
	/**
	 * 更新播放的按钮
	 */
	void updatePlayButton();
	QStringList::iterator curIter;

    Phonon::MediaObject *mediaObject;  
    Phonon::AudioOutput *audioOutput; 

    Node * curNode;//当前调试的节点

    QString startAudio;
    QString endAudio;
    QStringList defaultAudioList;

    bool waitEnterStatus;
};


#endif
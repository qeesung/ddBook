#include "audioPlayWidget.h"
#include <stdlib.h>
#include <ctime>
#include <QRegExp>
#include <QRegExpValidator>

AudioPlayWidget::AudioPlayWidget(Node * node ,  QWidget * parent):QWidget(parent)
{
	setupUi(this);

	curNode = node;

	/** 只能输入数字的转移码 */
	QRegExp reg("[0-9]+");
	lineEdit->setValidator(new QRegExpValidator(reg , this));

	mediaObject = new Phonon::MediaObject(this);
	audioOutput = new Phonon::AudioOutput(this);  

    Phonon::createPath(mediaObject, audioOutput);  
    seekSlider->setMediaObject(mediaObject);

    startAudio = node->getStartAudio();
    endAudio = node->getEndAudio();
    defaultAudioList = node->getDefaultAudioList();

    mediaObject->setCurrentSource(startAudio);
	playButton->setIcon(QIcon(":images/playAudio.png"));
	waitEnterStatus = true;//用来等待用户的输入
    // playStartAudio();
	connect(playButton , SIGNAL(clicked()) , this , SLOT(playOrPauseAudio()));
	connect(stopButton , SIGNAL(clicked()) , mediaObject , SLOT(stop()));
	connect(transButton , SIGNAL(clicked()) , this , SLOT(enterTransButton()));
	connect(mediaObject , SIGNAL(currentSourceChanged ( const Phonon::MediaSource &)) ,\
			 this , SLOT(audioChanged(const Phonon::MediaSource &)));
	connect(mediaObject , SIGNAL(finished()) , this , SLOT(audioStoped()));
}


void AudioPlayWidget::playStartAudio()
{
	mediaObject->stop();
	audioKindLabel->setText("<font color=green>Begin Audio:</font>");
	if(startAudio.isEmpty())
	{
		showLabel->setText("None");
		return;
	}
	mediaObject->setCurrentSource(startAudio);
	showLabel->setText(startAudio);
	mediaObject->play();
}

void AudioPlayWidget::playDefaultAudio()
{
	mediaObject->stop();
	//在默认列表里面取得一个默认的播放名字
	srand((unsigned)time(0));
	if(defaultAudioList.count() == 0)
		return;
	QString randomAudioName = defaultAudioList[rand() % defaultAudioList.count()];
	audioKindLabel->setText("<font color=blue>Default Audio:</font>");
	if(randomAudioName.isEmpty())
	{
		showLabel->setText("None");
		return;
	}
	showLabel->setText(randomAudioName);
	mediaObject->setCurrentSource(randomAudioName);
	mediaObject->play();
}

void AudioPlayWidget::playEndAudio()
{
	mediaObject->stop();
	audioKindLabel->setText("<font color=red>End Audio:</font>");
	if(endAudio.isEmpty())
	{
		showLabel->setText("None");
		return;
	}
	mediaObject->setCurrentSource(endAudio);
	showLabel->setText(endAudio);
	mediaObject->play();
}

void AudioPlayWidget::playGivenAudio(const QString & givenCode)
{
	mediaObject->stop();
	audioKindLabel->setText("<font color=yellow>Given Audio:</font>");
	QString givenAudio = curNode->getAllGivenTableAudio()[givenCode];
	mediaObject->setCurrentSource(givenAudio);
	showLabel->setText(givenAudio);
	mediaObject->play();
}


void AudioPlayWidget::playOrPauseAudio()
{
	if(mediaObject->state() == Phonon::PlayingState)
	{
		playButton->setIcon(QIcon(":images/playAudio.png"));
		playButton->setIconSize(QSize(32,32));
		mediaObject->pause();
	}
	else
	{
		playButton->setIcon(QIcon(":images/pauseAudio.png"));
		playButton->setIconSize(QSize(32,32));
		mediaObject->play();
	}
}

void AudioPlayWidget::enterTransButton()
{
	waitEnterStatus = false;
}


void AudioPlayWidget::audioChanged(const Phonon::MediaSource & mediaSource)
{
	if(mediaSource.fileName() == startAudio)
	{
		showLabel->setText(startAudio);
		audioKindLabel->setText("<font color=green>Begin Audio:</font>");
	}
	else if(mediaSource.fileName() == endAudio)
	{
		audioKindLabel->setText("<font color=red>End Audio:</font>");
		showLabel->setText(endAudio);
	}
}	


void AudioPlayWidget::audioStoped()
{
	playButton->setIcon(QIcon(":images/playAudio.png"));
	playButton->setIconSize(QSize(32,32));
	mediaObject->stop();
}


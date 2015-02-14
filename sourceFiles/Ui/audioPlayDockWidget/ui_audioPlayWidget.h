/********************************************************************************
** Form generated from reading UI file 'audioPlayWidget.ui'
**
** Created: Wed Feb 11 21:07:42 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOPLAYWIDGET_H
#define UI_AUDIOPLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <phonon/seekslider.h>

QT_BEGIN_NAMESPACE

class Ui_AudioPlayWidget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *audioKindLabel;
    QLabel *showLabel;
    Phonon::SeekSlider *seekSlider;
    QHBoxLayout *horizontalLayout;
    QPushButton *playButton;
    QPushButton *stopButton;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QPushButton *transButton;

    void setupUi(QWidget *AudioPlayWidget)
    {
        if (AudioPlayWidget->objectName().isEmpty())
            AudioPlayWidget->setObjectName(QString::fromUtf8("AudioPlayWidget"));
        AudioPlayWidget->resize(758, 80);
        horizontalLayout_3 = new QHBoxLayout(AudioPlayWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        audioKindLabel = new QLabel(AudioPlayWidget);
        audioKindLabel->setObjectName(QString::fromUtf8("audioKindLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(audioKindLabel->sizePolicy().hasHeightForWidth());
        audioKindLabel->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(audioKindLabel);

        showLabel = new QLabel(AudioPlayWidget);
        showLabel->setObjectName(QString::fromUtf8("showLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(showLabel->sizePolicy().hasHeightForWidth());
        showLabel->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(showLabel);


        verticalLayout_2->addLayout(horizontalLayout_2);

        seekSlider = new Phonon::SeekSlider(AudioPlayWidget);
        seekSlider->setObjectName(QString::fromUtf8("seekSlider"));
        sizePolicy1.setHeightForWidth(seekSlider->sizePolicy().hasHeightForWidth());
        seekSlider->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(seekSlider);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        playButton = new QPushButton(AudioPlayWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/playAudio.png"), QSize(), QIcon::Normal, QIcon::Off);
        playButton->setIcon(icon);
        playButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(playButton);

        stopButton = new QPushButton(AudioPlayWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/stopAudio.png"), QSize(), QIcon::Normal, QIcon::Off);
        stopButton->setIcon(icon1);
        stopButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(stopButton);


        horizontalLayout_3->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(AudioPlayWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMaximumSize(QSize(85, 16777215));

        verticalLayout->addWidget(lineEdit);

        transButton = new QPushButton(AudioPlayWidget);
        transButton->setObjectName(QString::fromUtf8("transButton"));
        sizePolicy.setHeightForWidth(transButton->sizePolicy().hasHeightForWidth());
        transButton->setSizePolicy(sizePolicy);
        transButton->setDefault(true);

        verticalLayout->addWidget(transButton);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(AudioPlayWidget);

        QMetaObject::connectSlotsByName(AudioPlayWidget);
    } // setupUi

    void retranslateUi(QWidget *AudioPlayWidget)
    {
        AudioPlayWidget->setWindowTitle(QApplication::translate("AudioPlayWidget", "Form", 0, QApplication::UnicodeUTF8));
        audioKindLabel->setText(QApplication::translate("AudioPlayWidget", "Begin Audio:", 0, QApplication::UnicodeUTF8));
        showLabel->setText(QApplication::translate("AudioPlayWidget", "...", 0, QApplication::UnicodeUTF8));
        playButton->setText(QString());
        stopButton->setText(QString());
        transButton->setText(QApplication::translate("AudioPlayWidget", "  TRANS  ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AudioPlayWidget: public Ui_AudioPlayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOPLAYWIDGET_H

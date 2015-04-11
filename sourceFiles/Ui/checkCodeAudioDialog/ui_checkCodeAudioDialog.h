/********************************************************************************
** Form generated from reading UI file 'checkCodeAudioDialog.ui'
**
** Created: Sat Apr 11 18:28:16 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKCODEAUDIODIALOG_H
#define UI_CHECKCODEAUDIODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CheckCodeAudioDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QListWidget *codeReListWidget;
    QListWidget *audioReListWidget;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startPushButton;
    QPushButton *closePushButton;

    void setupUi(QDialog *CheckCodeAudioDialog)
    {
        if (CheckCodeAudioDialog->objectName().isEmpty())
            CheckCodeAudioDialog->setObjectName(QString::fromUtf8("CheckCodeAudioDialog"));
        CheckCodeAudioDialog->resize(720, 545);
        verticalLayout_2 = new QVBoxLayout(CheckCodeAudioDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(CheckCodeAudioDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(CheckCodeAudioDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        codeReListWidget = new QListWidget(CheckCodeAudioDialog);
        codeReListWidget->setObjectName(QString::fromUtf8("codeReListWidget"));

        gridLayout->addWidget(codeReListWidget, 1, 0, 1, 1);

        audioReListWidget = new QListWidget(CheckCodeAudioDialog);
        audioReListWidget->setObjectName(QString::fromUtf8("audioReListWidget"));

        gridLayout->addWidget(audioReListWidget, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(CheckCodeAudioDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        label_6 = new QLabel(CheckCodeAudioDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(124, 205, 124);\n"
"background-color:  rgb(124, 205, 124);"));

        horizontalLayout->addWidget(label_6);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(CheckCodeAudioDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        label_7 = new QLabel(CheckCodeAudioDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 169, 184);\n"
"color: rgb(238, 169, 184);"));

        horizontalLayout_2->addWidget(label_7);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(CheckCodeAudioDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        label_8 = new QLabel(CheckCodeAudioDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("background-color: rgb(191, 62, 255);\n"
"color: rgb(191, 62, 255);"));

        horizontalLayout_3->addWidget(label_8);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        startPushButton = new QPushButton(CheckCodeAudioDialog);
        startPushButton->setObjectName(QString::fromUtf8("startPushButton"));

        horizontalLayout_5->addWidget(startPushButton);

        closePushButton = new QPushButton(CheckCodeAudioDialog);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));

        horizontalLayout_5->addWidget(closePushButton);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CheckCodeAudioDialog);
        QObject::connect(closePushButton, SIGNAL(clicked()), CheckCodeAudioDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CheckCodeAudioDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckCodeAudioDialog)
    {
        CheckCodeAudioDialog->setWindowTitle(QApplication::translate("CheckCodeAudioDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CheckCodeAudioDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Code check result:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CheckCodeAudioDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Audio check result:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CheckCodeAudioDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Used:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CheckCodeAudioDialog", "-------", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CheckCodeAudioDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Unused:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("CheckCodeAudioDialog", "-------", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CheckCodeAudioDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Unknown</span><span style=\" font-size:12pt; font-weight:600;\">:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("CheckCodeAudioDialog", "-------", 0, QApplication::UnicodeUTF8));
        startPushButton->setText(QApplication::translate("CheckCodeAudioDialog", "start", 0, QApplication::UnicodeUTF8));
        closePushButton->setText(QApplication::translate("CheckCodeAudioDialog", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CheckCodeAudioDialog: public Ui_CheckCodeAudioDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKCODEAUDIODIALOG_H

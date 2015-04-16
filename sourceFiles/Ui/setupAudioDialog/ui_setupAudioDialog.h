/********************************************************************************
** Form generated from reading UI file 'setupAudioDialog.ui'
**
** Created: Sat Apr 11 12:05:15 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPAUDIODIALOG_H
#define UI_SETUPAUDIODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SetupAudioDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addPushButton;
    QPushButton *delPushButton;
    QLabel *label;
    QLabel *alFilenameLabel;
    QSpacerItem *horizontalSpacer;
    QListWidget *audioListWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *savePushButton;
    QPushButton *closePushButton;

    void setupUi(QDialog *SetupAudioDialog)
    {
        if (SetupAudioDialog->objectName().isEmpty())
            SetupAudioDialog->setObjectName(QString::fromUtf8("SetupAudioDialog"));
        SetupAudioDialog->resize(482, 396);
        verticalLayout_2 = new QVBoxLayout(SetupAudioDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addPushButton = new QPushButton(SetupAudioDialog);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        horizontalLayout_2->addWidget(addPushButton);

        delPushButton = new QPushButton(SetupAudioDialog);
        delPushButton->setObjectName(QString::fromUtf8("delPushButton"));

        horizontalLayout_2->addWidget(delPushButton);

        label = new QLabel(SetupAudioDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        alFilenameLabel = new QLabel(SetupAudioDialog);
        alFilenameLabel->setObjectName(QString::fromUtf8("alFilenameLabel"));

        horizontalLayout_2->addWidget(alFilenameLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        audioListWidget = new QListWidget(SetupAudioDialog);
        audioListWidget->setObjectName(QString::fromUtf8("audioListWidget"));

        verticalLayout->addWidget(audioListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        savePushButton = new QPushButton(SetupAudioDialog);
        savePushButton->setObjectName(QString::fromUtf8("savePushButton"));

        horizontalLayout->addWidget(savePushButton);

        closePushButton = new QPushButton(SetupAudioDialog);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));

        horizontalLayout->addWidget(closePushButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SetupAudioDialog);
        QObject::connect(closePushButton, SIGNAL(clicked()), SetupAudioDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetupAudioDialog);
    } // setupUi

    void retranslateUi(QDialog *SetupAudioDialog)
    {
        SetupAudioDialog->setWindowTitle(QApplication::translate("SetupAudioDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        addPushButton->setText(QApplication::translate("SetupAudioDialog", "Add", 0, QApplication::UnicodeUTF8));
        delPushButton->setText(QApplication::translate("SetupAudioDialog", "Del", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SetupAudioDialog", "Current al file:", 0, QApplication::UnicodeUTF8));
        alFilenameLabel->setText(QApplication::translate("SetupAudioDialog", "al file name", 0, QApplication::UnicodeUTF8));
        savePushButton->setText(QApplication::translate("SetupAudioDialog", "Save", 0, QApplication::UnicodeUTF8));
        closePushButton->setText(QApplication::translate("SetupAudioDialog", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetupAudioDialog: public Ui_SetupAudioDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPAUDIODIALOG_H

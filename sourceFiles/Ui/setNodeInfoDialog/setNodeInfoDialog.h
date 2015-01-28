/********************************************************************************
** Form generated from reading UI file 'setNodeInfoDialog.ui'
**
** Created: Wed Jan 28 14:13:23 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SETNODEINFODIALOG_H
#define SETNODEINFODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_setNodeInfoDialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *nodeNameLineEdit;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *startAudioLineEdit;
    QLineEdit *endAudioLineEdit;
    QVBoxLayout *verticalLayout;
    QPushButton *startAudioPushButton;
    QPushButton *endAudioPushButton;
    QLabel *label_3;
    QListWidget *defaultAudioListWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addPushButton;
    QPushButton *deletePushButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelPushButton;
    QPushButton *okPushButton;

    void setupUi(QDialog *setNodeInfoDialog)
    {
        if (setNodeInfoDialog->objectName().isEmpty())
            setNodeInfoDialog->setObjectName(QString::fromUtf8("setNodeInfoDialog"));
        setNodeInfoDialog->resize(379, 388);
        gridLayout = new QGridLayout(setNodeInfoDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(setNodeInfoDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        nodeNameLineEdit = new QLineEdit(setNodeInfoDialog);
        nodeNameLineEdit->setObjectName(QString::fromUtf8("nodeNameLineEdit"));

        horizontalLayout_5->addWidget(nodeNameLineEdit);


        verticalLayout_7->addLayout(horizontalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(setNodeInfoDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(setNodeInfoDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_3->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        startAudioLineEdit = new QLineEdit(setNodeInfoDialog);
        startAudioLineEdit->setObjectName(QString::fromUtf8("startAudioLineEdit"));

        verticalLayout_2->addWidget(startAudioLineEdit);

        endAudioLineEdit = new QLineEdit(setNodeInfoDialog);
        endAudioLineEdit->setObjectName(QString::fromUtf8("endAudioLineEdit"));

        verticalLayout_2->addWidget(endAudioLineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        startAudioPushButton = new QPushButton(setNodeInfoDialog);
        startAudioPushButton->setObjectName(QString::fromUtf8("startAudioPushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startAudioPushButton->sizePolicy().hasHeightForWidth());
        startAudioPushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(startAudioPushButton);

        endAudioPushButton = new QPushButton(setNodeInfoDialog);
        endAudioPushButton->setObjectName(QString::fromUtf8("endAudioPushButton"));
        sizePolicy.setHeightForWidth(endAudioPushButton->sizePolicy().hasHeightForWidth());
        endAudioPushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(endAudioPushButton);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout);

        label_3 = new QLabel(setNodeInfoDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_4->addWidget(label_3);

        defaultAudioListWidget = new QListWidget(setNodeInfoDialog);
        defaultAudioListWidget->setObjectName(QString::fromUtf8("defaultAudioListWidget"));

        verticalLayout_4->addWidget(defaultAudioListWidget);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addPushButton = new QPushButton(setNodeInfoDialog);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        horizontalLayout_2->addWidget(addPushButton);

        deletePushButton = new QPushButton(setNodeInfoDialog);
        deletePushButton->setObjectName(QString::fromUtf8("deletePushButton"));

        horizontalLayout_2->addWidget(deletePushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cancelPushButton = new QPushButton(setNodeInfoDialog);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        horizontalLayout_3->addWidget(cancelPushButton);

        okPushButton = new QPushButton(setNodeInfoDialog);
        okPushButton->setObjectName(QString::fromUtf8("okPushButton"));

        horizontalLayout_3->addWidget(okPushButton);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_4);


        verticalLayout_7->addLayout(verticalLayout_6);


        gridLayout->addLayout(verticalLayout_7, 0, 0, 1, 1);


        retranslateUi(setNodeInfoDialog);

        QMetaObject::connectSlotsByName(setNodeInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *setNodeInfoDialog)
    {
        setNodeInfoDialog->setWindowTitle(QApplication::translate("setNodeInfoDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("setNodeInfoDialog", "Node name:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("setNodeInfoDialog", "Start Audio:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("setNodeInfoDialog", "End Audio:", 0, QApplication::UnicodeUTF8));
        startAudioPushButton->setText(QApplication::translate("setNodeInfoDialog", "...", 0, QApplication::UnicodeUTF8));
        endAudioPushButton->setText(QApplication::translate("setNodeInfoDialog", "...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("setNodeInfoDialog", "Default Audio:", 0, QApplication::UnicodeUTF8));
        addPushButton->setText(QApplication::translate("setNodeInfoDialog", "add", 0, QApplication::UnicodeUTF8));
        deletePushButton->setText(QApplication::translate("setNodeInfoDialog", "delete", 0, QApplication::UnicodeUTF8));
        cancelPushButton->setText(QApplication::translate("setNodeInfoDialog", "CANCEL", 0, QApplication::UnicodeUTF8));
        okPushButton->setText(QApplication::translate("setNodeInfoDialog", "  OK  ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class setNodeInfoDialog: public Ui_setNodeInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SETNODEINFODIALOG_H

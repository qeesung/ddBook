/********************************************************************************
** Form generated from reading UI file 'setupCodeDialog.ui'
**
** Created: Wed Apr 8 16:42:36 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPCODEDIALOG_H
#define UI_SETUPCODEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SetupCodeDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *newPushButton;
    QPushButton *delPushButton;
    QSpacerItem *horizontalSpacer;
    QListWidget *codeListWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *savePushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *SetupCodeDialog)
    {
        if (SetupCodeDialog->objectName().isEmpty())
            SetupCodeDialog->setObjectName(QString::fromUtf8("SetupCodeDialog"));
        SetupCodeDialog->resize(290, 523);
        verticalLayout_2 = new QVBoxLayout(SetupCodeDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        newPushButton = new QPushButton(SetupCodeDialog);
        newPushButton->setObjectName(QString::fromUtf8("newPushButton"));

        horizontalLayout_2->addWidget(newPushButton);

        delPushButton = new QPushButton(SetupCodeDialog);
        delPushButton->setObjectName(QString::fromUtf8("delPushButton"));

        horizontalLayout_2->addWidget(delPushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        codeListWidget = new QListWidget(SetupCodeDialog);
        codeListWidget->setObjectName(QString::fromUtf8("codeListWidget"));

        verticalLayout->addWidget(codeListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        savePushButton = new QPushButton(SetupCodeDialog);
        savePushButton->setObjectName(QString::fromUtf8("savePushButton"));

        horizontalLayout->addWidget(savePushButton);

        cancelPushButton = new QPushButton(SetupCodeDialog);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        horizontalLayout->addWidget(cancelPushButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SetupCodeDialog);
        QObject::connect(cancelPushButton, SIGNAL(clicked()), SetupCodeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetupCodeDialog);
    } // setupUi

    void retranslateUi(QDialog *SetupCodeDialog)
    {
        SetupCodeDialog->setWindowTitle(QApplication::translate("SetupCodeDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        newPushButton->setText(QApplication::translate("SetupCodeDialog", "New", 0, QApplication::UnicodeUTF8));
        delPushButton->setText(QApplication::translate("SetupCodeDialog", "Del", 0, QApplication::UnicodeUTF8));
        savePushButton->setText(QApplication::translate("SetupCodeDialog", "Save", 0, QApplication::UnicodeUTF8));
        cancelPushButton->setText(QApplication::translate("SetupCodeDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetupCodeDialog: public Ui_SetupCodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPCODEDIALOG_H

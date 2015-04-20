/********************************************************************************
** Form generated from reading UI file 'setupDefaultAudioDialog.ui'
**
** Created: Sun Apr 19 21:41:28 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPDEFAULTAUDIODIALOG_H
#define UI_SETUPDEFAULTAUDIODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SetupDefaultAudioDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *addPushButton;
    QPushButton *delPushButton;
    QLineEdit *searchLineEdit;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *savePushButton;
    QPushButton *closePushButton;

    void setupUi(QDialog *SetupDefaultAudioDialog)
    {
        if (SetupDefaultAudioDialog->objectName().isEmpty())
            SetupDefaultAudioDialog->setObjectName(QString::fromUtf8("SetupDefaultAudioDialog"));
        SetupDefaultAudioDialog->resize(400, 431);
        verticalLayout_2 = new QVBoxLayout(SetupDefaultAudioDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addPushButton = new QPushButton(SetupDefaultAudioDialog);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        horizontalLayout->addWidget(addPushButton);

        delPushButton = new QPushButton(SetupDefaultAudioDialog);
        delPushButton->setObjectName(QString::fromUtf8("delPushButton"));

        horizontalLayout->addWidget(delPushButton);

        searchLineEdit = new QLineEdit(SetupDefaultAudioDialog);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout->addWidget(searchLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        treeWidget = new QTreeWidget(SetupDefaultAudioDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        savePushButton = new QPushButton(SetupDefaultAudioDialog);
        savePushButton->setObjectName(QString::fromUtf8("savePushButton"));

        horizontalLayout_2->addWidget(savePushButton);

        closePushButton = new QPushButton(SetupDefaultAudioDialog);
        closePushButton->setObjectName(QString::fromUtf8("closePushButton"));

        horizontalLayout_2->addWidget(closePushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SetupDefaultAudioDialog);
        QObject::connect(closePushButton, SIGNAL(clicked()), SetupDefaultAudioDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetupDefaultAudioDialog);
    } // setupUi

    void retranslateUi(QDialog *SetupDefaultAudioDialog)
    {
        SetupDefaultAudioDialog->setWindowTitle(QApplication::translate("SetupDefaultAudioDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        addPushButton->setText(QApplication::translate("SetupDefaultAudioDialog", "Add", 0, QApplication::UnicodeUTF8));
        delPushButton->setText(QApplication::translate("SetupDefaultAudioDialog", "Del", 0, QApplication::UnicodeUTF8));
        savePushButton->setText(QApplication::translate("SetupDefaultAudioDialog", "Save", 0, QApplication::UnicodeUTF8));
        closePushButton->setText(QApplication::translate("SetupDefaultAudioDialog", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SetupDefaultAudioDialog: public Ui_SetupDefaultAudioDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPDEFAULTAUDIODIALOG_H

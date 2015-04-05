/********************************************************************************
** Form generated from reading UI file 'selectCodeDialog.ui'
**
** Created: Sun Apr 5 19:37:19 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTCODEDIALOG_H
#define UI_SELECTCODEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SelectCodeDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *newPushButton;
    QPushButton *delPushButton;
    QLineEdit *searchLineEdit;
    QListWidget *codeListWidget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *SelectCodeDialog)
    {
        if (SelectCodeDialog->objectName().isEmpty())
            SelectCodeDialog->setObjectName(QString::fromUtf8("SelectCodeDialog"));
        SelectCodeDialog->resize(338, 511);
        verticalLayout_2 = new QVBoxLayout(SelectCodeDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newPushButton = new QPushButton(SelectCodeDialog);
        newPushButton->setObjectName(QString::fromUtf8("newPushButton"));

        horizontalLayout->addWidget(newPushButton);

        delPushButton = new QPushButton(SelectCodeDialog);
        delPushButton->setObjectName(QString::fromUtf8("delPushButton"));

        horizontalLayout->addWidget(delPushButton);

        searchLineEdit = new QLineEdit(SelectCodeDialog);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));

        horizontalLayout->addWidget(searchLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        codeListWidget = new QListWidget(SelectCodeDialog);
        codeListWidget->setObjectName(QString::fromUtf8("codeListWidget"));

        verticalLayout->addWidget(codeListWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okPushButton = new QPushButton(SelectCodeDialog);
        okPushButton->setObjectName(QString::fromUtf8("okPushButton"));

        horizontalLayout_2->addWidget(okPushButton);

        cancelPushButton = new QPushButton(SelectCodeDialog);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        horizontalLayout_2->addWidget(cancelPushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SelectCodeDialog);
        QObject::connect(okPushButton, SIGNAL(clicked()), SelectCodeDialog, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), SelectCodeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SelectCodeDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectCodeDialog)
    {
        SelectCodeDialog->setWindowTitle(QApplication::translate("SelectCodeDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        newPushButton->setText(QApplication::translate("SelectCodeDialog", "New", 0, QApplication::UnicodeUTF8));
        delPushButton->setText(QApplication::translate("SelectCodeDialog", "Del", 0, QApplication::UnicodeUTF8));
        okPushButton->setText(QApplication::translate("SelectCodeDialog", "Ok", 0, QApplication::UnicodeUTF8));
        cancelPushButton->setText(QApplication::translate("SelectCodeDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SelectCodeDialog: public Ui_SelectCodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTCODEDIALOG_H

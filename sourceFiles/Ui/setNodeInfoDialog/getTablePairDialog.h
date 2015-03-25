/********************************************************************************
** Form generated from reading UI file 'getTablePairDialog.ui'
**
** Created: Wed Mar 25 17:08:33 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef GETTABLEPAIRDIALOG_H
#define GETTABLEPAIRDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_getTablePairDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *codeLineEdit;
    QLabel *label_2;
    QLineEdit *fileLineEdit;
    QPushButton *viewFilePushButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelPushButton;
    QPushButton *okPushButton;

    void setupUi(QDialog *getTablePairDialog)
    {
        if (getTablePairDialog->objectName().isEmpty())
            getTablePairDialog->setObjectName(QString::fromUtf8("getTablePairDialog"));
        getTablePairDialog->resize(475, 84);
        verticalLayout_2 = new QVBoxLayout(getTablePairDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(getTablePairDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        codeLineEdit = new QLineEdit(getTablePairDialog);
        codeLineEdit->setObjectName(QString::fromUtf8("codeLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(codeLineEdit->sizePolicy().hasHeightForWidth());
        codeLineEdit->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(codeLineEdit);

        label_2 = new QLabel(getTablePairDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        fileLineEdit = new QLineEdit(getTablePairDialog);
        fileLineEdit->setObjectName(QString::fromUtf8("fileLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fileLineEdit->sizePolicy().hasHeightForWidth());
        fileLineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(fileLineEdit);

        viewFilePushButton = new QPushButton(getTablePairDialog);
        viewFilePushButton->setObjectName(QString::fromUtf8("viewFilePushButton"));

        horizontalLayout->addWidget(viewFilePushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancelPushButton = new QPushButton(getTablePairDialog);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        horizontalLayout_2->addWidget(cancelPushButton);

        okPushButton = new QPushButton(getTablePairDialog);
        okPushButton->setObjectName(QString::fromUtf8("okPushButton"));

        horizontalLayout_2->addWidget(okPushButton);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(getTablePairDialog);
        QObject::connect(okPushButton, SIGNAL(clicked()), getTablePairDialog, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), getTablePairDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(getTablePairDialog);
    } // setupUi

    void retranslateUi(QDialog *getTablePairDialog)
    {
        getTablePairDialog->setWindowTitle(QApplication::translate("getTablePairDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("getTablePairDialog", "Code:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("getTablePairDialog", "File", 0, QApplication::UnicodeUTF8));
        viewFilePushButton->setText(QApplication::translate("getTablePairDialog", "...", 0, QApplication::UnicodeUTF8));
        cancelPushButton->setText(QApplication::translate("getTablePairDialog", "CANCEL", 0, QApplication::UnicodeUTF8));
        okPushButton->setText(QApplication::translate("getTablePairDialog", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class getTablePairDialog: public Ui_getTablePairDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // GETTABLEPAIRDIALOG_H

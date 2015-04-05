/********************************************************************************
** Form generated from reading UI file 'getTablePairDialog.ui'
**
** Created: Sun Apr 5 12:08:35 2015
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
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *codeLineEdit;
    QLineEdit *fileLineEdit;
    QVBoxLayout *verticalLayout_3;
    QPushButton *viewCodePushButton;
    QPushButton *viewFilePushButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelPushButton;
    QPushButton *okPushButton;

    void setupUi(QDialog *getTablePairDialog)
    {
        if (getTablePairDialog->objectName().isEmpty())
            getTablePairDialog->setObjectName(QString::fromUtf8("getTablePairDialog"));
        getTablePairDialog->resize(392, 119);
        verticalLayout_5 = new QVBoxLayout(getTablePairDialog);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(getTablePairDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(getTablePairDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        codeLineEdit = new QLineEdit(getTablePairDialog);
        codeLineEdit->setObjectName(QString::fromUtf8("codeLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(codeLineEdit->sizePolicy().hasHeightForWidth());
        codeLineEdit->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(codeLineEdit);

        fileLineEdit = new QLineEdit(getTablePairDialog);
        fileLineEdit->setObjectName(QString::fromUtf8("fileLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fileLineEdit->sizePolicy().hasHeightForWidth());
        fileLineEdit->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(fileLineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        viewCodePushButton = new QPushButton(getTablePairDialog);
        viewCodePushButton->setObjectName(QString::fromUtf8("viewCodePushButton"));

        verticalLayout_3->addWidget(viewCodePushButton);

        viewFilePushButton = new QPushButton(getTablePairDialog);
        viewFilePushButton->setObjectName(QString::fromUtf8("viewFilePushButton"));

        verticalLayout_3->addWidget(viewFilePushButton);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

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


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);


        retranslateUi(getTablePairDialog);
        QObject::connect(okPushButton, SIGNAL(clicked()), getTablePairDialog, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), getTablePairDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(getTablePairDialog);
    } // setupUi

    void retranslateUi(QDialog *getTablePairDialog)
    {
        getTablePairDialog->setWindowTitle(QApplication::translate("getTablePairDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("getTablePairDialog", "Code:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("getTablePairDialog", "Audio File:", 0, QApplication::UnicodeUTF8));
        viewCodePushButton->setText(QApplication::translate("getTablePairDialog", "...", 0, QApplication::UnicodeUTF8));
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

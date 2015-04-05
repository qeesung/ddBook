/********************************************************************************
** Form generated from reading UI file 'createCodeDialog.ui'
**
** Created: Sun Apr 5 10:28:27 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECODEDIALOG_H
#define UI_CREATECODEDIALOG_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateCodeDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *codeLineEdit;
    QLineEdit *pictureLineEdit;
    QVBoxLayout *verticalLayout_3;
    QPushButton *recordPushButton;
    QPushButton *pictureViewButton;
    QLabel *pictureLabel;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *okPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *CreateCodeDialog)
    {
        if (CreateCodeDialog->objectName().isEmpty())
            CreateCodeDialog->setObjectName(QString::fromUtf8("CreateCodeDialog"));
        CreateCodeDialog->resize(386, 119);
        horizontalLayout_3 = new QHBoxLayout(CreateCodeDialog);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(CreateCodeDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(CreateCodeDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        codeLineEdit = new QLineEdit(CreateCodeDialog);
        codeLineEdit->setObjectName(QString::fromUtf8("codeLineEdit"));

        verticalLayout_2->addWidget(codeLineEdit);

        pictureLineEdit = new QLineEdit(CreateCodeDialog);
        pictureLineEdit->setObjectName(QString::fromUtf8("pictureLineEdit"));

        verticalLayout_2->addWidget(pictureLineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        recordPushButton = new QPushButton(CreateCodeDialog);
        recordPushButton->setObjectName(QString::fromUtf8("recordPushButton"));

        verticalLayout_3->addWidget(recordPushButton);

        pictureViewButton = new QPushButton(CreateCodeDialog);
        pictureViewButton->setObjectName(QString::fromUtf8("pictureViewButton"));

        verticalLayout_3->addWidget(pictureViewButton);


        horizontalLayout->addLayout(verticalLayout_3);

        pictureLabel = new QLabel(CreateCodeDialog);
        pictureLabel->setObjectName(QString::fromUtf8("pictureLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pictureLabel->sizePolicy().hasHeightForWidth());
        pictureLabel->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pictureLabel);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        okPushButton = new QPushButton(CreateCodeDialog);
        okPushButton->setObjectName(QString::fromUtf8("okPushButton"));

        horizontalLayout_2->addWidget(okPushButton);

        cancelPushButton = new QPushButton(CreateCodeDialog);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        horizontalLayout_2->addWidget(cancelPushButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);


        retranslateUi(CreateCodeDialog);
        QObject::connect(okPushButton, SIGNAL(clicked()), CreateCodeDialog, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), CreateCodeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateCodeDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateCodeDialog)
    {
        CreateCodeDialog->setWindowTitle(QApplication::translate("CreateCodeDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateCodeDialog", "Code:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateCodeDialog", "Picture:", 0, QApplication::UnicodeUTF8));
        recordPushButton->setText(QApplication::translate("CreateCodeDialog", "Record", 0, QApplication::UnicodeUTF8));
        pictureViewButton->setText(QApplication::translate("CreateCodeDialog", "...", 0, QApplication::UnicodeUTF8));
        pictureLabel->setText(QApplication::translate("CreateCodeDialog", "Picture", 0, QApplication::UnicodeUTF8));
        okPushButton->setText(QApplication::translate("CreateCodeDialog", "Ok", 0, QApplication::UnicodeUTF8));
        cancelPushButton->setText(QApplication::translate("CreateCodeDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateCodeDialog: public Ui_CreateCodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECODEDIALOG_H

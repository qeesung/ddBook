/********************************************************************************
** Form generated from reading UI file 'chooseCpAlDialog.ui'
**
** Created: Sun Apr 19 20:44:53 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSECPALDIALOG_H
#define UI_CHOOSECPALDIALOG_H

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

class Ui_ChooseCpAlDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *cpFileLineEdit;
    QPushButton *cpFilePushButton;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *alFileLineEdit;
    QPushButton *alFilePushButton;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLineEdit *cdFileLineEdit;
    QPushButton *cdFilePushButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *okPushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *ChooseCpAlDialog)
    {
        if (ChooseCpAlDialog->objectName().isEmpty())
            ChooseCpAlDialog->setObjectName(QString::fromUtf8("ChooseCpAlDialog"));
        ChooseCpAlDialog->resize(567, 297);
        ChooseCpAlDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(ChooseCpAlDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ChooseCpAlDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(ChooseCpAlDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(ChooseCpAlDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        cpFileLineEdit = new QLineEdit(ChooseCpAlDialog);
        cpFileLineEdit->setObjectName(QString::fromUtf8("cpFileLineEdit"));

        horizontalLayout->addWidget(cpFileLineEdit);

        cpFilePushButton = new QPushButton(ChooseCpAlDialog);
        cpFilePushButton->setObjectName(QString::fromUtf8("cpFilePushButton"));

        horizontalLayout->addWidget(cpFilePushButton);


        verticalLayout->addLayout(horizontalLayout);

        label_4 = new QLabel(ChooseCpAlDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        verticalLayout->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(ChooseCpAlDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        alFileLineEdit = new QLineEdit(ChooseCpAlDialog);
        alFileLineEdit->setObjectName(QString::fromUtf8("alFileLineEdit"));

        horizontalLayout_2->addWidget(alFileLineEdit);

        alFilePushButton = new QPushButton(ChooseCpAlDialog);
        alFilePushButton->setObjectName(QString::fromUtf8("alFilePushButton"));

        horizontalLayout_2->addWidget(alFilePushButton);


        verticalLayout->addLayout(horizontalLayout_2);

        label_6 = new QLabel(ChooseCpAlDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));

        verticalLayout->addWidget(label_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_7 = new QLabel(ChooseCpAlDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        cdFileLineEdit = new QLineEdit(ChooseCpAlDialog);
        cdFileLineEdit->setObjectName(QString::fromUtf8("cdFileLineEdit"));

        horizontalLayout_4->addWidget(cdFileLineEdit);

        cdFilePushButton = new QPushButton(ChooseCpAlDialog);
        cdFilePushButton->setObjectName(QString::fromUtf8("cdFilePushButton"));

        horizontalLayout_4->addWidget(cdFilePushButton);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        okPushButton = new QPushButton(ChooseCpAlDialog);
        okPushButton->setObjectName(QString::fromUtf8("okPushButton"));

        horizontalLayout_3->addWidget(okPushButton);

        cancelPushButton = new QPushButton(ChooseCpAlDialog);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        horizontalLayout_3->addWidget(cancelPushButton);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(ChooseCpAlDialog);
        QObject::connect(okPushButton, SIGNAL(clicked()), ChooseCpAlDialog, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), ChooseCpAlDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChooseCpAlDialog);
    } // setupUi

    void retranslateUi(QDialog *ChooseCpAlDialog)
    {
        ChooseCpAlDialog->setWindowTitle(QApplication::translate("ChooseCpAlDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ChooseCpAlDialog", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Before start </span></p><p><span style=\" font-size:14pt; font-weight:600;\">choose three files that contain basic info</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ChooseCpAlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; font-style:italic;\">Step 1 </span><span style=\" font-size:12pt;\">: Please </span><span style=\" font-size:12pt; font-weight:600; font-style:italic;\">choose</span><span style=\" font-size:12pt;\"> or </span><span style=\" font-size:12pt; font-weight:600; font-style:italic;\">create</span><span style=\" font-size:12pt;\"> a cp file that contain code info :</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ChooseCpAlDialog", "<html><head/><body><p>Cp Filename ( default <span style=\" color:#ffaa00;\">cpData.cp </span>) :</p></body></html>", 0, QApplication::UnicodeUTF8));
        cpFilePushButton->setText(QApplication::translate("ChooseCpAlDialog", "...", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ChooseCpAlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; font-style:italic;\">Step 2</span><span style=\" font-size:12pt;\"> : And then </span><span style=\" font-size:12pt; font-weight:600; font-style:italic;\">choose</span><span style=\" font-size:12pt;\"> or </span><span style=\" font-size:12pt; font-weight:600; font-style:italic;\">create</span><span style=\" font-size:12pt;\"> a al file that contian audio info:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ChooseCpAlDialog", "<html><head/><body><p>AL Filename ( default <span style=\" color:#ffaa00;\">alData.aL </span>) : </p></body></html>", 0, QApplication::UnicodeUTF8));
        alFilePushButton->setText(QApplication::translate("ChooseCpAlDialog", "...", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ChooseCpAlDialog", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600; font-style:italic;\">Step 3</span><span style=\" font-size:12pt;\">: </span><span style=\" font-size:12pt; font-weight:600; font-style:italic;\">choose</span><span style=\" font-size:12pt;\"> or </span><span style=\" font-size:12pt; font-weight:600; font-style:italic;\">create</span><span style=\" font-size:12pt;\"> a cd file that contian  default audio info:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ChooseCpAlDialog", "<html><head/><body><p>Cd Filename (default <span style=\" color:#ffaa00;\">cdData.cd </span>) : </p></body></html>", 0, QApplication::UnicodeUTF8));
        cdFilePushButton->setText(QApplication::translate("ChooseCpAlDialog", "...", 0, QApplication::UnicodeUTF8));
        okPushButton->setText(QApplication::translate("ChooseCpAlDialog", "Ok", 0, QApplication::UnicodeUTF8));
        cancelPushButton->setText(QApplication::translate("ChooseCpAlDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ChooseCpAlDialog: public Ui_ChooseCpAlDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSECPALDIALOG_H

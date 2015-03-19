/********************************************************************************
** Form generated from reading UI file 'propertiesdialog.ui'
**
** Created: Thu Mar 19 16:39:14 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROPERTIESDIALOG_H
#define UI_PROPERTIESDIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_12;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_13;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(344, 392);
        verticalLayout_12 = new QVBoxLayout(Dialog);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_15 = new QLabel(Dialog);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        label_15->setFont(font);

        verticalLayout_8->addWidget(label_15);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(37, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(Dialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);


        horizontalLayout_6->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(35, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        spinBox_2 = new QSpinBox(Dialog);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout_2->addWidget(spinBox_2);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        horizontalSpacer_3 = new QSpacerItem(34, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_8->addLayout(horizontalLayout_6);


        verticalLayout_10->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_16 = new QLabel(Dialog);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_16->setFont(font1);

        verticalLayout_9->addWidget(label_16);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        label_12 = new QLabel(Dialog);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);

        label_11 = new QLabel(Dialog);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(71, 16));

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(71, 16));

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(71, 16));

        verticalLayout_2->addWidget(label_8);

        label_13 = new QLabel(Dialog);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(71, 16));

        verticalLayout_2->addWidget(label_13);

        label_14 = new QLabel(Dialog);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(71, 16));

        verticalLayout_2->addWidget(label_14);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_3->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(Dialog);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout_3->addWidget(pushButton_5);

        pushButton_4 = new QPushButton(Dialog);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_3->addWidget(pushButton_4);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_7->addLayout(horizontalLayout_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_4->addWidget(label_9);

        label_10 = new QLabel(Dialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_4->addWidget(label_10);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_5->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(Dialog);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_5->addWidget(lineEdit_2);


        horizontalLayout_4->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(horizontalLayout_4);


        verticalLayout_9->addLayout(verticalLayout_7);


        verticalLayout_10->addLayout(verticalLayout_9);


        verticalLayout_11->addLayout(verticalLayout_10);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_5->addWidget(buttonBox);


        verticalLayout_11->addLayout(horizontalLayout_5);


        verticalLayout_12->addLayout(verticalLayout_11);

        label_15->raise();
        label_16->raise();

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Dialog", "Position", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "X:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Y:", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Dialog", "Node Surface Info", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "TextColor:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "OutlineColor:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialog", "backgroundColor:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Dialog", "TransCodeTextColor:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Dialog", "TransCodeBackColor:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        pushButton->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("Dialog", "...", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Dialog", "Text contents:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Dialog", "TransCode:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROPERTIESDIALOG_H

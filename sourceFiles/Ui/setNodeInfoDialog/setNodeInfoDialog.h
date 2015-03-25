/********************************************************************************
** Form generated from reading UI file 'setNodeInfoDialog.ui'
**
** Created: Wed Mar 25 17:27:47 2015
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_setNodeInfoDialog
{
public:
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *nodeNameLineEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QLineEdit *transCodeLineEdit;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_9;
    QLineEdit *pictureLineEdit;
    QPushButton *picturePushButton;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *startAudioLineEdit;
    QPushButton *startAudioPushButton;
    QLabel *label_5;
    QTableWidget *startAudioTableWidget;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *startAudioAddPushButton;
    QPushButton *startAudioDeletePushButton;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_8;
    QLineEdit *endAudioLineEdit;
    QPushButton *endAudioPushButton;
    QLabel *label_6;
    QTableWidget *endAudioTableWidget;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *endAudioAddPushButton;
    QPushButton *endAudioDeletePushButton;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_7;
    QTableWidget *givenAudioTableWidget;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *givenAudioAddPushButton;
    QPushButton *givenAudioDeletePushButton;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QListWidget *defaultAudiotListWidget;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *defaultAudioAddPushButton;
    QPushButton *defaultAudioDeletePushButton;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelPushButton;
    QPushButton *okPushButton;

    void setupUi(QDialog *setNodeInfoDialog)
    {
        if (setNodeInfoDialog->objectName().isEmpty())
            setNodeInfoDialog->setObjectName(QString::fromUtf8("setNodeInfoDialog"));
        setNodeInfoDialog->resize(817, 599);
        verticalLayout_8 = new QVBoxLayout(setNodeInfoDialog);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(setNodeInfoDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        nodeNameLineEdit = new QLineEdit(setNodeInfoDialog);
        nodeNameLineEdit->setObjectName(QString::fromUtf8("nodeNameLineEdit"));

        horizontalLayout_5->addWidget(nodeNameLineEdit);


        horizontalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_8 = new QLabel(setNodeInfoDialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_11->addWidget(label_8);

        transCodeLineEdit = new QLineEdit(setNodeInfoDialog);
        transCodeLineEdit->setObjectName(QString::fromUtf8("transCodeLineEdit"));

        horizontalLayout_11->addWidget(transCodeLineEdit);


        horizontalLayout_2->addLayout(horizontalLayout_11);


        horizontalLayout_14->addLayout(horizontalLayout_2);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_9 = new QLabel(setNodeInfoDialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_12->addWidget(label_9);

        pictureLineEdit = new QLineEdit(setNodeInfoDialog);
        pictureLineEdit->setObjectName(QString::fromUtf8("pictureLineEdit"));

        horizontalLayout_12->addWidget(pictureLineEdit);


        horizontalLayout_13->addLayout(horizontalLayout_12);

        picturePushButton = new QPushButton(setNodeInfoDialog);
        picturePushButton->setObjectName(QString::fromUtf8("picturePushButton"));

        horizontalLayout_13->addWidget(picturePushButton);


        horizontalLayout_14->addLayout(horizontalLayout_13);


        verticalLayout_6->addLayout(horizontalLayout_14);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(setNodeInfoDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        startAudioLineEdit = new QLineEdit(setNodeInfoDialog);
        startAudioLineEdit->setObjectName(QString::fromUtf8("startAudioLineEdit"));

        horizontalLayout->addWidget(startAudioLineEdit);

        startAudioPushButton = new QPushButton(setNodeInfoDialog);
        startAudioPushButton->setObjectName(QString::fromUtf8("startAudioPushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startAudioPushButton->sizePolicy().hasHeightForWidth());
        startAudioPushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(startAudioPushButton);


        verticalLayout->addLayout(horizontalLayout);

        label_5 = new QLabel(setNodeInfoDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        verticalLayout->addWidget(label_5);

        startAudioTableWidget = new QTableWidget(setNodeInfoDialog);
        if (startAudioTableWidget->columnCount() < 2)
            startAudioTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        startAudioTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        startAudioTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        startAudioTableWidget->setObjectName(QString::fromUtf8("startAudioTableWidget"));

        verticalLayout->addWidget(startAudioTableWidget);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        startAudioAddPushButton = new QPushButton(setNodeInfoDialog);
        startAudioAddPushButton->setObjectName(QString::fromUtf8("startAudioAddPushButton"));

        horizontalLayout_6->addWidget(startAudioAddPushButton);

        startAudioDeletePushButton = new QPushButton(setNodeInfoDialog);
        startAudioDeletePushButton->setObjectName(QString::fromUtf8("startAudioDeletePushButton"));

        horizontalLayout_6->addWidget(startAudioDeletePushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_15->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(setNodeInfoDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        endAudioLineEdit = new QLineEdit(setNodeInfoDialog);
        endAudioLineEdit->setObjectName(QString::fromUtf8("endAudioLineEdit"));

        horizontalLayout_8->addWidget(endAudioLineEdit);

        endAudioPushButton = new QPushButton(setNodeInfoDialog);
        endAudioPushButton->setObjectName(QString::fromUtf8("endAudioPushButton"));
        sizePolicy.setHeightForWidth(endAudioPushButton->sizePolicy().hasHeightForWidth());
        endAudioPushButton->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(endAudioPushButton);


        verticalLayout_2->addLayout(horizontalLayout_8);

        label_6 = new QLabel(setNodeInfoDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        verticalLayout_2->addWidget(label_6);

        endAudioTableWidget = new QTableWidget(setNodeInfoDialog);
        if (endAudioTableWidget->columnCount() < 2)
            endAudioTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        endAudioTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        endAudioTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        endAudioTableWidget->setObjectName(QString::fromUtf8("endAudioTableWidget"));

        verticalLayout_2->addWidget(endAudioTableWidget);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        endAudioAddPushButton = new QPushButton(setNodeInfoDialog);
        endAudioAddPushButton->setObjectName(QString::fromUtf8("endAudioAddPushButton"));

        horizontalLayout_7->addWidget(endAudioAddPushButton);

        endAudioDeletePushButton = new QPushButton(setNodeInfoDialog);
        endAudioDeletePushButton->setObjectName(QString::fromUtf8("endAudioDeletePushButton"));

        horizontalLayout_7->addWidget(endAudioDeletePushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_15->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_7 = new QLabel(setNodeInfoDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        verticalLayout_3->addWidget(label_7);

        givenAudioTableWidget = new QTableWidget(setNodeInfoDialog);
        if (givenAudioTableWidget->columnCount() < 2)
            givenAudioTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        givenAudioTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        givenAudioTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        givenAudioTableWidget->setObjectName(QString::fromUtf8("givenAudioTableWidget"));

        verticalLayout_3->addWidget(givenAudioTableWidget);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        givenAudioAddPushButton = new QPushButton(setNodeInfoDialog);
        givenAudioAddPushButton->setObjectName(QString::fromUtf8("givenAudioAddPushButton"));

        horizontalLayout_9->addWidget(givenAudioAddPushButton);

        givenAudioDeletePushButton = new QPushButton(setNodeInfoDialog);
        givenAudioDeletePushButton->setObjectName(QString::fromUtf8("givenAudioDeletePushButton"));

        horizontalLayout_9->addWidget(givenAudioDeletePushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_9);


        horizontalLayout_16->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(setNodeInfoDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout_4->addWidget(label_3);

        defaultAudiotListWidget = new QListWidget(setNodeInfoDialog);
        defaultAudiotListWidget->setObjectName(QString::fromUtf8("defaultAudiotListWidget"));

        verticalLayout_4->addWidget(defaultAudiotListWidget);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        defaultAudioAddPushButton = new QPushButton(setNodeInfoDialog);
        defaultAudioAddPushButton->setObjectName(QString::fromUtf8("defaultAudioAddPushButton"));

        horizontalLayout_10->addWidget(defaultAudioAddPushButton);

        defaultAudioDeletePushButton = new QPushButton(setNodeInfoDialog);
        defaultAudioDeletePushButton->setObjectName(QString::fromUtf8("defaultAudioDeletePushButton"));

        horizontalLayout_10->addWidget(defaultAudioDeletePushButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_10);


        horizontalLayout_16->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_16);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_6);

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


        verticalLayout_7->addLayout(horizontalLayout_4);


        verticalLayout_8->addLayout(verticalLayout_7);


        retranslateUi(setNodeInfoDialog);

        QMetaObject::connectSlotsByName(setNodeInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *setNodeInfoDialog)
    {
        setNodeInfoDialog->setWindowTitle(QApplication::translate("setNodeInfoDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("setNodeInfoDialog", "Node Name:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("setNodeInfoDialog", "TransCode:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("setNodeInfoDialog", "Picture:", 0, QApplication::UnicodeUTF8));
        picturePushButton->setText(QApplication::translate("setNodeInfoDialog", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("setNodeInfoDialog", "Default Start Audio:", 0, QApplication::UnicodeUTF8));
        startAudioPushButton->setText(QApplication::translate("setNodeInfoDialog", "...", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("setNodeInfoDialog", "Start Audio:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = startAudioTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("setNodeInfoDialog", "FromNodeCode", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = startAudioTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("setNodeInfoDialog", "Audio", 0, QApplication::UnicodeUTF8));
        startAudioAddPushButton->setText(QApplication::translate("setNodeInfoDialog", "add", 0, QApplication::UnicodeUTF8));
        startAudioDeletePushButton->setText(QApplication::translate("setNodeInfoDialog", "delete", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("setNodeInfoDialog", "Default End Audio:", 0, QApplication::UnicodeUTF8));
        endAudioPushButton->setText(QApplication::translate("setNodeInfoDialog", "...", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("setNodeInfoDialog", "End Audio:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = endAudioTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("setNodeInfoDialog", "ToNodeCode", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = endAudioTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("setNodeInfoDialog", "Audio", 0, QApplication::UnicodeUTF8));
        endAudioAddPushButton->setText(QApplication::translate("setNodeInfoDialog", "add", 0, QApplication::UnicodeUTF8));
        endAudioDeletePushButton->setText(QApplication::translate("setNodeInfoDialog", "delete", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("setNodeInfoDialog", "Given Special Audio:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = givenAudioTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("setNodeInfoDialog", "GivenNodeCode", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = givenAudioTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("setNodeInfoDialog", "Audio", 0, QApplication::UnicodeUTF8));
        givenAudioAddPushButton->setText(QApplication::translate("setNodeInfoDialog", "add", 0, QApplication::UnicodeUTF8));
        givenAudioDeletePushButton->setText(QApplication::translate("setNodeInfoDialog", "delete", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("setNodeInfoDialog", "Default Audio:", 0, QApplication::UnicodeUTF8));
        defaultAudioAddPushButton->setText(QApplication::translate("setNodeInfoDialog", "add", 0, QApplication::UnicodeUTF8));
        defaultAudioDeletePushButton->setText(QApplication::translate("setNodeInfoDialog", "delete", 0, QApplication::UnicodeUTF8));
        cancelPushButton->setText(QApplication::translate("setNodeInfoDialog", "CANCEL", 0, QApplication::UnicodeUTF8));
        okPushButton->setText(QApplication::translate("setNodeInfoDialog", "  OK  ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class setNodeInfoDialog: public Ui_setNodeInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SETNODEINFODIALOG_H

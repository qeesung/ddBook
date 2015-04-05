/********************************************************************************
** Form generated from reading UI file 'setNodeInfoDialog.ui'
**
** Created: Tue Mar 31 20:50:56 2015
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
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_setNodeInfoDialog
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QFrame *frame_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *nodeNameLineEdit;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QLineEdit *transCodeLineEdit;
    QPushButton *transCodeViewButton;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *startAudioLineEdit;
    QLineEdit *endAudioLineEdit;
    QVBoxLayout *verticalLayout_5;
    QPushButton *startAudioPushButton;
    QPushButton *endAudioPushButton;
    QLabel *pictureLabel;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_6;
    QFrame *frame;
    QVBoxLayout *verticalLayout_8;
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
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *sameFlagCheckBox;
    QRadioButton *beforeRadioButton;
    QRadioButton *afterRadioButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_2;
    QPushButton *okPushButton;
    QPushButton *cancelPushButton;
    QPushButton *morePushButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *setNodeInfoDialog)
    {
        if (setNodeInfoDialog->objectName().isEmpty())
            setNodeInfoDialog->setObjectName(QString::fromUtf8("setNodeInfoDialog"));
        setNodeInfoDialog->resize(755, 482);
        gridLayout_2 = new QGridLayout(setNodeInfoDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(setNodeInfoDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);


        verticalLayout_10->addLayout(horizontalLayout_3);

        frame_2 = new QFrame(setNodeInfoDialog);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);


        horizontalLayout_2->addLayout(horizontalLayout_5);

        nodeNameLineEdit = new QLineEdit(frame_2);
        nodeNameLineEdit->setObjectName(QString::fromUtf8("nodeNameLineEdit"));

        horizontalLayout_2->addWidget(nodeNameLineEdit);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_11->addWidget(label_8);

        transCodeLineEdit = new QLineEdit(frame_2);
        transCodeLineEdit->setObjectName(QString::fromUtf8("transCodeLineEdit"));

        horizontalLayout_11->addWidget(transCodeLineEdit);

        transCodeViewButton = new QPushButton(frame_2);
        transCodeViewButton->setObjectName(QString::fromUtf8("transCodeViewButton"));

        horizontalLayout_11->addWidget(transCodeViewButton);


        horizontalLayout_2->addLayout(horizontalLayout_11);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        startAudioLineEdit = new QLineEdit(frame_2);
        startAudioLineEdit->setObjectName(QString::fromUtf8("startAudioLineEdit"));

        verticalLayout_2->addWidget(startAudioLineEdit);

        endAudioLineEdit = new QLineEdit(frame_2);
        endAudioLineEdit->setObjectName(QString::fromUtf8("endAudioLineEdit"));

        verticalLayout_2->addWidget(endAudioLineEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        startAudioPushButton = new QPushButton(frame_2);
        startAudioPushButton->setObjectName(QString::fromUtf8("startAudioPushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startAudioPushButton->sizePolicy().hasHeightForWidth());
        startAudioPushButton->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(startAudioPushButton);

        endAudioPushButton = new QPushButton(frame_2);
        endAudioPushButton->setObjectName(QString::fromUtf8("endAudioPushButton"));
        sizePolicy.setHeightForWidth(endAudioPushButton->sizePolicy().hasHeightForWidth());
        endAudioPushButton->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(endAudioPushButton);


        horizontalLayout->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout_7);

        pictureLabel = new QLabel(frame_2);
        pictureLabel->setObjectName(QString::fromUtf8("pictureLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pictureLabel->sizePolicy().hasHeightForWidth());
        pictureLabel->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(pictureLabel);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);


        verticalLayout_10->addWidget(frame_2);


        verticalLayout_11->addLayout(verticalLayout_10);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label_6 = new QLabel(setNodeInfoDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_6->setFont(font2);

        verticalLayout_9->addWidget(label_6);

        frame = new QFrame(setNodeInfoDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        verticalLayout_3->addWidget(label_7);

        givenAudioTableWidget = new QTableWidget(frame);
        if (givenAudioTableWidget->columnCount() < 2)
            givenAudioTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        givenAudioTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        givenAudioTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        givenAudioTableWidget->setObjectName(QString::fromUtf8("givenAudioTableWidget"));

        verticalLayout_3->addWidget(givenAudioTableWidget);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        givenAudioAddPushButton = new QPushButton(frame);
        givenAudioAddPushButton->setObjectName(QString::fromUtf8("givenAudioAddPushButton"));

        horizontalLayout_9->addWidget(givenAudioAddPushButton);

        givenAudioDeletePushButton = new QPushButton(frame);
        givenAudioDeletePushButton->setObjectName(QString::fromUtf8("givenAudioDeletePushButton"));

        horizontalLayout_9->addWidget(givenAudioDeletePushButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_9);


        horizontalLayout_16->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        verticalLayout_4->addWidget(label_3);

        defaultAudiotListWidget = new QListWidget(frame);
        defaultAudiotListWidget->setObjectName(QString::fromUtf8("defaultAudiotListWidget"));

        verticalLayout_4->addWidget(defaultAudiotListWidget);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        defaultAudioAddPushButton = new QPushButton(frame);
        defaultAudioAddPushButton->setObjectName(QString::fromUtf8("defaultAudioAddPushButton"));

        horizontalLayout_10->addWidget(defaultAudioAddPushButton);

        defaultAudioDeletePushButton = new QPushButton(frame);
        defaultAudioDeletePushButton->setObjectName(QString::fromUtf8("defaultAudioDeletePushButton"));

        horizontalLayout_10->addWidget(defaultAudioDeletePushButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_10);


        horizontalLayout_16->addLayout(verticalLayout_4);


        verticalLayout_8->addLayout(horizontalLayout_16);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        sameFlagCheckBox = new QCheckBox(frame);
        sameFlagCheckBox->setObjectName(QString::fromUtf8("sameFlagCheckBox"));

        horizontalLayout_7->addWidget(sameFlagCheckBox);

        beforeRadioButton = new QRadioButton(frame);
        beforeRadioButton->setObjectName(QString::fromUtf8("beforeRadioButton"));

        horizontalLayout_7->addWidget(beforeRadioButton);

        afterRadioButton = new QRadioButton(frame);
        afterRadioButton->setObjectName(QString::fromUtf8("afterRadioButton"));

        horizontalLayout_7->addWidget(afterRadioButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer);


        verticalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_9->addWidget(frame);


        verticalLayout_11->addLayout(verticalLayout_9);


        horizontalLayout_6->addLayout(verticalLayout_11);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        okPushButton = new QPushButton(setNodeInfoDialog);
        okPushButton->setObjectName(QString::fromUtf8("okPushButton"));

        verticalLayout_6->addWidget(okPushButton);

        cancelPushButton = new QPushButton(setNodeInfoDialog);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));

        verticalLayout_6->addWidget(cancelPushButton);

        morePushButton = new QPushButton(setNodeInfoDialog);
        morePushButton->setObjectName(QString::fromUtf8("morePushButton"));
        morePushButton->setCheckable(true);

        verticalLayout_6->addWidget(morePushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout_6);


        gridLayout_2->addLayout(horizontalLayout_6, 0, 0, 1, 1);


        retranslateUi(setNodeInfoDialog);
        QObject::connect(morePushButton, SIGNAL(toggled(bool)), frame, SLOT(setVisible(bool)));
        QObject::connect(okPushButton, SIGNAL(clicked()), setNodeInfoDialog, SLOT(accept()));
        QObject::connect(cancelPushButton, SIGNAL(clicked()), setNodeInfoDialog, SLOT(reject()));
        QObject::connect(morePushButton, SIGNAL(toggled(bool)), label_6, SLOT(setVisible(bool)));
        QObject::connect(sameFlagCheckBox, SIGNAL(toggled(bool)), beforeRadioButton, SLOT(setVisible(bool)));
        QObject::connect(sameFlagCheckBox, SIGNAL(toggled(bool)), afterRadioButton, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(setNodeInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *setNodeInfoDialog)
    {
        setNodeInfoDialog->setWindowTitle(QApplication::translate("setNodeInfoDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("setNodeInfoDialog", "Basic Info:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("setNodeInfoDialog", "Node Name:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("setNodeInfoDialog", "TransCode:", 0, QApplication::UnicodeUTF8));
        transCodeViewButton->setText(QApplication::translate("setNodeInfoDialog", "...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("setNodeInfoDialog", "Start Audio:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("setNodeInfoDialog", "End Audio:", 0, QApplication::UnicodeUTF8));
        startAudioPushButton->setText(QApplication::translate("setNodeInfoDialog", "...", 0, QApplication::UnicodeUTF8));
        endAudioPushButton->setText(QApplication::translate("setNodeInfoDialog", "...", 0, QApplication::UnicodeUTF8));
        pictureLabel->setText(QApplication::translate("setNodeInfoDialog", "<html><head/><body><p align=\"center\">Pciture</p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("setNodeInfoDialog", "Additional Info", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("setNodeInfoDialog", "Given Special Audio:", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = givenAudioTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("setNodeInfoDialog", "GivenCode", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = givenAudioTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("setNodeInfoDialog", "Audio", 0, QApplication::UnicodeUTF8));
        givenAudioAddPushButton->setText(QApplication::translate("setNodeInfoDialog", "add", 0, QApplication::UnicodeUTF8));
        givenAudioDeletePushButton->setText(QApplication::translate("setNodeInfoDialog", "delete", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("setNodeInfoDialog", "Default Audio:", 0, QApplication::UnicodeUTF8));
        defaultAudioAddPushButton->setText(QApplication::translate("setNodeInfoDialog", "add", 0, QApplication::UnicodeUTF8));
        defaultAudioDeletePushButton->setText(QApplication::translate("setNodeInfoDialog", "delete", 0, QApplication::UnicodeUTF8));
        sameFlagCheckBox->setText(QApplication::translate("setNodeInfoDialog", "Different state before and after the state", 0, QApplication::UnicodeUTF8));
        beforeRadioButton->setText(QApplication::translate("setNodeInfoDialog", "Before", 0, QApplication::UnicodeUTF8));
        afterRadioButton->setText(QApplication::translate("setNodeInfoDialog", "After", 0, QApplication::UnicodeUTF8));
        okPushButton->setText(QApplication::translate("setNodeInfoDialog", "  OK  ", 0, QApplication::UnicodeUTF8));
        cancelPushButton->setText(QApplication::translate("setNodeInfoDialog", "CANCEL", 0, QApplication::UnicodeUTF8));
        morePushButton->setText(QApplication::translate("setNodeInfoDialog", "More", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class setNodeInfoDialog: public Ui_setNodeInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SETNODEINFODIALOG_H

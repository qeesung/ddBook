/********************************************************************************
** Form generated from reading UI file 'previewNodeWidget.ui'
**
** Created: Wed Apr 22 18:37:07 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWNODEWIDGET_H
#define UI_PREVIEWNODEWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreviewWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *pictureLabel;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *nodeNameLabel;
    QLabel *label_4;
    QLabel *transCodeLabel;
    QLabel *label_6;
    QLabel *startAudioLabel;
    QLabel *label_7;
    QLabel *endAudioLabel;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_10;
    QTableWidget *givenAudioTableWidget;
    QLabel *labellll;
    QListWidget *defaultAudioListWidget;

    void setupUi(QWidget *PreviewWidget)
    {
        if (PreviewWidget->objectName().isEmpty())
            PreviewWidget->setObjectName(QString::fromUtf8("PreviewWidget"));
        PreviewWidget->resize(400, 564);
        PreviewWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 244, 222);"));
        verticalLayout = new QVBoxLayout(PreviewWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pictureLabel = new QLabel(PreviewWidget);
        pictureLabel->setObjectName(QString::fromUtf8("pictureLabel"));

        verticalLayout->addWidget(pictureLabel);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(PreviewWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setStyleSheet(QString::fromUtf8("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nodeNameLabel = new QLabel(PreviewWidget);
        nodeNameLabel->setObjectName(QString::fromUtf8("nodeNameLabel"));
        nodeNameLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 255, 205);"));

        gridLayout->addWidget(nodeNameLabel, 0, 1, 1, 1);

        label_4 = new QLabel(PreviewWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setStyleSheet(QString::fromUtf8("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        transCodeLabel = new QLabel(PreviewWidget);
        transCodeLabel->setObjectName(QString::fromUtf8("transCodeLabel"));
        transCodeLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 255, 205);"));

        gridLayout->addWidget(transCodeLabel, 1, 1, 1, 1);

        label_6 = new QLabel(PreviewWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setStyleSheet(QString::fromUtf8("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        startAudioLabel = new QLabel(PreviewWidget);
        startAudioLabel->setObjectName(QString::fromUtf8("startAudioLabel"));
        startAudioLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 255, 205);"));

        gridLayout->addWidget(startAudioLabel, 2, 1, 1, 1);

        label_7 = new QLabel(PreviewWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setStyleSheet(QString::fromUtf8("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        endAudioLabel = new QLabel(PreviewWidget);
        endAudioLabel->setObjectName(QString::fromUtf8("endAudioLabel"));
        endAudioLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(23, 255, 205);"));

        gridLayout->addWidget(endAudioLabel, 3, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_10 = new QLabel(PreviewWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));

        verticalLayout_2->addWidget(label_10);

        givenAudioTableWidget = new QTableWidget(PreviewWidget);
        if (givenAudioTableWidget->columnCount() < 2)
            givenAudioTableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        givenAudioTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        givenAudioTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        givenAudioTableWidget->setObjectName(QString::fromUtf8("givenAudioTableWidget"));
        givenAudioTableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 255, 190);"));

        verticalLayout_2->addWidget(givenAudioTableWidget);

        labellll = new QLabel(PreviewWidget);
        labellll->setObjectName(QString::fromUtf8("labellll"));
        labellll->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 127);"));

        verticalLayout_2->addWidget(labellll);

        defaultAudioListWidget = new QListWidget(PreviewWidget);
        defaultAudioListWidget->setObjectName(QString::fromUtf8("defaultAudioListWidget"));
        defaultAudioListWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 255, 190);"));

        verticalLayout_2->addWidget(defaultAudioListWidget);


        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(PreviewWidget);

        QMetaObject::connectSlotsByName(PreviewWidget);
    } // setupUi

    void retranslateUi(QWidget *PreviewWidget)
    {
        PreviewWidget->setWindowTitle(QApplication::translate("PreviewWidget", "Form", 0, QApplication::UnicodeUTF8));
        pictureLabel->setText(QApplication::translate("PreviewWidget", "none", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PreviewWidget", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Node Name:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        nodeNameLabel->setText(QApplication::translate("PreviewWidget", "none", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PreviewWidget", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Trans Code :</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        transCodeLabel->setText(QApplication::translate("PreviewWidget", "none", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PreviewWidget", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Start Audio:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        startAudioLabel->setText(QApplication::translate("PreviewWidget", "none", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PreviewWidget", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">End Audio  :  </span></p></body></html>", 0, QApplication::UnicodeUTF8));
        endAudioLabel->setText(QApplication::translate("PreviewWidget", "none", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("PreviewWidget", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Given Audio:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = givenAudioTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PreviewWidget", "code", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = givenAudioTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("PreviewWidget", "audio", 0, QApplication::UnicodeUTF8));
        labellll->setText(QApplication::translate("PreviewWidget", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:600;\">Code Default Audio:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PreviewWidget: public Ui_PreviewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWNODEWIDGET_H

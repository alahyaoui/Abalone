/********************************************************************************
** Form generated from reading UI file 'View.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_H
#define UI_VIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_View
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *myScene;
    QGroupBox *horizontalGroupBox;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *player1Data;
    QLabel *player1;
    QHBoxLayout *player1HorizontalLayout;
    QLabel *lostBlackMarbles;
    QLabel *blackMarbleLoss;
    QSpacerItem *spacerRow1;
    QVBoxLayout *player2Data;
    QLabel *player2;
    QHBoxLayout *player2HorizontalLayout;
    QLabel *lostWhiteMarbles;
    QLabel *whiteMarbleLoss;
    QGroupBox *horizontalGroupBox1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View)
    {
        if (View->objectName().isEmpty())
            View->setObjectName(QString::fromUtf8("View"));
        View->resize(1073, 900);
        View->setMinimumSize(QSize(1073, 900));
        View->setMaximumSize(QSize(1073, 920));
        centralwidget = new QWidget(View);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMinimumSize(QSize(0, 0));
        centralwidget->setMaximumSize(QSize(100000, 100000));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 60, 1071, 741));
        myScene = new QVBoxLayout(layoutWidget);
        myScene->setObjectName(QString::fromUtf8("myScene"));
        myScene->setContentsMargins(0, 0, 0, 0);
        horizontalGroupBox = new QGroupBox(centralwidget);
        horizontalGroupBox->setObjectName(QString::fromUtf8("horizontalGroupBox"));
        horizontalGroupBox->setGeometry(QRect(0, -20, 1071, 81));
        horizontalGroupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        horizontalLayout = new QHBoxLayout(horizontalGroupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        player1Data = new QVBoxLayout();
        player1Data->setObjectName(QString::fromUtf8("player1Data"));
        player1 = new QLabel(horizontalGroupBox);
        player1->setObjectName(QString::fromUtf8("player1"));
        player1->setMaximumSize(QSize(200, 60));
        player1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        player1->setMargin(1);

        player1Data->addWidget(player1);

        player1HorizontalLayout = new QHBoxLayout();
        player1HorizontalLayout->setObjectName(QString::fromUtf8("player1HorizontalLayout"));
        lostBlackMarbles = new QLabel(horizontalGroupBox);
        lostBlackMarbles->setObjectName(QString::fromUtf8("lostBlackMarbles"));
        lostBlackMarbles->setMaximumSize(QSize(200, 60));

        player1HorizontalLayout->addWidget(lostBlackMarbles);

        blackMarbleLoss = new QLabel(horizontalGroupBox);
        blackMarbleLoss->setObjectName(QString::fromUtf8("blackMarbleLoss"));

        player1HorizontalLayout->addWidget(blackMarbleLoss);


        player1Data->addLayout(player1HorizontalLayout);


        horizontalLayout->addLayout(player1Data);

        spacerRow1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerRow1);

        player2Data = new QVBoxLayout();
        player2Data->setObjectName(QString::fromUtf8("player2Data"));
        player2 = new QLabel(horizontalGroupBox);
        player2->setObjectName(QString::fromUtf8("player2"));

        player2Data->addWidget(player2);

        player2HorizontalLayout = new QHBoxLayout();
        player2HorizontalLayout->setObjectName(QString::fromUtf8("player2HorizontalLayout"));
        lostWhiteMarbles = new QLabel(horizontalGroupBox);
        lostWhiteMarbles->setObjectName(QString::fromUtf8("lostWhiteMarbles"));

        player2HorizontalLayout->addWidget(lostWhiteMarbles);

        whiteMarbleLoss = new QLabel(horizontalGroupBox);
        whiteMarbleLoss->setObjectName(QString::fromUtf8("whiteMarbleLoss"));

        player2HorizontalLayout->addWidget(whiteMarbleLoss);


        player2Data->addLayout(player2HorizontalLayout);


        horizontalLayout->addLayout(player2Data);

        horizontalGroupBox1 = new QGroupBox(centralwidget);
        horizontalGroupBox1->setObjectName(QString::fromUtf8("horizontalGroupBox1"));
        horizontalGroupBox1->setGeometry(QRect(0, 780, 1071, 111));
        horizontalGroupBox1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        horizontalLayout_2 = new QHBoxLayout(horizontalGroupBox1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(horizontalGroupBox1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        View->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1073, 22));
        View->setMenuBar(menubar);
        statusbar = new QStatusBar(View);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        View->setStatusBar(statusbar);

        retranslateUi(View);

        QMetaObject::connectSlotsByName(View);
    } // setupUi

    void retranslateUi(QMainWindow *View)
    {
        View->setWindowTitle(QApplication::translate("View", "MainWindow", nullptr));
        player1->setText(QApplication::translate("View", "Player 1", nullptr));
        lostBlackMarbles->setText(QApplication::translate("View", "Billes Perdues :", nullptr));
        blackMarbleLoss->setText(QApplication::translate("View", "0", nullptr));
        player2->setText(QApplication::translate("View", "Player 2", nullptr));
        lostWhiteMarbles->setText(QApplication::translate("View", "Billes Perdues :", nullptr));
        whiteMarbleLoss->setText(QApplication::translate("View", "0", nullptr));
        label->setText(QApplication::translate("View", "Clique sur un hexagone", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View: public Ui_View {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_H

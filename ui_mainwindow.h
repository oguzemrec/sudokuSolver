/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QUndoView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionlk;
    QWidget *centralwidget;
    QFrame *gridFrame;
    QGridLayout *gridLayoutSudoku;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layoutKey;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *layoutTool;
    QPushButton *buttonErase;
    QPushButton *buttonFillPoss;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonUndo;
    QPushButton *buttonRedo;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonClueEntering;
    QLabel *labelClueNumber;
    QRadioButton *radioButtonNoteMode;
    QRadioButton *radioButtonSolvingMode;
    QPushButton *buttonReset;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *pushButtonClearUndoView;
    QUndoView *undoView;
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLabel *labelMethod;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *pageComboBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelInfo;
    QPushButton *buttonSolution;
    QFrame *line;
    QPushButton *buttonXYWing;
    QPushButton *buttonXYZWing;
    QPushButton *buttonXWing;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_12;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_20;
    QLabel *label_19;
    QLabel *label_18;
    QLabel *label_17;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *label_14;
    QLabel *label_4;
    QLabel *label_13;
    QPushButton *buttonSkyScraper;
    QMenuBar *menubar;
    QMenu *menuk;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(1092, 678);
        actionlk = new QAction(MainWindow);
        actionlk->setObjectName(QString::fromUtf8("actionlk"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridFrame = new QFrame(centralwidget);
        gridFrame->setObjectName(QString::fromUtf8("gridFrame"));
        gridFrame->setGeometry(QRect(30, 80, 450, 450));
        gridLayoutSudoku = new QGridLayout(gridFrame);
        gridLayoutSudoku->setObjectName(QString::fromUtf8("gridLayoutSudoku"));
        gridLayoutSudoku->setHorizontalSpacing(6);
        gridLayoutSudoku->setVerticalSpacing(0);
        gridLayoutSudoku->setContentsMargins(9, 9, 9, 9);
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 570, 481, 41));
        layoutKey = new QHBoxLayout(horizontalLayoutWidget);
        layoutKey->setSpacing(0);
        layoutKey->setObjectName(QString::fromUtf8("layoutKey"));
        layoutKey->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 530, 441, 40));
        layoutTool = new QHBoxLayout(horizontalLayoutWidget_2);
        layoutTool->setSpacing(0);
        layoutTool->setObjectName(QString::fromUtf8("layoutTool"));
        layoutTool->setContentsMargins(0, 0, 0, 0);
        buttonErase = new QPushButton(horizontalLayoutWidget_2);
        buttonErase->setObjectName(QString::fromUtf8("buttonErase"));

        layoutTool->addWidget(buttonErase);

        buttonFillPoss = new QPushButton(horizontalLayoutWidget_2);
        buttonFillPoss->setObjectName(QString::fromUtf8("buttonFillPoss"));

        layoutTool->addWidget(buttonFillPoss);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layoutTool->addItem(horizontalSpacer);

        buttonUndo = new QPushButton(horizontalLayoutWidget_2);
        buttonUndo->setObjectName(QString::fromUtf8("buttonUndo"));

        layoutTool->addWidget(buttonUndo);

        buttonRedo = new QPushButton(horizontalLayoutWidget_2);
        buttonRedo->setObjectName(QString::fromUtf8("buttonRedo"));

        layoutTool->addWidget(buttonRedo);

        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 451, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonClueEntering = new QRadioButton(layoutWidget);
        radioButtonClueEntering->setObjectName(QString::fromUtf8("radioButtonClueEntering"));
        radioButtonClueEntering->setChecked(true);

        horizontalLayout->addWidget(radioButtonClueEntering);

        labelClueNumber = new QLabel(layoutWidget);
        labelClueNumber->setObjectName(QString::fromUtf8("labelClueNumber"));
        labelClueNumber->setMaximumSize(QSize(24, 16777215));
        QFont font;
        font.setPointSize(11);
        labelClueNumber->setFont(font);
        labelClueNumber->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout->addWidget(labelClueNumber);

        radioButtonNoteMode = new QRadioButton(layoutWidget);
        radioButtonNoteMode->setObjectName(QString::fromUtf8("radioButtonNoteMode"));
        radioButtonNoteMode->setChecked(false);

        horizontalLayout->addWidget(radioButtonNoteMode);

        radioButtonSolvingMode = new QRadioButton(layoutWidget);
        radioButtonSolvingMode->setObjectName(QString::fromUtf8("radioButtonSolvingMode"));
        radioButtonSolvingMode->setChecked(false);

        horizontalLayout->addWidget(radioButtonSolvingMode);

        buttonReset = new QPushButton(layoutWidget);
        buttonReset->setObjectName(QString::fromUtf8("buttonReset"));

        horizontalLayout->addWidget(buttonReset);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(490, 40, 258, 531));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        pushButtonClearUndoView = new QPushButton(layoutWidget1);
        pushButtonClearUndoView->setObjectName(QString::fromUtf8("pushButtonClearUndoView"));

        horizontalLayout_2->addWidget(pushButtonClearUndoView);


        verticalLayout->addLayout(horizontalLayout_2);

        undoView = new QUndoView(layoutWidget1);
        undoView->setObjectName(QString::fromUtf8("undoView"));

        verticalLayout->addWidget(undoView);

        verticalFrame = new QFrame(centralwidget);
        verticalFrame->setObjectName(QString::fromUtf8("verticalFrame"));
        verticalFrame->setGeometry(QRect(760, 41, 320, 320));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalFrame->sizePolicy().hasHeightForWidth());
        verticalFrame->setSizePolicy(sizePolicy);
        verticalFrame->setMinimumSize(QSize(0, 320));
        verticalFrame->setFrameShape(QFrame::Box);
        verticalFrame->setLineWidth(1);
        verticalLayout_2 = new QVBoxLayout(verticalFrame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(9, 9, 9, 9);
        label_2 = new QLabel(verticalFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(52, 16));
        label_2->setMaximumSize(QSize(52, 16));

        horizontalLayout_4->addWidget(label_2);

        labelMethod = new QLabel(verticalFrame);
        labelMethod->setObjectName(QString::fromUtf8("labelMethod"));
        labelMethod->setMinimumSize(QSize(55, 16));
        labelMethod->setMaximumSize(QSize(70, 16));

        horizontalLayout_4->addWidget(labelMethod);

        horizontalSpacer_2 = new QSpacerItem(17, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pageComboBox = new QComboBox(verticalFrame);
        pageComboBox->setObjectName(QString::fromUtf8("pageComboBox"));
        pageComboBox->setMinimumSize(QSize(110, 0));
        pageComboBox->setMaximumSize(QSize(120, 24));

        horizontalLayout_4->addWidget(pageComboBox);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(11, 0, 9, 4);
        labelInfo = new QLabel(verticalFrame);
        labelInfo->setObjectName(QString::fromUtf8("labelInfo"));

        horizontalLayout_5->addWidget(labelInfo);


        verticalLayout_2->addLayout(horizontalLayout_5);

        buttonSolution = new QPushButton(centralwidget);
        buttonSolution->setObjectName(QString::fromUtf8("buttonSolution"));
        buttonSolution->setGeometry(QRect(760, 430, 80, 24));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(740, -30, 20, 631));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy1);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        buttonXYWing = new QPushButton(centralwidget);
        buttonXYWing->setObjectName(QString::fromUtf8("buttonXYWing"));
        buttonXYWing->setGeometry(QRect(770, 480, 111, 24));
        buttonXYZWing = new QPushButton(centralwidget);
        buttonXYZWing->setObjectName(QString::fromUtf8("buttonXYZWing"));
        buttonXYZWing->setGeometry(QRect(890, 480, 111, 24));
        buttonXWing = new QPushButton(centralwidget);
        buttonXWing->setObjectName(QString::fromUtf8("buttonXWing"));
        buttonXWing->setGeometry(QRect(770, 520, 111, 24));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 60, 20, 491));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 9, 0, 9);
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMinimumSize(QSize(18, 25));
        label_12->setMaximumSize(QSize(18, 25));
        QFont font1;
        font1.setPointSize(9);
        font1.setItalic(true);
        label_12->setFont(font1);

        verticalLayout_3->addWidget(label_12);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(18, 25));
        label_3->setMaximumSize(QSize(18, 25));
        label_3->setFont(font1);

        verticalLayout_3->addWidget(label_3);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(18, 25));
        label_5->setMaximumSize(QSize(18, 25));
        label_5->setFont(font1);

        verticalLayout_3->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(18, 25));
        label_6->setMaximumSize(QSize(18, 25));
        label_6->setFont(font1);

        verticalLayout_3->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(18, 25));
        label_7->setMaximumSize(QSize(18, 25));
        label_7->setFont(font1);

        verticalLayout_3->addWidget(label_7);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(18, 25));
        label_8->setMaximumSize(QSize(18, 25));
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(label_8);

        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(18, 25));
        label_9->setMaximumSize(QSize(18, 25));
        label_9->setFont(font1);

        verticalLayout_3->addWidget(label_9);

        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMinimumSize(QSize(18, 25));
        label_10->setMaximumSize(QSize(18, 25));
        label_10->setFont(font1);

        verticalLayout_3->addWidget(label_10);

        label_11 = new QLabel(verticalLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(18, 25));
        label_11->setMaximumSize(QSize(18, 25));
        label_11->setFont(font1);

        verticalLayout_3->addWidget(label_11);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 60, 471, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(18, 0, 9, 0);
        label_20 = new QLabel(layoutWidget2);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setMinimumSize(QSize(18, 25));
        label_20->setMaximumSize(QSize(18, 25));
        label_20->setFont(font1);

        horizontalLayout_3->addWidget(label_20);

        label_19 = new QLabel(layoutWidget2);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setMinimumSize(QSize(18, 25));
        label_19->setMaximumSize(QSize(18, 25));
        label_19->setFont(font1);

        horizontalLayout_3->addWidget(label_19);

        label_18 = new QLabel(layoutWidget2);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMinimumSize(QSize(18, 25));
        label_18->setMaximumSize(QSize(18, 25));
        label_18->setFont(font1);

        horizontalLayout_3->addWidget(label_18);

        label_17 = new QLabel(layoutWidget2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMinimumSize(QSize(18, 25));
        label_17->setMaximumSize(QSize(18, 25));
        label_17->setFont(font1);
        label_17->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(label_17);

        label_16 = new QLabel(layoutWidget2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setMinimumSize(QSize(18, 25));
        label_16->setMaximumSize(QSize(18, 25));
        label_16->setFont(font1);

        horizontalLayout_3->addWidget(label_16);

        label_15 = new QLabel(layoutWidget2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMinimumSize(QSize(18, 25));
        label_15->setMaximumSize(QSize(18, 25));
        label_15->setFont(font1);

        horizontalLayout_3->addWidget(label_15);

        label_14 = new QLabel(layoutWidget2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setMinimumSize(QSize(18, 25));
        label_14->setMaximumSize(QSize(18, 25));
        label_14->setFont(font1);

        horizontalLayout_3->addWidget(label_14);

        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(18, 25));
        label_4->setMaximumSize(QSize(18, 25));
        label_4->setFont(font1);

        horizontalLayout_3->addWidget(label_4);

        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMinimumSize(QSize(18, 25));
        label_13->setMaximumSize(QSize(18, 25));
        label_13->setFont(font1);

        horizontalLayout_3->addWidget(label_13);

        buttonSkyScraper = new QPushButton(centralwidget);
        buttonSkyScraper->setObjectName(QString::fromUtf8("buttonSkyScraper"));
        buttonSkyScraper->setGeometry(QRect(890, 520, 111, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1092, 21));
        menuk = new QMenu(menubar);
        menuk->setObjectName(QString::fromUtf8("menuk"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
#if QT_CONFIG(shortcut)
        labelClueNumber->setBuddy(radioButtonNoteMode);
        label->setBuddy(pushButtonClearUndoView);
#endif // QT_CONFIG(shortcut)

        menubar->addAction(menuk->menuAction());
        menuk->addSeparator();
        menuk->addAction(actionlk);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sudoku Solver", nullptr));
        actionlk->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        buttonErase->setText(QCoreApplication::translate("MainWindow", "Erase", nullptr));
        buttonFillPoss->setText(QCoreApplication::translate("MainWindow", "Fill Possibilities", nullptr));
        buttonUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        buttonRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        radioButtonClueEntering->setText(QCoreApplication::translate("MainWindow", "Clue Mode", nullptr));
        labelClueNumber->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        radioButtonNoteMode->setText(QCoreApplication::translate("MainWindow", "Note Mode", nullptr));
        radioButtonSolvingMode->setText(QCoreApplication::translate("MainWindow", "Solving Mode", nullptr));
        buttonReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Command List", nullptr));
        pushButtonClearUndoView->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Method: ", nullptr));
        labelMethod->setText(QCoreApplication::translate("MainWindow", "Solution", nullptr));
        labelInfo->setText(QString());
        buttonSolution->setText(QCoreApplication::translate("MainWindow", "Solution", nullptr));
        buttonXYWing->setText(QCoreApplication::translate("MainWindow", "Y-Wing", nullptr));
        buttonXYZWing->setText(QCoreApplication::translate("MainWindow", "XYZ-Wing", nullptr));
        buttonXWing->setText(QCoreApplication::translate("MainWindow", "X-Wing", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "R1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "R2", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "R3", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "R4", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "R5", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "R6", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "R7", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "R8", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "R9", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "C1", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "C2", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "C3", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "C4", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "C5", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "C6", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "C7", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "C8", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "C9", nullptr));
        buttonSkyScraper->setText(QCoreApplication::translate("MainWindow", "Sky Scraper", nullptr));
        menuk->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

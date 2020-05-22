/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *btSearch;
    QTableWidget *tableWidget_2;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *btNewTable;
    QPushButton *btDeleteTable;
    QPushButton *btInsertData;
    QPushButton *btdeleteData;
    QPushButton *lockButton;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1094, 854);
        MainWindow->setIconSize(QSize(30, 30));
        MainWindow->setAnimated(true);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setMinimumSize(QSize(281, 0));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_4 = new QHBoxLayout(page);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(1, 25));
        label_3->setMaximumSize(QSize(16777215, 25));

        verticalLayout_2->addWidget(label_3);

        listWidget = new QListWidget(page);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_2->addWidget(listWidget);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        comboBox = new QComboBox(page);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(comboBox);

        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 25));
        lineEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(lineEdit);

        btSearch = new QPushButton(page);
        btSearch->setObjectName(QString::fromUtf8("btSearch"));
        btSearch->setMinimumSize(QSize(0, 25));
        btSearch->setMaximumSize(QSize(16777215, 28));

        horizontalLayout_2->addWidget(btSearch);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 3);
        horizontalLayout_2->setStretch(3, 3);
        horizontalLayout_2->setStretch(4, 1);

        verticalLayout_3->addLayout(horizontalLayout_2);

        tableWidget_2 = new QTableWidget(page);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));

        verticalLayout_3->addWidget(tableWidget_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        horizontalLayout_4->addLayout(horizontalLayout_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        horizontalLayout_5->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btNewTable = new QPushButton(centralWidget);
        btNewTable->setObjectName(QString::fromUtf8("btNewTable"));

        verticalLayout->addWidget(btNewTable);

        btDeleteTable = new QPushButton(centralWidget);
        btDeleteTable->setObjectName(QString::fromUtf8("btDeleteTable"));

        verticalLayout->addWidget(btDeleteTable);

        btInsertData = new QPushButton(centralWidget);
        btInsertData->setObjectName(QString::fromUtf8("btInsertData"));

        verticalLayout->addWidget(btInsertData);

        btdeleteData = new QPushButton(centralWidget);
        btdeleteData->setObjectName(QString::fromUtf8("btdeleteData"));

        verticalLayout->addWidget(btdeleteData);

        lockButton = new QPushButton(centralWidget);
        lockButton->setObjectName(QString::fromUtf8("lockButton"));
        lockButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 50, 50);\n"
""));

        verticalLayout->addWidget(lockButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_5->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1094, 25));
        menuBar->setMaximumSize(QSize(16777215, 25));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionNew);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\350\241\250", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\255\227\346\256\265", nullptr));
        btSearch->setText(QCoreApplication::translate("MainWindow", "\346\235\241\344\273\266\346\237\245\346\211\276", nullptr));
        btNewTable->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\250\346\240\274", nullptr));
        btDeleteTable->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\241\250\346\240\274", nullptr));
        btInsertData->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\346\225\260\346\215\256", nullptr));
        btdeleteData->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        lockButton->setText(QCoreApplication::translate("MainWindow", "\350\247\243\351\224\201\350\241\250\346\240\274", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

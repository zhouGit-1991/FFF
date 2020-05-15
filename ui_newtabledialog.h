/********************************************************************************
** Form generated from reading UI file 'newtabledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTABLEDIALOG_H
#define UI_NEWTABLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_newTableDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *deleteBt;
    QPushButton *AddDataBt;
    QPushButton *OKBt;
    QPushButton *CancelBt;

    void setupUi(QDialog *newTableDialog)
    {
        if (newTableDialog->objectName().isEmpty())
            newTableDialog->setObjectName(QString::fromUtf8("newTableDialog"));
        newTableDialog->resize(581, 457);
        verticalLayout_2 = new QVBoxLayout(newTableDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(newTableDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        lineEdit = new QLineEdit(newTableDialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        tableWidget = new QTableWidget(newTableDialog);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        deleteBt = new QPushButton(newTableDialog);
        deleteBt->setObjectName(QString::fromUtf8("deleteBt"));

        horizontalLayout->addWidget(deleteBt);

        AddDataBt = new QPushButton(newTableDialog);
        AddDataBt->setObjectName(QString::fromUtf8("AddDataBt"));

        horizontalLayout->addWidget(AddDataBt);

        OKBt = new QPushButton(newTableDialog);
        OKBt->setObjectName(QString::fromUtf8("OKBt"));

        horizontalLayout->addWidget(OKBt);

        CancelBt = new QPushButton(newTableDialog);
        CancelBt->setObjectName(QString::fromUtf8("CancelBt"));

        horizontalLayout->addWidget(CancelBt);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(newTableDialog);

        QMetaObject::connectSlotsByName(newTableDialog);
    } // setupUi

    void retranslateUi(QDialog *newTableDialog)
    {
        newTableDialog->setWindowTitle(QCoreApplication::translate("newTableDialog", "\346\226\260\345\273\272\350\241\250\346\240\274", nullptr));
        label->setText(QCoreApplication::translate("newTableDialog", "\346\267\273\345\212\240\350\241\250\346\240\274\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("newTableDialog", "\345\255\227\346\256\265\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("newTableDialog", "\345\255\227\346\256\265\347\261\273\345\236\213", nullptr));
        deleteBt->setText(QCoreApplication::translate("newTableDialog", "\345\210\240\351\231\244\345\255\227\346\256\265", nullptr));
        AddDataBt->setText(QCoreApplication::translate("newTableDialog", "\345\242\236\345\212\240\346\225\260\346\215\256\351\241\271", nullptr));
        OKBt->setText(QCoreApplication::translate("newTableDialog", "\347\241\256\350\256\244", nullptr));
        CancelBt->setText(QCoreApplication::translate("newTableDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newTableDialog: public Ui_newTableDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTABLEDIALOG_H

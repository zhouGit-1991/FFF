/********************************************************************************
** Form generated from reading UI file 'insertdatadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTDATADIALOG_H
#define UI_INSERTDATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_insertDataDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *insertDataDialog)
    {
        if (insertDataDialog->objectName().isEmpty())
            insertDataDialog->setObjectName(QString::fromUtf8("insertDataDialog"));
        insertDataDialog->resize(668, 508);
        verticalLayout = new QVBoxLayout(insertDataDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(insertDataDialog);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(insertDataDialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(insertDataDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(insertDataDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(insertDataDialog);

        QMetaObject::connectSlotsByName(insertDataDialog);
    } // setupUi

    void retranslateUi(QDialog *insertDataDialog)
    {
        insertDataDialog->setWindowTitle(QCoreApplication::translate("insertDataDialog", "\346\217\222\345\205\245\346\225\260\346\215\256", nullptr));
        pushButton_3->setText(QCoreApplication::translate("insertDataDialog", "\346\217\222\345\205\245\344\270\200\350\241\214\346\225\260\346\215\256", nullptr));
        pushButton->setText(QCoreApplication::translate("insertDataDialog", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("insertDataDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insertDataDialog: public Ui_insertDataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTDATADIALOG_H

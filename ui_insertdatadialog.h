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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_insertDataDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;

    void setupUi(QDialog *insertDataDialog)
    {
        if (insertDataDialog->objectName().isEmpty())
            insertDataDialog->setObjectName(QString::fromUtf8("insertDataDialog"));
        insertDataDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(insertDataDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(insertDataDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(240, 110, 69, 22));

        retranslateUi(insertDataDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), insertDataDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), insertDataDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(insertDataDialog);
    } // setupUi

    void retranslateUi(QDialog *insertDataDialog)
    {
        insertDataDialog->setWindowTitle(QCoreApplication::translate("insertDataDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insertDataDialog: public Ui_insertDataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTDATADIALOG_H

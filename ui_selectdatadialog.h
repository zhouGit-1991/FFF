/********************************************************************************
** Form generated from reading UI file 'selectdatadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTDATADIALOG_H
#define UI_SELECTDATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_selectDataDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *selectDataDialog)
    {
        if (selectDataDialog->objectName().isEmpty())
            selectDataDialog->setObjectName(QString::fromUtf8("selectDataDialog"));
        selectDataDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(selectDataDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(selectDataDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), selectDataDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), selectDataDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(selectDataDialog);
    } // setupUi

    void retranslateUi(QDialog *selectDataDialog)
    {
        selectDataDialog->setWindowTitle(QCoreApplication::translate("selectDataDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selectDataDialog: public Ui_selectDataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTDATADIALOG_H

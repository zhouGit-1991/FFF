/********************************************************************************
** Form generated from reading UI file 'newdbdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDBDIALOG_H
#define UI_NEWDBDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_newDBDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *newDBDialog)
    {
        if (newDBDialog->objectName().isEmpty())
            newDBDialog->setObjectName(QString::fromUtf8("newDBDialog"));
        newDBDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(newDBDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(newDBDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), newDBDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newDBDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(newDBDialog);
    } // setupUi

    void retranslateUi(QDialog *newDBDialog)
    {
        newDBDialog->setWindowTitle(QCoreApplication::translate("newDBDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newDBDialog: public Ui_newDBDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDBDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'updatadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATADIALOG_H
#define UI_UPDATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_updataDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *updataDialog)
    {
        if (updataDialog->objectName().isEmpty())
            updataDialog->setObjectName(QString::fromUtf8("updataDialog"));
        updataDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(updataDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(updataDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), updataDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), updataDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(updataDialog);
    } // setupUi

    void retranslateUi(QDialog *updataDialog)
    {
        updataDialog->setWindowTitle(QCoreApplication::translate("updataDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class updataDialog: public Ui_updataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATADIALOG_H

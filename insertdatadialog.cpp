#include "insertdatadialog.h"
#include "ui_insertdatadialog.h"

insertDataDialog::insertDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insertDataDialog)
{
    ui->setupUi(this);
}

insertDataDialog::~insertDataDialog()
{
    delete ui;
}

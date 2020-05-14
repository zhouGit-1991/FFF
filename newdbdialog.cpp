#include "newdbdialog.h"
#include "ui_newdbdialog.h"

newDBDialog::newDBDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newDBDialog)
{
    ui->setupUi(this);
}

newDBDialog::~newDBDialog()
{
    delete ui;
}

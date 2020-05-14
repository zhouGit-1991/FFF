#include "updatadialog.h"
#include "ui_updatadialog.h"

updataDialog::updataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::updataDialog)
{
    ui->setupUi(this);
}

updataDialog::~updataDialog()
{
    delete ui;
}

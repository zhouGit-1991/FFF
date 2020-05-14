#include "selectdatadialog.h"
#include "ui_selectdatadialog.h"

selectDataDialog::selectDataDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectDataDialog)
{
    ui->setupUi(this);
}

selectDataDialog::~selectDataDialog()
{
    delete ui;
}

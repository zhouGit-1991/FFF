#include "newtabledialog.h"
#include "ui_newtabledialog.h"
#include <QTableWidget>
#include <iostream>
#include <QStringList>
newTableDialog::newTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newTableDialog)
{
    ui->setupUi(this);



}

newTableDialog::~newTableDialog()
{
    delete ui;
}

void newTableDialog::on_AddDataBt_clicked()
{
    QComboBox * box = new QComboBox;
    QStringList _list;
    _list<<"NULL"<<"INTEGER"<<"REAL"<<"TEXT"<<"BLOB";
    box->addItems(_list);
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(row+1);
    ui->tableWidget->setCellWidget(row,1,box);



}

void newTableDialog::on_deleteBt_clicked()
{
    std::cout<<"on_deleteBt_clicked";
    QList<QTableWidgetSelectionRange >  _list= ui->tableWidget->selectedRanges();//所有选中的项

    int count=_list.count();
    QVector<int>vecRows;
     std::cout<<"count "<<count;
    for(int i=0;i<count;i++)
    {
        int row=_list.at(i).topRow();//获取选中的行
       if(!vecRows.contains(row))
       {
           vecRows.append(row);
           std::cout<<row;
           ui->tableWidget->removeRow(row);
       }

    }

}

void newTableDialog::on_OKBt_clicked()
{
    std::cout<<"OK clicked";
    //遍历整个表格

    for(int row = 0; row < ui->tableWidget->rowCount();++row)
    {
        m_strTableData += ui->tableWidget->item(row,0)->text();
        m_strTableData+=" \"";
        QComboBox * box = (QComboBox *)ui->tableWidget->cellWidget(row,1);
        m_strTableData+= box->currentText();
        m_strTableData+="\",";

    }
     m_strTableData= m_strTableData.left(m_strTableData.length()-1);

    emit sendTableData(ui->lineEdit->text(),m_strTableData);

}

void newTableDialog::on_CancelBt_clicked()
{
}

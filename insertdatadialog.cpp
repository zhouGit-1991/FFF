#include "insertdatadialog.h"
#include "ui_insertdatadialog.h"
#include <QUuid> 
insertDataDialog::insertDataDialog(QStringList head, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::insertDataDialog)
{
    qRegisterMetaType<StringMapVec>("StringMapVec");
    ui->setupUi(this);
    
    ui->tableWidget->setColumnCount(head.count());
    ui->tableWidget->setHorizontalHeaderLabels(head);//初始化表头
    
}

insertDataDialog::~insertDataDialog()
{
    delete ui;
}

void insertDataDialog::on_pushButton_3_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    
    QString guid = QUuid::createUuid().toString();
    ui->tableWidget->setItem(ui->tableWidget->rowCount() - 1, 0, new QTableWidgetItem(guid));
}

void insertDataDialog::on_pushButton_2_clicked()
{
    close();
    deleteLater();
}

void insertDataDialog::on_pushButton_clicked()
{
    //获取所有数据，打包数据发送信号
    QVector<QMap<QString, QString>> dataVec;
    int rowCount = ui->tableWidget->rowCount();
    int colCount = ui->tableWidget->columnCount();
    
    for (int _row = 0; _row < rowCount; ++_row)
    {
        QMap<QString, QString> dataMap;
        for (int _col = 0; _col < colCount; ++_col)
        {
            QString _key = ui->tableWidget->horizontalHeaderItem(_col)->text();
            _key = _key.left(_key.indexOf('('));
            //
            if (!ui->tableWidget->item(_row, _col))
            {
                QMessageBox _box;
                _box.setText(QString::fromLocal8Bit("检查数据的正确性 行 :%1，  列 :%2")
                    .arg(QString::number(_row))
                        .arg(QString::number(_col))
                        );
                _box.exec();
                return;

            }
            QString _value = ui->tableWidget->item(_row, _col)->text();
            dataMap[ _key]= _value;
        }
        dataVec.append(dataMap);
    }
    emit sendInsertData(dataVec);


}

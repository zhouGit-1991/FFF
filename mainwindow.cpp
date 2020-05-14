#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <QFileDialog>
extern vector<map<string,string>> m_res;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionOpen,&QAction::triggered,this,&MainWindow::on_actionOpen_clicked);
    connect(ui->actionNew,&QAction::triggered,this,&MainWindow::on_actionNew_clicked);
    //
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDB(string dbName)
{
    if(!sql.openDB(dbName))
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(sql.getErr()));

    }
    else
    {
        QString text = /*"数据库名称:"+*/QString::fromStdString(dbName);
        text = text.right(text.length() - text.lastIndexOf('/')-1);
        ui->label_2->setText(text);

        std::cout<<"11111"<<endl;
        sql.ExcuteSql( "SELECT name FROM sqlite_master WHERE type='table' ORDER BY name;",false);
        for (int i = 0; i < m_res.size(); ++i)
        {
            map<string, string>::iterator _it = m_res[i].begin();
            for (; _it != m_res[i].end();)
            {
                ui->listWidget->addItem(QString::fromStdString(_it->second));
                ++_it;
            }

        }

        

    }


}

void MainWindow::createTable(string tableName,string createData)
{
    if(!sql.createTable(tableName,createData/*"姓名 text,性别 text"*/))
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString((sql.getErr())));
        msgBox.exec();
        return;
    }

    QMessageBox msgBox;
    msgBox.setText("sucess create Table");
    msgBox.exec();

}



void MainWindow::createDB(string dbName)
{
    if(!sql.openDB(dbName))
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(sql.getErr()));
        msgBox.exec();
    }
}

void MainWindow::deleteTable(string tableName)
{
    if(!sql.deleteTable(tableName))
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(sql.getErr()));
        msgBox.exec();
    }
}

void MainWindow::insertData(string tableName, map<string,string> insertMap)
{
    if(!sql.insertData(tableName,insertMap))
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(sql.getErr()));
        msgBox.exec();
    }
}

void MainWindow::deleteData(string tableName, map<string,string> deleteMap)
{
    if(!sql.deleteData(tableName,deleteMap))
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(sql.getErr()));
        msgBox.exec();
    }
}

void MainWindow::selectData(string clumn,string tableName,map<string,string> _tmap)
{
    if(!sql.selectSql(clumn,tableName,_tmap))
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(sql.getErr()));
        msgBox.exec();
    }

}

void MainWindow::on_actionNew_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("New Config"),
            "",
            tr("DataBase Files (*.db)"));

        if (fileName.isEmpty())
        {
            QMessageBox msgBox;
            msgBox.setText(QString("新建的数据库不合法!"));
            msgBox.exec();
           return;
        }
        else
        {
           openDB(fileName.toStdString());
        }
}

void MainWindow::on_actionOpen_clicked()
{

    QString file_name = QFileDialog::getOpenFileName(this,
            tr("Open File"),
            "",
            tr("DataBase Files (*.db)"),
            0);
        if (file_name.isEmpty())
        {
           return;
        }
        else{
           openDB(file_name.toStdString());
        }

}

void MainWindow::on_btNewTable_clicked()
{
    if(!sql.isOpen())
    {
        QMessageBox msgBox;
        msgBox.setText(QString("数据库没有打开!"));
        msgBox.exec();
        //return;
    }
    newTableDialog *dialog = new newTableDialog;
    dialog->show();
    QString _sql;
    connect(dialog,&newTableDialog::sendTableData,this,&MainWindow::slotGetNewTable);
    dialog->exec();

}

void MainWindow::on_btDeleteTable_clicked()
{
    //删除表格：
}

void MainWindow::on_btInsertData_clicked()
{
}

void MainWindow::on_btdeleteData_clicked()
{
}

void MainWindow::on_btUpdata_clicked()
{
}

void MainWindow::on_btSelectData_clicked()
{
}

void MainWindow::slotGetNewTable(QString tableName, QString _sql)
{
    m_strSsql = _sql;
    m_tableName = tableName;
    newTableDialog* table =static_cast<newTableDialog*> (sender());
    createTable(tableName.toStdString(),_sql.toStdString());
    table->close();


}




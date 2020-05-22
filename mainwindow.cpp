#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDataStream>

#include <QFileDialog>
#include <QMapIterator>
#include <QSharedPointer>
extern vector<map<string,string>> m_res;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_allowChangeTable(false)
{
    ui->setupUi(this);
    connect(ui->actionOpen,&QAction::triggered,this,&MainWindow::on_actionOpen_clicked);
    connect(ui->actionNew,&QAction::triggered,this,&MainWindow::on_actionNew_clicked);
    connect(ui->listWidget, &QListWidget::itemClicked, this, &MainWindow::slotUpdataTable);

    connect(ui->tableWidget_2, &QTableWidget::doubleClicked, this, &MainWindow::itemDoubleClicked);
    //connect(ui->tableWidget_2, &QTableWidget::itemChanged, this, &MainWindow::onbtUpdata);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDB(string dbName)
{
    slotUpdataTable(NULL);
    sql.closeDB();
    if(!sql.openDB(dbName))
    {
        showMsg(QString::fromStdString(sql.getErr()));
    }
    else
    {
        for (;ui->listWidget->count()>0;)
        {
            ui->listWidget->takeItem(0);
        }
     
        ui->listWidget->clear();
        QString text = /*"数据库名称:"+*/QString::fromStdString(dbName);
        text = text.right(text.length() - text.lastIndexOf('/')-1);
        setWindowTitle(text);
        m_res.clear();
        //查找数据库中的表格数量
        vector<string> vec = sql.getDataBaseAllTables();
        for (int i = 0; i < vec.size(); ++i)
        {
            ui->listWidget->addItem(QString::fromStdString(vec[i]));
        }
    }

}

void MainWindow::createTable(string tableName,string createData)
{
    if(!sql.createTable(tableName,createData/*"姓名 text,性别 text"*/))
    {
        
        showMsg(QString::fromStdString((sql.getErr())));        
        return;
    }

    showMsg("sucess create Table");
    openDB(m_strDbName.toStdString());

}



void MainWindow::createDB(string dbName)
{
    if(!sql.openDB(dbName))
    {
        showMsg(QString::fromStdString(sql.getErr()));
    }
}

void MainWindow::deleteTable(string tableName)
{
    if(!sql.deleteTable(tableName))
    {
        showMsg(QString::fromStdString(sql.getErr()));
    }
}

void MainWindow::insertData(string tableName, map<string,string> insertMap)
{
    if(!sql.insertData(tableName,insertMap))
    {
        showMsg(QString::fromStdString(sql.getErr()));
    }
}

void MainWindow::deleteData(string tableName, map<string,string> deleteMap)
{
    if(!sql.deleteData(tableName,deleteMap))
    {
        showMsg(QString::fromStdString(sql.getErr()));
    }
}

void MainWindow::selectData(string clumn,string tableName,map<string,string> _tmap)
{
    if(!sql.selectSql(clumn,tableName,_tmap))
    {
        showMsg(QString::fromStdString(sql.getErr()));
    }

}

void MainWindow::showMsg(QString msg)
{
    
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}

void MainWindow::on_actionNew_clicked()
{
    if (isConnect)
    {
        disconnect(ui->tableWidget_2, &QTableWidget::itemChanged, this, &MainWindow::onbtUpdata);
        isConnect = false;
    }
    
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("New Config"),
            "",
            tr("DataBase Files (*.db)"));

        if (fileName.isEmpty())
        {
            showMsg(QString::fromLocal8Bit("新建的数据库不合法!"));
            
           return;
        }
        else
        {
           openDB(fileName.toStdString());
        }
}


void MainWindow::on_actionOpen_clicked()
{
    if (isConnect)
    {
        disconnect(ui->tableWidget_2, &QTableWidget::itemChanged, this, &MainWindow::onbtUpdata);
        isConnect = false;
    }
    m_strDbName = QFileDialog::getOpenFileName(this,
            tr("Open File"),
            "",
            tr("DataBase Files (*.db)"),
            0);
    if (m_strDbName.isEmpty())
    {
        return;
    }
    else{
        openDB(m_strDbName.toStdString());
    }

}

void MainWindow::on_btNewTable_clicked()
{
    if (isConnect)
    {
        disconnect(ui->tableWidget_2, &QTableWidget::itemChanged, this, &MainWindow::onbtUpdata);
        isConnect = false;
    }
    if(!sql.isOpen())
    {
       
        showMsg(QString("数据库没有打开!"));
        return;

    }
    newTableDialog *dialog = new newTableDialog;
    dialog->show();
    QString _sql;
    connect(dialog,&newTableDialog::sendTableData,this,&MainWindow::slotGetNewTableMsg);
    dialog->exec();

}

void MainWindow::on_btDeleteTable_clicked()
{
    //删除表格：
    if (isConnect)
    {
        disconnect(ui->tableWidget_2, &QTableWidget::itemChanged, this, &MainWindow::onbtUpdata);
        isConnect = false;
    }
    
    if(ui->listWidget->currentItem())
    {
        QString tableName = ui->listWidget->currentItem() ->text();
        sql.deleteTable(tableName.toStdString());
        openDB(m_strDbName.toStdString());
        m_tableName.clear();
    }
    slotUpdataTable(NULL);
     
}

void MainWindow::on_btInsertData_clicked()
{
    //首先获取数据库表 获取表的类型和字段
    
    if (isConnect)
    {
        disconnect(ui->tableWidget_2, &QTableWidget::itemChanged, this, &MainWindow::onbtUpdata);
        isConnect = false;
    }
    QStringList _tableHeadList;
    if (ui->listWidget->currentItem())
    {
        m_tableName = ui->listWidget->currentItem()->text();
        vector<map<string,string>> vec = sql.getTableAttributeByName(m_tableName.toStdString());

        for (int i = 0; i < vec.size(); ++i)
        {
            map<string, string>::iterator _it = vec[i].begin();
            QString strH;
            while (_it != vec[i].end())
            {
                
                QString _key = QString::fromStdString(_it->first);
                if ("name" != _key && "type" != _key)
                {
                    ++_it;
                    continue;
                }
                QString str ;
                if ("name" == _key)
                {
                    str += QString::fromStdString(_it->second);
                    str += "(";
                }
                else
                {
                    str += QString::fromStdString(_it->second);
                    str += ")";
                }
               
                strH += str;
                ++_it;
            }
            _tableHeadList << strH;
        }
        insertDataDialog* dialog = new insertDataDialog(_tableHeadList);
        dialog->show();
        connect(dialog, &insertDataDialog::sendInsertData, this, &MainWindow::slotInsertData);

    }
}

void MainWindow::on_btdeleteData_clicked()
{
    if (isConnect)
    {
        disconnect(ui->tableWidget_2, &QTableWidget::itemChanged, this, &MainWindow::onbtUpdata);
        isConnect = false;
    }
    if (!ui->tableWidget_2->currentItem())
    {
        return;
    }
    int row = ui->tableWidget_2->row(ui->tableWidget_2->currentItem());
    map<string, string> _map;
    _map["UUID"] = ui->tableWidget_2->item(row, 0)->text().toStdString();
    sql.deleteData(m_tableName.toStdString(), _map);
    slotUpdataTable(NULL);
    
}

void MainWindow::on_lockButton_clicked()
{
    QAbstractItemView::EditTriggers ediTriger = ui->tableWidget_2->editTriggers();
    int i = 0;
    if (m_allowChangeTable)
    {
        m_allowChangeTable = !m_allowChangeTable;
        ui->lockButton->setStyleSheet("background-color: rgb(255, 50, 50);");
        ui->lockButton->setText("解锁表格");
        ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    else
    {

        
        m_allowChangeTable = !m_allowChangeTable;
        ui->lockButton->setStyleSheet("background-color: rgb(85, 255, 0);");
        ui->lockButton->setText("锁定表格");
        
        ui->tableWidget_2->setEditTriggers(QAbstractItemView::DoubleClicked| QAbstractItemView::SelectedClicked | QAbstractItemView::EditKeyPressed);
    }
}

void MainWindow::onbtUpdata(QTableWidgetItem* item)
{
    //更改数据
    //获取单元的行和列
    int row = ui->tableWidget_2->row(item);
    int col = ui->tableWidget_2->column(item);
    QString _key = m_tableHeadList.at(col);
    QString _value = item->text();
    
    QString UUID = ui->tableWidget_2->item(row, 0)->text();
    map<string, string> conditionMap;
    conditionMap["UUID"] = UUID.toStdString();
    map<string, string> setValueMap;
    setValueMap[_key.toStdString()] = _value.toStdString();
    sql.updateData(m_tableName.toStdString(), setValueMap, conditionMap);
}

void MainWindow::on_btSearch_clicked()
{
    if (isConnect)
    {
        disconnect(ui->tableWidget_2, &QTableWidget::itemChanged, this, &MainWindow::onbtUpdata);
        isConnect = false;
    }
    //条件查找目前界面支持一个字段
    QString _conditionKey = ui->comboBox->currentText();
    QString _conditionValue = ui->lineEdit->text();
    map<string, string> _map;
    _map[_conditionKey.toStdString()] = _conditionValue.toStdString();
    if (!sql.selectSql("", m_tableName.toStdString(), _map))
    {
        showMsg(QString("数据库没有打开!"));       
        return;
    }
    
    //将数据更新到tableWidget2里

    //更新查找到的表格数据。

    vector<map<string, string>> _vec = m_res;
    int colCount = 0;
    if (_vec.size() > 0 && _vec[0].size() > 0)
    {
        colCount = _vec[0].size();
        map<string, string>::iterator _itS = _vec[0].begin();

        while (_itS != _vec[0].end())
        {
            m_tableHeadList << QString::fromStdString(_itS->first);
            ++_itS;
        }
        ui->comboBox->clear();
        ui->comboBox->addItems(m_tableHeadList);

        ui->tableWidget_2->setRowCount(_vec.size());
        ui->tableWidget_2->setColumnCount(colCount);
        ui->tableWidget_2->setHorizontalHeaderLabels(m_tableHeadList);
        for (int i = 0; i < _vec.size(); ++i)
        {
            map<string, string>::iterator _it = _vec[i].begin();

            while (_it != _vec[i].end())
            {
                QString text = QString::fromStdString(_it->second);
                int _col = m_tableHeadList.indexOf(QString::fromStdString(_it->first));
                ui->tableWidget_2->setItem(i, _col, new QTableWidgetItem(text));
                ++_it;
            }
        }
    }
    else
    {
        ui->tableWidget_2->clear();
        ui->tableWidget_2->setColumnCount(0);
        ui->tableWidget_2->setRowCount(0);
    }
}

void MainWindow::itemDoubleClicked()
{
    if (!isConnect)
    {
        connect(ui->tableWidget_2, &QTableWidget::itemChanged, this, &MainWindow::onbtUpdata);
        isConnect = true;
    }
    
}

void MainWindow::slotGetNewTableMsg(QString tableName, QString _sql)
{
    m_strSsql = _sql;
    m_tableName = tableName;
    newTableDialog* table =static_cast<newTableDialog*> (sender());
    createTable(tableName.toStdString(),_sql.toStdString());
    table->close();
    table->deleteLater();
}

void MainWindow::slotUpdataTable(QListWidgetItem* item)
{
    //获取表名称   显示表的信息
    m_tableName.clear();
    if (isConnect)
    {
        disconnect(ui->tableWidget_2, &QTableWidget::itemChanged, this, &MainWindow::onbtUpdata);
        isConnect = false;
    }
    
    QString tableName = item? item->text(): m_tableName;

    vector<map<string,string>> _vec = sql.getDataBytable(tableName.toStdString());
    
    int colCount = 0;
    if (_vec.size() > 0 && _vec[0].size() > 0)
    {
        colCount = _vec[0].size();
        map<string, string>::iterator _itS = _vec[0].begin();
        m_tableHeadList.clear();
        while (_itS != _vec[0].end())
        {
            m_tableHeadList << QString::fromStdString(_itS->first);
            ++_itS;
        }
        ui->comboBox->clear();
        ui->comboBox->addItems(m_tableHeadList);
        
        ui->tableWidget_2->setRowCount(_vec.size());
        ui->tableWidget_2->setColumnCount(colCount);
        ui->tableWidget_2->setHorizontalHeaderLabels(m_tableHeadList);
        for (int i = 0; i < _vec.size(); ++i)
        {
            map<string, string>::iterator _it = _vec[i].begin();

            while (_it != _vec[i].end())
            {
                QString text = QString::fromStdString(_it->second);
                int _col = m_tableHeadList.indexOf(QString::fromStdString(_it->first));
                ui->tableWidget_2->setItem(i, _col, new QTableWidgetItem(text));
                ++_it;
            }
        }
    }
    else
    {
        ui->tableWidget_2->clear();
        ui->tableWidget_2->setColumnCount(0);
        ui->tableWidget_2->setRowCount(0);
    }
}

void MainWindow::slotInsertData(const StringMapVec& vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        map<string, string> _map;
        QMapIterator<QString, QString> _it(vec[i]);
        while (_it.hasNext())
        {
            _it.next();
            _map[_it.key().toStdString()] = _it.value().toStdString();

        }
       
        sql.insertData(m_tableName.toStdString(), _map);
    }

    insertDataDialog* dia = static_cast<insertDataDialog*>(sender());
    dia->close();
    dia->deleteLater();
    slotUpdataTable(NULL);
}

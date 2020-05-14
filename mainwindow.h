#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>
#include "sqliteoperat.h"

#include "newtabledialog.h"


using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //打开数据库
    void openDB(string dbName);



    //创建数据库
    void createDB(string dbName);

    //创建表格
    void createTable(string tableName,string createData);

    //删除表格
    void deleteTable(string tableName);

    //增加数据

    void insertData(string tableName, map<string, string> insertMap);

    //删除数据
    void deleteData(string tableName, map<string, string> deleteMap);
    //修改数据

    //查询数据
    void selectData(string, string tableName, map<string, string> _tmap);

public slots:
    void on_actionNew_clicked();
    void on_actionOpen_clicked();
    void on_btNewTable_clicked();
    void on_btDeleteTable_clicked();
    void on_btInsertData_clicked();
    void on_btdeleteData_clicked();
    void on_btUpdata_clicked();
    void on_btSelectData_clicked();

    void slotGetNewTable(QString tableName,QString _sql);
    
private:

    QString m_strSsql;
    QString m_tableName;
    Ui::MainWindow *ui;
    sqliteOPERAT sql;


};

#endif // MAINWINDOW_H

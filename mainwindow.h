#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>

#include <QListWidgetItem>
#include "sqliteoperat.h"

#include "insertdatadialog.h"
#include "newtabledialog.h"
#include <QTableWidgetItem>

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

private:
    void showMsg(QString msg);
public slots:
    void on_actionNew_clicked();//新建数据库菜单
    void on_actionOpen_clicked();//打开数据库菜单
    void on_btNewTable_clicked();//新建表格
    void on_btDeleteTable_clicked();//删除表格被按下
    void on_btInsertData_clicked();//插入按钮按下，弹出插入数据的界面
    void on_btdeleteData_clicked();//删除一行数据
    void on_lockButton_clicked();//锁定按钮被按下事件，用来切换是否允许修改表格内容的事件
    void onbtUpdata(QTableWidgetItem* item);//更改表格数据
    
    
    void on_btSearch_clicked();

    void itemDoubleClicked();//双击表格中的数据
    void slotGetNewTableMsg(QString tableName,QString _sql);//获取新表信息
    void slotUpdataTable(QListWidgetItem* item);//更新tableWidget
    void slotInsertData(const StringMapVec& vec);

    
    
private:
    bool m_allowChangeTable;
    QStringList m_tableHeadList;//表格的表头
    QString m_strDbName;
    QString m_strSsql;//执行sql语句
    QString m_tableName;//当前的表名
    Ui::MainWindow *ui;
    sqliteOPERAT sql;

    bool isConnect = false;


};

#endif // MAINWINDOW_H

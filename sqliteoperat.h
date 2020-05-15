#ifndef SQLITEOPERAT_H
#define SQLITEOPERAT_H
#include <iostream>
#include "sqlite3.h"
#include <map>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

enum EXSQLTYPE
{
    EX_INIT = 0,//默认值
    EX_SAVE,//不删除之前的字段
    EX_ATTR//查询表格字段名称和类型用的

};

class sqliteOPERAT
{
public:
    sqliteOPERAT();
    ~sqliteOPERAT();


    //创建一个表  返回是否正确创建 create数据名和类型之间使用英文逗号分割
    bool createTable(string tableName, string createData);

    //打开数据库
    bool openDB(string dbName);

    // 关闭数据库
    bool closeDB();

    //执行指定的sql语句被
    //返回值表示执行后查询的结果数
    //如select函数返回满足条件的个数，0表示没有查询到结果。
    bool ExcuteSql(string sql, EXSQLTYPE ex_type = EX_INIT);

    //执行指定的sql语句被
    //返回值表示执行后查询的结果数
    //如select函数返回满足条件的个数，0表示没有查询到结果。
    bool selectSql(string clumn, string tableName, map<string, string> condition);

    //更改数据 tableName 表名，
    //setValue 要更改的map表  key是列名 value是更改值
    //condition是更改条件的map表，key是列名 value是限定条件列的值。
    bool updateData(string tableName,map<string,string> setValue, map<string,string> condition);

    //增加数据：tableName 表名，insertValue是增加数据的列值map表，
    bool insertData(string tableName, map<string, string> insertValue);

    //获取所有的表格名称
    vector<string> getDataBaseAllTables();

    //根据表名称获取表的所有字段及类型
    vector<map<string,string>> getTableAttributeByName(string tableName);

    //根据表格名称获取表格中的数据
    vector<map<string, string>> getDataBytable(string tableName);


    //删除表中的数据
    //condition是删除条件的map表，key是列名 value是限定条件列的值。
    bool deleteData(string tableName, map<string, string> condition);

    bool deleteTable(string tableName);
    //错误描述
    string getErr();

    map<string,string> getResult();
    bool isOpen(){ return m_isOpen;}
private:
    bool m_isOpen;
    string m_strErr;
    sqlite3 *m_pDB;

};

#endif // SQLITEOPERAT_H

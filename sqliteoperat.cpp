#include "sqliteoperat.h"
//#include 
vector<map<string,string>> m_res;
static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    cout<<"call back"<<endl;
    if(NotUsed == "T")
    {
        m_res.clear();
    }

    for(int i=0; i<argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        map<string, string> _map;
        _map[azColName[i]] = argv[i];
        m_res.push_back(_map);
   }
   return 0;
}

sqliteOPERAT::sqliteOPERAT():
    m_isOpen(false)
  ,m_pDB(NULL)
{

}

sqliteOPERAT::~sqliteOPERAT()
{
    {
        if(m_pDB)
        {
            closeDB();
        }
    }
}


bool sqliteOPERAT::createTable(string tableName, string createData)
{
    char* zErrMsg;

    string sql;
    sql = "CREATE TABLE "+tableName+"("+createData+");";

    return ExcuteSql(sql);

}

bool sqliteOPERAT::openDB(string dbName)
{
    int rc;
    rc = sqlite3_open_v2(dbName.c_str(), &m_pDB,SQLITE_OPEN_READWRITE|SQLITE_OPEN_CREATE,NULL);
    if(rc )
    {
        m_strErr = sqlite3_errmsg(m_pDB);
        cout << m_strErr<<" openDB Err "<< sqlite3_errmsg(m_pDB)<<endl;
        m_isOpen = false;
        return false;
    }
     cout << m_strErr<<" openDB Err "<< sqlite3_errmsg(m_pDB)<<endl;

    m_strErr.clear();
    m_isOpen = true;

    return true;
}

bool sqliteOPERAT::closeDB()
{
    if(SQLITE_OK == sqlite3_close(m_pDB))
    {
        return true;
    }
    return false;
}

bool sqliteOPERAT::ExcuteSql(string sql ,bool isDelete)
{
    char* zErrMsg;
    char* _arg = new char[2];
    if (isDelete)
    {
        strcpy(_arg, "T");
    }
    else
    {
        strcpy(_arg, "F");
    }
    
    cout <<"\n sqliteOPERAT::ExcuteSql sql =   "<<sql<<endl;
    int rc = sqlite3_exec(m_pDB, sql.c_str(), callback, _arg, &zErrMsg);
    if( rc != SQLITE_OK ){
        m_strErr = zErrMsg;
        sqlite3_free(zErrMsg);
        return false;
    }

    return true;

}

bool sqliteOPERAT::selectSql(string clumn,string tableName,map<string,string> condition)
{
    m_res.clear();
    string sql = "SELECT ";
    if(clumn.empty())
    {
        sql += "* FROM ";
        sql+=tableName;
    }
    else
    {
        sql+=clumn;
        sql+=" FROM ";
        sql+=tableName;
    }
    if(condition.size()!=0)
    {
        sql +=" WHERE (";
        map<string,string>::iterator  _it = condition.begin();
        while(_it!=condition.end())
        {
            sql+=_it->first;
            sql+=" = \"";
            sql+=_it->second;
            _it++;
            sql+="\" AND ";
        }
        sql.erase(sql.length()-5,5);

        sql+=")";
    }
    sql+=";";
    return ExcuteSql(sql);
}

bool sqliteOPERAT::updateData(string tableName, map<string, string> setValue, map<string, string> condition)
{

    /*
sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1; "

*/
    if(setValue.size() == 0)
    {
        m_strErr = " update Data is Empty";
        return false;
    }

    string sql = "UPDATE ";
    sql +=tableName;
    sql+=" set ";

    map<string,string>::iterator  _itS = setValue.begin();
    do
    {
        sql+=_itS->first;
        sql+=" = \"";

        sql+=_itS->second;
        sql+="\", ";

        _itS++;

    }while(_itS != setValue.end());
    sql.erase(sql.length()-2,2);

    if(condition.size()>0)
    {
        sql+= " WHERE (";
        map<string,string>::iterator  _itC = condition.begin();
        while(_itC != condition.end())
        {
            sql+=_itC->first;
            sql+=" = \"";
            sql+=_itC->second;
            sql+="\" AND ";
            _itC++;
        }
        sql.erase(sql.length()-5,5);

        sql+=")";
    }
    sql+=" ;";
    return ExcuteSql(sql);


}

bool sqliteOPERAT::insertData(string tableName, map<string, string>insertValue)
{
    if(insertValue.size() == 0)
    {
        return false;
    }

    string sql = "INSERT INTO ";
    sql+=tableName;
    sql+=" (";

    map<string,string>::iterator  _it = insertValue.begin();
    string _column;
    string _values;
    while(_it!=insertValue.end())
    {
        _column+=_it->first;
        _column+=",";
        _values+="\"";
        _values+=_it->second;
        _values+="\",";
        _it++;

    }

    _column.erase(_column.length()-1,1);
    _values.erase(_values.length()-1,1);
    sql+=_column;
    sql+=") VALUES ";
    sql+="(";
    sql+=_values;
    sql+=");";
    return ExcuteSql(sql);

}

vector<string> sqliteOPERAT::getDataBaseAllTables()
{
    vector <string> vec;
    char *szError = NULL;
    char**dbNames=NULL;
    int row,col;
    string sql = "SELECT name FROM sqlite_master WHERE type='table' ORDER BY name";
    int result = sqlite3_get_table( m_pDB,sql.c_str(),&dbNames,&row,&col,&szError);
    //dbResult就是查道询结果，row和col分别是返回结果集的行数（回包含表头）和列数
    if( szError )
    {
        m_strErr = szError;
        sqlite3_free(szError);

        return vec;
     }
    else
    {
        int i = 0;
        while(*dbNames)
        {
            if(0 < i)
            {
                cout<<i<<endl;
                cout<< *dbNames<<endl;
                vec.push_back(string(*dbNames));
            }
            ++dbNames;
            ++i;
        }
    }
    std::cout<<"eee"<<endl;
    return vec;

}

bool sqliteOPERAT::deleteData(string tableName, map<string, string> condition)
{
    if(tableName.empty())
    {
        cout<<"------"<<tableName<<"-----hhhhh"<<endl;
        return false;
    }
    string sql = "DELETE from ";
    sql+= tableName;
    sql+=" WHERE (";

    map<string,string>::iterator  _it = condition.begin();
    while(_it != condition.end())
    {
        sql+=_it->first;
        sql+=" = \"";
        sql+=_it->second;
        sql+="\" AND ";
        _it++;
    }

    sql.erase(sql.length()-5,5);
    sql+=");";

    std::cout<<"delete sql "<<sql<<endl;
    return ExcuteSql(sql);

}

bool sqliteOPERAT::deleteTable(string tableName)
{
    string sql = "DROP TABLE "+tableName+";";
    return ExcuteSql(sql);

}

string sqliteOPERAT::getErr()
{
    return m_strErr;
}

//map<string, string> sqliteOPERAT::getResult()
//{
//    map<string, string>::iterator _it = m_res.begin();
//
//    while(_it!=m_res.end())
//    {
//        cout<<_it->first<<"  "<<_it->second;
//        _it++;
//    }
//    cout <<endl;
//    return m_res;
//}

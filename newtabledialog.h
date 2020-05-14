#ifndef NEWTABLEDIALOG_H
#define NEWTABLEDIALOG_H

#include <QDialog>
#include <QComboBox>
#include "newtabledialog.h"


namespace Ui {
class newTableDialog;
}

//创建表格UI类
class newTableDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit newTableDialog(QWidget *parent = 0);
    ~newTableDialog();
public slots:
    void on_AddDataBt_clicked();
    void on_deleteBt_clicked();
    void on_OKBt_clicked();
    void on_CancelBt_clicked();
    
signals:
    void sendTableData(QString tableName,QString _tableData);
private:
    QString m_strTableData;//姓名 text,性别 text

    Ui::newTableDialog *ui;
};

#endif // NEWTABLEDIALOG_H

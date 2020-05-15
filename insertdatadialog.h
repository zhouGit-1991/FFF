#ifndef INSERTDATADIALOG_H
#define INSERTDATADIALOG_H
#include <QMetatype>
#include <QDialog>
#include <QMessageBox>

typedef QVector<QMap<QString, QString>> StringMapVec;

namespace Ui {
class insertDataDialog;
}

class insertDataDialog : public QDialog
{
    Q_OBJECT
    
public:
    //显示构造函数 第一个字符串是设置ui表格头
    explicit insertDataDialog(QStringList head, QWidget *parent = 0);
    ~insertDataDialog();
    
public slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
signals:
    void sendInsertData(const StringMapVec & vec);
private:
    Ui::insertDataDialog *ui;
};

#endif // INSERTDATADIALOG_H

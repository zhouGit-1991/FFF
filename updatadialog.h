#ifndef UPDATADIALOG_H
#define UPDATADIALOG_H

#include <QDialog>

namespace Ui {
class updataDialog;
}

class updataDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit updataDialog(QWidget *parent = 0);
    ~updataDialog();
    
private:
    Ui::updataDialog *ui;
};

#endif // UPDATADIALOG_H

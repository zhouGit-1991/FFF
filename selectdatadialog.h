#ifndef SELECTDATADIALOG_H
#define SELECTDATADIALOG_H

#include <QDialog>

namespace Ui {
class selectDataDialog;
}

class selectDataDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit selectDataDialog(QWidget *parent = 0);
    ~selectDataDialog();
    
private:
    Ui::selectDataDialog *ui;
};

#endif // SELECTDATADIALOG_H

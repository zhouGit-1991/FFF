#ifndef INSERTDATADIALOG_H
#define INSERTDATADIALOG_H

#include <QDialog>

namespace Ui {
class insertDataDialog;
}

class insertDataDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit insertDataDialog(QWidget *parent = 0);
    ~insertDataDialog();
    
private:
    Ui::insertDataDialog *ui;
};

#endif // INSERTDATADIALOG_H

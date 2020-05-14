#ifndef NEWDBDIALOG_H
#define NEWDBDIALOG_H

#include <QDialog>

namespace Ui {
class newDBDialog;
}

class newDBDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit newDBDialog(QWidget *parent = 0);
    ~newDBDialog();
    
private:
    Ui::newDBDialog *ui;
};

#endif // NEWDBDIALOG_H

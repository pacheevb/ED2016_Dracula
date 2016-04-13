#ifndef VMESA_H
#define VMESA_H

#include <QDialog>

namespace Ui {
class VMesa;
}

class VMesa : public QDialog
{
    Q_OBJECT

public:
    explicit VMesa(QWidget *parent = 0);
    ~VMesa();

private slots:
    void on_mano1_clicked();

private:
    Ui::VMesa *ui;
};

#endif // VMESA_H

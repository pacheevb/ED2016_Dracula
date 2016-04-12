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

private:
    Ui::VMesa *ui;
};

#endif // VMESA_H

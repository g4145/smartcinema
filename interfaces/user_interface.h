#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include <QMainWindow>

namespace Ui {
class user_interface;
}

class user_interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit user_interface(QWidget *parent = nullptr);
    ~user_interface();

private:
    Ui::user_interface *ui;
};

#endif // USER_INTERFACE_H

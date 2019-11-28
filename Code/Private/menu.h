#ifndef MENU_H
#define MENU_H

#include "spisok.h"
#include <QMainWindow>

namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_Button_admin_clicked();

    void on_Button_guest_clicked();

    void on_password_returnPressed();

private:
    Ui::Menu *ui;
    spisok *window;
    guestspis *window_guest;
};

#endif // MENU_H

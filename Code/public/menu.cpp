#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
   // ui->Button_guest->setStyleSheet("QLineEdit{background-color: rgba(0, 0, 0);}");

}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_Button_admin_clicked()
{
    QString login_=ui->login->text();
    QString password_=ui->password->text();
    if(login_ == "Slava" && password_== "123"){
        window= new spisok();
        window->setStyleSheet("font-size:18px;background-color:rgb(46, 47, 48);");
        window->show();
        ui->login->clear();
        ui->password->clear();
        connect(window,&spisok::open_menu,this,&Menu::show);
        close();
    }
    else
        QMessageBox::warning(this,"Ошибка","Не правильный логин или пароль.");
}

void Menu::on_Button_guest_clicked()
{
    window_guest = new guestspis();
    connect(window_guest,&guestspis::open_menu,this,&Menu::show);
    window_guest->show();
    close();
}


void Menu::on_password_returnPressed()
{
    on_Button_admin_clicked();
}

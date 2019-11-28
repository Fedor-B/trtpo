#ifndef GUESTSPIS_H
#define GUESTSPIS_H

#include <QMainWindow>

#include "pokaz_film.h"

namespace Ui {
class guestspis;
}

class guestspis : public QMainWindow
{
    Q_OBJECT

signals:
    void open_menu();

public:
    explicit guestspis(QWidget *parent = nullptr);
    ~guestspis();

private slots:

    void pysto();

    void on_close_clicked();

    void on_return_menu_clicked();

    void show_list();

    void count_plus()
    {
        if(count_column==3)
        {
            count_row++;
            count_column =0;
        }
    }

    void name_open();
    void on_pushButton_clicked();

    void on_search_returnPressed();

private:
    QString NameButton;
    int numberButton;
    int count_row = 0,count_column=0;
    Ui::guestspis *ui;
    kinofilm *poster=new kinofilm;
    pokaz_film *open_window;

};

#endif // GUESTSPIS_H

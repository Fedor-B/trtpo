#ifndef SPISOK_H
#define SPISOK_H

#include <QMainWindow>
#include "redactor.h"
#include <QListWidgetItem>
#include <string>

namespace Ui {
class spisok;
}

class spisok : public QMainWindow
{
    Q_OBJECT



public:
    explicit spisok(QWidget *parent = nullptr);
    ~spisok();

signals:

    void open_menu();

private slots:


    void on_add_film_clicked();

    void on_okey_clicked();

    void add();

    void add2();

    void on_sort_all_clicked();

    void on_delete_all_clicked();

    void on_delete_2_clicked();

    void show_list();

    void count_plus();

    void on_name_clicked();

private:
    QString NameButton;
    int numberButton;
    Ui::spisok *ui;
    Redactor * window;
    kinofilm *spis_;
    int count_row=0,
    count_column=0;
};


#endif // SPISOK_H

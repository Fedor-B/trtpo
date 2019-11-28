#ifndef POKAZ_FILM_H
#define POKAZ_FILM_H

#include <QMainWindow>
#include "myclass.h"

namespace Ui {
class pokaz_film;
}

class pokaz_film : public QMainWindow
{
    Q_OBJECT

signals:
    void open_spisok();
public:
    explicit pokaz_film(kont *object = nullptr ,QWidget *parent = nullptr);
    ~pokaz_film();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pokaz_film *ui;
};

#endif // POKAZ_FILM_H

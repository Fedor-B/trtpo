#ifndef REDACTOR_H
#define REDACTOR_H

#include <QMainWindow>
#include "guestspis.h"

namespace Ui {
class Redactor;
}

class Redactor : public QMainWindow
{
    Q_OBJECT

signals:
    void open_spisok();
    void delete_element();

public:
    explicit Redactor(kont *object = nullptr,QWidget *parent = nullptr);
    ~Redactor();

private slots:
    void on_pushButton_clicked();

    void on_add_picture_clicked();

    void on_pushButton_2_clicked();
    
    void on_Redac_picture_clicked();

private:
    Ui::Redactor *ui;
    kont temprary, *obj=nullptr;
};

#endif // REDACTOR_H

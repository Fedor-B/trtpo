#include "pokaz_film.h"
#include "ui_pokaz_film.h"

pokaz_film::pokaz_film(kont *object ,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pokaz_film)
{
    ui->setupUi(this);
    ui->picture->setPixmap(object->image_.scaled(420,460));
    ui->Name_film->setText(object->name_);

    ui->scrool_ganre->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrool_ganre->setWidget(ui->Janre);
    ui->Janre->setText(object->janre_);

    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(ui->opisanie);
    ui->opisanie->setText(object->opis_);
}

pokaz_film::~pokaz_film()
{
    delete ui;
}

void pokaz_film::on_pushButton_clicked()
{
    emit open_spisok();
    close();
}

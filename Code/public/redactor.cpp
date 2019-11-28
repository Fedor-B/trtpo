#include "redactor.h"
#include "ui_redactor.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QPixmap>


Redactor::Redactor(kont *object,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Redactor)
{
    ui->setupUi(this);
    if ( object == nullptr)
    {
        QPixmap pict(":/new/prefix1/image/net_avatarki.jpg");
        temprary.image_=pict;
        ui->pic->setPixmap(temprary.image_.scaled(490,460));
       // ui->Redac_picture->hide();
    }
    else
    {
        temprary.janre_=object->janre_;
        temprary.name_=object->name_;
        temprary.opis_=object->opis_;
        temprary.image_=object->image_;
        obj=object;
        ui->add_picture->hide();
        ui->pic->setPixmap(object->image_.scaled(490,460));
        ui->name->setText(object->name_);
        ui->genre->setText(object->janre_);
        ui->opis->setText(object->opis_);
    }
}

Redactor::~Redactor()
{
    delete ui;
}

void Redactor::on_pushButton_clicked()
{
    QFile file("file.txt");
    QFile file_picture("picture.txt");
    file.open(QIODevice::Append);
    file_picture.open(QIODevice::Append);
    if(!(file.isOpen() && file_picture.isOpen()))
    {
        setStyleSheet("background-color:white;");
        setStyleSheet("QPushButton:enabled {color: black}  QPushButton{background-color:grey} QPushButton:hover {color: white}");
        QMessageBox::warning(this,"Ошибка","Данные не могут быть записаны в файл",QMessageBox::Ok);
        ui->statusbar->showMessage("Попробуйте еще раз.");
    }
    QDataStream write (&file);
    if(ui->name->text()=="")
        temprary.name_="none";
    else temprary.name_=ui->name->text();
    if(ui->genre->text()=="")
        temprary.janre_=" ";
    else temprary.janre_=ui->genre->text();
    if(ui->opis->toPlainText()=="")
        temprary.opis_=" ";
    else temprary.opis_=ui->opis->toPlainText();
    write << temprary.name_ << temprary.janre_ << temprary.opis_;
    file.flush();
    file.close();
    QDataStream writ(&file_picture);
    writ<<temprary.image_;
    file_picture.flush();
    file_picture.close();
    if(obj==nullptr)emit open_spisok();
    else emit delete_element();
    close();
}


void Redactor::on_add_picture_clicked()
{
    QPixmap ping = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "Picture (*.jpg *.png)"//;;Text File (*.txt);;Music File (*.mp3)
                );
    temprary.image_=ping;
    QSize PicSize(490,460);
    ui->pic->setPixmap(ping.scaled(PicSize));
    ui->add_picture->hide();
}

void Redactor::on_pushButton_2_clicked()
{
    emit open_spisok();
    close();
}

void Redactor::on_Redac_picture_clicked()
{
    QPixmap ping = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "Picture (*.jpg)"//;;Text File (*.txt);;Music File (*.mp3)
                );
    temprary.image_=ping;
    QSize PicSize(490,460);
    ui->pic->setPixmap(ping.scaled(PicSize));
    ui->add_picture->hide();
}

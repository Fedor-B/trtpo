#include "spisok.h"
#include "ui_spisok.h"
#include <QMessageBox>
#include <QFile>
#include <QLabel>
#include <iostream>
#include <QToolButton>

using namespace std;

spisok::spisok(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::spisok)
{
    ui->setupUi(this);
    spis_ = new kinofilm();
    if(!spis_->creat_massiv())
        QApplication::quit();
    ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(ui->gridLayoutWidget);
    show_list();

}


spisok::~spisok()
{
    delete window;
    delete ui;
}


void spisok::on_add_film_clicked()
{
    window= new Redactor();
    window->show();
    connect(window,&Redactor::open_spisok,this,&spisok::add);
    close();
}

void spisok::on_okey_clicked()
{
    close();
    emit open_menu();
}

void spisok::add()
{
    spisok::show();
    spis_=new kinofilm ();
    if(!spis_->creat_massiv())
        QApplication::quit();
    show_list();
}

void spisok::add2()
{
    spisok::show();
    spis_=new kinofilm ();
    if(!spis_->creat_massiv())
        QApplication::quit();
    int i=NameButton.toInt();
    spis_->delete_one_element(i);
    show_list();
}


void spisok::on_sort_all_clicked()
{
    spis_->sort_massiv();
    show_list();
}

void spisok::on_delete_all_clicked()
{
    spis_->delete_massiv();
    QFile file("file.txt");
    QFile file_picture("picture.txt");
    file.open(QIODevice::WriteOnly);
    file_picture.open(QIODevice::WriteOnly);
    file.close();
    file_picture.close();
    file.flush();
    file_picture.flush();
    show_list();
}


void spisok::show_list()
{

    QLayoutItem *it;
    while((it=ui->gridLayout->takeAt(0))!=0){
        ui->gridLayout->removeItem(it);
        it->widget()->deleteLater();
        delete it;}
    for (int i=0;i<spis_->Size();++i)
    {

        kont abc=spis_->returnkont(i);
        QLabel *pix=new QLabel;
        QLabel *opi=new QLabel;

        QScrollArea *area=new QScrollArea;
        ui->scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        area->setWidgetResizable(true);
        area->setWidget(opi);
        area->setStyleSheet("border-top:red");
        opi->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
        opi->setWordWrap(true);
        QToolButton *name=new QToolButton();

        //QPushButton *name=new QPushButton;
        QString n=QString::number(i);

        name->setObjectName(n);
        name->resize(name->sizeHint().width(),name->sizeHint().height());
        //name->setFixedSize(190,190);
        name->setStyleSheet("QAbstractButton {"
                            "background: rgba(255,255,255,0);"
                            "color:white;"
                            "font-size:40px;}"
                            " QPushButton:hover{color: black }");
        name->setText(abc.name_);
        opi->setText(abc.opis_);
        pix->setPixmap(abc.image_.scaled(190,190));


        ui->gridLayout->addWidget(pix,count_row,count_column++);
        ui->gridLayout->addWidget(name,count_row,count_column++);
        ui->gridLayout->addWidget(area,count_row,count_column++);
        count_plus();

        connect(name,&QToolButton::clicked,this,&spisok::on_name_clicked);
    }
}


void spisok::on_name_clicked()
{
    NameButton=qobject_cast<QToolButton*>(sender())->objectName();
    numberButton=NameButton.toInt();
    kont a=spis_->returnkont(numberButton);
    window= new Redactor(&a);
    window->show();
    connect(window,&Redactor::open_spisok,this,&spisok::add);
    connect(window,&Redactor::delete_element,this,&spisok::add2);
    close();
}

void spisok::count_plus()
{
    if(count_column==3)
    {
        count_row++;
        count_column =0;
    }
}

void spisok::on_delete_2_clicked()
{
    if(spis_->Size()==0)
    {
        ui->statusbar->showMessage("Нету фильмов");
        return;
    }
    else{
        spis_->delete_one_element(spis_->Size()-1);
        show_list();
    }
}








#include "guestspis.h"
#include "ui_guestspis.h"
#include <QLabel>

guestspis::guestspis(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::guestspis)
{
    ui->setupUi(this);
    ui->film_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->film_list->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->film_list->setWidgetResizable(true);
        poster->creat_massiv();
        ui->film_list->setWidget(ui->gridLayoutWidget);
        if(poster->empty())
        {
            pysto();
        }
        else
        {
            show_list();
        }
}

guestspis::~guestspis()
{
    delete ui;
}

void guestspis::on_close_clicked()
{
    QApplication::quit();
}

void guestspis::pysto()
{
    QLabel *picture=new QLabel();
    QPixmap pix(":/new/prefix1/image/net_izobrazheniya.png");
    picture->setPixmap(pix.scaled(780,488));
    ui->gridLayout->addWidget(picture);
}

void guestspis::show_list()
{

    QLayoutItem *it;
    while((it=ui->gridLayout->takeAt(0))!=0){
        ui->gridLayout->removeItem(it);
        it->widget()->deleteLater();
        delete it;}
    for (int i=0;i<poster->Size();++i)
    {

        kont abc=poster->returnkont(i);
        QLabel *pix=new QLabel;
        QLabel *opi=new QLabel;

        QScrollArea *area=new QScrollArea;
        ui->film_list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->film_list->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        area->setWidgetResizable(true);
        area->setWidget(opi);
        area->setStyleSheet("border-top:red");
        opi->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Minimum);
        opi->setWordWrap(true);
        QPushButton *name=new QPushButton;
        QString n=QString::number(i);
        name->setObjectName(n);
        name->resize(name->sizeHint().width(),name->sizeHint().height());
        //        name->setFixedSize(260,260);
        name->setStyleSheet("QAbstractButton {"
                            "background: rgba(255,255,255,0);"
                            "color:orange;"
                            "font-size:40px;}"
                            " QPushButton:hover{color: black }");
        name->setText(abc.name_);
        opi->setText(abc.opis_);
        pix->setPixmap(abc.image_.scaled(260,260));


        ui->gridLayout->addWidget(pix,count_row,count_column++);
        ui->gridLayout->addWidget(name,count_row,count_column++);
        ui->gridLayout->addWidget(area,count_row,count_column++);
        count_plus();

        connect(name,&QPushButton::clicked,this,&guestspis::name_open);
    }
}


void guestspis::name_open()
{
    NameButton=qobject_cast<QPushButton*>(sender())->objectName();
    numberButton=NameButton.toInt();
    kont a=poster->returnkont(numberButton);
    open_window= new pokaz_film(&a);
    open_window->show();
    connect(open_window,&pokaz_film::open_spisok,this,&guestspis::show);
     close();
}

void guestspis::on_return_menu_clicked()
{
    emit open_menu();
    close();
}

void guestspis::on_pushButton_clicked()
{
    try{
    QString search=ui->search->text();
    kont tutorial=poster->search_element(search);
    open_window=new pokaz_film(&tutorial);
    open_window->show();
    ui->search->clear();
    connect(open_window,&pokaz_film::open_spisok,this,&guestspis::show);
     close();
    }catch (const std::exception &ex)
    {
        QMessageBox::warning(this,"Ошибка",ex.what());
    }

}

void guestspis::on_search_returnPressed()
{
    on_pushButton_clicked();
    ui->search->clear();
}

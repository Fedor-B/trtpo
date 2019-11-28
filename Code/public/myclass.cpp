#include "myclass.h"
#include <QFile>
#include <QMessageBox>

bool kinofilm::creat_massiv()
{
    QFile file1     ("file.txt");
    QFile png       ("picture.txt");
    if(!png.open(QIODevice::ReadOnly))
    {
        png.open(QIODevice::WriteOnly);
        png.close();
        png.open(QIODevice::ReadOnly);
    }
    if(!file1.open(QIODevice::ReadOnly))
    {
        file1.open(QIODevice::WriteOnly);
        file1.close();
        file1.open(QIODevice::ReadOnly);
    }
    QDataStream read (&png);
    QDataStream readFilm (&file1);
    while(!file1.atEnd())
    {
    kont arr_;
    QString name,genre,opis;
    QPixmap image;
    read>>image;
    readFilm>>name>>genre>>opis;
    arr_.name_=name;
    arr_.janre_=genre;
    arr_.opis_=opis;
    arr_.image_=image;
    massiv.push_back(arr_);
    }
    file1.close();
    png.close();
    return true;
}

int kinofilm::Size()
{
    return massiv.size();
}

const QString & kinofilm::names_(int  a)
{
    return massiv[a].name_;
}

const QPixmap &kinofilm::images(int a)
{
    return massiv[a].image_;
}

void kinofilm::add(const kont & ABC)
{
   massiv.push_back(ABC);
}

void kinofilm::sort_massiv()
{
    qSort(massiv.begin(),massiv.end(),[](const kont &lhs,const kont &rhs){return lhs.name_<rhs.name_;});
    perepis();
}

void kinofilm::delete_massiv()
{
    massiv.clear();
}

void kinofilm::delete_one_element(const int & number)
{
    auto a=&massiv[number];
    massiv.erase(a);
    perepis();
}

void kinofilm::perepis()
{
    QFile file("file.txt");
    QFile file_picture("picture.txt");
    file.open(QIODevice::WriteOnly);
    file_picture.open(QIODevice::WriteOnly);
    if(!(file.isOpen() && file_picture.isOpen()))
        throw std::runtime_error ("Файл не открыт");
    QDataStream read_pic(&file_picture);
    QDataStream read(&file);
    for(int i=0;i<massiv.size();++i)
    {
        read << massiv[i].name_<<massiv[i].janre_<<massiv[i].opis_;
        read_pic << massiv[i].image_;
    }
    file.close();
    file_picture.close();
    file.flush();
    file_picture.flush();
}

kont kinofilm::returnkont(int i)
{
    return massiv[i];
}

kont kinofilm::search_element(QString &name)
{
    for (int var = 0; var < massiv.size(); ++var)
        if (name == massiv[var].name_)
            return massiv[var];
    throw std::runtime_error("Нету такого фильма");
}


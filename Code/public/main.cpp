#include "menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w;
    w.show();

    return a.exec();
}
//#include "spisok.h"
//#include <QApplication>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    spisok w;
//    w.show();

//    return a.exec();
//}

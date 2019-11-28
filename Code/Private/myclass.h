#include <QPixmap>
#include <QMessageBox>


struct kont
{
    QString name_;
    QString janre_;
    QString opis_;
    QPixmap image_;
};


class kinofilm
{
public:

    bool creat_massiv();

    int Size();

    const QString & names_(int a);

    const QPixmap & images (int a);

    void add(const kont & ABC);

    void sort_massiv();

    void delete_massiv();

    void delete_one_element(const int&);

    void perepis();

    kont returnkont(int i);

    bool empty()
    {
        return massiv.empty();
    }

    kont search_element(QString & );

private:
    QVector<kont> massiv;
};

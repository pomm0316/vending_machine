#include "widget.h"
#include <QApplication>

void meunFals();

int main(int argc, char *argv[])
{
    void meunFals();
    QApplication a(argc, argv);

    Widget w;
    w.show();

    //Widget w2;
    //w2.show();

    return a.exec();
}

#include "mainwindow.h"
#include <QApplication>
//#include "Card.h"
//#include "Decorator.h"
//#include "Singleton.h"

bool decision = false;

extern

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}

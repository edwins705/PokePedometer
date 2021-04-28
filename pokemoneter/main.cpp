#include "mainmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // Remove this if necessary
    QApplication a(argc, argv);
    MainMenu w;
    w.show();
    return a.exec();
}

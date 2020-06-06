#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationDisplayName("Поиск каталогов");

    MainWindow w;
    w.resize(370, 240);
    w.show();
    return a.exec();
}

#include <QApplication>
#include "mainwindow.hpp"
#include <QSlider>



int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    MainWindow k;

    k.show();
    app.exec();
    return 0;

}

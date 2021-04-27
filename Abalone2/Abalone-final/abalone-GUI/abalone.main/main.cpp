//#include "mainwindow.h"
#include "abalone.view/mainwindow2.h"
#include <QApplication>

/*
 * POC based on abs code HexagripUI.
 * rewrite to better comprehension (and simplification
 * on first approach)
 *
 * GHexagon are clickable hexagone who emit signal.
 */

int main(int argc, char * argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    MainWindow2 w;
    w.show();

    return a.exec();
}

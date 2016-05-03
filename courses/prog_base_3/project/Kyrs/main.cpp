#include <QtGui/QApplication>
#include "mainwindow.h"
#include "search.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
     //QObject::MainWindow * wnd = new QObject::MainWindow::on_search_clicked();
   //  QObject::MainWindow::on_search_clicked();
    // QObject::connect(&w , SIGNAL(clicked()), &wnd ,SLOT(show()));

     //wnd->show();
    
    return a.exec();
}

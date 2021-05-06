#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include"cours.h"
#include"examen.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Connection c;
    bool test=c.createconnect();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

MainWindow w;
//ThemeWidget *widget = new ThemeWidget();
//w.setCentralWidget(widget);
//w.resize(900, 600);
w.show();

    return a.exec();
}

#include "accueil.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QMediaPlayer>
#include<qthread.h>
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

accueil w;
w.show();

QMediaPlayer* player;
player= new QMediaPlayer;
player->setMedia(QUrl::fromLocalFile("C:/Users/MY HP/Desktop/Nouveau dossier/Application_Desktop_Movenpick/malek/bienvenu.mp3"));
player->play();
qDebug()<<player->errorString();
QThread::sleep(1);

    return a.exec();
}

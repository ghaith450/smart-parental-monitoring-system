#ifndef STATACCEUIL_H
#define STATACCEUIL_H

#include <QWidget>
#include "suivi_medical.h"

namespace Ui {
class statAcceuil;
}

class statAcceuil : public QWidget
{
    Q_OBJECT

public:
    explicit statAcceuil(QWidget *parent = nullptr);
    ~statAcceuil();
private slots:
    void on_widget_customContextMenuRequested(const QPoint &pos);

private:
private:
    Ui::statAcceuil *ui;

    suivi_medical tmpchambre;


};

#endif // STATACCEUIL_H




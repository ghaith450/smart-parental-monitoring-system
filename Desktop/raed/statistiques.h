#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QDialog>
#include <QWidget>
#include "argent.h"

namespace Ui {
class statistiques;
}

class statistiques: public QDialog
{
    Q_OBJECT

public:
    explicit statistiques(QWidget *parent = nullptr);
    void on_tabchambre_activated(const QModelIndex &index);
    ~statistiques();

private slots:
    void on_widget_customContextMenuRequested(const QPoint &pos);

private:
    Ui::statistiques *ui;
    argent tmpchambre;
};

#endif // STATISTIQUES_H

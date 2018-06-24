#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "badge.h"
#include "badgeconnector.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QList<Badge*> badges;
};

#endif // MAINWINDOW_H

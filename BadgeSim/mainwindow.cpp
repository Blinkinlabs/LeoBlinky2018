#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("LeoBlinky 2018 Simulator");

    Badge* badgeA = new Badge("DIS", 7, this);
    Badge* badgeB = new Badge("ORI", 7, this);
    Badge* badgeC = new Badge("ENT", 9, this);
    Badge* badgeD = new Badge("ED", 6, this);

    BadgeConnector* connectorAB = new BadgeConnector(badgeA, badgeB, this);
    BadgeConnector* connectorBC = new BadgeConnector(badgeB, badgeC, this);
    BadgeConnector* connectorCD = new BadgeConnector(badgeC, badgeD, this);

    badges.append(badgeA);
    badges.append(badgeB);
    badges.append(badgeC);
    badges.append(badgeD);

    QHBoxLayout *badgeLayout = new QHBoxLayout();

    badgeLayout->addWidget(badgeA);
    badgeLayout->addWidget(connectorAB);
    badgeLayout->addWidget(badgeB);
    badgeLayout->addWidget(connectorBC);
    badgeLayout->addWidget(badgeC);
    badgeLayout->addWidget(connectorCD);
    badgeLayout->addWidget(badgeD);

    ui->centralWidget->layout()->addItem(badgeLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

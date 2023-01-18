#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("hello world");
    connect(this, SIGNAL(mySignal_1()), this, SLOT(mySlot_1()));
    connect(this, SIGNAL(mySignal_2(int)), this, SLOT(mySlot_2(int)));
    connect(this, &MainWindow::mySignal_1, this, &MainWindow::mySlot_1);
    connect(this, &MainWindow::mySignal_2, this, &MainWindow::mySlot_2);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::mySlot_1);
    emit mySignal_1();
    emit mySignal_2(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mySlot_1()
{
    qDebug() << "call mySlot_1";
}

void MainWindow::mySlot_2(int data)
{
    qDebug() << "call mySlot_2" << data;
}


void MainWindow::on_pushButton_clicked()
{
    qDebug() << "call on pushbutton clicked()";
}


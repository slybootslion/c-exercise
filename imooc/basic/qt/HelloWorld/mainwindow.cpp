#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "signalslot.h"
#include <QThread>
#include <QTimer>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton->setText("hello btn");
    ui->pushButton->installEventFilter(this);

    connect(this, SIGNAL(mySignal_1()), this, SLOT(mySlot_1()));
    connect(this, SIGNAL(mySignal_2(int)), this, SLOT(mySlot_2(int)));
    connect(this, &MainWindow::mySignal_1, this, &MainWindow::mySlot_1);
    connect(this, &MainWindow::mySignal_2, this, &MainWindow::mySlot_2);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::mySlot_1);

    emit mySignal_1();
    emit mySignal_2(100);

    SignalSlot *ssObj = new SignalSlot;
    connect(this, &MainWindow::mySignal_1, ssObj, &SignalSlot::testSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->pushButton) {
        if (event->type() == QEvent::MouseButtonPress) {
            qDebug() << "mouse button press event filter";
            return true;
        }
    }
    return QMainWindow::eventFilter(watched, event);
}

void MainWindow::mySlot_1()
{
    qDebug() << "call mySlot()";
}

void MainWindow::mySlot_2(int data)
{
    qDebug() << "call mySlot(int data)"<< data;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "call on pushbutton clicked()";
    emit mySignal_1();
}


void MainWindow::on_pushButton_2_clicked()
{
    QEventLoop loop;
    QTimer::singleShot(3 * 1000, &loop, &QEventLoop::quit);
    qDebug() << "Start event loop";
    loop.exec();
    qDebug() << "End event loop";
}

void MainWindow::on_pushButton_3_clicked()
{
    QDialog d;
    d.show();
    QEventLoop loop;
    connect(&d, SIGNAL(finished(int)), &loop, SLOT(quit()));
//    connect(&d, &QDialog::finished, &loop, &QEventLoop::quit);
    loop.exec();
    qDebug() << "event loop quit ok";
}

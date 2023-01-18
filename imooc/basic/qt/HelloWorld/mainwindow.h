#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void mySignal_1();
    void mySignal_2(int data);
public slots:
    void mySlot_1();
    void mySlot_2(int data);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
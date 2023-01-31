#include "cloudmusicwindow.h"
#include "ui_cloudmusicwindow.h"

CloudMusicWindow::CloudMusicWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CloudMusicWindow)
{
    ui->setupUi(this);
}

CloudMusicWindow::~CloudMusicWindow()
{
    delete ui;
}


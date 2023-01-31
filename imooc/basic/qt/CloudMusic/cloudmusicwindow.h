#ifndef CLOUDMUSICWINDOW_H
#define CLOUDMUSICWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CloudMusicWindow; }
QT_END_NAMESPACE

class CloudMusicWindow : public QMainWindow
{
    Q_OBJECT

public:
    CloudMusicWindow(QWidget *parent = nullptr);
    ~CloudMusicWindow();

private:
    Ui::CloudMusicWindow *ui;
};
#endif // CLOUDMUSICWINDOW_H

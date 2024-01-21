#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();
private slots:
    void on_actionClose_triggered();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

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
    void on_saveButton_clicked();
    void on_refreshButton_clicked();
    void on_restoreButton_clicked();
    void on_editButton_clicked();
    void on_saveEditionButton_clicked();
private:
    bool validEntries();
    void setTextBoxPlaceHolder();

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

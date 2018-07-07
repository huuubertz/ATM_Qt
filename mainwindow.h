#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_ok_logIn_clicked(bool checked);

    void on_checkBox_card_2_stateChanged(int arg1);

    void on_checkBox_card_3_stateChanged(int arg1);

    void on_checkBox_card_1_stateChanged(int arg1);
    void main_menu();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

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

    void wyplata_pieniedzy(int quantity=0, bool receipt=false);

    void saldo();

    void main_menu();

    void logout();

private:
    Ui::MainWindow *ui;
    QPushButton* button = NULL;
    QPushButton *_button_card[12];
    QLabel *_label[8];

};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void buttonAclicked();
    void buttonBclicked();

private slots:

    void on_pushButton_ok_logIn_clicked(bool checked);

    void on_checkBox_card_2_stateChanged(int arg1);

    void on_checkBox_card_3_stateChanged(int arg1);

    void on_checkBox_card_1_stateChanged(int arg1);

    void wyplata_pieniedzy(int quantity=0, bool receipt=false);

    void wyplata20();

    void wyplata50();

    void wyplata100();

    void wyplata200();

    void wyplata500();

    void collect_money();

    void saldo();

    void main_menu();

    void logout();

private:
    Ui::MainWindow *ui;
    QWidget* window_atm;
    QPushButton* button = NULL;
    QPushButton *_button_card[12];
    QLabel *_label[8];
    int buttoA, buttonB;
    QPushButton* butonierka = NULL;

    int cash_withdrawal(int quantity=0, bool receipt=false);
    void _set_disabled_to_all_card_buttons(int numbers);
};

#endif // MAINWINDOW_H

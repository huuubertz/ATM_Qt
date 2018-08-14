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

private slots:

    void on_pushButton_ok_logIn_clicked(bool checked);

    void on_checkBox_card_2_stateChanged(int arg1);

    void on_checkBox_card_3_stateChanged(int arg1);

    void on_checkBox_card_1_stateChanged(int arg1);

    void cash_withdrawal_window();

    void withdrawal20();

    void withdrawal50();

    void withdrawal100();

    void withdrawal200();

    void withdrawal500();

    void withdrawal50_without_receipt();

    void collect_money();

    void get_receipt();

    void saldo();

    void main_menu();

    void logout();

private:
    Ui::MainWindow *ui;
    QWidget* window_atm;
    QPushButton* button = NULL;
    QPushButton *_button_card[12];
    QLabel *_label[8];

    int cash_withdrawal(int quantity=0, bool receipt=false);
    void _set_disabled_to_all_card_buttons(int numbers=8);
    void _clear_all_labels(int numbers=8);
};

#endif // MAINWINDOW_H

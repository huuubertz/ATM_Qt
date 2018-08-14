#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextBrowser>
#include <QLineEdit>
#include <QMessageBox>
#include <string>
#include <fstream>

// My libs
#include "Singleton.h"
#include "Card.h"
#include "Decorator.h"

Server* Server::_instance = 0;

// Create global instance of Card to TEST
Factory* fabryka = NULL;

Card* card_1 = fabryka->create_individual_card();
Card* card_2 = fabryka->create_individual_card();
Card* card_3 = fabryka->create_individual_card();

Card* card =NULL;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // -------------------------------------------- LogIn window ---------------------------------------------------------
    // ustawiamy maxymalna liczbe znakow, PIN = 4 znaki
    ui->line_password->setMaxLength(4);
    // ukrywamy widocznosc wpisywanych znakow
    ui->line_password->setEchoMode(QLineEdit::Password);

    // -------------------------------------------- Server -------------------------------------------------------

    // Add instance of Card to server to TEST
    Server* server = Server::instance();

    server->add_new_account_to_database(card_1);
    server->add_new_account_to_database(card_2);
    server->add_new_account_to_database(card_3);

    server->change_password_of_card(card_1, 1234);
    server->change_password_of_card(card_2, 2345);
    server->change_password_of_card(card_3, 3456);

    server->change_saldo_on_account(card_1, 51);
    server->change_saldo_on_account(card_2, 512.46);
    server->change_saldo_on_account(card_3, 51246.24);

    // -------------------------------------------- INIT OF MAIN WINDOW -------------------------------------------------------

    window_atm = new QWidget;
    window_atm->setFixedSize(400, 230);

    _button_card[0] = new QPushButton("",window_atm);
    _button_card[0]->setGeometry(10,10,50,30);
    _button_card[0]->setEnabled(false);

    _button_card[1] = new QPushButton("",window_atm);
    _button_card[1]->setGeometry(10,40,50,30);
    _button_card[1]->setEnabled(false);

    _button_card[2] = new QPushButton("",window_atm);
    _button_card[2]->setGeometry(10,70,50,30);
    _button_card[2]->setEnabled(false);

    _button_card[3] = new QPushButton("",window_atm);
    _button_card[3]->setGeometry(10,100,50,30);

    _button_card[4] = new QPushButton("",window_atm);
    _button_card[4]->setGeometry(340,10,50,30);

    _button_card[5] = new QPushButton("",window_atm);
    _button_card[5]->setGeometry(340,40,50,30);

    _button_card[6] = new QPushButton("",window_atm);
    _button_card[6]->setGeometry(340,70,50,30);

    _button_card[7] = new QPushButton("",window_atm);
    _button_card[7]->setGeometry(340,100,50,30);

    _button_card[8] = new QPushButton("Logout",window_atm);
    _button_card[8]->setGeometry(290,130,100,30);

    // create push batton get receipt from atm
    _button_card[9] = new QPushButton("Get receipt",window_atm);
    _button_card[9]->setGeometry(10,130,100,30);
    _button_card[9]->setEnabled(false);

    // create push button to colect money from atm
    _button_card[10] = new QPushButton("Collect money",window_atm);
    _button_card[10]->setGeometry(60,160,280,30);
    _button_card[10]->setEnabled(false);

    // create push button to put money to atm
    _button_card[11] = new QPushButton("Put money",window_atm);
    _button_card[11]->setGeometry(60,190,280,30);
    _button_card[11]->setEnabled(false);

    // create labels for main interface of atm
    _label[0] = new QLabel("", window_atm);
    _label[0]->setGeometry(70, 10, 50, 30);

    _label[1] = new QLabel("", window_atm);
    _label[1]->setGeometry(70, 40, 50, 30);

    _label[2] = new QLabel("", window_atm);
    _label[2]->setGeometry(70, 70, 50, 30);

    _label[3] = new QLabel("Other", window_atm);
    _label[3]->setGeometry(70, 100, 50, 30);

    _label[4] = new QLabel("Payment of \n 50 zl", window_atm);
    _label[4]->setGeometry(270, 10, 70, 30);

    _label[5] = new QLabel("Cash \n withdrawal", window_atm);
    _label[5]->setGeometry(270, 40, 70, 30);

    _label[6] = new QLabel("Account \n balance", window_atm);
    _label[6]->setGeometry(270, 70, 70, 30);

    _label[7] = new QLabel("Cash \n payment", window_atm);
    _label[7]->setGeometry(270, 100, 70, 30);

    // -------------------------------------------- Signals -------------------------------------------------------

    connect(_button_card[4], SIGNAL (clicked()), this, SLOT (withdrawal50_without_receipt()));
    connect(_button_card[5], SIGNAL (clicked()), this, SLOT (cash_withdrawal_window()));
    connect(_button_card[6], SIGNAL (clicked()), this, SLOT (saldo()));
    connect(_button_card[8], SIGNAL (clicked()), this, SLOT (logout()));
    connect(_button_card[9], SIGNAL (clicked()), this, SLOT (get_receipt()));
    connect(_button_card[10], SIGNAL (clicked()), this, SLOT (collect_money()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


// ------------------------------------ LOGIN WINDOW -----------------------------------------------------

void MainWindow::on_pushButton_ok_logIn_clicked(bool checked)
{
    // TESTING without reader and card
    Server* server = Server::instance();
    // karta 1 global
    QString qhaslo_1 = QString::number(server->get_password_of_card(card));
    // karta 2 global
    QString qhaslo_2 = QString::number(server->get_password_of_card(card));
    // karta 3 global
    QString qhaslo_3 = QString::number(server->get_password_of_card(card));

    // pobierz dane z textboxa po wcisnieciu ok
    QString password = ui->line_password->text();

    // if checkbox 1 jest zaznaczony to ...
    if(ui->checkBox_card_1->isChecked() == true)
    {
        if(password == qhaslo_1)
        {
             QMessageBox::information(this, "password", "Zostales pomyslnie zalogowany");
             // ukryj okno logowania
             MainWindow::setVisible(false);
             // otworz dostep do menu
             MainWindow::main_menu();

        }
        else QMessageBox::information(this, "password", "haslo jest NIEprawidlowe");
    }

    // if checkbox 2 jest zaznaczony to ...
    if(ui->checkBox_card_2->isChecked() == true)
    {
        if(password == qhaslo_2)
        {
            QMessageBox::information(this, "password", "Zostales pomyslnie zalogowany");
            // ukryj okno logowania
            MainWindow::setVisible(false);
            // otworz dostep do menu
            MainWindow::main_menu();

        }
        else QMessageBox::information(this, "password", "haslo jest NIEprawidlowe");
    }

    // if checkbox 3 jest zaznaczony to ...
    if(ui->checkBox_card_3->isChecked() == true)
    {
        if(password == qhaslo_3)
        {
             QMessageBox::information(this, "password", "Zostales pomyslnie zalogowany");
             // ukryj okno logowania
             MainWindow::setVisible(false);
             // otworz dostep do menu
             MainWindow::main_menu();

        }
        else QMessageBox::information(this, "password", "haslo jest NIEprawidlowe");
    }

}

void MainWindow::on_checkBox_card_1_stateChanged(int arg1)
{
    if(ui->checkBox_card_1->isChecked() == true){
        ui->checkBox_card_2->setChecked(false);
        ui->checkBox_card_3->setChecked(false);

        card = card_1;
    }
}

void MainWindow::on_checkBox_card_2_stateChanged(int arg1)
{
    if(ui->checkBox_card_2->isChecked() == true){
        ui->checkBox_card_1->setChecked(false);
        ui->checkBox_card_3->setChecked(false);

        card = card_2;
    }
}

void MainWindow::on_checkBox_card_3_stateChanged(int arg1)
{
    if(ui->checkBox_card_3->isChecked() == true){
        ui->checkBox_card_1->setChecked(false);
        ui->checkBox_card_2->setChecked(false);

        card = card_3;
    }
}

// -------------------------------- MAIN WINDOW OF ATM ------------------------------------------------------------------

void MainWindow::main_menu()
{
    window_atm->show();
}

void MainWindow::cash_withdrawal_window() {

   // Funkcja, ktora przyjmuje tablice i w petli uzupelnia text do labela i enabled z kolejnej tablicy.
   _label[0]->setText("20");
   _button_card[0]->setEnabled(true);
   _label[1]->setText("50");
   _button_card[1]->setEnabled(true);
   _label[2]->setText("");
   _button_card[2]->setEnabled(false);
   _label[3]->setText("");
   _button_card[3]->setEnabled(false);
   _label[4]->setText("100");
   _button_card[4]->setEnabled(true);
   _label[5]->setText("200");
   _button_card[5]->setEnabled(true);
   _label[6]->setText("500");
   _button_card[6]->setEnabled(true);
   _label[7]->setText("inna kwota");
   _button_card[7]->setEnabled(true);

   connect(_button_card[0], SIGNAL (clicked()), this, SLOT (withdrawal20()));
   connect(_button_card[1], SIGNAL (clicked()), this, SLOT (withdrawal50()));
   disconnect(_button_card[4], SIGNAL (clicked()), this, SLOT (withdrawal50_without_receipt()));
   connect(_button_card[4], SIGNAL (clicked()), this, SLOT (withdrawal100()));
   disconnect(_button_card[5], SIGNAL (clicked()), this, SLOT (wyplata_pieniedzy()));
   connect(_button_card[5], SIGNAL (clicked()), this, SLOT (withdrawal200()));
   disconnect(_button_card[6], SIGNAL (clicked()), this, SLOT (saldo()));
   connect(_button_card[6], SIGNAL (clicked()), this, SLOT (withdrawal500()));

   QObject* button = QObject::sender();
   if (button == MainWindow::_button_card[7])
   {
       QMessageBox::information(this, "Logout", "See you");
   }
}

void MainWindow::saldo() {

    std::string balance = std::to_string(card->get_saldo());
    QString qbalance = QString::fromStdString(balance);
    QMessageBox::information(this, "Saldo", qbalance);
}

void MainWindow::logout()
{
    QMessageBox::information(this, "Logout", "See you");
    QCoreApplication::quit();
}

void MainWindow::withdrawal20()
{
    cash_withdrawal(20);
}

void MainWindow::withdrawal50()
{
    cash_withdrawal(50);
}

void MainWindow::withdrawal100()
{
    cash_withdrawal(100);
}

void MainWindow::withdrawal200()
{
    cash_withdrawal(200);
}

void MainWindow::withdrawal500()
{
    cash_withdrawal(500);
}

void MainWindow::withdrawal50_without_receipt()
{
    cash_withdrawal(50);
}

int MainWindow::cash_withdrawal(int quantity,  bool receipt)
{
    if (quantity > card->get_saldo())
    {
        QMessageBox::information(this, "Fail", "You haven't as much money.");
    }

    else
    {
        card->set_saldo(card->get_saldo() - quantity);
        QString qbalance = QString::number(card->get_saldo());
        QMessageBox::information(this, "Ok", qbalance);

        _set_disabled_to_all_card_buttons(8);
        _clear_all_labels();
        _button_card[9]->setEnabled(true);
        _button_card[10]->setEnabled(true);
        card->set_last_withdrawal(quantity);
        return card->get_saldo();
    }
}

void MainWindow::_set_disabled_to_all_card_buttons(int numbers)
{
    for (int i = 0; i < numbers; i++)
    {
        _button_card[i]->setEnabled(false);
    }

}

void MainWindow::_clear_all_labels(int numbers)
{
    for (int i = 0; i < numbers; i++)
    {
        _label[i]->setText("");
    }
}

void MainWindow::collect_money()
{
    _button_card[10]->setEnabled(false);
}

void MainWindow::get_receipt()
{
    _button_card[9]->setEnabled(false);

    std::ofstream* myfile = new std::ofstream("receipt.txt");

    if (myfile->is_open())
    {
        *myfile << std::to_string(card->get_last_withdrawal());
        myfile->close();
    }

    else QMessageBox::information(this, "Wrong", "Unable to write to file");
}

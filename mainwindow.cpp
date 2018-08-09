#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextBrowser>
#include <QLineEdit>
#include <QMessageBox>
#include <string>

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

    // -------------------------------------------- Signals -------------------------------------------------------

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
    QWidget* window_atm = new QWidget;
    window_atm->setFixedSize(400, 230);

    MainWindow::_button_card[0] = new QPushButton("",window_atm);
    MainWindow::_button_card[0]->setGeometry(10,10,50,30);
    MainWindow::_button_card[0]->setEnabled(false);

    MainWindow::_button_card[1] = new QPushButton("",window_atm);
    MainWindow::_button_card[1]->setGeometry(10,40,50,30);
    MainWindow::_button_card[1]->setEnabled(false);

    MainWindow::_button_card[2] = new QPushButton("",window_atm);
    MainWindow::_button_card[2]->setGeometry(10,70,50,30);
    MainWindow::_button_card[2]->setEnabled(false);

    MainWindow::_button_card[3] = new QPushButton("",window_atm);
    MainWindow::_button_card[3]->setGeometry(10,100,50,30);

    MainWindow::_button_card[4] = new QPushButton("",window_atm);
    MainWindow::_button_card[4]->setGeometry(340,10,50,30);

    MainWindow::_button_card[5] = new QPushButton("",window_atm);
    MainWindow::_button_card[5]->setGeometry(340,40,50,30);

    MainWindow::_button_card[6] = new QPushButton("",window_atm);
    MainWindow::_button_card[6]->setGeometry(340,70,50,30);

    MainWindow::_button_card[7] = new QPushButton("",window_atm);
    MainWindow::_button_card[7]->setGeometry(340,100,50,30);

    MainWindow::_button_card[8] = new QPushButton("Logout",window_atm);
    MainWindow::_button_card[8]->setGeometry(290,130,100,30);

    // create push batton get receipt from atm
    MainWindow::_button_card[9] = new QPushButton("Get receipt",window_atm);
    MainWindow::_button_card[9]->setGeometry(10,130,100,30);
    MainWindow::_button_card[9]->setEnabled(false);

    // create push button to colect money from atm
    MainWindow::_button_card[10] = new QPushButton("Collect money",window_atm);
    MainWindow::_button_card[10]->setGeometry(60,160,280,30);
    MainWindow::_button_card[10]->setEnabled(false);

    // create push button to put money to atm
    MainWindow::_button_card[11] = new QPushButton("Put money",window_atm);
    MainWindow::_button_card[11]->setGeometry(60,190,280,30);
    MainWindow::_button_card[11]->setEnabled(false);

    // create labels for main interface of atm
    MainWindow::_label[0] = new QLabel("", window_atm);
    MainWindow::_label[0]->setGeometry(70, 10, 50, 30);

    MainWindow::_label[1] = new QLabel("", window_atm);
    MainWindow::_label[1]->setGeometry(70, 40, 50, 30);

    MainWindow::_label[2] = new QLabel("", window_atm);
    MainWindow::_label[2]->setGeometry(70, 70, 50, 30);

    MainWindow::_label[3] = new QLabel("Other", window_atm);
    MainWindow::_label[3]->setGeometry(70, 100, 50, 30);

    MainWindow::_label[4] = new QLabel("Payment of \n 50 zl", window_atm);
    MainWindow::_label[4]->setGeometry(270, 10, 100, 30);

    MainWindow::_label[5] = new QLabel("Cash \n payment", window_atm);
    MainWindow::_label[5]->setGeometry(270, 40, 50, 30);

    MainWindow::_label[6] = new QLabel("Account \n balance", window_atm);
    MainWindow::_label[6]->setGeometry(270, 70, 70, 30);

    MainWindow::_label[7] = new QLabel("Cash \n withdrawal", window_atm);
    MainWindow::_label[7]->setGeometry(270, 100, 70, 30);

    connect(_button_card[4], SIGNAL (clicked()), this, SLOT (wyplata_pieniedzy()));
    connect(_button_card[6], SIGNAL (clicked()), this, SLOT (saldo()));
    connect(_button_card[8], SIGNAL (clicked()), this, SLOT (logout()));

    QObject* button = QObject::sender();
    if(button == _button_card[3]){
        window_atm->close();
        QMessageBox::information(this, "Logout", "chuj");

    }

    window_atm->show();
}

void MainWindow::wyplata_pieniedzy(int quantity, bool receipt) {


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


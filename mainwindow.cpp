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

// Create global instance of Card
Factory* fabryka = NULL;

Card* karciocha = fabryka->create_individual_card();
Card* card_1 = fabryka->create_individual_card();
Card* card_2 = fabryka->create_individual_card();
Card* card_3 = fabryka->create_individual_card();

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

    // Add instance of Card to server
    Server* server = Server::instance();

    server->add_new_account_to_database(card_1);
    server->add_new_account_to_database(card_2);
    server->add_new_account_to_database(card_3);

    server->change_password_of_card(card_1, 1234);

}

MainWindow::~MainWindow()
{
    delete ui;
}


// ------------------------------------ LOGIN WINDOW -----------------------------------------------------

void MainWindow::on_pushButton_ok_logIn_clicked(bool checked)
{
    Server* server = Server::instance();
    // SPR. czy klasy odpowiadajace za tworzenie kard, serwer i dekoartor dzialaja
    Card* _karta = NULL;
    Factory* _factory = NULL;

    _karta = _factory->create_individual_card();

    _karta->set_password(1254);

    std::string haslo = std::to_string(_karta->get_password());
    QString qhaslo = QString::fromStdString(haslo);

    server->add_new_account_to_database(_karta);

    // Karta 2
    Card* _karta_2 = NULL;

    _karta_2 = _factory->create_individual_card();
    _karta_2->set_password(2345);

    //server->add_new_account_to_database(_karta_2);

    QString qhaslo_2 = QString::number(server->get_password_of_card(_karta_2));

    server->add_new_account_to_database(_karta_2);

    // karta 3 global
    karciocha->set_password(5678);

    QString qhaslo_3 = QString::number(server->get_password_of_card(karciocha));

    server->add_new_account_to_database(karciocha);

    // pobierz dane z textboxa po wcisnieciu ok
    QString password = ui->line_password->text();

    // if checkbox 1 jest zaznaczony to ...
    if(ui->checkBox_card_1->isChecked() == true)
    {
        if(password == qhaslo)
        {
             QMessageBox::information(this, "password", "Zostales pomyslnie zalogowany");
             //Server::_ATM_menu_visibility=true;

             // ukryj okno logowania
             MainWindow::setVisible(false);
             // otworz dostep do menu
             MainWindow::main_menu();

        }
        else QMessageBox::information(this, "password", "haslo jest NIEprawidlowe");
        // stworz obiekt karty 1 ustaw jakies przykladowe haslo
        // if dobre to ustaw zmienna globalna na true iiiii poruszaj sie po interfejsie bankomatu
        // pasuje przerobic to bo pierwsz if check box zrob to i to i dopiero wtedy w tym ifie kolejny if sprawdzajacy haslo jak sie kliknie guzika
    }

    // if checkbox 2 jest zaznaczony to ...

    if(ui->checkBox_card_2->isChecked() == true)
    {
        /*
        if (Server::_ATM_menu_visibility == true)
        {
            QMessageBox::information(this, "password", "zmienna dziala jak FIKS");
        }
        */

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

    // if checkbox 3 jest zaznaczony to ...

    if(ui->checkBox_card_3->isChecked() == true)
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

}

void MainWindow::on_checkBox_card_1_stateChanged(int arg1)
{
    if(ui->checkBox_card_1->isChecked() == true){
        ui->checkBox_card_2->setChecked(false);
        ui->checkBox_card_3->setChecked(false);
    }
}

void MainWindow::on_checkBox_card_2_stateChanged(int arg1)
{
    if(ui->checkBox_card_2->isChecked() == true){
        ui->checkBox_card_1->setChecked(false);
        ui->checkBox_card_3->setChecked(false);
    }
}

void MainWindow::on_checkBox_card_3_stateChanged(int arg1)
{
    if(ui->checkBox_card_3->isChecked() == true){
        ui->checkBox_card_1->setChecked(false);
        ui->checkBox_card_2->setChecked(false);
    }
}

// -------------------------------- MAIN WINDOW OF ATM ------------------------------------------------------------------

void MainWindow::main_menu()
{
    QWidget* window_atm = new QWidget;
    window_atm->setFixedSize(400, 230);

    // create button for main interface of atm
    //QPushButton *_button_card_1 = new QPushButton("",window_atm);
    //_button_card_1->setGeometry(10,10,50,30);

    MainWindow::_button_card[0] = new QPushButton("",window_atm);
    MainWindow::_button_card[0]->setGeometry(10,10,50,30);

    MainWindow::_button_card[1] = new QPushButton("",window_atm);
    MainWindow::_button_card[1]->setGeometry(10,40,50,30);

    MainWindow::_button_card[2] = new QPushButton("",window_atm);
    MainWindow::_button_card[2]->setGeometry(10,70,50,30);

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

    // create push batton to put card inside atm
    //QPushButton *_button_card_9 = new QPushButton("Put card",window_atm);
    //_button_card_9->setGeometry(290,130,100,30);

    MainWindow::_button_card[8] = new QPushButton("Put card",window_atm);
    MainWindow::_button_card[8]->setGeometry(290,130,100,30);

    // create push batton get receipt from atm
    MainWindow::_button_card[9] = new QPushButton("Get receipt",window_atm);
    MainWindow::_button_card[9]->setGeometry(10,130,100,30);

    // create push button to colect money from atm
   MainWindow::_button_card[10] = new QPushButton("Collect money",window_atm);
    MainWindow::_button_card[10]->setGeometry(60,160,280,30);

    // create push button to put money to atm
    MainWindow::_button_card[11] = new QPushButton("Put money",window_atm);
    MainWindow::_button_card[11]->setGeometry(60,190,280,30);

    // create labels for main interface of atm
    MainWindow::_label[0] = new QLabel("", window_atm);
    MainWindow::_label[0]->setGeometry(70, 10, 50, 30);

    MainWindow::_label[1] = new QLabel("", window_atm);
    MainWindow::_label[1]->setGeometry(70, 40, 50, 30);

    MainWindow::_label[2] = new QLabel("", window_atm);
    MainWindow::_label[2]->setGeometry(70, 70, 50, 30);

    MainWindow::_label[3] = new QLabel("inne uslugi", window_atm);
    MainWindow::_label[3]->setGeometry(70, 100, 50, 30);

    MainWindow::_label[4] = new QLabel("wyplata 50 PLN \n bez wydruku", window_atm);
    MainWindow::_label[4]->setGeometry(250, 10, 100, 30);

    MainWindow::_label[5] = new QLabel("Wyplata gotowki \n w PLN", window_atm);
    MainWindow::_label[5]->setGeometry(270, 40, 50, 30);

    MainWindow::_label[6] = new QLabel("Zapytanie \n o saldo", window_atm);
    MainWindow::_label[6]->setGeometry(270, 70, 70, 30);


    MainWindow::_label[7] = new QLabel("Wyplata \n gotowki", window_atm);
    MainWindow::_label[7]->setGeometry(270, 100, 70, 30);

    // create text browers to display information about
    // login, wrong pin, or your decision

    //QTextBrowser* text_browser_1 = new QTextBrowser(window_atm);
    //text_browser_1->setGeometry(130,40,150,70);
    //text_browser_1->setText("Welcone in ATM :-) \n Put Card to start sesion. \n");

    connect(_button_card[4], SIGNAL (clicked()), this, SLOT (wyplata_pieniedzy()));
    connect(_button_card[6], SIGNAL (clicked()), this, SLOT (saldo()));



    window_atm->show();
}

void MainWindow::wyplata_pieniedzy(int quantity, bool receipt) {


}

void MainWindow::saldo() {
    // zmienic na double bo ucina po przecinku
    karciocha->set_saldo(234.56);
    std::string gownochuj = std::to_string(karciocha->get_saldo());
    QString qgownochuj = QString::fromStdString(gownochuj);
    QMessageBox::information(this, "Saldo", qgownochuj);


}


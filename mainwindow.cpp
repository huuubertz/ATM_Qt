#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextBrowser>
#include <QLineEdit>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // -------------------------------------------- LogIn window ---------------------------------------------------------
    // ustawiamy maxymalna liczbe znakow, PIN = 4 znaki
    ui->line_password->setMaxLength(4);

    // -------------------------------------------- Signals -------------------------------------------------------

}

MainWindow::~MainWindow()
{
    delete ui;
}

// ---------------------- KLAWAITURA ----------------------------------------------
/*
void MainWindow::on_pushButton_3_clicked(bool checked)
{
    // create window for keyboard
    QWidget* window_keyboard = new QWidget;
    window_keyboard->setFixedSize(220, 140);

    // create button for keyboard
    QPushButton *_button_card_1 = new QPushButton("7",window_keyboard);
    _button_card_1->setGeometry(10,10,60,30);

    QPushButton *_button_card_2 = new QPushButton("4",window_keyboard);
    _button_card_2->setGeometry(10,40,60,30);

    QPushButton *_button_card_3 = new QPushButton("1",window_keyboard);
    _button_card_3->setGeometry(10,70,60,30);

    QPushButton *_button_card_4 = new QPushButton("OK",window_keyboard);
    _button_card_4->setGeometry(10,100,60,30);

    QPushButton *_button_card_5 = new QPushButton("8",window_keyboard);
    _button_card_5->setGeometry(80,10,60,30);

    QPushButton *_button_card_6 = new QPushButton("5",window_keyboard);
    _button_card_6->setGeometry(80,40,60,30);

    QPushButton *_button_card_7 = new QPushButton("2",window_keyboard);
    _button_card_7->setGeometry(80,70,60,30);

    QPushButton *_button_card_8 = new QPushButton("0",window_keyboard);
    _button_card_8->setGeometry(80,100,60,30);

    QPushButton *_button_card_9 = new QPushButton("9",window_keyboard);
    _button_card_9->setGeometry(150,10,60,30);

    QPushButton *_button_card_10 = new QPushButton("6",window_keyboard);
    _button_card_10->setGeometry(150,40,60,30);

    QPushButton *_button_card_11 = new QPushButton("3",window_keyboard);
    _button_card_11->setGeometry(150,70,60,30);

    QPushButton *_button_card_12 = new QPushButton("CANCLE",window_keyboard);
    _button_card_12->setGeometry(150,100,60,30);

    window_keyboard->show();

}
*/

// ------------------------------------ LOGIN WINDOW -----------------------------------------------------

void MainWindow::on_pushButton_ok_logIn_clicked(bool checked)
{

    // to do unVISIBLE password entered

    // pobierz dane z textboxa po wcisnieciu ok
    QString password = ui->line_password->text();

    // if checkbox 1 jest zaznaczony to ...

    if(ui->checkBox_card_1->isChecked() == true)
    {
        if(password == "1234")
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

        if(password == "2345")
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
        if(password == "3456")
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
    QPushButton *_button_card_1 = new QPushButton("",window_atm);
    _button_card_1->setGeometry(10,10,50,30);

    QPushButton *_button_card_2 = new QPushButton("",window_atm);
    _button_card_2->setGeometry(10,40,50,30);

    QPushButton *_button_card_3 = new QPushButton("",window_atm);
    _button_card_3->setGeometry(10,70,50,30);

    QPushButton *_button_card_4 = new QPushButton("",window_atm);
    _button_card_4->setGeometry(10,100,50,30);

    QPushButton *_button_card_5 = new QPushButton("",window_atm);
    _button_card_5->setGeometry(340,10,50,30);

    QPushButton *_button_card_6 = new QPushButton("",window_atm);
    _button_card_6->setGeometry(340,40,50,30);

    QPushButton *_button_card_7 = new QPushButton("",window_atm);
    _button_card_7->setGeometry(340,70,50,30);

    QPushButton *_button_card_8 = new QPushButton("",window_atm);
    _button_card_8->setGeometry(340,100,50,30);

    // create push batton to put card inside atm
    QPushButton *_button_card_9 = new QPushButton("Put card",window_atm);
    _button_card_9->setGeometry(290,130,100,30);

    // create push batton get receipt from atm
    QPushButton *_button_card_to_get_receipt = new QPushButton("Get receipt",window_atm);
    _button_card_to_get_receipt->setGeometry(10,130,100,30);

    // create push button to colect money from atm
    QPushButton *_button_card_10 = new QPushButton("Collect money",window_atm);
    _button_card_10->setGeometry(60,160,280,30);

    // create push button to put money to atm
    QPushButton *_button_card_11 = new QPushButton("Put money",window_atm);
    _button_card_11->setGeometry(60,190,280,30);

    // create labels for main interface of atm
    QLabel* label_1 = new QLabel("", window_atm);
    label_1->setGeometry(70, 10, 50, 30);

    QLabel* label_2 = new QLabel("", window_atm);
    label_2->setGeometry(70, 40, 50, 30);

    QLabel* label_3 = new QLabel("", window_atm);
    label_3->setGeometry(70, 70, 50, 30);

    QLabel* label_4 = new QLabel("inne uslugi", window_atm);
    label_4->setGeometry(70, 100, 70, 30);

    QLabel* label_5 = new QLabel("wyplata 50 PLN \n bez wydruku", window_atm);
    label_5->setGeometry(250, 10, 100, 30);

    QLabel* label_6 = new QLabel("Wyplata gotowki \n w PLN", window_atm);
    label_6->setGeometry(270, 40, 50, 30);

    QLabel* label_7 = new QLabel("Zapytanie \n o saldo", window_atm);
    label_7->setGeometry(270, 70, 70, 30);

    QLabel* label_8 = new QLabel("Wyplata \n gotowki", window_atm);
    label_8->setGeometry(270, 100, 70, 30);

    // create text browers to display information about
    // login, wrong pin, or your decision

    //QTextBrowser* text_browser_1 = new QTextBrowser(window_atm);
    //text_browser_1->setGeometry(130,40,150,70);
    //text_browser_1->setText("Welcone in ATM :-) \n Put Card to start sesion. \n");


    window_atm->show();
}


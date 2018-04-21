#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextBrowser>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect (ui->pushButton, SIGNAL (clicked(bool)), this, SLOT (on_pushButton_clicked));
    connect (ui->pushButton_2, SIGNAL (clicked(bool)), this, SLOT (on_pushButton_clicked));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 *   QWidget *window_card = new QWidget;
        window_card->setFixedSize(100,50);
        window_card->show();
        */

void MainWindow::on_pushButton_clicked(bool checked)
{
    QWidget *window_card = new QWidget;
    window_card->setFixedSize(300,130);

    QPushButton *_button_card_1 = new QPushButton("Card 1",window_card);
    _button_card_1->setGeometry(10,10,280,30);

    QPushButton *_button_card_2 = new QPushButton("Card 2",window_card);
    _button_card_2->setGeometry(10,40,280,30);

    QPushButton *_button_card_3 = new QPushButton("Card 3",window_card);
    _button_card_3->setGeometry(10,70,280,30);

    window_card->show();
}

void MainWindow::on_pushButton_2_clicked(bool checked)
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

    // create push button to col;ect money from atm
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

    QLabel* label_4 = new QLabel("", window_atm);
    label_4->setGeometry(70, 100, 50, 30);

    QLabel* label_5 = new QLabel("", window_atm);
    label_5->setGeometry(290, 10, 50, 30);

    QLabel* label_6 = new QLabel("", window_atm);
    label_6->setGeometry(290, 40, 50, 30);

    QLabel* label_7 = new QLabel("", window_atm);
    label_7->setGeometry(290, 70, 50, 30);

    QLabel* label_8 = new QLabel("", window_atm);
    label_8->setGeometry(290, 100, 50, 30);

    // create text browers to display information about
    // login, wrong pin, or your decision

    QTextBrowser* text_browser_1 = new QTextBrowser(window_atm);
    text_browser_1->setGeometry(130,40,150,70);
    text_browser_1->setText("Welcone in ATM :-) \n Put Card to start sesion. \n");


    window_atm->show();

}

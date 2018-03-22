#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText(" ");
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_9->setText(" ");
    ui->label_10->setVisible(false);
    ui->label_11->setVisible(false);
    ui->label_12->setVisible(false);

    ui->pushButton_5->setText(" ");
    ui->pushButton_6->setText(" ");
    ui->pushButton_7->setText(" ");
    ui->pushButton_8->setText(" ");
    ui->pushButton_13->setText(" ");
    ui->pushButton_14->setText(" ");
    ui->pushButton_15->setText(" ");
    ui->pushButton_16->setText(" ");

    connect (ui->pushButton, SIGNAL (clicked(bool)), this, SLOT (on_pushButton_clicked));
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

#include "mainwindow.h"
#include <QApplication>
#include "Card.h"
#include "Decorator.h"
#include "Singleton.h"

bool decision = false;

static volatile Card* _card = NULL;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    //Card* card_1 = new Wrapper_PL(new Card_individual);

    //Card* card_2 = new Card_individual;

    //card_2->set_password(1234);
    //cout << card_2->get_password() << endl;

    Card* card_2 = new Wrapper_PL(new Card_individual);

    card_2->about_account();
    card_2->set_password(12345);
    //std::cout << card_2->get_password() << std::endl;

    Factory* factory = NULL;

    Card* _karta[3];
    _karta[0] = new Wrapper_PL(factory->create_individual_card());
    _karta[0]->set_password(1235);
    //cout << _karta[0]->get_password() << endl;
    //cout << _karta[0]->get_ID() << endl;

    // Tworzymy obiekt typu Server, ktory bedzie udawal baze danych
    Server* server = Server::instance();

    // Dodajemy stworzoną wyzej karte do bazy danych
    server->add_new_account_to_database(_karta[0]);

    //card_1->about_account();

    //cout << card_1->get_password << endl;

    return a.exec();
}

#include <iostream>
#include <string>

#include "Card.h"
#include "Decorator.h"
#include "Singleton.h"


using namespace std;

int main() {
	/*
	//Card* card_1 = new Wrapper_PL(new Card_individual);

	//Card* card_2 = new Card_individual;

	//card_2->set_password(1234);
	//cout << card_2->get_password() << endl;

	Card* card_2 = new Wrapper_PL(new Card_individual);

	card_2->about_account();
	card_2->set_password(12345);
	cout << card_2->get_password() << endl;

	Factory* factory = NULL;

	Card* _karta[3];
	_karta[0] = new Wrapper_PL(factory->create_individual_card());
	_karta[0]->set_password(1235);
	cout << _karta[0]->get_password() << endl;
	cout << _karta[0]->get_ID() << endl;

	// Tworzymy obiekt typu Server, ktory bedzie udawal baze danych
	Server* server = Server::instance();

	// Dodajemy stworzon� wyzej karte do bazy danych
	server->add_new_account_to_database(_karta[0]);

	//card_1->about_account();

	//cout << card_1->get_password << endl;
	*/

	// test generatora id

	Card* _karta;
	Factory* factory = NULL;

	_karta = factory->create_individual_card();
	// pokaz ID
	cout << _karta->get_ID() << endl;
	_karta->set_password(6789);

	Card* _karta_2;

	_karta_2 = factory->create_individual_card();
	// pokaz ID
	cout << _karta_2->get_ID() << endl;

	// przypadek gdy tworzymy tablice kart

	Card* _card[10];

	for (int i = 0; i <= 9; i++)
	{
		_card[i] = factory->create_individual_card();
		cout << _card[i]->get_ID() << endl;
	}

	// haslo z int na string4
	string haslo = to_string(_karta->get_password());

	cout << haslo << endl;

	// Tworzymy obiekt typu Server, ktory bedzie udawal baze danych
	Server* server = Server::instance();

	// Dodajemy stworzon� wyzej karte do bazy danych
	server->add_new_account_to_database(_card[0]);

	// Odczytaj instancje czy obiekt? z serwera.
	server->get_card_instance(2);







	system("pause");
	return 0;
}
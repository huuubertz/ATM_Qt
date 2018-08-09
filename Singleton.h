#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <vector>
#include "Card.h"	

class Server{
private:
	static Server* _instance;

	// tworzymy wektor, ktory bedzie symulowal baze danych na id i haslo
    std::vector<Card*> _m_id_data_base;

	Server()
	{

	}

public:
	// SINGLETON zapewniamy, ze bedzie istniala tylko jedna instancja klasy Decision
	static Server* instance(){
		if (!_instance){
			_instance = new Server;
		}
		return _instance;
	}

	void add_new_account_to_database(Card* _card) {
		_m_id_data_base.push_back(_card);
	}

    int get_password_of_card(Card* _card) {
        return _card->get_password();
    }

    void change_password_of_card(Card* card, int password) {
        card->set_password(password);
    }

    void change_saldo_on_account(Card* card, double value) {
        card->set_saldo(value);
    }

    // zmienna dajaca dostep do glownego menu ATM
    static bool ATM_menu_visibility;
};


//Server* Server::_instance;

// zainicjalizowanie poczatkowa wartoscia FALSE zmiennej odpowiadajacej za dostp do menu
bool Server::ATM_menu_visibility=false;

#endif

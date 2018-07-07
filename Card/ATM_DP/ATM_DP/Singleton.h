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

	Card_individual get_card_instance(int _number_of_card) {
		//return _m_id_data_base[_number_of_card]
			// Nie moge tak zrobic bo nie ma konstruktora ktory pozwolilby mi na zrzutowanie vectora typu card na card individual. 
			// Chyba ze w przyplywnie naglej kreatywnosci zmienie ten typ na Card_individual i bedzie banglalo? 
	}

};


Server* Server::_instance;

#endif
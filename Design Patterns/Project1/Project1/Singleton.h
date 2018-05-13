#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <vector>
#include "Factory.h"

class Decision{
private:
	// tworzymy wektor, ktory bedzie symulowal baze danych na id i haslo
	std::vector<Card*> _m_id_data_base;
	std::vector<Card*> _m_password_data_base;

	static Decision* _instance;

	Decision()
	{

	}
public:
	// SINGLETON zapewniamy, ze bedzie istniala tylko jedna instancja klasy Decision
	static Decision* instance(){
		if (!_instance){
			_instance = new Decision;
		}
		return _instance;
	}
	// ABSTRACT FACTORY METHOD create new card for individual person 
	Card* create_individual_account(){
		return new Card_individual;
	}
	// ABSTRACT FACTORY METHOD create new card for administrator 
	Card* create_administrator_account(){
		return new Card_administrator;
	}

	// dodaj do BAZY DANYCH id konta
	void add_new_account_to_data_base(Card* c){
		_m_id_data_base.push_back(c);
		std::cout << _m_id_data_base.back() << std::endl;
	}



	//template <typename data>
	//void check_card(data* card);
};

Decision* Decision::_instance = 0;

#endif
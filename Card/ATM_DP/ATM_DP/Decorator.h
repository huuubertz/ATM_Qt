#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include "Card.h"

class Wrapper:public Card{
private:
	Card* _m_card;
public:
	Wrapper(Card* _card) //: _m_card(_card)
	{
		_m_card = _card;
	}

	void about_account() {
		_m_card->about_account();
	}

	void about_transaction() {
		_m_card->about_transaction();
	}

	void set_password(int _password) {
		_m_card->set_password(_password);
	}

	int get_password() {
		return _m_card->get_password();
	}

	int get_ID() {
		return _m_card->get_ID();
	}

	virtual Card* create_individual_account_with_wrapp() = 0;
};

class Wrapper_PL:public Wrapper{
public:

	Wrapper_PL(Card *card) : Wrapper(card)
	{

	}


	void about_account() {
		Wrapper::about_account();
		std::cout << "Wrapper_PL zaimplementowany" << std::endl;
	}

	Card* create_individual_account_with_wrapp() {
		return new Wrapper_PL(new Card_individual);
	}

};

#endif
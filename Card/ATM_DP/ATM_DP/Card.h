#ifndef CARD_H
#define CARD_H

#include <iostream>

class Card{
protected:
	static int _m_id_generator;
	int _m_id;
	// przerobic haslo na tablice char 
	// latwiej bedzie sprawdzic poprawnosc pin'u
	int _m_password;
public:
	Card()
	{
		_m_id_generator++;
	}
	// SETERS and GETTERS
	virtual void set_password(int _password) = 0;
	virtual int get_password() = 0;
	virtual int get_ID() = 0;
	virtual void about_account() = 0;
	virtual void about_transaction() = 0;

};

int Card::_m_id_generator = 0;

class Card_individual :public Card{
public:
	Card_individual() 
	{
		_m_id = _m_id_generator;
	}
	// SETERS and GETTERS
	
	void set_password(int _password){
		_m_password = _password;
	}
	
	int get_password() {
		return _m_password;
	}

	int get_ID() {
		return _m_id;
	}

	void about_account() {
		std::cout << "account without wrapp" << std::endl;
	}

	void about_transaction() {
		std::cout << "about transaction" << std::endl;
	}

};

class Factory{
public:
	Card* create_individual_card() {
		return new Card_individual;
	}
};

#endif
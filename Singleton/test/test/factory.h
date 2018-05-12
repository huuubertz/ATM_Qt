#ifndef FACTORY_H
#define FACTORY_H
#include<iostream>
class Card{
protected:
	int _m_id;
	char _m_password[4];
public:
	virtual void set_password(char _pass) = 0;
	virtual int get_Id() = 0;
	virtual char* get_passowrd() = 0;
};

class Card_individual : public Card{
private:
	static int _id_generator;
public:
	Card_individual()
	{
		_m_id = _id_generator;
		_id_generator += 1;
	}

	void set_password(char _pass){
		std::cout << "" << std::endl;
	}
	int get_Id(){
		return _m_id;
	}
	char *get_passowrd(){
		std::cout << "" << std::endl;
		return _m_password;
	}
};

int Card_individual::_id_generator = 0;

class Card_administrator :public Card{
public:
	void set_Id(int _id){
		std::cout << "" << std::endl;
	}
	void set_password(char _pass){
		std::cout << "" << std::endl;
	}
	int get_Id(){
		std::cout << "" << std::endl;
		return 3;
	}
	char* get_passowrd(){
		std::cout << "" << std::endl;
		return _m_password;
	}
};

class Card_creator{
public:
Card* create_card_individual(){
return new Card_individual;
}
Card* create_card_administrator(){
return new Card_administrator;
}

};

/*
class Card_creator_online: public Card_creator{
public:
Card* create_card_individual(){
return new Card_individual;
}
};

class Card_creator_admin: public Card_creator{
public:
Card* create_card_administrator(){
return new Card_administrator;
}
};
*/
#endif
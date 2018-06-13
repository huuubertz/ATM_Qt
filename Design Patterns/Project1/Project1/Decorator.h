#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include "factory.h"

class Wrapper:public Card{
private:
	Card *m_karta;
public:

	Wrapper(Card *karta){
		m_karta = karta;
	}

	void konto_walutowe(){
		m_karta->konto_walutowe();
	}
};

class Wrapper_pln :public Wrapper{
public:
	Wrapper_pln(Card* _card) : Wrapper(_card)
	{
		
	}

	~Wrapper_pln()
	{
		std::cout << "PLN delete" << std::endl;
	}

	void konto_walutowe(){
		Wrapper::konto_walutowe();
		std::cout << "PLN" << ", ";
	}

};

class Wrapper_euro :public Wrapper{
public:
	Wrapper_euro(Card *_card) : Wrapper(_card)
	{

	}
	~Wrapper_euro() 
	{
		std::cout << "Euro wrapper delete" << " ";
	}
	
	// virtual
	void konto_walutowe(){
		Wrapper::konto_walutowe();
		std::cout << "Euro wrapper" << std::endl;
	}

};


#endif
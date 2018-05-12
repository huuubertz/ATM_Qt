#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include "factory.h"

class Wrapper{
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

class Wrapper_pln :public Card{
public:
	~Wrapper_pln()
	{
		std::cout << "PLN delete" << std::endl;
	}

	void konto_walutowe(){
		std::cout << "PLN" << ", ";
	}

	void set_password(char _pass){ std::cout << "Euro wrapper" << std::endl; }
	int get_Id(){ return 2; }
	char* get_passowrd(){ return; }
	void konto_walutowe(){ std::cout << "Euro wrapper" << std::endl; }
};

class Wrapper_euro :public Wrapper{
public:
	Wrapper_euro(Card *karta) : Wrapper(karta)
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

	void set_password(char _pass){ std::cout << "Euro wrapper" << std::endl; }
	int get_Id(){ return 2; }
	char* get_passowrd(){ return; }
	void konto_walutowe(){ std::cout << "Euro wrapper" << std::endl; }

};


#endif
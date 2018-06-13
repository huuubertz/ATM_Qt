#include <iostream>
#include "Factory.h"
#include "Singleton.h"
#include "Decorator.h"

int main(){
	/*
	//Card_creator* factory;

	Card* karta[2];

	//karta[0] = factory->create_card_individual;

	Decision* decyzja = Decision::instance();

	karta[1] = decyzja->create_individual_account();
	karta[0] = decyzja->create_individual_account();

	//karta[1]->get_Id;

	std::cout << karta[1]->get_Id() << " " << karta[0]->get_Id() << std::endl;

	decyzja->add_new_account_to_data_base(karta[0]);
	*/

	Card* karta = new Wrapper_euro(new Wrapper_pln);
	system("pause");
	return 0;
}
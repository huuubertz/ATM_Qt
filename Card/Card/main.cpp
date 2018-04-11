#include<iostream>
#include "card.h"
#include "AccessDecision.h"

int Card::generate_id=0;
AccessDecision* AccessDecision::instance;

int main(){

	Card new_card;

	new_card.setPassword(921);
	std::cout << new_card.getPassword() << std::endl;

	system("pause");
	return 0;
}
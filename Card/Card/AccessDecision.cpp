#include "AccessDecision.h"

AccessDecision* AccessDecision::getInstance(){
	if (instance == NULL){
		instance = new AccessDecision();
	}
	else return instance;
}
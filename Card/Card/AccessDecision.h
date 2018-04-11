#ifndef ACCESSDECISION_H
#define ACCESSDECISION_H

#include<iostream>
#include <cstdint>

class AccessDecision{
private:
	static AccessDecision* instance;
	static bool decision;
	static uint8_t login_attempts;

	AccessDecision(){

	}
public:
	static AccessDecision* getInstance();
	~AccessDecision(){

	}
};
#endif
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <cstdint>

class Card{
private:
	static int generate_id;
	int m_id;
	int m_password;

public:
	Card()
	{
		m_id = generate_id;
		generate_id++;
	}

	Card(const Card&) = delete;

	void setPassword(int pass){
		m_password = pass;
	}

	int getPassword(){
		return m_password;
	}

	int getId(){
		return m_id;
	}


};

#endif
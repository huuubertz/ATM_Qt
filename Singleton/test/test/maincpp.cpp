#include<iostream>
#include<vector>

using namespace std;

class Card{
public:
	static Card* create_card(int choice);
	virtual void show_card_description() = 0;
};

int main(){

	/*
	int var;

	var = 200;

	int *ptr;
	int **pptr;

	ptr = &var;
	pptr = &ptr;

	cout << var << endl;
	cout << ptr << " " << *ptr << " " << &ptr << endl;
	cout << pptr << " " << *pptr << " " << **pptr << endl;

	int j = 2;
	int i = 3;
	int e = 5;
	j = i++;
	cout << j << endl;
	e = ++i;
	cout << j << endl;
	*/

	/*
	int tab[] = { 0, 2, 5 };
	int *p_tab;
	p_tab = tab;

	(*p_tab)++;
	p_tab++;
	(*p_tab++)++;

	p_tab + 5;

	cout << tab[0] << ", " << tab[1] << ", " << tab[2] << p_tab + 5 << endl;
	*/

	/*
	Card_creator *factory = new Card_creator;

	Card* karta[2];

	karta[0] = factory->create_card_individual;
	*/
	vector<Card*> karciwo;
	int choiciwo;

	for (int i = 0; i < 4; i++){
		cin >> choiciwo;

		karciwo.push_back(Card::create_card(choiciwo));

		karciwo[0]->show_card_description();

	}
	cin >> choiciwo;

	karciwo.push_back(Card::create_card(choiciwo));

	karciwo[0]->show_card_description();
	
	system("pause");
	return 0;
}

class Card_individual: public Card{
private:
	int _id;
	int _pass;
	static int _id_generator;
public:
	Card_individual()
	{
		_id = _id_generator;
		_id_generator++;
	}

	Card_individual(int _password) : _pass(_password)
	{

	}
	void show_card_description(){
		cout << "indyvidual card" << _id<< endl;
	}

	void set_password(int _password){
		_pass = _password;
	}
	int get_password(){
		return _pass;
	}
	
};

int Card_individual::_id_generator = 0;

Card *Card::create_card(int choice){

	if (choice == 1){
		return new Card_individual;
	}
}
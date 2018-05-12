#include <iostream>

// using namespace std for faster debug
using namespace std;

// create function
void higer_layer(){
	cout << "hello in higher layer" << endl;
}

// create pointer to function
typedef void(*callback)(void);
// define function
void register_callback(callback ptr_register_callback);

int main(){

	callback ptr_my_callback = higer_layer;
	register_callback(higer_layer);
	system("pause");
	return 0;
}

void register_callback(callback ptr_register_callback){

	cout << "inside register callback" << endl;
	(*ptr_register_callback)();

}


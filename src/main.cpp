#include <string>
#include <ostream>
#include <iostream>
#include "compte.h"
#include "comptecheque.h"
using namespace std;
int main(){
	try{
		CompteCheque a(1,"Claudine");
		CompteCheque b(12,"Antonio",500);
		CompteCheque c(13,"Bernardino",800,3);
		cout << a;
		cout << b;
		cout << c;

		a.depot(100.01);
		b.retrait(500);
		c.retrait(800.01);
	}
	catch(const char * ex){
		cout << "Exception : " << ex << endl;
	}
	return 0;
}
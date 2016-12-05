#include <string>
#include <ostream>
#include <iostream>
#include "compte.h"
using namespace std;
int main(){
	Compte a(1,"Claudine");
	Compte b(12,"Antonio",500);
	cout << a;
	cout << b;
	a.depot(100.01);
	b.retrait(500.01);
	cout << a;
	cout << b;
	return 0;
}
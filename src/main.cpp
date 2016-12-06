#include <string>
#include <ostream>
#include <iostream>

#include "compte.h"
#include "comptecheque.h"
#include "livret.h"
#include "pel.h"
#include "moneo.h"

using namespace std;
int main(){
	//Compte chèque
	cout <<endl << "***Comptes cheques***"<<endl;
	CompteCheque claudine(1,"Claudine");
	CompteCheque antonio(12,"Antonio",500);
	CompteCheque bernardino(13,"Bernardino",800,300);
	cout << claudine;
	cout << antonio;
	cout << bernardino;
	//Mauvaise creation : solde negatif
	try{
		cout << "creation avec montant = -6"<<endl;
		CompteCheque bad(15,"Roberio",-6);
	}catch(const char * ex){
		cout << "Exception : " << ex << endl;
	}
	//Dépassement de découvert
	try{
		bernardino.retrait(1100);
		cout << "retrait 10 cts"<<endl;
		bernardino.retrait(0.1);
	}catch(const char * ex){
		cout << "Exception : " << ex << endl;
	}
	//Livret
	cout <<endl << "***Livrets***"<<endl;
	Livret roberio(2,"Roberio",3);
	Livret elena(3,"Elena",1600,3);
	cout << roberio;
	cout << elena;	
	//PEL 
	//Moneo
	//Virement
	/*try{
		CompteCheque a(1,"Claudine");
		CompteCheque b(12,"Antonio",500);
		CompteCheque c(13,"Bernardino",800,3);

		Livret l(2,"Barbara",1000,5);
		Pel p(2,"Barbara",10000);

		cout << a;
		cout << b;
		cout << c;
		cout << l;
		cout << p;

		double interets = l.versementInteret();

		cout << "Interets gagnes : " << interets << endl;

		a.depot(100.01);
		b.retrait(500);
		c.retrait(800.01);
		p.virement(a,100);
		cout << a;
		cout << p;
	}
	catch(const char * ex){
		cout << "Exception : " << ex << endl;
	}*/
	return 0;
}
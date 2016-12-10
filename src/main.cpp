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
	try{
		cout << "retrait -100 euro"<<endl;
		claudine.retrait(-100);
	}catch(const char * ex){
		cout << "Exception : " << ex << endl;
	}
	bernardino.setDecouvert(600);
	cout << "decouvert bernardino = 600";
	bernardino.retrait(300);
	//Livret
	cout <<endl << "***Livrets***"<<endl;
	Livret roberio(2,"Roberio",3);
	Livret elena(3,"Elena",1600,3);
	cout << roberio;
	cout << "interet = " << roberio.getTauxInteret() << "%"<<endl;
	cout << "solde min = " << roberio.getSoldeMinimum() << "euro"<<endl;
	cout << elena;
	cout << "interet = " << elena.getTauxInteret() << "%"<<endl;
	cout << "solde min = " << elena.getSoldeMinimum() << "euro"<<endl;
	try{
		cout << "Roberio interets = " << roberio.versementInteret() <<endl;
		cout << "Elena interets = " << elena.versementInteret() <<endl;
		cout << elena;
		cout << "solde min = " << elena.getSoldeMinimum() << "euro"<<endl;
		//retrait en dessous du seuil
		roberio.retrait(150);
	}catch(const char * ex){
		cout << "Exception : " << ex << endl;
	}
	try{
		//retrait negatif
		elena.retrait(-150);
	}catch(const char * ex){
		cout << "Exception : " << ex << endl;
	}
	//PEL
	cout <<endl << "***PEL***"<<endl;
	Pel samanta(112,"Samanta");
	cout << samanta;
	samanta.depot(500);
	cout << samanta;
	Pel barbara(2,"Barbara",10000);
	cout << barbara;
	cout << "interet = " << barbara.getTauxInteret() << "%"<<endl;
	barbara.setTauxInteret(5);
	cout << "interet = " << barbara.getTauxInteret() << "%"<<endl;
	cout << "Barbara interets = " << barbara.versementInteret() <<endl;
	cout << barbara;
	try{
		//retrait d'une somme differente du solde
		barbara.retrait(10000);
	}catch(const char * ex){
		cout << "Exception : " << ex << endl;
	} 
	barbara.retrait(10500);
	try{
		//depot negatif
		barbara.depot(-500);
	}catch(const char * ex){
		cout << "Exception : " << ex << endl;
	}
	//Moneo
	cout << endl << "###MONEO###"<< endl;
	Moneo a(antonio,50);
	Moneo b(claudine,90,90);
	Moneo c(bernardino,100,0);
	try{
		cout << a;
		cout << b;
		cout << c;
		a.recharge();
		bernardino.depot(6000);
		c.recharge();
		c.retrait(50);
		c.recharge();
		b.recharge();
	}catch(const char * ex){
		cout << "Exception : " << ex << endl;
	}
	//Virement
	cout << endl << "###Virement###"<< endl;
	cout << bernardino;
	cout << antonio;
	bernardino.virement(antonio,50);
	cout << bernardino;
	cout << antonio;
	return 0;
}
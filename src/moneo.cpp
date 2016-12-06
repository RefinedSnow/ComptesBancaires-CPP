#include <string>
#include <ostream>
#include <iostream>

#include "moneo.h"
using namespace std;

Moneo::Moneo(CompteCheque &compte, double soldeMax) : Moneo(compte,soldeMax,0){

}

Moneo::Moneo(CompteCheque &compte, double max, double montant) : compteCheque(compte){
	if(montant > max){
		throw "Creation de moneo impossible, montant superieur au solde max";
	}
	if(montant < 0 ||soldeMax <= 0){
		throw "Creation de moneo impossible, montant negatif";	
	}
	solde = montant;
	compteCheque = compte;
	soldeMax = max;	
}

void Moneo::retrait(double montant){
	if(montant > solde){
		throw "Moneo : paiement impossible, montant > solde";
	}
	if(montant <= 0){
		throw "Moneo : paiement impossible, montant nul ou negatif";
	}

	solde -= montant;
	cout << "Moneo du compte no : " << compteCheque.getNumCompte() << " retrait : " << montant << endl;
	cout << "Nouveau solde : " << solde << endl;
}

void Moneo::recharge(){
	if(solde == soldeMax){
		throw "Moneo : recharge impossible la carte est pleine";
	}
	compteCheque.retrait(soldeMax-solde);
	cout << "Moneo du compte no : " << compteCheque.getNumCompte() << " recharge  : " << soldeMax-solde << endl;
	solde = soldeMax;
	cout << "Nouveau solde : " << solde << endl;
}
ostream& operator<<(ostream &strm, const Moneo& m) {
	strm << "Moneo de " << m.compteCheque.getNomTitulaire() <<" solde max : " << m.soldeMax;
	strm << " solde : " << m.solde;
	return strm << endl;
}
#include <string>
#include <ostream>
#include <iostream>

#include "moneo.h"
using namespace std;

Moneo::Moneo(CompteCheque &compte, double soldeMax) : Moneo(compte,soldeMax,0){

}

Moneo::Moneo(CompteCheque &compte, double max, double montant) : compteCheque(compte){
	compteCheque = compte;
	solde = montant;
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
	solde = soldeMax;
	cout << "Moneo du compte no : " << compteCheque.getNumCompte() << " recharge  : " << soldeMax-solde << endl;
	cout << "Nouveau solde : " << solde << endl;
}
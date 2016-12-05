#include <string>
#include <ostream>
#include <iostream>

#include "comptecheque.h"
using namespace std;

CompteCheque::CompteCheque(int numCompte, string nomTitulaire) : CompteCheque(numCompte,nomTitulaire,0,0){
	cout << "+++CompteCheque(numCompte, nomTitulaire)" << endl;
}
CompteCheque::CompteCheque(int numCompte, string nomTitulaire, double solde) : CompteCheque(numCompte,nomTitulaire,solde,0){
	cout << "+++CompteCheque(numCompte, nomTitulaire, solde)" << endl;
}
CompteCheque::CompteCheque(int numCompte, string nomTitulaire, double solde, double montant) : Compte(numCompte,nomTitulaire,solde){
	if(montant < 0){
		throw "Montant de decouvert negatif, montant nul ou positif attendu";
	}
	decouvert = montant;
	cout << "+++CompteCheque(numCompte, nomTitulaire, solde, decouvert) : " << endl;
	cout << numCompte << ", " << nomTitulaire << ", " << solde << ", " << montant << endl;
}

void CompteCheque::retrait(double montant){
	bool condition = (solde - montant) < -decouvert;
	if(montant <= 0){
		throw "Montant de retrait nul ou negatif, montant positif attendu";
	}
	if(condition){
		throw "Operation non autorisee, decouvert depasse";
	}
	solde -= montant;
	cout << "Compte no : " << numCompte << " retrait : " << montant << endl;
	cout << "Nouveau solde : " << solde << endl;
}

double CompteCheque::getDecouvert() const{
	return decouvert;
}
void CompteCheque::setDecouvert(double montant){
	if(montant >= 0){
		decouvert = montant;
	}
	else{
		throw "Montant de decouvert negatif, montant nul ou positif attendu";
	}
}
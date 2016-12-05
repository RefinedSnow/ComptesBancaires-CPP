#include <string>
#include <ostream>
#include <iostream>
#include "compte.h"
using namespace std;

Compte::Compte(int num, string nom){
	numCompte = num;
	nomTitulaire = nom;
	solde = 0;
}
Compte::Compte(int num, string nom, double montant){
	numCompte = num;
	nomTitulaire = nom;
	solde = montant;
}

bool Compte::depot(double montant){
	if(montant > 0){
		solde += montant;
		cout << "Compte no : " << numCompte << " depot : " << montant << endl;
		cout << "Nouveau solde : " << solde << endl;
		return true;
	}
	return false;
}

bool Compte::retrait(double montant){
	if(montant > 0){
		solde -= montant;
		cout << "Compte no : " << numCompte << " retrait : " << montant << endl;
		cout << "Nouveau solde : " << solde << endl;
		return true;
	}
	return false;
}

int Compte::getNumCompte() const{
	return numCompte;
}
double Compte::getSolde() const{
	return solde;
}
string Compte::getNomTitulaire() const{
	return nomTitulaire;
}

ostream& operator<<(ostream &strm, const Compte& c) {
	strm << "Compte numero : " << c.getNumCompte() << " Titulaire : " << c.getNomTitulaire() << " Solde : " << c.getSolde();
    return strm << endl;
}
#include <string>
#include <ostream>
#include <iostream>
#include "compte.h"
using namespace std;

Compte::Compte(int num, string nom) : Compte(num,nom,0) {
	//cout << "+++Compte(numCompte,nomTitulaire) : " << num << "," << nom;
}

Compte::Compte(int num, string nom, double montant){
	if(montant < 0){
		throw "Creation de compte avec solde negatif non autorise";
	}
	numCompte = num;
	nomTitulaire = nom;
	solde = montant;
	//cout << "+++Compte(numCompte,nomTitulaire,solde) : " << num << "," << nom << "," << montant;
}

void Compte::depot(double montant){
	if(montant <= 0){
		throw "Montant de depot nul ou negatif, montant positif attendu";
	}
	solde += montant;
	cout << "Compte no : " << numCompte << " depot : " << montant << endl;
	cout << "Nouveau solde : " << solde << endl;
}

void Compte::retrait(double montant){
	if(montant <= 0){
		throw "Montant de retrait nul ou negatif, montant positif attendu";
	}
	solde -= montant;
	cout << "Compte no : " << numCompte << " retrait : " << montant << endl;
	cout << "Nouveau solde : " << solde << endl;
}

void Compte::virement(Compte compte, double montant){
	retrait(montant);
	compte.depot(montant);
	cout << "Virement de  : " << numCompte << " vers : " << compte.numCompte << endl;
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
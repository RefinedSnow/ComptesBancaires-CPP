#include <string>
#include <ostream>
#include <iostream>

#include "compte.h"
#include "livret.h"
using namespace std;

Livret::Livret(int num, string nom, double taux) : Livret(num,nom,0,taux){
	cout << "+++Livret(numCompte, nomTitulaire, tauxInteret)" << endl;
}
Livret::Livret(int num, string nom, double montant, double taux) : Compte(num,nom,montant){
	cout << "+++Livret(numCompte, nomTitulaire, solde, tauxInteret)" << endl;
	cout << num << ", " << nom << ", " << montant << ", " << taux << endl;
	tauxInteret = taux;
	soldeMinimum = montant;
}
double Livret::getTauxInteret() const{
	return tauxInteret;
}
double Livret::getSoldeMinimum() const{
	return soldeMinimum;
}
void Livret::retrait(double montant){
	bool condition = (solde - montant) < 0;
	if(montant <= 0){
		throw "Montant de retrait nul ou negatif, montant positif attendu";
	}
	if(condition){
		throw "Operation non autorisee, montant du retrait superieur au sold ";
	}
	solde -= montant;
	cout << "Livret no : " << numCompte << " retrait : " << montant << endl;
	cout << "Nouveau solde : " << solde << endl;
}
double Livret::versementInteret(){
	double interets = (tauxInteret/100) * soldeMinimum;
	solde += interets;
	soldeMinimum = solde;
	return interets;
}
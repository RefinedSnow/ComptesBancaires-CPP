#include <string>
#include <ostream>
#include <iostream>
#include "pel.h"

using namespace std;

Pel::Pel(int num, string nom) : Pel(num,nom,0){

}

Pel::Pel(int num, string nom, double solde) : Livret(num,nom,solde,0){

}

double Pel::getTauxInteret(){
	return Pel::tauxInteret;
}

double Pel::versementInteret(){
	double interets = (Pel::tauxInteret/100) * soldeMinimum;
	solde += interets;
	soldeMinimum = solde;
	return interets;
}

double Pel::setTauxInteret(double taux){
	Pel::tauxInteret = taux;
}

void Pel::retrait(double montant){
	if(montant != solde){
		throw "PEL : retrait impossible, le montant du retrait doit etre egal au solde";
	}
	solde -= montant;
	cout << "PEL no : " << numCompte << " retrait : " << montant << endl;
	cout << "Nouveau solde : " << solde << endl;
}
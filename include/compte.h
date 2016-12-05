#ifndef C_COMPTE
#define C_COMPTE

#include <string>
#include <ostream>
#include <iostream>
using namespace std;

class Compte{
	private:
	int numCompte;
	string nomTitulaire;
	double solde;

	public:
	Compte(int numCompte, string nomTitulaire);
	Compte(int numCompte, string nomTitulaire, double solde);

	bool depot(double montant);
	bool retrait(double montant);

	int getNumCompte() const;
	string getNomTitulaire() const;
	double getSolde() const;

	friend ostream& operator<<(ostream &strm, const Compte& c);
};
#endif
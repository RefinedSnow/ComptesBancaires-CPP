#ifndef C_LIVRET
#define C_LIVRET

#include <string>
#include <ostream>
#include <iostream>
#include "compte.h"

using namespace std;

class Livret : public Compte{
	private:
	double tauxInteret;
	double soldeMinimum;

	public:
	Livret(int numCompte, string nomTitulaire, double tauxInteret);
	Livret(int numCompte, string nomTitulaire, double solde, double tauxInteret);

	double getTauxInteret() const;
	double getSoldeMinimum() const;
	void retrait(double montant);

	double versementInteret();
};
#endif
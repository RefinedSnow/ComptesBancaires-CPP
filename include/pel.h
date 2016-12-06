#ifndef C_PEL
#define C_PEL

#include <string>
#include <ostream>
#include <iostream>

#include "livret.h"

using namespace std;

class Pel : public Livret{
	protected:
	static double tauxInteret;

	public:
	Pel(int numCompte, string nomTitulaire);
	Pel(int numCompte, string nomTitulaire, double solde);


	virtual void retrait(double montant);
	static double getTauxInteret();
	virtual double versementInteret();
	static void setTauxInteret(double tauxInteret);
};
#endif
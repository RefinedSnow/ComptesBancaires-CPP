#ifndef C_PEL
#define C_PEL

#include <string>
#include <ostream>
#include <iostream>
#include "livret.h"

using namespace std;

class Pel : public Livret{
	private:
	static double tauxInteret;

	public:
	Pel(int numCompte, string nomTitulaire);
	Pel(int numCompte, string nomTitulaire, double solde);


	void retrait(double montant);
	static double getTauxInteret();
	double versementInteret();
	static double setTauxInteret(double tauxInteret);
};
#endif
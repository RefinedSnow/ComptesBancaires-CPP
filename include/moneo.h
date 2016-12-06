#ifndef C_MONEO
#define C_MONEO

#include <string>
#include <ostream>
#include <iostream>
#include "comptecheque.h"

using namespace std;

class Moneo{
	private:
	double solde;
	double soldeMax;
	CompteCheque &compteCheque;

	public:
	Moneo(CompteCheque &compteCheque, double soldeMax);
	Moneo(CompteCheque &compteCheque, double soldeMax, double solde);

	virtual void retrait(double montant);
	void recharge();
};
#endif
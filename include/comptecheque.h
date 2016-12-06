#ifndef C_COMPTECH
#define C_COMPTECH

#include <string>
#include <ostream>
#include <iostream>
#include "compte.h"

using namespace std;

class CompteCheque : public Compte{
	protected:
	double decouvert;

	public:
	CompteCheque(int numCompte, string nomTitulaire);
	CompteCheque(int numCompte, string nomTitulaire, double solde);
	CompteCheque(int numCompte, string nomTitulaire, double solde, double decouvert);
	double getDecouvert() const;
	virtual void retrait(double montant);
	void setDecouvert(double montant);
	friend ostream& operator<<(ostream &strm, const CompteCheque& c);
};
#endif
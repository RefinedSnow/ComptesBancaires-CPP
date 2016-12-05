#ifndef C_COMPTE
#define C_COMPTE

#include <string>

class Compote{
	private:
	int numCompte;
	string nomTitulaire;
	double solde;

	public:
	Compte();
	Compte(double solde);

	bool depot();
	bool retrait();

};
#endif
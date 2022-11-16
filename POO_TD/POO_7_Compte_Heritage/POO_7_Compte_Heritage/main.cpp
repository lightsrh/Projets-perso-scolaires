#include <iostream>
using namespace std;
#include "hearders.h"

int main()
{
	Compte_remunere mon_Compte;		//creation d'un compte en compte remuneré
	mon_Compte.Crediter(100);
	mon_Compte.interet();
	mon_Compte.Afficher();
	return 0;
}
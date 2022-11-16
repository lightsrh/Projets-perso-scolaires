#include <iostream>
using namespace std;
#include "heure.h"

int main()
{
	Heure temps1(1, 15, 18);
	Heure temps2(1, 3, 9);
	Heure temps3;
	temps3.Saisir();
	cout << "temps apres saisie" << endl;
	temps1.Afficher();
	temps1.Add1seconde();
	cout << "temps apres ajout seconde" << endl;
	temps1.Afficher();
	temps1.Sub1seconde();
	cout << "temps apres sub une seconde" << endl;
	temps1.Afficher();
	temps1.diff2tps(temps3);
	temps2.Conversion_hms();
	return 0;
}
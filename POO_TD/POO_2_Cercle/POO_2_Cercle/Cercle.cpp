#include <iostream>
using namespace std;
#include <math.h>
#include "Cercle.h"

void Cercle::Saisir(void)
{
	cout << "Donne la valeur de l'abscisse du centre" << endl;
	cin >> XC;
	cout << "Donne la valeur de l'ordonnee du centre" << endl;
	cin >> YC;
	cout << "Donne la valeur du rayon du cercle" << endl;
	cin >> rayon;
}

void Cercle::Afficher(void)
{
	cout << "Les coordonnees du centre sont en : " << XC << "; " << XC << endl;
	cout << "Le rayon du cercle est de : " << rayon<<endl;
}

void Cercle::Perimetre(void)
{
	cout << "Le perimetre du cercle est de : " << 2 * 3.14*rayon << endl;
}

void Cercle::Surface(void)
{
	cout << "La surface du cercle est de : " << 3.14*rayon*rayon << endl;
}

void Cercle::Volume(void)
{
	cout << "Le volume associe au cercle est egal a : " << (4.0 / 3)*3.14*rayon*rayon*rayon << endl;
}

Cercle::Cercle(float x, float y, float r)
{
	XC = x;
	YC = y;
	rayon = r;
}

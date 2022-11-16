#include <iostream>
using namespace std;
#include <math.h>
#include "Point.h"

void Point::initialiser(void)
{
	cout << "Donne la valeur de l'abscisse" << endl;
	cin >> abscisse;
	cout << "Donne la valeur de l'ordonnee" << endl;
	cin >> ordonnee;
}

void Point::translater(void)
{
	float a, b;
	cout << "De combien translater en abscisse" << endl;
	cin >> a;
	abscisse = abscisse + a;
	cout << "De combien translater en ordonnee" << endl;
	cin >> b;
	ordonnee = ordonnee + b;

}

void Point::modifier(void)
{
	cout << "Quelle est la nouvelle valeure de l'abscisse" << endl;
	cin >> abscisse;
	cout << "Quelle est la nouvelle valeur de l'ordonnee" << endl;
	cin >> ordonnee;
}

float Point::distance(const Point & point2)
{
	return sqrt((point2.abscisse - abscisse)*(point2.abscisse - abscisse) + (point2.ordonnee - ordonnee)*(point2.ordonnee - ordonnee));
}

void Point::afficher(void)
{
	cout << "Les coordonnees sont : " << abscisse << "; " << ordonnee << endl;
}

Point::Point(float a, float o)
{
	abscisse = a;
	ordonnee = o;
}

//Fichier corrompu

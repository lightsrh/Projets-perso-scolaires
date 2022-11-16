#include <iostream>
using namespace std;
#include <math.h>
#include "headers.h"

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

Point Point::addition(const Point & point2)
{
	Point point3;
	point3.abscisse = abscisse + point2.abscisse;
	point3.ordonnee = ordonnee + point2.abscisse;
	return point3;
}

Point Point::operator+(const Point & point2)
{
	Point point3;
	point3.abscisse = abscisse + point2.abscisse;
	point3.ordonnee = ordonnee + point2.abscisse;
	return point3;
}

Point::Point(float a, float o)
{
	cout << "constructeur de Point" << endl;
	abscisse = a;
	ordonnee = o;
}

Point::~Point(void)
{
	cout << "destruction de l'objet Point" << endl;
}


Point_nomme::Point_nomme(float xa, float ya, char n)
{
	cout << "constructeur de Point_nomme" << endl;
	Point(xa,ya);
	nom = n;
}

void Point_nomme::afficher(void)
{
	cout << nom<<" ";
	Point::afficher();
}


void Point_nomme::modifier(void)
{
	cout << "quel est le nom du point ? " << endl;
	cin >> nom;
	Point::modifier();
}

Point_nomme::~Point_nomme(void)
{
	cout << "destruction point nommé" << endl;
}

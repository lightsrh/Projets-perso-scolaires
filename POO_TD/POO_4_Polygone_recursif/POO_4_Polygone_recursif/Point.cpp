#include <iostream>
using namespace std;
#include <math.h>
#include "Point.h"

Point::Point(float a, float o)		//constructeur de la classe point
{
	abscisse = a;
	ordonnee = o;
}

void Point::initialiser(void)		//permet d'initialiser la valeur d'un point
{
	cout << "Donne la valeur de l'abscisse" << endl;
	cin >> abscisse;
	cout << "Donne la valeur de l'ordonnee" << endl;
	cin >> ordonnee;
}

void Point::translater(void)		//permet de rajouter des valeurs aux coordonnees d'un point
{
	float a, b;
	cout << "De combien translater en abscisse" << endl;
	cin >> a;
	abscisse = abscisse + a;
	cout << "De combien translater en ordonnee" << endl;
	cin >> b;
	ordonnee = ordonnee + b;

}

void Point::modifier(void)			//permet de modifier les valeurs d'un point
{
	cout << "Quelle est la nouvelle valeure de l'abscisse" << endl;
	cin >> abscisse;
	cout << "Quelle est la nouvelle valeur de l'ordonnee" << endl;
	cin >> ordonnee;
}

float Point::distance(const Point & point2)		//calcul la distance entre deux points
{
	return sqrt((point2.abscisse - abscisse)*(point2.abscisse - abscisse) + (point2.ordonnee - ordonnee)*(point2.ordonnee - ordonnee));
}

void Point::afficher(void)			//affiche les coordonnees d'un point
{
	cout << "Les coordonnees sont : " << abscisse << "; " << ordonnee << endl;
}

float Point::additionA(const Point & point2)		//add la valeur de deux abscisses de points et retourne le resultat
{
	return abscisse + point2.abscisse;
}

float Point::additionO(const Point & point2)		//add la valeur de deux ordonnées de Points et retourne le resultat
{
	return ordonnee + point2.ordonnee;
}


void Polygone::Perimetre(void)		//calculer le perimetre d'un polygone et l'afficher
{
	float p = 0;
	for (int i = 0; i < n; i++)		//on tourne sur tous les points
	{
		if (i == n - 1)
		{
			p = p + tp[i].distance(tp[0]);		//Si on atteint le dernier point on oublie pas de faire le dernier avec le premier et de l'ajouter au perimetre total
		}
		else
		{
			p = p + tp[i].distance(tp[i + 1]);		//on ajoute la distance entre deux points au perimetre total
		}
	}
	cout << "Le perimetre du polygone est de : " << p << endl;
}

void Polygone::Surface(void)
{
	float S = 0;
	int j = n - 1;
	if (n == 1)
	{
		cout << "L'aire est nulle car il n'y a qu'un seul point " << endl;
	}
	else {
		for (int i = 0; i < n; i++)
		{
			S += (tp[j].additionA(tp[i]))*(tp[j].additionO(tp[i]));
			j = i;
		}
		cout << "L'aire du polygone est de : " << abs(S / 2) << endl;
	}
	
}

void Polygone::Set(void)
{
	int nb;
	cout << "combien de points pour le polygone ? " << endl;
	cin >> nb;
	/*Ici on ne modifie pas la valeur du n sinon ca risque de poser des problemes en l'utilisant plus tard, 
	mais du coup on ne sait pus la taille du tableau ce qui est problématique */
	tp = new Point[nb];
	for (int i = 0; i < nb; i++)		//3 appels à la classe Point pour remplir le tableau
	{

		tp[i].initialiser();
	}
}

int Polygone::Getn(void)
{
	int getn;
	getn = n;
	return n;
}

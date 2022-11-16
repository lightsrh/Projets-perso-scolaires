#include <iostream>
using namespace std;
#include "Point.h"


int main(void)
{
	int nb_points;	
	Point *pop = NULL;		//creation du pointeur vers le vide (rien ne se place en mémoire
	float perim =0;
	cout << "Combien de points ?" << endl;
	cin >> nb_points;
	pop = new Point[nb_points];		//allocation de place pour le tableau de nb_points + exection de nb_points fois le constructeur de Point
	for (int i = 0; i < nb_points; i++)
	{
		(pop + i)->afficher();
	}
	delete[] pop;
	pop = new Point[4];
	for (int i = 0; i < nb_points; i++)
	{
		(pop + i)->initialiser();
	}
	for (int i = 0; i < nb_points; i++)		//on tourne sur tous les points
	{
		if (i == nb_points - 1)
		{
			perim = perim + pop[i].distance(pop[0]);		//Si on atteint le dernier point on oublie pas de faire le dernier avec le premier et de l'ajouter au perimetre total
		}
		else
		{
			perim = perim + pop[i].distance(pop[i + 1]);		//on ajoute la distance entre deux points au perimetre total
		}
	}
	cout << "Le perimetre du polygone est de : " << perim << endl;
	for (int i = 0; i < nb_points; i++)
	{
		(pop + i)->afficher();
	}
	return 0;
}
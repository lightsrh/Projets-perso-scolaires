#include <iostream>
using namespace std;
#include "headers.h"

Suite::Suite(int nb_termes)		//constructeur de la classe
{	
	n = nb_termes;
	if (nb_termes != 0)			//si on n'a pas un tableau vide alors on peut construire
	{
		pop = new float[nb_termes];		//creation du tableau dynamique
		pop[0] = 8;				//premier element du tableau = 8
		for (int i = 1; i < nb_termes; i++)		//on remplit tout le tableau
		{
			pop[i] = (1.0 / 2)*(pop[i - 1]) - 3;		//calcul de la valeur a rentrer dans le tableau et affectation
		}
	}
}
void Suite::Get(int indice)
{
	if (0< indice and indice < n)
	{
		cout << "le point d'indice " << indice << " a une valeur de " << pop[indice] << endl;
	}
	else
	{
		cout << "l'indice donne n'est pas le bon" << endl;
	}
	
}

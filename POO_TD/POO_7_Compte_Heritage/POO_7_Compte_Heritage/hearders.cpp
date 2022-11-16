#include <iostream>
using namespace std;
#include "hearders.h"

void Compte::Afficher(void)			//afficher le solde du compte
{
	cout << "Votre solde est de : " << solde << endl;
}

void Compte::Debiter(float d)			//retirer de l'argent du compte
{
	solde = solde - d;
}

void Compte::Crediter(float c)			//ajouter de l'argent au compte
{
	solde = solde + c;
}

float Compte::Gets(void)
{
	return solde;
}

void Compte::Sets(float c)
{
	solde = solde + c;
}

Compte_remunere::Compte_remunere(float t)		//constructeur de la classe pour le compte remunere
{
	cout<<"Donne le taux"<<endl;			//definition du taux
	cin >> taux;
}

void Compte_remunere::interet(void)		//calcul de l'interet et affectation au solde
{
	Sets((Gets()*taux) / 100);		//si on est en private
	//solde = solde + ((solde * taux) / 100);		//si on est en protected 
}

void Compte_remunere::Afficher(void)			//fait appelle au "Afficher" de la classe Compte et affiche le taux
{
	Compte::Afficher();
	cout << "le taux est de : " << taux << endl;
}
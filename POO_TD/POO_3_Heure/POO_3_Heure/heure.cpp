#include <iostream>
using namespace std;
#include "heure.h"

void Heure::Saisir(void)
{
	cout << "Donne le nombre d'heures " << endl;
	cin >> heures;
	cout << "Donne le nombre de minutes" << endl;
	cin >> minutes;
	cout << "Donne le nombre de secondes" << endl;
	cin >> secondes;
}

void Heure::Afficher(void)
{
	cout << "L'heure est de : " << heures << " : " << minutes << " : " << secondes << endl;
}

void Heure::Add1seconde(void)
{
	int retenue;
	retenue = (secondes + 1) ;
	retenue = retenue - 60;
	if (retenue >  0)
	{
		secondes = secondes + 1 - 60;
		retenue = (minutes + 1) ;
		retenue = retenue - 60;
		cout << retenue << endl;
		if (retenue > 0)
		{
			minutes = minutes + 1 - 60;
			heures = heures + 1;
		}
	}
	else
	{
		secondes = secondes + 1;
	}
}

void Heure::Sub1seconde(void)
{
	if (heures == 0 and minutes == 0 and secondes == 0)
	{
		cout << "Ce n'est pas possible de retirer du temps a un temps deja nul" << endl;
	}
	else
	{
		if (secondes == 0)
		{
			if (minutes == 0)
			{
				heures = heures - 1;
				minutes = 59;

			}
			else
			{
				minutes = minutes - 1;
				secondes = 59;
			}
		}
		else
		{
			secondes = secondes - 1;
		}
	}
}

void Heure::diff2tps(Heure tps2)
{
	int new_heures, new_minutes, new_secondes,retenue;
	new_secondes = secondes - tps2.secondes;
	retenue = 0;
	if (new_secondes < 0)
	{
		retenue = 1;
		new_secondes = 60 + new_secondes;
	}
	new_minutes = minutes - tps2.minutes-retenue;
	retenue = 0;
	if (new_minutes < 0)
	{
		retenue = 1;
		new_minutes = 60 + new_minutes;
	}
	new_heures = heures - tps2.heures-retenue;
	if (new_heures < 0)
	{
		cout << "On ne peux pas soustraire une une plus grande a une heure plus petite" << endl;
	}
	else
	{
		cout << "le nouveau temps est de : " << new_heures << "; " << new_minutes << " ;" << new_secondes << endl;
	}
}

int Heure::Conversion_hms(void)
{
	int tps_secondes;
	tps_secondes = secondes + 60 * minutes + 3600 * heures;
	cout << "le temps converti en secondes est de : " << tps_secondes << endl;
	return tps_secondes;
}

Heure::Heure(int h, int m, int s)
{
	heures = h;
	minutes = m;
	secondes = s;
}

void temps_1::heure_1(void)
{
	int ts;
	Heure nt;
	ts = Conversion_hms();
	ts = ts - 1;
	nt = Conversion_h(ts);		//attribut a creer pour retransformer en hms depuis que secondes
	heures = nt.heures;
	minutes = nt.minutes;
	secondes = nt.secondes;
}

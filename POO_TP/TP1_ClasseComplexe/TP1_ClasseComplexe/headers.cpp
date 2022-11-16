#include <iostream>
#include <math.h>
using namespace std;
#include "headers.h"

void Complexe::afficher(void) const		//Afficher un complexe en cout
{
	char signe = '+';
	if (im < 0) 
	{
		if (re == 0)
		{
			cout << "	le complexe est egal a " << im;
		}
		else
		{
			signe = '-';
			cout << "	le complexe est egal a " << re << im << "j" << endl;
		}
	}
	else
	{
		if (re == 0)
		{
			if (im == 0)
			{
				cout << "	le complexe est nul" << endl;
			}
			else
			{	
				cout << "	le complexe est egal a " << im << endl;
			}
		}
		else
		{
			if (im == 0)
			{
				cout << "	le complexe est egal a " << im << endl;
			}
			else
			{
				cout << "	le complexe est egal a " << re << signe << im << "j" << endl;

			}
		}
	}
}

void Complexe::afficher(ostream& flux) const		//afficher un complexe avec un operator de cout
{
	cout << im;
	char signe = '+';
	if (im < 0)
	{
		if (re == 0)	//-xj
		{
			flux << "	le complexe est egal a " << im;
		}
		else  //y-xj
		{
			signe = '-';
			flux << "	le complexe est egal a " << re << im << "j" << endl;
		}
	}
	else
	{
		if (re == 0)	
		{
			if (im == 0)	//0
			{
				flux << "	le complexe est nul" << endl;
			}
			else  //xj
			{
				flux << "	le complexe est egal a " << im << endl;
			}
		}
		else  //y+xj
		{
			flux << "	le complexe est egal a " << re << signe << im << "j" << endl;
		}
	}
}

bool Complexe::comparaison(const Complexe & z2) const		//comparer deux complexes et renvoyer si ils sont egaux
{
	if (re == z2.re && im == z2.im)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Complexe Complexe::addition(const Complexe & complexe2) const		//additionner deux complexes et retourner le resultat
{
	Complexe complexe3;
	complexe3.re = re + complexe2.re;
	complexe3.im = im + complexe2.im;
	return complexe3;
}

Complexe Complexe::multiplication(const Complexe & complexe2) const		//multiplier deux complexes
{
	Complexe complexe3;
	float imag;
	imag =-( im * complexe2.im);
	complexe3.re = re * complexe2.re + imag;
	complexe3.im = im * complexe2.re + re*complexe2.im;
	return complexe3;
}

Complexe Complexe::soustraction(const Complexe & z2) const		//Soustraire deux complexes et retourner le resultat
{
	Complexe res;
	res.re = re - z2.re;
	res.im = im - z2.im;
	return res;
}

Complexe Complexe::division(const Complexe & z2) const		//diviser deux complexes et retourner le resultat
{
	Complexe denom,temp(re,im),res,numer;
	denom = z2.multiplication(z2.conjugue());
	numer = temp.multiplication(z2.conjugue());
	res.re = numer.re / denom.re;
	res.im = numer.im / denom.re;
	return res;
}

Complexe Complexe::conjugue(void) const		//retourner le conjugué d'un complexe
{
	Complexe res;
	res.re = re;
	res.im = -im;
	return res;
}

Complexe Complexe::oppose(void) const		//retourner l'opposé d'un complexe
{
	Complexe res;
	res.re = -re;
	res.im = -im;
	return res;
}

//a) 

/*Complexe Complexe::operator+(const Complexe & z2) const
{
	Complexe res;
	res.re = re + z2.re;
	res.im = im + z2.im;
	return res;
}

Complexe Complexe::operator-(float reel) const
{
	Complexe res;
	res.re = re + reel;
	return res;
}
*/
Complexe::Complexe(float reel, float imaginaire)		//contructeur de l'objet complexe
{
	re = reel;
	im = imaginaire;
	cout << "Constructeur de l'objet" << endl;
}

Complexe::Complexe(const Complexe & z)		//surcharge constructeur de copie, existant par défaut si on en a besoin
{
	re = z.re;
	im = z.im;
	cout << "constructeur de copie" << endl;
}

Complexe::~Complexe(void)		//destructeur de l'objet complexe
{
	cout << "Destruction de l'objet" << endl;
}

//b)
Complexe operator+(const Complexe & zAdd1, const Complexe & zAdd2)		//Surcharge d'operateur + pour l'addition
//Si on laisse .re fonctionne pas car encapsulation et mode private 
{
	return zAdd1.addition(zAdd2);
}

Complexe operator*(const Complexe & z1, const Complexe & z2)		//surcharge operator * pour la multiplication
{
	return z1.multiplication(z2);
}

Complexe operator-(const Complexe & z1, const Complexe & z2)		//surcharge d'operator - pour la soustraction
{
	return z1.soustraction(z2);
}

Complexe operator/(const Complexe & z1, const Complexe & z2)		//surcharge d'operator / pour la division
{
	return z1.division(z2);
}

Complexe operator==(const Complexe & z1, const Complexe & z2)		//surcharge de l'operator == pour le test d'égalité
{
	return z1.comparaison(z2);
}


ostream & operator<<(ostream & flux, const Complexe & z)				//surcharge d'operator << pour l'affichage sur cmd de sortie en cout
//flux en param d'entrée sortie car on le modifie en lui ajoutant des elems
{
	z.afficher();
	return flux;
	// TODO: insérer une instruction return ici
}

//3-

float Complexe ::argument(void) const		//calculer l'argument d'un complexe et le retourner
{
	float argument;
	if (re == 0)
	{
		if (im == 0)
		{
			argument = 0;
		}
		else
		{
			if (im > 0)
			{
				argument = 3.14 / 2;
			}
			else
			{
				argument = -3.14 / 2;
			}
		}
	}
	else
	{
		if (re > 0)
		{
			argument = atan(im / re);
		}
		else
		{
			argument = atan(im / re) + 3.14;
		}
	}
	if (argument > 2 * 3.14)
	{
		argument = argument - (2 * 3.14);
	}
	return argument;
}



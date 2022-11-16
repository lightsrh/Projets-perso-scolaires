#include <iostream>
using namespace std;
#include "ChainCar.h"

ChainCar::ChainCar(const char * init)
{
	cout << "Constructeur de chaine de caractere" << endl;
	//Determiner la longueur de la chaine
	len = 0;
	while (init[len] != '\0')
	{
		len++;
	}
	//creer la zone et allouer de la mémoire
	p_str = new char[len];
	for (unsigned int i = 0; i < len; i++)
	{
		p_str[i] = init[i];
	}
}

/*ChainCar::ChainCar(const ChainCar & ch)
{
	//cout << "constructeur de copie de chaine de caracteres par initialisation" << endl;
	//Determiner la taille de la chaine ChainCar
	len = ch.len;	//fonctionne aussi avec len=ch.len() car on se trouve dans la classe
	//Creation d'une nouvelle zone
	p_str = new char[len];
	for (unsigned int i = 0; i < len; i++)
	{
		p_str[i] = ch.p_str[i];	//on accede au pointeur de la chaine ch
	}
}*/

void ChainCar::afficher(void)const
{
	for (unsigned int i = 0; i < len; i++)
	{
		cout << p_str[i];
	}
}

void ChainCar::minToMaj(void)
{
	for (unsigned int i = 0; i < len; i++)
	{
		if (p_str[i] > 96)		//p_str[i]>='a' && p_str[i]<='z'
		{
			p_str[i] = p_str[i] - 32;		//p_str[i] = p_str[i]+'A'-'a';
		}
	}
}

void ChainCar::afficher(ostream & flux) const
{
	for (unsigned int i = 0; i < len; i++)
	{
		flux << p_str[i];
	}
}

ChainCar ChainCar::ajouter(const ChainCar& str2)const
{
	ChainCar concat;
	delete[] concat.p_str;
	concat.len = len + str2.len;	//taille de la nouvelle chaine
	concat.p_str = new char[concat.len];
	for (unsigned int j = 0; j < len; j++)
	{
		concat.p_str[j] = p_str[j];
	}
	for (unsigned int j = 0; j < str2.len; j++)
	{
		concat.p_str[j + len] = str2.p_str[j];
	}
	return concat;
}

ChainCar ChainCar::ajouter(const char * str2)const
{
	ChainCar concat;
	delete[] concat.p_str;
	unsigned int str2len = 0;
	while (str2[str2len] != '\0')
	{
		str2len++;
	}
	concat.len = len + str2len;	//taille de la nouvelle chaine
	concat.p_str = new char[concat.len];
	for (unsigned int j = 0; j < len; j++)
	{
		concat.p_str[j] = p_str[j];
	}
	for (unsigned int j = 0; j < str2len; j++)
	{
		concat.p_str[j + len] = str2[j];
	}
	return concat;
}

ChainCar ChainCar::operator=(const ChainCar & ch)
{
	//cout << "Constructeur de copie de chaine de caractere par affectation" << endl;
	// /!\on doit liberer l'espace occupé
	delete p_str;
	//Determiner la longueur de la chaine
	len = ch.len;
	//creer la zone et allouer de la mémoire 
	p_str = new char[len];
	for (unsigned int i = 0; i < len; i++)
	{
		p_str[i] = ch.p_str[i];
	}
	return *this;		//On retourne l'objet lui-même
}

ChainCar ChainCar::operator+(const ChainCar & str2)
{
	ChainCar concat;
	delete concat.p_str;
	concat.len = len + str2.len;	//taille de la nouvelle chaine
	concat.p_str = new char[concat.len];
	for (unsigned int j = 0; j < len; j++)
	{
		concat.p_str[j] = p_str[j];
	}
	for (unsigned int j = 0; j < str2.len; j++)
	{
		concat.p_str[j + len] = str2.p_str[j];
	}
	return concat;
}

ChainCar ChainCar::operator+(const char * str2)
{
	ChainCar concat;
	delete concat.p_str;
	unsigned int str2len = 0;
	while (str2[str2len] != '\0')
	{
		str2len++;
	}
	concat.len = len + str2len;	//taille de la nouvelle chaine
	concat.p_str = new char[concat.len];
	for (unsigned int j = 0; j < len; j++)
	{
		concat.p_str[j] = p_str[j];
	}
	for (unsigned int j = 0; j < str2len; j++)
	{
		concat.p_str[j + len] = str2[j];
	}
	return concat;
}

ostream & operator<<(ostream & flux, const ChainCar & str)
{
	str.afficher(flux);
	return flux;
}

ChainCar::~ChainCar(void)
{
	cout << "destructeur de la zone de caracteres" << endl;
	//On doit supprimer la zone en mémoire (p_str et init seront suppr mais si on en force par la destruction de la mémoire celle-ci va rester et causer une fuite mémoire
	delete[] p_str;
}


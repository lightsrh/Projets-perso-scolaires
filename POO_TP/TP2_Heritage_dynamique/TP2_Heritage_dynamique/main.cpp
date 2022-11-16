# include < iostream >
using namespace std;
#include "ChainCar.h"
int main(void)
{
	ChainCar nom(" MAYER "), prenom(" Kevin ");
	ChainCar specialite(" Decathlon ");
	ChainCar sportif=specialite;
	sportif = nom + " " + prenom + ": " + specialite;// concatenation
	cout << sportif << endl;// affichage
	return 0;
}

/*#include<iostream>
using namespace std;
#include"headers.h"

int main(void)
{
	ChainCar prenom("Sarah"), nom("Theoulle"), addition;
	ChainCar name=nom;//ou ChaineCar name(nom);//qui est equivalent	//appel au constructeur de copie
	cout << name<<endl;
	ChainCar firstname;	//pas d'appel au constructeur de copie
	firstname=prenom;		//Ici la copie de tous les caractères mais aussi de len, sans faire appel au constructeur de copie
	cout << firstname << endl;
	addition = prenom.ajouter("nom");
	addition.afficher();
	cout << endl;
	ChainCar specialite("Decathlon");
	system("pause");
	ChainCar sportif = addition + "bonjour";		//+ return bien la bonne chaine mais au moment de stocker dans sportif le len est en dépassement de capacité
	cout << sportif << endl;
													//cout <<sportif << endl;//affichage avec surcharge operator << qui fonctionne
	//Le dernier construit est le premier detruit donc on détruit prenom puis firstname puis name puis nom OR on l'a dejà détruit si on a pas le constructeur de copie  
	return 0;
}*/


/*#include <iostream>
using namespace std;
#include "headers.h"

int main()
{
	ChainCar str1("Sarah");
	ChainCar str2(" Theoulle");
	ChainCar result;
	str1.afficher();
	str1.minToMaj();
	str1.afficher();
	result = str1.ajouter(str2);
	result.afficher();
	return 0;
}*/

/*
prenom.afficher();
	cout << " de longueur " << prenom.getLen() << endl;
	nom.afficher();
	cout << " de longueur " << nom.getLen() << endl;
	//nom.minToMaj();
	nom.afficher();
	cout << endl;
	//On aimerait ecrire les lignes suivantes:
	   //debut partie a decommenter
	 name.afficher();
	  cout<<endl;
	  name.minToMaj();
	  name.afficher();
	  cout<<endl;
	  //system("pause");
	  nom.afficher();
	  cout << endl;
	  cout<<"On veut afficher le nom de famille, en maj. Est ce normal?"<<endl;		//Si on a pas le constructeur de copie On s'attend a avoir le nom en minuscules car on ne l'a pas mit en maj mais comme on a donné a nom les adresses de name et name est en majuscules....
	  //system("pause");
	  firstname.minToMaj();
	  firstname.afficher();
	  cout<<endl;
	  //system("pause");
	  prenom.afficher();
	  cout << endl;
	  cout<<"On veut afficher le prenom, en maj. Est ce normal?"<<endl;		//Si on a pas le constructeur de copie On a mit firstname en maj et prenom reste normalemment en min sauf que l'on a copié les adresses au début donc prenom a au final les mêmes adresses que firstname et celui-ci est en maj...
	  //system("pause");
	  cout<<"adresse de prenom : "<<(void*)prenom.getstr()<<endl;			// Si on a pas le constructeur de copie Attention on a la même adresse pour prenom et firstname car on a fait une copie de la premiere adresse dans firstname quand on a fait le '='
	  cout<<"adresse de firstname : "<<(void*)firstname.getstr()<<endl;
	  cout << "adresse de nom : " << (void*)nom.getstr() << endl;			// Si on a pas le constructeur de copie Attention on a la même adresse pour prenom et firstname car on a fait une copie de la premiere adresse dans firstname quand on a fait le '='
	  cout << "adresse de name : " << (void*)name.getstr() << endl;
	  system("pause");
*/
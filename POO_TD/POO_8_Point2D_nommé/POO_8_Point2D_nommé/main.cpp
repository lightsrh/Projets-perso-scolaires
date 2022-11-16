#include "headers.h"
#include <iostream>
using namespace std;

int main()
{
	/*Point p1;		Point 1
	Point_nomme pn1;
	p1.afficher();
	p1.initialiser();
	p1.afficher();
	cout << "etape 2 : " << endl;		//point 2
	pn1.afficher();
	pn1.initialiser();
	pn1.afficher();*/
	/*Point *p = NULL;		//ne se passe rien		//point 3
	char reponse;
	cout << "donner oui si on veut un point,sinon non" << endl;
	cin >> reponse;
	if (reponse == 'O')
	{
		p = new Point;		//appelle le constucteur
		p->afficher();
		p->initialiser();
		p->afficher();
		delete p;		//pas de [] sinon il delete en boucle /!
	}
	else 
	{ p = new Point_nomme;
	p->afficher();
	p->modifier();
	p->afficher();
	delete p;
	}*/
	Point point1;		//construction des points sur lesquels on travaille
	Point point2;
	Point point3;
	Point point4;
	point1.initialiser();		//initialisation
	point2.initialiser();
	point3 = point1.addition(point2);		//affectation au point 3 des coordonnées addditionnées de point1 et point2
	//Pour + on a un constructeur de copie qui permet de mettre les valeurs de droite dans l'objet de gauche, ce qui ensuite fait un destructeur, c'est pour ca qu'on en a 5 au lieud e 4 avec les 4 constructeurs
	point3.afficher();
	point4 = point2 + point3;		//operateur "+" definit dans la classe qui permet d'additionner deux points
	point4.afficher();
	return 0;
}
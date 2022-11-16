#include <iostream>
using namespace std;
#include "headers.h"
//On a plus de destructeurs que de constructeurs car le '=' fait des copies des complexes pour les affecter et doit ensuite les detruire, mais ne fait pas appel au constructeur
int main()
{
	Complexe z(1,0);
	Complexe z1(1, 1);
	Complexe z2(2, -1);
	Complexe z3(3,-6);
	Complexe z4(3, -4);
	float temp;
	//Tests persos
	//a)
	/*
	z.afficher();
	temp = z.partie_reelle();
	cout <<"	partie reelle = "<< temp << endl;
	temp = z.partie_imaginaire();
	cout << "	partie imaginaire = " << temp << endl;
	temp = z.module();
	z3 = z.addition(z2);
	z3.afficher();
	z3 = z.multiplication(z2);
	z3.afficher();
	*/

	//tests persos

	/*z3 = z+ z1 + z2;		//il fait ((z+z1)+z2), il effetcue dans l'ordre selon lequel il voit les operateurs
	z3.afficher();
	//La suite fonctionne dans les deux sens pour la fonction definie hors de la classe mais uniquement dans le premier sens pour la méthode définie dans la classe
	z3 = z + 3;			//on peut ajouter un reel qui ira alors dans le premier attribut d'un complexe appelé seul par le constructeur et qui met 0 à l'imaginaire, ne fonctionne pas si dans le constructeur on fait affectation de l'imaginaire puis du reel
	z3.afficher();
	z3 = 3 + z;			
	z3.afficher();		//Dans classe --> fonctionne pas, hors classe --> fonctionne en appelant le constructeur pour mettre 3 en reel d'un complexe (im = 0)
	//z3 = z - 4;			// attention operateur - sert a ajouter un reel a un complexe
	//z3.afficher();
	z3 = z1*z2;
	z3.afficher();
	z = z1 + z2 * z3;		//Il fait dans l'ordre des priorités du calcul classique
	z.afficher();
	z = z1 * z2 + z3;		//Il fait dans l'ordre de ce qui est appelé donc * en premier puis + 
	z.afficher();
	z = (z1 + z2) * z3;		//Il fait dans l'ordre des priorités du calcul classique, en respectant les parenthèses si on en met
	cout << z;
	temp = z1.argument();
	cout <<"l'argument de z1 est : "<< temp<<endl;
	z = z1.conjugue();
	cout << z1 << "et son conjugue : " << z << endl;
	z = z1.oppose();
	cout << z1 << "et son oppose : " << z << endl;
	z = z1.soustraction(z2);
	cout << z1 << " -" << z2 << "= "<<z << endl;
	z = z1.division(z2);
	cout << z1 << "divise par  " << z2<<"= "<<z << endl;
	cout <<"0 = nb differents, 1= nb egaux --> "<< z1.comparaison(z2)<<endl;
	*/
	z = (z1 / z2)*(z1 / z2) + (z3.conjugue() / z4);
	cout << z << endl;		//= -0.92+1.44j
	temp = z.module();
	cout << temp<<endl;		//=1.7088
	temp = z.argument();
	cout << temp<<endl;		//=2.13773
	return 0;
}
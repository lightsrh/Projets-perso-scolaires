#include <iostream>
using namespace std;
#include "headers.h"

int main()
{
	Suite S0;		//on définit une suite avec 0 elements (attention a gerer l'exception dans le constucteur
	Suite S4(4);		//Suite avec 4 elements
	Suite S11(12);		//Suite avec 12 termes
	S4.Get(1);			//afficher le terme d'indice 1 (le deuxieme element)
	S11.Get(11);		//affiche le terme d'indice 11 (le douzieme element)
	return 0;
}
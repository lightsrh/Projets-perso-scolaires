#include "Point.h"
#include <iostream>
using namespace std;

int main()
{
	float d;
	Point test1;
	Point test2;
	test1.initialiser();
	test1.afficher();
	d=test1.distance(test2);
	cout << d<<endl;
	test1.translater();
	test1.afficher();
	test1.modifier();
	test1.afficher();
	return 0;
}
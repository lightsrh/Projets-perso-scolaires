#include <iostream>
using namespace std;

class Point				//classe de points avec deux dimensions
{
	private:			//definition des attributs de la classe Point
		float abscisse;
		float ordonnee;
	public:				//definition des methodes de la classe Point
		void initialiser(void);
		void translater(void);
		void modifier(void);
		float distance(const Point & point2);
		void afficher(void);
		float additionA(const Point & point2);
		float additionO(const Point & point2);
		Point(float a = 0, float o=0);		//constructeur de la classe
};

class Polygone			//creation d'un polygone qui appelle n fois la classe point dans le constructeur (pour les n points)
{
private :
	Point *tp;		// definition des attributs de la classe triangle
	int n;
public :
	void Perimetre(void);
	void Surface(void);
	void Set(void);
	int Getn(void);
	Polygone(void)			//constructeur de la classe 
	{
		int nb;
		cout << "combien de points pour le polygone ? " << endl;
		cin >> nb;
		n = nb;
		tp = new Point[nb];
		for (int i = 0; i<nb; i++)		//3 appels à la classe Point pour remplir le tableau
		{ 
			
			tp[i].initialiser();
		}
			
	}
	~Polygone(void)
	{
		delete[] tp;
		cout << "Destruction enclenchee, dans 3...2...1...destruction de l'objet" << endl;
	}
};

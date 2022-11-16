class Suite		//classe Suite
{
private:
	float *pop = nullptr;		//attribut pointeur vers le tableau contenant les elements de la suite
	int n;
public:
	void Get(int indice);		//methode pour recuperer la valeur du terme d'indice "indice"
	Suite(int nb_termes = 0);	//constructeur de la classe qui par défaut ne créer aucun element
	~Suite(void)				//destructeur de la classe
	{
		delete[] pop;			//delete du pointeur de la classe apres chaque utilisation
		cout << "Destruction enclenchee, dans 3...2...1...destruction de l'objet" << endl;
	}
};

class Point
{
private:
	float abscisse;
	float ordonnee;
public:
	virtual void initialiser(void);		//virtual pour utiliser les deux methodes de l'heritage quand on appelle un point nommé plutot que les deux methodes ici
	void translater(void);
	void modifier(void);
	float distance(const Point & point2);
	virtual void afficher(void);
	Point addition(const Point & point2);
	Point operator +(const Point & point2);
	Point(float a = 0, float o = 0);
	~Point(void);
};

class Point_nomme : public Point
{
private:
	char nom;
public:
	Point_nomme(float xa = 0, float ya =0, char n = 'Z');
	virtual void afficher(void);
	void modifier(void);
	~Point_nomme(void);
};

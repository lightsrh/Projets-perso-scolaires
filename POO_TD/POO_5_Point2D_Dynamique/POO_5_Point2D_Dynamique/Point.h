class Point
{
	private:
		float abscisse;
		float ordonnee;
	public:
		void initialiser(void);
		void translater(void);
		void modifier(void);
		float distance(const Point & point2);
		void afficher(void);
		Point(float a = 0, float o = 0);
};
//fichier corrompu
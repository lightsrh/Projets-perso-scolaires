class Cercle
{
private:
	float XC;
	float YC;
	float rayon;
public:
	void Saisir(void);
	void Afficher(void);
	void Perimetre(void);
	void Surface(void);
	void Volume(void);
	Cercle(float x = 0, float y = 0, float r = 0);
};

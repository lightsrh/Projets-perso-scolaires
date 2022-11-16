class Complexe
{
private:
	float re;
	float im;
public:
	void afficher(void) const;
	float partie_reelle(void)
	{
		return re;
	}
	float partie_imaginaire(void)
	{
		return im;
	}
	float module(void)
	{
		return sqrt(re*re + im * im);	
	}
	void afficher(ostream& flux) const;
	float argument(void) const;
	bool comparaison(const Complexe & z2) const;
	Complexe conjugue(void) const;
	Complexe oppose(void) const;
	Complexe addition(const Complexe & complexe2) const;
	Complexe multiplication(const Complexe & complexe2) const;
	Complexe soustraction(const Complexe & z2) const;
	Complexe division(const Complexe & z2) const;
	
	/*
	Complexe operator+ (const Complexe & z2) const;
	Complexe operator- (float reel) const;
	*/
	
	Complexe(float reel = 0, float imaginaire = 0);
	Complexe(const Complexe &);
	~Complexe(void);
};

/*b)*/

Complexe operator+ (const Complexe & zAdd1, const Complexe & zAdd2);
/* L'utilisation de z1+z2 est équivalent à operator+(z1,z2)*/

Complexe operator*(const Complexe & z1, const Complexe & z2);

Complexe operator-(const Complexe & z1, const Complexe & z2);

Complexe operator/(const Complexe & z1, const Complexe & z2);

Complexe operator==(const Complexe & z1, const Complexe & z2);

ostream& operator<<(ostream& flux, const Complexe& z);
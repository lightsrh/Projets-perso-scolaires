class Heure
{
protected:
	float heures;
	float minutes;
	double secondes;
public:
	void Saisir(void);
	void Afficher(void);
	void Add1seconde(void);
	void Sub1seconde(void);
	void diff2tps(Heure tps2);
	int Conversion_hms(void);
	Heure Conversion_h(int);
	Heure(int h = 0, int m = 0, int s = 0);
};

class temps_1 : public Heure
{
public :
	void heure_1(void);

};

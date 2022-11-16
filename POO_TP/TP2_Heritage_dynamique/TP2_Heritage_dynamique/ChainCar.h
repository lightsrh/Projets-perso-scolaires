class ChainCar
{
private:
	char * p_str;
	unsigned int len;
public:
	ChainCar(const char * init = " ");	//const important ici car on donne l'adresse du char et il ne faut pas le modifier (un float sera copié donc on s'en fiche si cette copie est modifiée)
	//ChainCar(const ChainCar&);
	unsigned int getLen(void)const
	{
		return len;
	}
	char * getstr(void)const
	{
		return p_str;
	}
	void afficher(void)const;
	void minToMaj(void);
	void afficher(ostream& flux) const;
	ChainCar ajouter(const ChainCar&)const;
	ChainCar operator=(const ChainCar&);
	ChainCar operator+(const ChainCar&);
	ChainCar operator+(const char *);
	ChainCar ajouter(const char*)const;
	~ChainCar(void);
};

ostream& operator<<(ostream&, const ChainCar&);


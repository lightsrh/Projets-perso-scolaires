class Compte
{
private :			//attention a bien mettre en protected pour pouvoir y acceder avec l'heritage, sinon utiliser Gets et Sets pour rester en private
	float solde;
public:
	Compte(float s = 0)		//constructeur
	{
		solde = s;
	}
	void Afficher(void);		
	void Debiter(float d);
	void Crediter(float c);
	float Gets(void);
	void Sets(float c);

};

class Compte_remunere : public Compte		//heritage de Compte pour calculer le taux de remuneration
{
private:
	int taux;
public:
	Compte_remunere(float t = 0);		//constructeur de la classe heritée
	void interet(void);					//calcul de l'interet et application au solde
	void Afficher(void);			//afficher la valeur
};
/*class Bank Test unwichtig
{
	test1
public:
	Bank();
	Bank(const int &bz,std::string name);
	~Bank();
	std::string Bankname;
	int blz;
	int konten[100];
	
private:
	
};
: private Bank */
class Konto 
{
public:
	Konto();
	explicit Konto(const int &nr);
	~Konto();
	void einzahlen(const int &summe);
	void print(void);
	void abheben(const int &summe,int test);
	void uberweisen(const int &summe,int test,Konto &zu);
	int getGuthaben(void);
	void setPin(int pn);
	void setNachnameInhaber(std::string name);
	void setVornameInhaber(std::string name);


private:
	int guthaben;
	int kontoNr;
	int pin=0;
	std::string vornameInhaber;
	std::string nachnameInhaber;
};

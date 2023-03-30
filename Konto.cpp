#include <iostream>
#include <iomanip>
#include <string>
#include "Konto.h"

/*Bank::Bank(const int &bz,std::string name){
	blz=bz;
	Bankname=name;
	std::cout<<"Die Bank "<<Bankname<<" mit der BLZ "<<blz<<" wurde erfolgreich erstellt"<<std::endl;
}

Bank::~Bank(){
test2
}*/

Konto::Konto(const int &nr){
	kontoNr=nr;
	std::cout<<"Das Konto mit der Kontonummer "<<std::setw(4)<<std::setfill('0')<<kontoNr<<" wurde erfolgreich erstellt"<<std::endl<<std::endl;
	guthaben=0;
}

Konto::~Konto(){
	
}

void Konto::einzahlen(const int &summe){
	guthaben+=summe;
	std::cout<<"Einzahlen von "<<summe<<" Euro auf Konto "<<std::setw(4)<<std::setfill('0')<<kontoNr<<" erfolgreich"<<std::endl<<std::endl;
}

void Konto::abheben(const int &summe,int test){
	if(pin==test){
		if(summe<=guthaben){
			guthaben=guthaben-summe;
			std::cout<<"Abheben von "<<summe<<" Euro auf Konto "<<std::setw(4)<<std::setfill('0')<<kontoNr<<"  erfolgreich"<<std::endl<<std::endl;
		}
	}
}

void Konto::uberweisen(const int &summe,int test,Konto &zu){
	if(pin==test){
		if(summe<=guthaben){
			guthaben-=summe;
			zu.guthaben+=summe;
			std::cout<<summe<<" Euro wurden erfolgreich von Konto "<<std::setw(4)<<std::setfill('0')<<kontoNr<<" auf Konto "<<std::setw(4)<<std::setfill('0')<<zu.kontoNr<<" uberwiesen"<<std::endl<<std::endl;
		}
	}
}

void Konto::print(){
	std::cout<<"Der Kontoinhaber ist: "<<vornameInhaber<<" "<<nachnameInhaber<<std::endl;
	std::cout<<"Deine Kontonummer: "<<std::setw(4)<<std::setfill('0')<<kontoNr<<std::endl;
	std::cout<<"Dein Guthaben: "<<guthaben<<" Euro"<<std::endl;
	if(pin!=0){
		std::cout<<"Dein Pin: ****"<<std::endl<<std::endl;
	}else{
		std::cout<<std::endl;
	}
}

int Konto::getGuthaben(){
	return guthaben;
}

void Konto::setPin(int pn){
	pin=pn;
	std::cout<<"Der Pin zu Konto "<<std::setw(4)<<std::setfill('0')<<kontoNr<<" wurde erfolgreich geaendert"<<std::endl<<std::endl;
}

void Konto::setNachnameInhaber(std::string name){
	nachnameInhaber=name;
	std::cout<<"Der Nachname zu Konto "<<std::setw(4)<<std::setfill('0')<<kontoNr<<" wurde erfolgreich geaendert in "<<name<<std::endl<<std::endl;
}

void Konto::setVornameInhaber(std::string name){
	vornameInhaber=name;
	std::cout<<"Der Vorname zu Konto "<<std::setw(4)<<std::setfill('0')<<kontoNr<<" wurde erfolgreich geaendert in "<<name<<std::endl<<std::endl;
}

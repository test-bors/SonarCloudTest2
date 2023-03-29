#include <iostream>
#include <string>
#include "Konto.h"

int main(){
	Konto ru(0001);
	ru.setNachnameInhaber("Hinz");
	ru.setVornameInhaber("Ruben");
	ru.setPin(1234);
	ru.einzahlen(50);
	ru.print();
	Konto test=Konto(0002);
	test.setNachnameInhaber("Mustermann");
	test.setVornameInhaber("Max");
	test.print();
	ru.uberweisen(30,1234,test);
	ru.print();
	test.print();
//test4
}

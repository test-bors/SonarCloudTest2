#include <iostream>
#include <iomanip>

int main(int argc, char *argv[]){
	for(int i=0;i<2;i++){
		std::cout<<"Hallo SonarCloud"<<std::endl;
	}

	for(int i=0;i<5;i++){
		std::cout<<"Hallo Sonar"<<std::endl;
	}

	int x=0;
	std::cin>>x;
	if(x<3){
		std::cout<<"Hallo kein Test"<<x<<std::endl;
	}
	else if(x>5){
		std::cout<<"Hallo ein Test"<<x<<std::endl;
	}
	int faktor1=1;
	int faktor2=1;
	std::cout<<"Wähle den ersten Faktor: ";
	std::cin>>faktor1;
	std::cout<<"Wähle den zweiten Faktor: ";
	std::cin>>faktor2;
	int sum=0;
	while(faktor1>0){
		if((faktor1%2)!=0){
			sum+=faktor2;
			std::cout<<std::setw(4)<<std::left<<faktor1<<std::right<<std::setw(6)<<faktor2<<std::endl;
		}else{
			std::cout<<std::setw(6)<<std::left<<faktor1<<std::right<<"-"<<std::setw(7)<<std::setfill('-')<<faktor2<<"-"<<std::setfill(' ')<<std::endl;
		}
		faktor1/=2;
		faktor2*=2;
	}
	std::cout<<"---------------"<<std::endl<<std::setw(10)<<sum<<std::endl;
}
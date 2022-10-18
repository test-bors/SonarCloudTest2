#include <iostream>

int main(int argc, char *argv[]){
	for(int i=0;i<3;i++){
		std::cout<<"Hallo SonarCloud"<<std::endl;
	}
	
	for(int i=0;i<3;i++){
		std::cout<<"Hallo Test"<<std::endl;
	}
	int x=0;
	std::cin>>x;
	if(x<3){
		std::cout<<"Hallo kein Test"<<std::endl;
	}
	else if(x>1){
		std::cout<<"Hallo kein Test"<<std::endl;
	}
	else{
		std::cout<<"Hallo ein Test"<<std::endl;
	}
}

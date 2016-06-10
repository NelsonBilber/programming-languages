#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	for(int i = 0 ; i < 3 ; i++){
		std::cout<< "i = " << i << std::endl;
		for(int j = 0; j < 700; j++){
			std::cout<<"\t"<<"j = " << j << std::endl;
			if(j > 2){
				if(j > 5){
					break;
					std::cout<<"Breaks the loop ! " << std::endl;
				} else {
					std::cout<<"\t\t"<<"j = " << j << std::endl;
				}
			}
		} 
	}
	
	return 0;
}

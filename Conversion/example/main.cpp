#include "IO-Plus.h" //Another header of mine for Input and Output
#include "Conversion.h" //The header for the convert command
int main(){
	int x = 123;
	std::string con = Convert(x, 123); // this will convert x's value 123 from an int to a string this can be preety much useful for you
	print("%v", con); 
	return 0;
}	
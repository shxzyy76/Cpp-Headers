#include "Randomized.h"
#include "IO-Plus.h"
int main(){
	Random rng; // rng is the variable
	int number = rng(1, 100); // 1 is the minimum value to assign while 100 is the maximum
	print("%v", number); // to print the variable number 
	return 0;
}
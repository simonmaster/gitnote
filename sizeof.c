#include <stdio.h>


void printOther( char cArray[], int intArray[] ) {
	/*** Note compile should put out warning msg here
	***/
	printf("sizeof cArray = %ld\n", sizeof(cArray) ) ;
	printf("sizeof intArray = %ld\n", sizeof(intArray) );
	;
}



void printSizeof() {
	int  a;
	int  arrayInt[10];
	char c;
	char arrayChar[10];

	printf("sizeof a = %ld   arrayInt  = %ld\n", sizeof(a), sizeof(arrayInt) );
	printf("sizeof c = %ld   arrayChar = %ld\n", sizeof(c), sizeof(arrayChar) );
	printOther(arrayChar, arrayInt);
}



int main(int ac, char * av[]) {
	printSizeof();
	return 0;
}


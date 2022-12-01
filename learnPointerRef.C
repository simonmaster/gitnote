#include <iostream>

using namespace std;

/* Example to include "C" header
*/
extern "C" {
	void xDumpbuf(FILE*, unsigned char* where, int size);
};


/* Variable here for fun
*/
int		myIntArray[2]; 
int		myIntValue;
long	myLongArray[2]; 
long	myLongValue;
short	myShortArray[2]; 
short	myShortValue;
char	myCharArray[2];
char	myCharValue;

struct playDb {
	long l;
	short s;
	char c;
	friend ostream& operator<<(ostream & os, const struct playDb & v) {
		os << "playDb " << hex << v.l << " " << v.s << " [" << v.c << "]" ;
		return os;
	}
};
struct playDb 	myDbArray[2]; 
struct playDb 	myDbValue; 


short *	myShortPtr;
int *	myIntPtr;
long *	myLongPtr;
char *	myCharPtr;
struct playDb *	myDbPtr; 

//
//	showSize
//
void	showSizes() {
	cout << "Show data size" << "\n";
	cout << "=================================================\n" ;
	cout << "sizeof(int) " << sizeof(myIntValue) << " bytes\n";
	cout << "sizeof(long) " << sizeof(myLongValue) << " bytes\n";
	cout << "sizeof(short) " << sizeof(myShortValue) << " bytes\n";
	cout << "sizeof(char) " << sizeof(myCharValue) << " bytes\n";
	cout << "sizeof(playDb) " << sizeof(myDbValue) << " bytes\n";
	cout << "\n";

	cout << "sizeof(myIntArray) " << sizeof(myIntArray) << " bytes\n";
	cout << "sizeof(myLongArray) " << sizeof(myLongArray) << " bytes\n";
	cout << "sizeof(myShortArray) " << sizeof(myShortArray) << " bytes\n";
	cout << "sizeof(myCharArray) " << sizeof(myShortArray) << " bytes\n";
	cout << "sizeof(myDbArray) " << sizeof(myDbArray) << " bytes\n";
	cout << "\n";

	cout << "sizeof(int*) " << sizeof(myIntPtr) << " bytes\n";
	cout << "sizeof(long*) " << sizeof(myLongPtr) << " bytes\n";
	cout << "sizeof(short*) " << sizeof(myShortPtr) << " bytes\n";
	cout << "sizeof(char*) " << sizeof(myCharPtr) << " bytes\n";
	cout << "sizeof(playDb*) " << sizeof(myDbPtr) << " bytes\n";
	cout << "\n";
}

void incAnyBuffer(void * p, unsigned char v, int size) {
	unsigned char *from;
	from = (unsigned char*) p;
	while (--size) {
		*from++ = v++;
	}
}


//
// copyData2Buffer
// copy data from src to dst
//
void copyData2Buffer( void * src, void * dst, int size) {
	unsigned char *from, *to;
	from = (unsigned char*) src;
	to = (unsigned char*) dst;
	while (--size >= 0) {
		*to++ = *from++;
	}
	
}

void dumpDbValue() {
	struct playDb xxx[3];

	xxx[0].l = 0x1111;
	xxx[0].s = 0x99;
	xxx[0].c = 'A';
	xxx[1].l = 0x2222;
	xxx[1].s = 0x88;
	xxx[1].c = 'B';
	xxx[2].l = 0x3333;
	xxx[2].s = 0x77;
	xxx[2].c = 'C';

	cout << "playDb " << xxx << "\n";
	cout << "playDb " << xxx[0] << "\n";
	xDumpbuf(stdout, (unsigned char*) &xxx[0], sizeof(struct playDb));
	cout << "playDb " << xxx[1] << "\n";
	xDumpbuf(stdout, (unsigned char*) &xxx[1], sizeof(struct playDb));
	cout << "playDb " << xxx[2] << "\n";
	xDumpbuf(stdout, (unsigned char*) &xxx[2], sizeof(struct playDb));
	cout  << "\n\n";

	struct playDb *p;
	p = xxx;
	for (int i=0; i++ < 3; ) {
		cout << "p " << *p << "\n";
		p++;
	}
	cout << "==========================================" << endl;
}

void dumpAddress() {
	cout << "Show Address" << "\n";
	cout << "==========================================" << endl;
	cout << "myIntPtr   " << myIntPtr    <<"\n";
	cout << "myLongPtr  " << myLongPtr   <<"\n";
	cout << "myShortPtr " << myShortPtr  <<"\n";
	cout << "myCharPtr  " << (void*)myCharPtr <<"\n";
	cout << "myDbPtr    " << myDbPtr     <<"\n";
	cout << "==========================================" << endl;

}

void setupAddress() {
	myIntPtr = myIntArray;
	myLongPtr = &myLongArray[0];
	myShortPtr = &myShortArray[0];
	myCharPtr = myCharArray;
	myDbPtr = myDbArray;
}

void testingPtr() {
	// reset all the pointers
	setupAddress();

	*myIntPtr = 0x5555;
	*(myIntPtr+1) = 0x6666;

	cout <<"\nShowing Int Buffer here\n";
	cout << "First  Int " << hex << myIntArray[0] << endl;
	xDumpbuf(stdout, (unsigned char*)myIntArray, sizeof(long));
	cout << "Second Int " << hex << myIntArray[1] << endl;
	xDumpbuf(stdout, (unsigned char*)&myIntArray[1], sizeof(long));
	cout <<"\n";

	*myLongPtr = 0x0123456789ABCDEF;
	myLongPtr[1] = 0xBBBBBBBBBBBBBBBB;

	cout <<"\nShowing Long Buffer here\n";
	cout << "First  Long " << hex << myLongArray[0] << endl;
	xDumpbuf(stdout, (unsigned char*)myLongArray, sizeof(long));
	cout << "Second Long " << hex << myLongArray[1] << endl;
	xDumpbuf(stdout, (unsigned char*)&myLongArray[1], sizeof(long));
	cout <<"\n";

	cout << "===================================\n";
	cout << "show 64 bytes from the buffer value from myIntPtr" << endl;
	xDumpbuf(stdout, (unsigned char*)myIntPtr, 0x40);

	cout << "===================================\n";
	// copy the values from long buffer to int buffer
	cout << "Resigning myIntBuf with myLongArray size\n";
	copyData2Buffer( (void*)myLongArray, (void*)myIntArray, sizeof(myLongArray) );

	cout << "show 64 bytes from the buffer value from myIntPtr" << endl;
	xDumpbuf(stdout, (unsigned char*)myIntPtr, 0x40);


}

int main(int ac, char *av[]) {
	showSizes();
	dumpDbValue();

	// setup all address
	setupAddress();
	dumpAddress();

	//
	testingPtr();
	return 0;
}






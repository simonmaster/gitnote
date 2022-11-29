//
//
//
#include <iostream>
#include <iomanip>

using namespace std;
//
//	
//
class Foo {
private:
	void _initHelper() {
		myCounter = objCounter++;		// save object counter and 
										// inc the global object counter my Foo
		myValue = myCounter * 100;
		s = new string;
		*s = getStatus();
		cout << "_initHelper " << *s << '\n';
	}
public:
	string getStatus() {
		ostringstream os ;
		os << "Foo" << " myCounter = " << myCounter 
					<< " myValue = " << myValue ;
		return os.str();
	}

	// constructor
	Foo() {
		_initHelper();
	}
	~Foo() {
		cout << "\nDestructor " << *s <<'\n';
		delete s;
	}

private:
	friend ostream& operator<< ( ostream& os, const Foo& v ) {
		os << *(v.s) << "\n";
		return os;
	}

	string * s;
	int myValue;
	int	myCounter;

	static int objCounter;
};


//
//	Location for private storage of the objCounter
//
int Foo::objCounter = 0;


//
// temp func to do a little printing
// 
void printObj(string name, Foo f) {
	cout << "printObj " << name << "[" << f.getStatus() << "]\n";
}


// testing
int main(int ac, char * av[]) {

	cout << "instantiate A\n";
	Foo A;
	cout << "A " << A << "\n";

	cout << "instantiate B\n";
	Foo B;
	cout << "B " << B << "\n";

#if 0
	printObj("B", B);

	cout << "instantiate C\n";
	Foo C;
	cout << "C " << C << "\n";

	cout << "I will not in trouble here B=C" << "\n";
	B = C;

#endif

	cout << "\n===================================\n";
	cout << "Ready for crash\n";
	return 0;
}




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
	void _initHelper( string tag ) {
		myCounter = objCounter++;		// save object counter and 
										// inc the global object counter my Foo
		myValue = myCounter * 100;
		s = new string;
		*s = getStatus();
		cout << "_initHelper " << tag << *s << '\n';
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
		_initHelper( "Constructor" );
	}
	~Foo() {
		cout << "\nDestructor " << *s <<'\n';
		delete s;
	}

	// copy constuctor
	Foo(const Foo& f) {
		_initHelper("Copy constructor");
		myValue = f.myValue;
		// myCounter = f.myCounter; // dont copy the counter
		*s = getStatus();
	}

	// assignment operator
	Foo& operator= (const Foo& f) {
		_initHelper("assignment operator");
		myValue = f.myValue;
		// myCounter = f.myCounter; // dont copy the counter
		*s = getStatus();
		return *this;
	}

	// move constructor
	Foo(Foo&& f) {
		_initHelper("move constructor");
		myValue = f.myValue;
		// myCounter = f.myCounter; // dont copy the counter
		*s = getStatus();
	}

	// move assignment operator
	Foo& operator= (Foo&& f) {
		_initHelper("move assignment operator");
		myValue = f.myValue;
		// myCounter = f.myCounter; // dont copy the counter
		*s = getStatus();
		return *this;
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
int Foo::objCounter = 1;


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

	Foo C = std::move(B);


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




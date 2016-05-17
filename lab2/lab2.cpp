#include <iostream>

using namespace std;

/*
Angel Mejia
Algorithms Lab 2
September 9, 2015
*/

class monkey {
public:
	bool hungry;

	monkey() {cout << "Hello i'm the default constructor from class monkey!" << endl;}
	monkey(bool a){cout << "Hello i'm the constructor from class monkey! That was called on input bool" << endl;}
	~monkey(){cout << "Destructor from monkey called" << endl;}

	void eatBanana(){cout << "Hello i'm function eatBanana from class monkey!" << endl;}
	void dive(){cout << "Hello i'm function dive from class monkey!" << endl;}

	virtual void monkeyAround(){cout << "Hello i'm function monkeyAround from class monkey!" << endl;}

};

class ape:public monkey {
public:
	ape() {cout << "Hello i'm the default constructor from class ape!" << endl;}
	ape(bool b){cout << "Hello i'm the constructor from class ape! That was called on input bool" << endl;}
	~ape(){cout << "Destructor from ape called" << endl;}
	void eatBanana(){cout << "Hello i'm function eatBanana from class ape!" << endl;}
	virtual void monkeyAround(){cout << "Hello i'm function monkeyAround from class ape!" << endl;}
	virtual void useTool(){cout << "Hello i'm function useTool from class ape!" << endl;}

};

class whale {
public:
	char *melody;
	whale(){cout << "Hello i'm the default constructor from class whale!" << endl;}
	whale(char *c){cout << "Hello i'm the constructor from class whale! That was called on input char*" << endl;}
	~whale(){cout << "The Destructor from whale called" << endl; }
	void sing(){cout << "Hello i'm function sing from class whale!" << endl;}
	virtual void dive(){cout << "Hello i'm function dive from class whale!" << endl;}

};

class human:public ape, public whale {
public:
	human(){cout << "Hello i'm the default constructor from class human!" << endl;}
	human(bool d):ape(d){cout << "Hello i'm the constructor from class whale! That was called on inputs bool and ape" << endl;}
	human(bool i, char *f):ape(i), whale(f){cout << "Hello i'm the constructor from class human! That was called on input bool and char* on ape and whale" << endl;}
	~human(){cout << "Destructor from human called" << endl;}
	void eatBanana(){cout << "Hello i'm function eatBanana from class human!" << endl;}
	void monkeyAround(){cout << "Hello i'm function monkeyAround from class human!" << endl;}
	void useTool(){cout << "Hello i'm function useTool from class human!" << endl;}
	void dive(){cout << "Hello i'm function dive from class human!" << endl;}
};

template <class mytype> 
mytype roundNum (mytype a, mytype b, mytype c) {
	int num;
	
	num = int(a + 0.5);
	if (num % 2 == 0)
		return b;
	else
		return c;
}

template <class mytype> 
class cell {
public:
	mytype value;

	cell *next;

	cell(){};
	cell(mytype b){value = b;}
};

int main () {
	monkey *m;
	ape *a;
	human *h;

	m = new ape(true);

	m->eatBanana();

	a = new human;

	delete m;
	m = a;

	m->monkeyAround();

	a->monkeyAround();

	m->eatBanana();

	a->eatBanana();

	a->useTool();

	h = (human*)a;

	delete h;
	h = new human(true, NULL);

	h->sing();

	delete h;
	h = new human(true);

	whale *w;
	w = new human;
	w->sing();


	//delete a;
	a = (human*)h;
	a->dive();

	int x;
	int y;
	int z;
	int templateReturn;

	cout << "Enter a Value for x: " << endl;
	cin >> x;
	cout << "Enter a Value for y: " << endl;
	cin >> y;
	cout << "Enter a Value for z: " << endl;
	cin >> z;

	templateReturn = roundNum(x,y,z);

	cout << "The result from the template class is: " << templateReturn << endl;

	// Used as stall so cmd does not immediately close on windows computer after running .exe
	//cout << "Press ENTER key to end program..." << endl; 
	//cin.get();
	//cin.get();
	return 0;
}
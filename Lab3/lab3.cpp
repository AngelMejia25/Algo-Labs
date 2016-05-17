#include <iostream>

using namespace std;

class intcell {
public:
	int value;

	intcell *next;
	intcell(int i){value = i, next = NULL;}

	intcell(int a, intcell *b){ value = a, next = b;}

	intcell operator+(intcell c){intcell n(value + c.value); return n;}
};

class myIntQueueADT {
public:
	virtual int firstValue () = 0;
	virtual void enqueue (int a) = 0;
	virtual int dequeue () = 0;
	virtual int maxValue () = 0;
	virtual void print () = 0;

};

class llIntQueue:public myIntQueueADT {
public:
	intcell *first;
	intcell *last;

	llIntQueue(){first = NULL, last = NULL;}
	
	int firstValue(){return first->value;}

	void enqueue(int data){
		intcell *temp = new intcell(data);
	
		cout << "Enter data to enqueue: ";
		cin >> data;
	
		temp->value = data;
		temp->next = NULL;

		if(first == NULL){
			first = temp;
		}else{
			last->next = temp;
		}

		last = temp;

	}

	int dequeue(){
		intcell *temp;

		if (first == NULL){

			cout << "The Queue is empty: " << endl;
		}else{

			temp = first;
			first = first->next;

			cout << "The value Dequeued is " << temp->value;

			delete temp;

		}
	}

	int maxValue(){
		int Max;
		intcell *currentCell = first;

		Max = currentCell->value;

		while (currentCell != NULL){

			if (currentCell->value > Max){
				Max = currentCell->value;
			}
			currentCell = currentCell->next;
		}
		return Max;
	}

	void print(){
		intcell *currentCell = first;
		while (currentCell != NULL){
			cout << currentCell << " ,";
			currentCell = currentCell->next;
		}
		cout << "\ndone." << endl;
	}

	llIntQueue operator+(llIntQueue x){
		intcell* cur1=first;
		intcell* cur2=x.first;
		llIntQueue *newq= new llIntQueue;
		while(cur1 != NULL && cur2!=NULL){
			newq.enqueue(cur1->value+cur2->value);
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		//Finish copying non empty queue


		return *newq;
	};
};


int main () {
	intcell a(5), b(4), c(0);

	c = a + b;
	cout << c.value << endl;
	
	llIntQueue var1;
	llIntQueue var2;
	llIntQueue var3;

	myIntQueueADT* point;
	
	int integers;	
	cout << "Enter 10 integers to be queued: " << endl;

	for (int n=1;n<=10;n++){
		cout << "Enter an integer: " << endl;
		cin >> integers;
		var1.enqueue(integers);
	}

	cout << "integers have successfully been queued." << endl;

	int maxV = var1.maxValue();


	cout << "The maxValue is: " << maxV << endl;

	cout << "Enter the values of the second queue: " << endl;

	int integers;	
	cout << "Enter 10 integers to be queued: " << endl;

	for (int n=1;n<=10;n++){
		var2.enqueue(integers);
	}

	cout << "Enter the values of the third queue: " << endl;

	int integers;	
	cout << "Enter 10 integers to be queued: " << endl;

	for (int n=1;n<=10;n++){
		var1.enqueue(integers);
	}

	var3 = var1 + var2;

	point = &var3;

	cout << "the max is " << point -> maxValue();
	point -> print();

	return 0;
}
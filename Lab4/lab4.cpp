#include <iostream>
#include <time.h>
#include <stdlib.h> 
#include <fstream>

using namespace std;

/* The program was finished when I saw you on friday, but i forgot to submit that day.
*
*
*
* For a 100000 size array it takes 82328 clock ticks
* For a 200000 size array it takes 334656 Clock ticks
* For a 300000 size array it takes 750000 clock ticks
* For the First doubling of the array the program time nearly quadrupled in size, and
* after that the program took almost ten times as long when the size of the array was tripled.
*/
void generateFile(){
	//srand(time(NULL));
	
	ofstream myfile;
	myfile.open("InputNumbers.dat");


	for (int i = 0; i<10;i++){
		myfile << rand() << " " << rand() << " " << rand() << endl;
	}
	cout << "File has been written too." << endl;
	myfile.close();
}

class integerTriples{
public:
	int value1;
	int value2;
	int value3;

	integerTriples(){};

	integerTriples(int a,int b,int c){value1 = a, value2 = b, value3 = c;}

	bool operator==(integerTriples trip2){
		//{return (value1 == trip2.value1 && value2 == trip2.value2 && value3 == trip2.value3);} Also works

		if (value1 == trip2.value1 && value2 == trip2.value2 && value3 == trip2.value3)
			return true;
		else
			return false;
		
	}

	bool operator<(integerTriples trip2){
		//{(value1 < trip2.value1) || (value1 == trip2.value1 && value2 < trip2.value2) || (value1 == trip2.value1 && value2 == trip2.value2 && value3 < trip2.value3 )}

		if ((value1 < trip2.value1) || 
			(value1 == trip2.value1 && value2 < trip2.value2) ||
			(value1 == trip2.value1 && value2 == trip2.value2 && value3 < trip2.value3 )
			)
			return true;
		else
			return false;
	}

	bool operator>(integerTriples trip2){

		if ((value1 > trip2.value1) || 
			(value1 == trip2.value1 && value2 > trip2.value2 )||
			(value1 == trip2.value1 && value2 == trip2.value2 && value3 > trip2.value3) 
			)
			return true;
		else
			return false;
	}

	bool operator<=(integerTriples trip2){

		if ((value1 < trip2.value1) || 
			(value1 == trip2.value1 && value2 < trip2.value2) ||
			(value1 == trip2.value1 && value2 == trip2.value2 && value3 < trip2.value3) ||
			(value1 == trip2.value1 && value2 == trip2.value2 && value3 == trip2.value3)
			)
			return true;
		else
			return false;
	}


	bool operator>=(integerTriples trip2){

		if ((value1 > trip2.value1)  || 
			(value1 == trip2.value1 && value2 > trip2.value2) ||
			(value1 == trip2.value1 && value2 == trip2.value2 && value3 > trip2.value3) ||
			(value1 == trip2.value1 && value2 == trip2.value2 && value3 == trip2.value3))
			return true;
		else
			return false;
	}


};

integerTriples* readFile (int nbLines) {
	ifstream myfile("InputNumbers.dat");
	
	integerTriples *array = new integerTriples[nbLines];


	for (int i = 0; i < nbLines;i++){
		int x, y, z;
		myfile >> x >> y >> z;
		array[i].value1 = x;
		array[i].value2 = y;
		array[i].value3 = z;

	}
	return array;
}

integerTriples findMax(integerTriples *a, int n, int &maxIndex){
	maxIndex = 0;
	integerTriples maxSoFar = a[0];

	for(int i=1; i < n; i++){
		if (a[i] > maxSoFar)
			maxSoFar = a[i];
			maxIndex = i;
	}
	return maxSoFar;
 
}

void print (integerTriples *a, int n){

	for(int i= 0; i< n;i++){
		cout << a[i].value1 << " " << a[i].value2 << " " << a[i].value3 << endl;
	} 


}

int oursort(integerTriples *a, int n){
	int maxIndex=0;
	integerTriples temp(0, 0, 0);

	for(int i=0;i<n;i++){
		integerTriples maxElem = findMax(a, n-i, maxIndex);
		temp=a[maxIndex];
		
		a[maxIndex] = a[n-i-1];
		a[n-i-1] = temp;
	}
}

int ourSortTiming(int size){
	integerTriples *a = readFile(size);


	clock_t start, end;
	start = clock();

	oursort(a, size);

	end = clock();

	cout << "The computation timing took: " << (end - start) << " Clock ticks" << endl;
}



int main(){

	//generateFile();

	integerTriples *test = readFile(10);

	//integerTriples a = test;

	print(test, 10);


	oursort(test, 100);


	//ourSortTiming(100000);
	//ourSortTiming(200000);
	//ourSortTiming(300000);


	return 0;
}
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class inventoryItem
{
private: 
	int isbn;
	float price;
	string title;
public:
	
	friend class inventoryItem;
	inventoryItem(int a, float b, string c){isbn = a, price = b, title = c;}
	
	string tostring(){
		string s;
		ostringstream convert;
		convert << "Title: " << title << " ISBN: " << isbn << " Price:  $" << price << endl; 
		s = convert.str();
		return s;
	}
	
	bool operator==(inventoryItem x){

		if (isbn == x.isbn)
			return true;
		else
			return false;

	}	

	bool operator==(int y){

		if (isbn == y)
			return true;
		else
			return false;
	}


};

inventoryItem** readFile(string fileName, int &nblines){
	ifstream myfile;
	myfile.open(fileName.c_str());
	myfile >> nblines;
	inventoryItem **A = new inventoryItem *[nblines];

	for (int i = 0; i < nblines;i++){
		int numb;
		float deci;
		string gibberish;
		string stored;

		myfile >> gibberish >> gibberish >> numb >> gibberish >> deci >> gibberish >> gibberish >> gibberish >> stored >> gibberish;
		A[i] = new inventoryItem(numb, deci, stored);
	}

	return A;
};

void printFile(inventoryItem** Array, int &nblines, string FileName){
	ofstream myfile;
	myfile.open(FileName.c_str());
	myfile << nblines << endl;

	for (int i = 0; i < nblines;i++){
		myfile << Array[i]->tostring();

	}
}

inventoryItem* searchArray(inventoryItem **A, int &nblines, int isb){
	int i = 0;
	while(i < nblines){

		if(A[i]->operator==(isb)){
			return A[i];
		}
		else{
			i++;
		}
	}
	return NULL;
}

int main () {

	inventoryItem **database; //either a 2 dimentional array of inventoryItems, or an array of pointers to inventoryItems 
	int nblines;

	database = readFile("barn.moo", nblines);
	//cout << "readfile done" << endl;
	
	// now nblines contains the size of the array database

	printFile(database, nblines, "out.txt");
	//cout << "printFile done" << endl;

	inventoryItem* isbnFind= searchArray(database, nblines, 118659060);
	//cout << "searcharray done" << endl;

	if(isbnFind == NULL){
		cout << isbnFind;
	}
	else{
		cout << isbnFind->tostring();
	}
	//cin.get();
	return 0;
}
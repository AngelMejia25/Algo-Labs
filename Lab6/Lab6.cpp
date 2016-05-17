#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int stringMatchingBF (string n, string m) {
	for(int i =0; i < n.length()-m.length();i++){
		int j=0;
		
		while (j < m.length() && n[i+j] == m[j]){
			j++;
		}

		if (j==m.length()){
			return i;
			cout << "String match at position: " << endl;
		} 
	}
	return -1;
}

class point2D {
public:
	int xCoord;
	int yCoord;


	point2D(int a, int b){xCoord = a; yCoord = b;}

	string tostring() {
		string point;
		ostringstream convert;
		convert << "(" << xCoord << ", " << yCoord << ")";
		point = convert.str();
		return point;
	}

};

void closestPairBF(point2D **A, int ASize, int &Index1, int &Index2){
	int minDistance = ((A[0]->yCoord - A[1]->yCoord)*(A[0]->yCoord - A[1]->yCoord)) + 
						((A[0]->xCoord - A[1]->xCoord)*(A[0]->xCoord - A[1]->xCoord));
	Index1 = 0;
	Index2 = 1;

	for(int i = 0; i < ASize-2;i++)
	{
		for(int j=i+1; j < ASize-1; j++)
		{	
			if (minDistance > ((A[i]->yCoord - A[j]->yCoord)*(A[i]->yCoord - A[j]->yCoord)) + 
				((A[i]->xCoord - A[j]->xCoord)*(A[i]->xCoord - A[i]->xCoord)))
				{
					minDistance = ((A[0]->xCoord - A[1]->xCoord)*(A[0]->xCoord - A[1]->xCoord));
					Index1 = i;
					Index2 = j;
				}
		}
	}
}

int main(){
	string fileName;

	cout << "Enter the name of your input file: " << endl;
	cin >> fileName;

	ifstream theFile;
	theFile.open(fileName.c_str());

	string fileType;
	cout << "Is your File a text file, or a file of numbers? ";
	cin >> fileType;

	while (fileType != "text" || "t" || "numbers" || "n"){


		if (fileType == "text" || fileType == "t") {
			int nblines;
			theFile >> nblines;
			int i = 0;
			string fileLines;
	

			  
			while (i < nblines){
				theFile >> fileLines;
				getline(theFile, fileLines);
				

			}

			string wordSearch;

			cout << "What word would you like to look for: ";
			cin >> wordSearch;

			if (wordSearch == "") {
				cout << "end" << endl;
			}
			
			stringMatchingBF(wordSearch, fileLines);

			cin.get();

		}
		else if (fileType == "numbers" || fileType == "n"){
			int nblines;
			theFile >> nblines;
			int i = 0;
			point2D** Array = new point2D* [nblines];
			int x;
			int y;

			while (i < nblines){
				

				theFile >> x >> y;
				Array[i] = new point2D(x, y);
			}

			closestPairBF(Array, nblines, x, y);

			cout << Array[x]->tostring() << endl;
			cout << Array[y]->tostring() << endl;

			cin.get();

		}	
		else{
			cout << "Please enter a 'text' or 'numbers'" << endl;
		}
	}



}



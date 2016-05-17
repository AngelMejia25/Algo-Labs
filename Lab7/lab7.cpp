#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class mygraph {
private:
	int count1, count2;
	int *mark, *markprime;
public:
	int nbvertices;
	int** adjmatrix;

	void DFS();
	void dfs(int v);

	mygraph(){nbvertices = 0, adjmatrix = NULL;}

	mygraph(int a){nbvertices = a;
		adjmatrix = new int*[nbvertices];
		for(int i = 0; i < nbvertices; i++){
			adjmatrix[i] = new int[nbvertices];
		}
	}

	~mygraph(){
		for(int i = 0; i < nbvertices; i++){
			delete[] adjmatrix[i];
		}
		delete[] adjmatrix;
	}


	mygraph(string fileName){
		ifstream myFile;
		myFile.open(fileName.c_str());
		myFile >> nbvertices;

		adjmatrix = new int*[nbvertices];

		for (int i = 0; i < nbvertices; i++){
			adjmatrix[i] = new int[nbvertices];

			for (int j = 0; j < nbvertices; j++){
				myFile >> adjmatrix[i][j];
			}
		}

	}
};

void mygraph::DFS (){
	mark = new int[nbvertices];
	markprime = new int[nbvertices];
	
	count1 = 0;
	count2 = 0;

	for (int v = 0; v < nbvertices; v++){
		if (mark[v] == 0) {
			dfs(v);
		}

	}
	
	for ( int i = 1; i <= nbvertices; i++){
		for(int j = 0; j < nbvertices;j++){
			if(mark[j] == i){
				cout << j << " ";
			}
		}
	}

	cout << endl;

	for (int i = 1; i <= nbvertices; i++){
		for (int j = 0; j < nbvertices; j++){
			if (markprime[j] == i){
				cout << j << " ";
			}

		}
	}


}

void mygraph::dfs(int v){
	count1++;
	mark[v] = count1;
	for (int w = 0; w < nbvertices; w++){
		if(adjmatrix[v][w] == 1){
			if (mark[w] == 0){
				dfs(w);
			}
		}
	}
	count2++;
	markprime[v] = count2;
}


int main(){
	string file;

	cout << "Please enter your filename: ";
	cin >> file;
	cout << "\n";

	mygraph *h;
	h = new mygraph(file);

	h->DFS();

	cin.get();
	cin.get();
	return 0;
}
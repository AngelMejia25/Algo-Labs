#include <iostream>
#include <math.h>
#include <sstream>
#include <fstream>

using namespace std;

const int INTMAX = 30000;

/*
void BinSearch(int A[], int l, int r, int k){
	if (l < r) {
		int mid = floor((l+r)/2);
		if (A[mid] == k){
			return mid;
		}
		else if (A[mid] > k){
			return BinSearch(A, l, mid-1, k);
		}
		else {
			return BinSearch(A, mid+1, r, k);
		}
	}
	else {
		return -1;
	}
}*/

int DCsearch(int A[], int l, int r, int k){
	if (l <= r) {
		int mid = floor((l+r)/2);
		if (A[mid] == k){
			return mid;
		}
		else {	
			int left, right;

			left = DCsearch(A, l, mid-1, k);
			right = DCsearch(A, mid+1, r, k);

			if (left != -1){
				return left;
			}
			else if (right != -1){
				return right;
			}
		}
	}
	else {
		return -1;
	}
}

int DCsum(int A[], int l, int r){
	if (l == r) {
		return A[l];
	}
	else {
		int mid = (l + r)/2;
		int lsum = DCsum(A, l, mid);
		int rsum = DCsum(A, mid+1, r);
		return lsum + rsum;
	}


}
int main(){
	ifstream myfile;
	string fileName;

	cout << "Please enter a name of the file: ";
	cin >> fileName;
	cout << endl;

	myfile.open(fileName.c_str());

	//int A[] = {0,1,2,3,4,5,6,7};
	//int l = 0;
	//int r = 7;
	//cout << l << endl << r << endl; 

	int A[INTMAX];
	string line;

	for (int i =0; i < INTMAX; i++){
		myfile >> A[i];
	}

	int l = 0;
	int r = INTMAX -1;
	int A2[INTMAX];

	for(int i = 0; i < INTMAX; i++){

		A2[i] = A[i];
	}

	//cout << DCsearch(A, l, r, 32) << endl;

	cout << DCsum(A2, l, r);

	cin.get();
	cin.get();

	return 0;
}
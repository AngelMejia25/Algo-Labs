/* infile1.dat
The time taken for Mergesort 30 times is: 249  Clock ticks 
The time taken for LomutoQS 30 times is: 140 Clock ticks 
The time taken for HoareQS 30 times is: 125 Clock ticks 

infile2.dat
The time taken for Mergesort 30 times is: 249 Clock ticks 
The time taken for LomutoQS 30 times is: 142 Clock ticks 
The time taken for HoareQS 30 times is: 124 Clock ticks 

infile3.dat
The time taken for Mergesort 30 times is: 250 Clock ticks 
The time taken for LomutoQS 30 times is: 141 Clock ticks 
The time taken for HoareQS 30 times is: 121 Clock ticks 

infile4.dat
The time taken for Mergesort 30 times is: 215 Clock ticks 
The time taken for LomutoQS 30 times is: 29531 Clock ticks 
The time taken for HoareQS 30 times is: 30397 Clock ticks 

infile5.dat
The time taken for Mergesort 30 times is: 198 Clock ticks 
The time taken for LomutoQS 30 times is: 29787 Clock ticks 
The time taken for HoareQS 30 times is: 62 Clock ticks 

The algorithms tend to do well and work well on most of the files until they reach the 4th and 5th
files respectively. Merge sort tends to stay consistent with all the files but runs a little 
faster on the 4th and 5th files while the other sorts do not. The lomuto quick sort had a bad
time with the 4th and 5th files taking considerbly longer than on the first three files. Hoare's
quick sort only staggered on the 4th file but finished the 5th file incredibly fast. I expected
Merge sort to always be the slowest of the sorting algorithms and was suprised to find that
in certain conditions it's the best one you can use. I assume the reason for this is because
how each algorithm goes about sorting the individual arrays. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

const int INTMAX = 30000;

void Merge(int A[], int B[], int C[], int n1, int n2){
// assume B and C are sorted
//B has size n1, A has size n1 + n2, C has size n2
	int i = 0, j = 0, k = 0;

	while (i < n1 && j < n2){
		if (B[i] < C[j]){
			A[k] = B[i];
			i++;
		}
		else{
			A[k] = C[j];
			j++;
		}
		k++;
	}
	if (i = n1){
		while (j < n2){
			A[k] = C[j];
			k++;
			j++;
		}
	}
	else{
		while (i < n1){
			A[k] = B[i];
			k++;
			i++;
		}
	}
}

void Mergesort(int A[], int n ){
	if ( n > 1){
		int half = n/2;;

		int B[half];
		int C[n-half];

		for (int i =0; i < half; i++){
			B[i] = A[i];
		}
		for (int i = 0; i < n-half; i++){
			C[i] = A[half + i];
		}
		Mergesort(B, half);
		Mergesort(C, n-half);
		Merge(A, B, C, half, n-half);
		delete B;
		delete C;
	}

}

int LumotoPartition(int A[], int l, int r){
	int P = A[l];
	int s = l;

	for (int i = l + 1; i < r + 1; i++){
		if (A[i] < P){
			s++;
			swap(A[s], A[i]);
		}
	}
	swap(A[l], A[s]);
	return s;
}

void LomutoQuickSort(int A[], int l, int r){
	if (l < r){
		int s = LumotoPartition(A, l, r);
		LomutoQuickSort(A, l, s-1);
		LomutoQuickSort(A, s+1, r);
	}
}

int HoarePartition(int A[], int l, int r){
	if (A[l] > A[r]){
		swap(A[l],A[r]);
	}
	int P = A[l];
	int i = l;
	int j = r + 1;
	do {
		do {i++;} while(A[i] < P);
		do {j--;} while(A[j] > P);
		swap(A[i],A[j]); 
	} 
	while (i < j);

	swap(A[i], A[j]);
	swap(A[l], A[j]);
	return j;
}

void HoareQuickSort(int A[], int l, int r){
	if (l < r){
		int s = HoarePartition(A, l, r);
		HoareQuickSort(A, l, s-1);
		HoareQuickSort(A, s+1, r);
	}
}

int main () {
	ifstream myfile;
	string fileName;

	cout << "Please enter a name of the file: ";
	cin >> fileName;
	cout << endl;

	myfile.open(fileName.c_str());

	int array[INTMAX];
	string line;

	for (int i =0; i < INTMAX; i++){
		myfile >> array[i];
	}


	int array2[INTMAX];
	int count = 0;

	clock_t start, end;
	clock_t start2, end2;
	clock_t start3, end3;


	start = clock();

	while ( count < 30){
	
		for(int i = 0; i < INTMAX; i++){

			array2[i] = array[i];
		}
		Mergesort(array2, INTMAX);
		count++;
	}
	end = clock();

	cout << "The time taken for Mergesort 30 times is: " << (end - start) << " Clock ticks." << endl;
	start2 = clock();

	count = 0;
	while ( count < 30){
	
		for(int i = 0; i < INTMAX; i++){

			array2[i] = array[i];
		}
		LomutoQuickSort(array2, 0, INTMAX - 1);
		count++;
	}
	end2 = clock();

	cout << "The time taken for LomutoQuickSort 30 times is: " << (end2 - start2) << " Clock ticks." << endl;
	
	start3 = clock();
	count = 0;
	while ( count < 30){
	
		for(int i = 0; i < INTMAX; i++){

			array2[i] = array[i];
		}
		HoareQuickSort(array2, 0, INTMAX - 1);
		count++;
	}

	end3 = clock();

	cout << "The time taken for HoareQuickSort 30 times is: " << (end3 - start3) << " Clock ticks." << endl;


	cin.get();
	cin.get();

	myfile.close();

	return 0;
}
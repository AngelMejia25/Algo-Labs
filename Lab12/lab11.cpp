/* Angel Mejia
6) 
a) first collision: 175
b) Fifth Collision: 23481
c) total number of collisions: 33162
d) total number of empty spaces: 33162
e) Max number of collisions: 8
f) Random Keys you need: 1074691
g) Max collisions after full table: 30
*/


#include <iostream>
#include <random>

using namespace std;

default_random_engine generator;

uniform_int_distribution<int> distribution(0,180000);

int generateRandomKey()
{
	return distribution(generator);
}

int hashfunction(long key){
	return ((11057 * key) % 179999) % 90000;
}

int main(){
	long table[90000];

	bool first = false;
	bool fifth = false;
	int key;
	int hashedKey;
	int spaceCount = 0;
	int collisionCount = 0;
	int collisionMax = 0;
	int cellsfilled = 0; //used for max needed keys to fill table
	long i =0;

	for (i = 0; i < 90000; i++){
		table[i] = 0;
	}

	for (i = 0; cellsfilled < 90000; i++){ 	
		key = generateRandomKey();
		hashedKey = hashfunction(key);
		if (table[hashedKey] == 0){
		cellsfilled++;
		}
		table[hashedKey]++;

		if (table[hashedKey] == 2 && first == false) {
			cout << "Collision at: " << i << endl;
			first = true;
		}

		if (table[hashedKey] == 5 && fifth == false){
			cout << "Collision at: " << i << endl;
			fifth = true;
		}

		if (table[hashedKey] > 1){
			collisionCount++;
		}

	}

	cout << "Number of times loop had to go around: " << i << endl;

	for (i = 0; i < 90000; i++){
		
		if (table[i] == 0){
			spaceCount++;
		}

		if (table[i] > collisionMax){
			collisionMax = table[i];
		}

	}

	
	cout << "total number of collisions: " << collisionCount << endl;
	cout << "Total number of empty spaces: " << spaceCount << endl;
	cout << "Max number of collisions: " << collisionMax << endl;

	cin.get();
}

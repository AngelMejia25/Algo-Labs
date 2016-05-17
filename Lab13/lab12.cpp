#include <iostream>

using namespace std;

class changeStruct{
public:
	int tot;
	int *each;
	changeStruct(int n){
		tot = 0;
		each = new int[n];
		for (int i=0; i <= n; i++){
			each[i] = 0;
		}
	}
};

int *fullDPChangeMaking(int coins[], int n, int amount){
	changeStruct **F = new changeStruct* [amount + 1];
	F[0] = new changeStruct(n);
	for(int i = 1; i < amount + 1; i++){
		changeStruct *minsofar = new changeStruct(n);
		minsofar-> tot = i + 1;
		int j=0;
		while(j < n && (coins[j] <= i)){
			if (F[i - coins[j]]->tot + 1 < minsofar->tot){
				for(int k=0; k < n; k++){
					minsofar->each[k] = F[i - coins[j]]->each[k];
				}
				minsofar->each[j]++;
				minsofar->tot = F[i - coins[j]]->tot + 1;
			}
			j++;
		}
		F[i] = minsofar;
	}
	return F[amount]->each;
}

int *greedyChangeMaking(int coins[], int n, int amount){
	int *nb;
	nb = new int [n];
	int left = amount;
	for (int i = n; i >= 0; i--){
		nb[i] = left / coins[i];
		left = left - (nb[i] * coins[i]);
	}

	return nb;

}

int main(){
	int nbcoins;

	cout << "Please enter the number of coins and their value" << endl << "Coin number: ";
	cin >> nbcoins;
	cout << endl << "value: ";
	int coinVal[nbcoins];

	for(int i = 0; i < nbcoins; i++){
		cin >> coinVal[i];
		cout << "and: ";

	}
	cout << endl;

	int change = 0;
	int *amt = 0;

	int choice;

	cout << "Which Algorithm would you like to use?" << endl << "1 - Greedy Algorithm" << endl
		<< "2 - Dynamic Programming Algorithm" << endl << "Enter 1 or 2: ";
	cin >> choice;
	cout << endl;

	if (choice == 1){
		cout << "You have Selected Greedy." << endl;
		while (change >= 0){
			cout << endl << "How much change would you like: ";
			cin >> change;
			cout << endl;
			if (change > 0) {
				amt = greedyChangeMaking(coinVal, nbcoins, change);
				cout << "Your change is: " << endl;
				for (int j =0; j < nbcoins; j++){
					cout << amt[j] << " Coins of value : " << coinVal[j] << endl;
				}
			}
		}
	}
	else if (choice == 2){
		cout << "You have selected Dynamic." << endl;
		while (change >= 0){
			cout << endl << "How much change would you like: ";
			cin >> change;
			cout << endl;
			if (change > 0) {
				amt = fullDPChangeMaking(coinVal, nbcoins, change);
				cout << "Your change is: " << endl;
				for (int j =0; j < nbcoins; j++){
					cout << amt[j] << " Coins of value : " << coinVal[j] << endl;
				}
			}
		}

	}
	else{
		cout << "Please enter a valid number..." << endl;
	}

	cout << "Program ending...";
	cin.get();
	cin.get();

	return 0;
}
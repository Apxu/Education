#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <numeric>
#include <deque>
using namespace std;

deque<int> train;
deque<int> train_on_station;
deque<int> train_for_validation;

void shuffle (int train_lenght){
	
	int TMP;
	
	// for (int k = 0; k < train_lenght; k++){
		// train_for_validation[k] = 0;
	// }
    // for (int k = 0; k < train_lenght; k++){
		// train_on_station[k] = 0;
	// }
	
	train_for_validation.clear();
	train_on_station.clear();
	
	for (int i = 1; i <= train_lenght; i++){
		
		train_on_station.push_back(i);
		
		while (!train_on_station.empty()){
			if (train_on_station.back() == train[train_for_validation.size()]){
				train_for_validation.push_back(train_on_station.back());
				train_on_station.pop_back();
			}
			else {
				break;
			}
		}
		
	}
	
	while (!train_on_station.empty()){
		TMP = train_on_station.back();
		train_for_validation.push_back(TMP);
		train_on_station.pop_back();
	}
}

bool is_possible (int train_lenght){

	shuffle (train_lenght);
	if (train_for_validation == train){
		return true;
	}
	return false;
}

int main(void) {
	int train_lenght, input;
	
	while (true){
		
		cin >> train_lenght;
		if (train_lenght == 0){
			break;
		}
		
		while (true){
			train.clear();
			cin >> input;
			
			if (input == 0){
				break;
			}
			else{
				train.push_back(input);
				for (int i = 1; i < train_lenght; i++){
					cin >> input;
					train.push_back(input);
				}
			}
			
			if (is_possible(train_lenght)){
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		cout << endl;
	}
}
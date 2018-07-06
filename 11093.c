#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <numeric>
using namespace std;

vector<int> gasStationPetrol;
vector<int> gasStationDistance;

bool calculations (int currentPosition, int petrol){
	
	// cout << "Position: " << currentPosition << endl;
	int tmp = currentPosition;
	while (currentPosition <= gasStationPetrol.size()){
		petrol = petrol + gasStationPetrol[currentPosition] - gasStationDistance[currentPosition];
		// cout << "Petrol = " << petrol << endl;
		if (petrol >= 0){
			currentPosition++;
		}
		else {
			return false;
		}
	}
	
	currentPosition = 0;
	while (currentPosition <= tmp){
		petrol = petrol + gasStationPetrol[currentPosition] - gasStationDistance[currentPosition];
		// cout << "Petrol = " << petrol << endl;
		if (petrol >= 0){
			currentPosition++;
		}
		else {
			return false;
		}
	}
	
	return true;
}


int main(void) {
	int number_of_cases, number_of_gasStations, input;
	
	cin >> number_of_cases;
	for (int T = 1; T <= number_of_cases; T++){
		
		gasStationPetrol.clear();
		gasStationDistance.clear();
		
		cin >> number_of_gasStations;
		for (int N = 0; N < number_of_gasStations; N++){
			cin >> input;
			gasStationPetrol.push_back(input);
		}
		
		for (int N = 0; N < number_of_gasStations; N++){
			cin >> input;
			gasStationDistance.push_back(input);
		}		
		
		cout << "Case " << T <<": ";
		
		if (accumulate(gasStationPetrol.begin(), gasStationPetrol.end(), 0) < accumulate(gasStationDistance.begin(), gasStationDistance.end(), 0)) {
			cout << "Not possible" << endl;
		}
		else {
			for (int i = 0; i <= number_of_gasStations; i++){
				if (calculations (i, 0)){
					cout << "Possible from station " << i+1 << endl;
					break;
				}
			}
		}
		
		
		
		
		
		
	}
}
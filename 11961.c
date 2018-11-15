#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <numeric>
#include <queue> 
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <sstream>
using namespace std;

vector<string> vect[13];
vector<string> output;

bool debug = false;
int tc_number, number_of_letters, letters_to_change;
char for_replace[] = {'T', 'G', 'C', 'A'};


void generate_vectors (string dna, int length, int target_length){
	
	if (length == target_length){
		vect[target_length].push_back (dna);
		return;
	}
	
	for (int i = 0; i < 4; i++){
		generate_vectors(dna + for_replace[i], length+1, target_length);
	}
	
}


int diferences (string test_dna, string dna){
	
	int diff = 0;
	
	for (int i = 0; i < dna.length(); i++){
		if (test_dna[i] != dna[i]){
			diff++;
		}
	}
	
	return diff;
}

int main(void) {
	
	string dna, temp_string;
	int counter;
	
	for (int i = 0; i < 11; i++){
		generate_vectors ("", 0, i);
	}

	cin >> tc_number;
	
	for (int i = 0; i < tc_number; i++){
		
		cin >> number_of_letters >> letters_to_change;
		
		cin >> dna;
		
		counter = 0;
		output.clear();
		
		if(debug){
			cout << "Number of TC: " << tc_number << endl;
			cout << "Number of letters: " << number_of_letters << endl;
			cout << "Letters to change: " << letters_to_change << endl;
			cout << "Input string length: " << dna.length() << endl;
			
			for (int m = 0; m < vect[number_of_letters].size(); m++){
				cout << vect[number_of_letters][m] << endl;
			}
		}
		
		for (int k = 0; k < vect[number_of_letters].size(); k++){
			if (diferences(vect[number_of_letters][k],dna) <= letters_to_change){
				counter++;
				output.push_back(vect[number_of_letters][k]);
			}
		}
		
		cout << counter << endl;
		
		while(!output.empty()){
			cout <<  output.back() << endl;
			output.pop_back();
		}
		
	}
}
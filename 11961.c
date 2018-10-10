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

vector<string> result;

bool debug = false;
int tc_number, number_of_letters, letters_to_change;
char for_replace[] = {'A', 'G', 'C', 'T'};

void recursion (string dna, int step, int current_letter){
	
	char temp_letter;
	
	if (step == letters_to_change){
		if(debug){
			cout << dna << endl;
		}
		result.push_back (dna);
		return;
	}
	
	for (int i = 0; i < number_of_letters; i++){
		
		temp_letter = dna[i];
		dna[i] = for_replace[0];
		recursion(dna, step+1, current_letter);
		dna[i] = temp_letter;
		
		temp_letter = dna[i];
		dna[i] = for_replace[1];
		recursion(dna, step+1, current_letter);
		dna[i] = temp_letter;
		
		temp_letter = dna[i];
		dna[i] = for_replace[2];
		recursion(dna, step+1, current_letter);
		dna[i] = temp_letter;
		
		temp_letter = dna[i];
		dna[i] = for_replace[3];
		recursion(dna, step+1, current_letter);
		dna[i] = temp_letter;
	}
}

int main(void) {
	
	string dna, temp_string;
	
	cin >> tc_number;
	
	for (int i = 0; i < tc_number; i++){
		
		cin >> number_of_letters >> letters_to_change;
		
		cin >> dna;
		
		if(debug){
			cout << "Number of TC: " << tc_number << endl;
			cout << "Number of letters: " << number_of_letters << endl;
			cout << "Letters to change: " << letters_to_change << endl;
			cout << "Input string length: " << dna.length() << endl;
		}
		
		result.clear();
		
		for (int k = 0; k < number_of_letters; k++){
			recursion (dna, 0, k);
		}
		
		sort( result.begin(), result.end() );
		result.erase( unique( result.begin(), result.end() ), result.end() );
		cout << result.size() << endl;
		
		for (int m = 0; m < result.size(); m++){
			cout << result[m] << endl;
		}
		
	}
	
}
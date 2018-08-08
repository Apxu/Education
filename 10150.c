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

string list[25143];

// set<string> list;
set<string> visited;
string start_word, end_word;

bool debug = true;

int main(void) {
	
	string input;
	int word_counter = 0;
	stringstream ss;
	
	
	//Read the dictionary words
	while(true){
		getline(cin, input);
		if(input == ""){
			if(debug){
				cout << "Number of words: " << word_counter << endl;
			}
			break;
		}
		else {
			list[word_counter] = input;
			word_counter++;
		}
	}
	
	if(debug){
		for (int i = 0; i < word_counter; i++){
			cout << list[i] << endl;
		}
	}
	
	//Read the start/end words
	while(cin >> start_word >> end_word){
		
		if(debug){
			cout << "Start: " << start_word << endl;
			cout << "End: " << end_word << endl;
		}
		
		
	}
	
	return 0;
}
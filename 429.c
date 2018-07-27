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

string list[205];
bool used[205];
string start_word, end_word;
int word_counter;
bool debug = false;

bool is_suitable(string test_word, string word_from_list, int number_of_different_letters){
	
	int test_word_length = test_word.length();
	
	if(debug){
		cout << test_word << " ? " << word_from_list;
	}
	
	for (int i = 0; i < test_word_length; i++){
		
		if (test_word[i] != word_from_list[i]){
			number_of_different_letters++;
		}
		
	}
	if (number_of_different_letters == 1){
		if (debug){
			cout << " Return true" << endl;
		}
		return true;
	}
	else {
		if (debug){
			cout << " Return false" << endl;
		}
		return false;
	}
}

void clear_used (){
	if (debug){
		cout << "CLEAR USED WORDS" << endl;
	}
	for (int i = 0; i < word_counter; i++){
		used[i] = false;
	}
}

void function(string test_word, int number_of_moves){
	
	int word_length = test_word.length();
	
	struct word {
		word() : test_word(), number_of_moves() {}
		word(string test_word, int number_of_moves)
		: test_word(test_word), number_of_moves(number_of_moves) {}

		string test_word;
		int number_of_moves;

	} ;
	
	queue<word> moves;
	moves.push(word(test_word, number_of_moves));
	
	while (!moves.empty()){
		
		string test_word = moves.front().test_word;
		int number_of_moves = moves.front().number_of_moves;
		moves.pop();
		
		if (test_word == end_word) {
			cout << number_of_moves;
		}
		else {
			number_of_moves++;
			
			for (int j = 0; j < word_counter; j++){
				int list_word_length = list[j].length();
				if (list_word_length == word_length && list[j] != start_word &&!used[j] && is_suitable(test_word, list[j], 0)){
					if(debug){
						cout << "Push: " << list[j] << endl;
					}
					moves.push(word(list[j], number_of_moves));
					used[j] = true;
				}
			}
		}
	}
	return;
}

int main(void) {
	
	int tc_counter;
	cin >> tc_counter;
	stringstream ss;
	string input, str;
	
	for (int i = 0; i < tc_counter; i++){
		
		if (debug){
			cout << "Number of TC: " << tc_counter << endl;
			cout << "Current TC: " << i+1 << endl;
		}
		
		word_counter = 0;
		
		while (cin >> list[word_counter]){
			
			if (list[word_counter][0] == '*'){
				if (debug){
					cout << "Found * in a list; Break list input" << endl;
				}
				break;
			}
			
			if (debug){
				cout << "Word from list:           " << list[word_counter] << endl;
			}
			
			word_counter++;
			// used[word_counter] = false;

		}
		
		// while(cin >> start_word >> end_word){
			
			// if(debug){
				// cout << endl << "Start: " << start_word << endl;
				// cout << "End: " << end_word << endl;
			// }
			
			// clear_used();
			// cout << start_word << " " << end_word << " ";
			// function(start_word, 0);
			// cout << endl;
			
		// }
		
		
		// ss.clear();
		getline(cin, input); // Ignore 1 line
		while(true){
			
			getline(cin, input);
			
			if (debug){
				cout << "Getline input: " << input << endl;
			}
			
			ss.clear();
			
			if(input.empty()){
				break;
			}
			else{
				ss.str(input);
			}
			ss >> start_word >> end_word;
			
			if(debug){
				cout << endl << "Start: " << start_word << endl;
				cout << "End: " << end_word << endl;
			}
			
			clear_used();
			cout << start_word << " " << end_word << " ";
			function(start_word, 0);
			cout << endl;
			
		}
		
		if (i+1 != tc_counter){
			cout << endl;
		}
		
		
	}
	
	return 0;
}
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
using namespace std;

char list[205][10];

void function(int length, string letters, int number_of_moves){
	
	struct word {
		word() : length(), letters(), number_of_moves() {}
		word(int length, char letters[10], int number_of_moves)
		: length(length), letters(letters), number_of_moves(number_of_moves) {}
		
		int length;
		string letters;
		int number_of_moves;

	} ;
	
	queue<word> moves;
	// moves.push(word(length, letters, number_of_moves));
	
	// while (!moves.empty()){
		
	// }
	
	
	
	
	
	return;
}

int main(void) {
	
	int tc_counter, word_counter, string_length, length, tmp;
	string input, start_word, end_word;
	bool is_first;
	
	cin >> tc_counter;
	// cout << "Number of cases: " << tc_counter << endl;
	getline(cin,input); //ignore
	
	for (int i = 0; i < tc_counter; i++){
		
		word_counter = 0;
		
		while (true){
			
			getline(cin,input);
			
			if (input[0] == '*'){
				break;
			}
			
			string_length = input.length();
			for (int j = 0; j < string_length; j++){
				list[word_counter][j] = input[j];
			}
			
			word_counter++;

		}
		
		while(true){
			getline(cin,input);
			
			if (input.empty()){
				break;
			}
			
			is_first = true;
			tmp = 0;
			for (int k = 0; k < input.length(); k++){
				if (input[k] == ' '){
					is_first = false;
				}
				if (is_first){
					start_word += input[k];
					tmp++;
					
					cout << input[k];
				}
				else{
					end_word += input[k];
				}
			}
			
			cout << "Start word: " << start_word << endl;
			cout << "End word: " << end_word << endl;
			
			length = start_word.length();
			
			// function(length, start_word, 0);
			
		}
	}
	
	return 0;
}
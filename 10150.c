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
bool used_words[25143];
string start_word, end_word;
int word_counter;

bool debug = false;

void clear_used (){
	if (debug){
		cout << "CLEAR USED WORDS" << endl;
	}
	for (int i = 0; i < word_counter; i++){
		used_words[i] = false;
	}
}

bool is_suitable (string test_word, string word_from_list, int number_of_different_letters) {
	
	int test_word_length = test_word.length();
	
	if(debug){
		cout << "Comparison: [" << test_word << "] ? [" << word_from_list << "]" << endl;
	}
	
	for (int i = 0; i < test_word_length; i++){
		
		if (test_word[i] != word_from_list[i]){
			number_of_different_letters++;
		}
		
	}
	
	if (number_of_different_letters == 1){
		if(debug){
			cout << "Found word with only 1 different letter" << endl;
		}
		return true;
	}
	else {
		return false;
	}
	
}



void bfs (string test_word, string end_word, int number_of_moves){
	
	int word_lenrth = test_word.length();
	
	struct word {
		word() : test_word(), number_of_moves(), previous_word_index() {}
		word(string test_word, int number_of_moves, deque<int> previous_word_index)
		: test_word(test_word), number_of_moves(number_of_moves), previous_word_index(previous_word_index) {}
		
		string test_word;
		int number_of_moves;
		deque<int> previous_word_index;
		
	} ;
	
	deque<int> queue_of_used_words;
	queue<word> moves;
	moves.push(word(test_word, number_of_moves, queue_of_used_words));
	
	while (!moves.empty()){
		
		test_word = moves.front().test_word;
		number_of_moves = moves.front().number_of_moves;
		deque<int> previous_word_index = moves.front().previous_word_index;
		moves.pop();
		
		if (test_word == end_word){
			if(debug){
				cout << "#RESULT#" << endl;
			}
			cout << start_word << endl;
			while (!previous_word_index.empty()){
				cout << list[previous_word_index.front()] << endl;
				previous_word_index.pop_front();
			}
			return;
		}
		else {
			
			number_of_moves++;
			
			for (int i = 0; i < word_counter; i++){
				int list_word_length = list[i].length();
				if (list_word_length == word_lenrth && list[i] != start_word && !used_words[i] && is_suitable(test_word, list[i], 0)){
					
					if(debug){
						cout << "Push to queue: " << list[i] << endl;
					}
					
					deque<int>TEMP = previous_word_index;
					TEMP.push_back(i);
					
					if(debug){
						cout << "Number of moves: " << number_of_moves << endl;
						cout << "List of words in deque:" << endl;
						cout << "_______________________" << endl;
						deque<int> TEMP2 = previous_word_index;
						while (!TEMP2.empty()){
							cout << list[TEMP2.front()] << endl;
							TEMP2.pop_front();
						}
						cout << "_______________________" << endl;
						
					}
					
					moves.push(word(list[i], number_of_moves, TEMP));
					used_words[i] = true;
					
				}
				
				
			}
			
		}
	}
	
	cout << "No solution." << endl;
	
}

int main(void) {
	
	string input;
	word_counter = 0;
	bool start = true;
	
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
	
	//Read the start / end words
	while(cin >> start_word >> end_word){
		
		if(!start){
			cout << endl;
		}
		
		if(debug){
			cout << "Start: " << start_word << endl;
			cout << "End: " << end_word << endl;
		}
		
		clear_used();
		
		bfs (start_word, end_word, 0);
		start = false;
	}
	
	return 0;
}
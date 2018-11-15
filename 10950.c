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

char letter[30];
string letter_code[30];
vector< pair <char,string> > coded_letters;

int tc_counter, number_of_chars, output_counter;
string coded_string;

bool debug = false;

bool prefix(string test_string){
	
	if (test_string.length() > coded_string.length()){
		return false;
	}
	else{
		return coded_string.substr(0,test_string.length()) == test_string;
	}
	
}

void recursion(string test_string, string output, string TMP_output){
	
	if (test_string.length() == coded_string.length()){
		output_counter++;
		if(debug){
			cout << output << " - " << TMP_output << endl;
			cout << "RETURN" << endl;
		}
		else{
			cout << output << endl;
			return;
		}
	}
	
	for (int i = 0; i < number_of_chars; i++){
		
		pair <char,string> test_letter = coded_letters[i];
		
		if(debug){
			cout << "Test string: " << test_string << endl;
			cout << "Letter code: " << letter_code[i] << endl;
			cout << "Coded string: " << coded_string << endl;
		}
		
		if((prefix(test_string + coded_letters[i].second)) && (output_counter < 100)){
			
			recursion(test_string + coded_letters[i].second, output + coded_letters[i].first, TMP_output + letter_code[i] + ' ');
			
		}
		else if(prefix(test_string + '0' + coded_letters[i].second) && output_counter < 100){
			
			recursion(test_string + '0' + coded_letters[i].second, output + coded_letters[i].first, TMP_output + '0' + letter_code[i] + ' ');
			
		}
		
	}
	
}


int main(void) {
	string test_string, output, TMP_output;
	
	tc_counter = 1;
	
	while(true){
		
		cin >> number_of_chars;
		
		coded_letters.clear();
		output_counter = 0;
		
		if(number_of_chars == 0){
			break;
		}
		
		for (int i = 0; i < number_of_chars; i++){
			
			cin >> letter[i] >> letter_code[i];
			coded_letters.push_back( make_pair (letter[i],letter_code[i]) );
			
		}
		
		sort(coded_letters.begin(), coded_letters.end());
		
		cin >> coded_string;
		
		cout << "Case #" << tc_counter << endl;
		
		if (debug){
			for (int i = 0; i < number_of_chars; i++){
				cout << letter[i] << " = " << letter_code[i] << endl;
			}
			cout << coded_string << endl;
		}
		
		test_string = "";
		output = "";
		TMP_output = "";
		recursion(test_string, output, TMP_output);
		
		tc_counter++;
		
		cout << endl;
		
	}
	
	
}
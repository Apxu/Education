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
int tc_counter, number_of_chars;
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
		if(debug){
			cout << output << " - " << TMP_output << endl;
		}
		else{
			cout << output << endl;
		}
		
		if(debug){
			cout << "RETURN" << endl;
		}
		
		return;
	}
	
	for (int i = 0; i < number_of_chars; i++){
		
		string temp_string = "0";
		
		if(debug){
			cout << "Test string: " << test_string << endl;
			cout << "Letter code: " << letter_code[i] << endl;
			cout << "Coded string: " << coded_string << endl;
		}
		
		if(prefix(test_string + letter_code[i])){
			
			recursion(test_string + letter_code[i], output + letter[i], TMP_output + letter_code[i] + ' ');
			
		}
		else if(prefix(test_string + '0' + letter_code[i])){
			
			recursion(test_string + '0' + letter_code[i], output + letter[i], TMP_output + '0' + letter_code[i] + ' ');
			
		}
		
	}
	
}


int main(void) {
	string test_string, output, TMP_output;
	
	tc_counter = 1;
	
	while(true){
		
		cin >> number_of_chars;
		
		if(number_of_chars == 0){
			break;
		}
		
		for (int i = 0; i < number_of_chars; i++){
			
			cin >> letter[i] >> letter_code[i];
			
		}
		
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
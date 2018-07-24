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

char list[205][100];

int main(void) {
	
	int tc_counter, word_counter, string_length;
	string input, TMP;
	
	cin >> tc_counter;
	cout << "Number of cases: " << tc_counter << endl;
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
		
		for (int k = 0; k < word_counter; k++){
			cout << list[k] << endl;
			TMP = list[k];
			cout << "String length: " << TMP.length() << endl;
		}
		
		getline(cin,input);
		cout << "1:" << input << endl;
		getline(cin,input);
		cout << "2:" << input << endl;
		
	}
	
	return 0;
}
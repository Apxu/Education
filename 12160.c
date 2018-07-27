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

bool debug = true;
int number_of_moves;
int button[10];
bool visited [10000];

void clear_visited(){
	for (int i = 0; i < 10000; i++){
		visited[i] = false;
	}
}

void function (int current_number, int lock_number, int R){
	
	number_of_moves = 0;
	
	while (true){
		if (current_number == lock_number){
			cout << number_of_moves << endl;
		}
		
		for (int i = 0; i < R; i++){
			
		}
		
	}
	
	
	return;
}

int main(void) {
	
	int L, U, R;
	int case_number = 1;
	
	while (true){
		
		cin >> L >> U >> R;
		
		if (L == 0 && U == 0 && R ==0){
			if(debug){
				cout << "The end!" << endl;
			}
			break;
		}
		
		visited[L] = true;
		
		if(debug){
			printf("%04i %04i %i\n", L, U, R);

		}
		
		for (int i = 0; i < R; i++){
			cin >> button[i];
			if(debug){
				printf("Button #%i: %04i\n", i+1, button[i]);
			}
		}
		
		clear_visited();
		
		cout << "Case " << case_number << ": "<< "#PLACEHOLDER#" << endl;
		
		case_number++;
		
	}
	
	
	return 0;
}
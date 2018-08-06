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

bool debug = false;
int return_number_of_moves;
int button[10];
bool visited [10000];

void clear_visited(){
	for (int i = 0; i < 10000; i++){
		visited[i] = false;
	}
}

void function (int current_number, int lock_number, int R, int number_of_moves){
	
	struct number {
		number() : current_number(), number_of_moves(), prev_number() {}
		number(int current_number, int number_of_moves, int prev_number)
		: current_number(current_number), number_of_moves(number_of_moves), prev_number(prev_number) {}
		
		int current_number;
		int number_of_moves;
		int prev_number;
	} ;
	
	queue<number> combinations;
	combinations.push(number(current_number, number_of_moves, 0));
	
	while (!combinations.empty()){
		
		int current_number = combinations.front().current_number;
		int number_of_moves = combinations.front().number_of_moves;
		int prev_number = combinations.front().prev_number;
		combinations.pop();
		
		if(debug){
			cout << "_______________________" << endl;
			cout << "Currrent number: " << current_number << endl;
			cout << "Lock number: " << lock_number << endl;
			cout << "_______________________" << endl;
		}
		
		if (current_number == lock_number){
			if(debug){
				cout << "WIN!" << endl;
			}
			return_number_of_moves = number_of_moves;
			return;
		}
		else {
			
			number_of_moves++;
			int temp_number = current_number;
			
			for (int i = 0; i < R; i++){
				
				if(debug){
					cout << "current_number = current_number + button[" << i << "]" << endl;
					cout << "current_number = " << current_number << " + " << button[i] << endl;
				}
				
				current_number = temp_number;
				prev_number = current_number;
				current_number = current_number + button[i];
				current_number = current_number % 10000;
				
				if(debug){
					cout << "current_number % 10000 = " << current_number << endl;
				}
				
				if(debug){
					cout << "Visited " << current_number << "? " << visited[current_number] << endl;
				}
				
				if(!visited[current_number]){

					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves, prev_number));
					
					if(debug){
						cout << "Previous number: " << prev_number << endl;
						cout << "Number " << current_number << " pushes to queue" << endl;
						cout << "Number of moves: " << number_of_moves << endl;
					}
					
				}
			}
		}
	}
	return;
}

int main(void) {
	
	int L, U, R;
	int case_number = 1;
	
	while (true){
		
		cin >> L >> U >> R;
		
		return_number_of_moves = 0;
		
		if (L == 0 && U == 0 && R ==0){
			if(debug){
				cout << "The end!" << endl;
			}
			break;
		}
		
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
		visited[L] = true;
		function(L, U, R, 0);
		
		if (return_number_of_moves == 0){
			cout << "Case " << case_number << ": Permanently Locked" << endl;
		}
		else {
			cout << "Case " << case_number << ": "<< return_number_of_moves << endl;
		}
		
		case_number++;
		
	}
	
	
	return 0;
}
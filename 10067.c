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
bool visited[10000];
int return_number_of_moves;

void clear_visited(){
	for(int i = 0; i < 10000; i++){
		visited[i] = false;
	}
}


void function(int current_number, int target_number, int number_of_moves){
	
	int temp_number;
	int cn[4];
	
	struct number {
		number() : current_number(), number_of_moves() {}
		number(int current_number, int number_of_moves)
		: current_number(current_number), number_of_moves(number_of_moves) {}
		
		int current_number;
		int number_of_moves;
	} ;
	
	queue<number> combinations;
	combinations.push(number(current_number, number_of_moves));
	
	while(!combinations.empty()){
		
		int current_number = combinations.front().current_number;
		int number_of_moves = combinations.front().number_of_moves;
		
		combinations.pop();
		
		if(current_number == target_number){
			if(debug){
				cout << "WIN!" << endl;
			}
			return_number_of_moves = number_of_moves;
			return;
		}
		else {
			
			number_of_moves++;
			
			cn[0] = current_number / 1000;
			cn[1] = (current_number - cn[0]*1000) / 100;
			cn[2] = (current_number - cn[0]*1000 - cn[1]*100) / 10;
			cn[3] = (current_number - cn[0]*1000 - cn[1]*100 - cn[2]*10);
			
			if(debug){
				cout << "current_number: " << current_number << endl;
				cout << "cn1: " << cn[0] << endl;
				cout << "cn2: " << cn[1] << endl;
				cout << "cn3: " << cn[2] << endl;
				cout << "cn4: " << cn[3] << endl;
			}
			
			//+1000
			if(cn[0]+1 == 10){
				current_number = 0*1000 + cn[1]*100 + cn[2]*10 + cn[3];
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			else{
				current_number = (cn[0]+1)*1000 + cn[1]*100 + cn[2]*10 + cn[3];
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			
			//+100
			if (cn[1]+1 == 10){
				current_number = cn[0]*1000 + 0*100 + cn[2]*10 + cn[3];
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			else{
				current_number = cn[0]*1000 + (cn[1]+1)*100 + cn[2]*10 + cn[3];
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			
			//+10
			if (cn[2]+1 == 10){
				current_number = cn[0]*1000 + cn[1]*100 + 0*10 + cn[3];
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			else{
				current_number = cn[0]*1000 + cn[1]*100 + (cn[2]+1)*10 + cn[3];
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			
			//+1
			if(cn[3]+1 == 10){
				current_number = cn[0]*1000 + cn[1]*100 + cn[2]*10 + 0;
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			else {
				current_number = cn[0]*1000 + cn[1]*100 + cn[2]*10 + cn[3]+1;
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			
			//-1000
			if(cn[0] == 0){
				current_number = 9000 + cn[1]*100 + cn[2]*10 + cn[3];
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			else {
				current_number = (cn[0] - 1)*1000 + cn[1]*100 + cn[2]*10 + cn[3];
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			
			//-100
			if(cn[1] == 0){
				current_number = cn[0]*1000 + 900 + cn[2]*10 + cn[3];
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			else{
				current_number = cn[0]*1000 + (cn[1] - 1)*100 + cn[2]*10 + cn[3];
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			
			//-10
			if(cn[2] == 0){
				current_number = cn[0]*1000 + cn[1]*100 + 90 + cn[3];
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			else{
				current_number = cn[0]*1000 + cn[1]*100 + (cn[2] - 1)*10 + cn[3];
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			
			//-1
			if(cn[3] == 0){
				current_number = cn[0]*1000 + cn[1]*100 + cn[2]*10 + 9;
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			else{
				current_number = cn[0]*1000 + cn[1]*100 + cn[2]*10 + (cn[3] - 1);
				if(!visited[current_number]){
					visited[current_number] = true;
					combinations.push(number(current_number, number_of_moves));
				}
			}
			
			
		}
	}
	return;
}

int main(void) {
	
	int N, temp, start_number, target_number, F, forbidden_number;
	
	int start[4], finish[4];
	
	cin >> N;
	
	if(debug){
		cout << "Number of TC: " << N << endl;
	}
	
	for (int i = 0; i < N; i++){
		
		clear_visited();
		start_number = 0;
		target_number = 0;
		return_number_of_moves = 0;
		
		for (int k = 1000; k >= 1; k=k/10){
			cin >> temp;
			start_number = start_number + temp*k;
		}
		visited[start_number] = true;
		
		for (int k = 1000; k >= 1; k=k/10){
			cin >> temp;
			target_number = target_number + temp*k;
		}
		
		if(debug){
			cout << "Start number: " << start_number << endl;
			cout << "Target number: " << target_number << endl;
		}
		
		cin >> F;
		
		for (int j = 0; j < F; j++){
			
			forbidden_number = 0;
			
			for (int k = 1000; k >= 1; k=k/10){
				cin >> temp;
				forbidden_number = forbidden_number + temp*k;
			}
			
			visited[forbidden_number] = true;
			
			if(debug){
				cout << "Forbidden number: " << forbidden_number << endl;
			}

		}
		
		if (start_number == target_number){
			cout << "0" << endl;
		}
		else{
			function(start_number, target_number, 0);
			if(return_number_of_moves == 0){
				cout << "-1" << endl;
			}
			else {
				cout << return_number_of_moves << endl;
			}
		}
		
		if(debug){
			cout << "End of TC" << endl;
			cout << "________________________________" << endl;
		}
		
	}
	
	return 0;
}
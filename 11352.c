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

char map[105][105];
bool visited[105][105];
int total_rows, total_columns, start_row, start_column, end_row, end_column, result_number_of_moves;

bool debug = false;

void clear_visited(){
	for(int k = 0; k < total_rows; k++){
		for (int l = 0; l < total_columns; l++){
			visited[k][l] = false;
		}
	}
}

void hit_by_horse(int horse_row, int horse_column){
	//left UP
	if (horse_row-1 >= 0 && horse_column-2 >=0 && map[horse_row-1][horse_column-2] != 'B'){
		visited[horse_row-1][horse_column-2] = true;
		
		if(debug){
			if (map[horse_row-1][horse_column-2] != 'Z'){
				map[horse_row-1][horse_column-2] = 'H';
			}
		}
		
	}
	
	//left DOWN
	if (horse_row+1 < total_rows && horse_column-2 >=0 && map[horse_row+1][horse_column-2] != 'B'){
		visited[horse_row+1][horse_column-2] = true;
		
		if(debug){
			if (map[horse_row+1][horse_column-2] != 'Z'){
				map[horse_row+1][horse_column-2] = 'H';
			}
		}
	}
	
	//right UP
	if (horse_row-1 >=0 && horse_column+2 < total_columns && map[horse_row-1][horse_column+2] != 'B'){
		visited[horse_row-1][horse_column+2] = true;
		
		if(debug){
			if (map[horse_row-1][horse_column+2] != 'Z'){
				map[horse_row-1][horse_column+2] = 'H';
			}
		}
	}
	
	//right DOWN
	if (horse_row+1 < total_rows && horse_column+2 < total_columns && map[horse_row+1][horse_column+2] != 'B'){
		visited[horse_row+1][horse_column+2] = true;
		
		if(debug){
			if (map[horse_row+1][horse_column+2] != 'Z'){
				map[horse_row+1][horse_column+2] = 'H';
			}
		}
	}
	
	//top LEFT
	if (horse_row-2 >=0 && horse_column-1 >=0 && map[horse_row-2][horse_column-1] != 'B'){
		visited[horse_row-2][horse_column-1] = true;
		
		if(debug){
			if (map[horse_row-2][horse_column-1] != 'Z'){
				map[horse_row-2][horse_column-1] = 'H';
			}
		}
	}
	
	//top RIGHT
	if (horse_row-2 >=0 && horse_column+1 < total_columns && map[horse_row-2][horse_column+1] != 'B'){
		visited[horse_row-2][horse_column+1] = true;
		
		if(debug){
			if (map[horse_row-2][horse_column+1] != 'Z'){
				map[horse_row-2][horse_column+1] = 'H';
			}
		}
	}
	
	//bottom LEFT
	if (horse_row+2 < total_rows && horse_column-1 >=0 && map[horse_row+2][horse_column-1] != 'B'){
		visited[horse_row+2][horse_column-1] = true;
		
		if(debug){
			if (map[horse_row+2][horse_column-1] != 'Z'){
				map[horse_row+2][horse_column-1] = 'H';
			}
		}
	}
	
	//bottom ROGHT
	if (horse_row+2 < total_rows && horse_column+1 < total_columns && map[horse_row+2][horse_column+1] != 'B'){
		visited[horse_row+2][horse_column+1] = true;
		
		if(debug){
			if (map[horse_row+2][horse_column+1] != 'Z'){
				map[horse_row+2][horse_column+1] = 'H';
			}
		}
	}
}

void bfs (int current_row, int current_column, int number_of_moves){
	
	struct position {
		position() : current_row(), current_column(), number_of_moves() {}
		position(int current_row, int current_column, int number_of_moves)
		: current_row(current_row), current_column(current_column), number_of_moves(number_of_moves) {}
		
		int current_row;
		int current_column;
		int number_of_moves;
	} ;
	
	queue<position> moves;
	moves.push(position(current_row, current_column, number_of_moves));
	
	while (!moves.empty()){
		int current_row = moves.front().current_row;
		int current_column = moves.front().current_column;
		int number_of_moves = moves.front().number_of_moves;
		moves.pop();
		
		if (current_row == end_row && current_column == end_column){
			if(debug){
				cout << "WIN!" << endl;
			}
			result_number_of_moves = number_of_moves;
			return;
		}
		else {
			
			number_of_moves++;
			
			//Move UP
			if (current_row-1 >= 0 && !visited[current_row-1][current_column]){
				visited[current_row-1][current_column] = true;
				moves.push(position(current_row-1, current_column, number_of_moves));
			}
			
			//Move DOWN
			if (current_row+1 < total_rows && !visited[current_row+1][current_column]){
				visited[current_row+1][current_column] = true;
				moves.push(position(current_row+1, current_column, number_of_moves));
			}
			
			//Move LEFT
			if (current_column-1 >= 0 && !visited[current_row][current_column-1]) {
				visited[current_row][current_column-1] = true;
				moves.push(position(current_row, current_column-1, number_of_moves));
			}
			
			//Move RIGHT
			if (current_column+1 < total_columns && !visited[current_row][current_column+1]){
				visited[current_row][current_column+1] = true;
				moves.push(position(current_row, current_column+1, number_of_moves));
			}
			
			//Move UP - LEFT
			if (current_row-1 >= 0 && current_column-1 >= 0 && !visited[current_row-1][current_column-1]){
				visited[current_row-1][current_column-1] = true;
				moves.push(position(current_row-1, current_column-1, number_of_moves));
			}
			
			//Move UP - RIGHT
			if (current_row-1 >= 0 && current_column+1 < total_columns && !visited[current_row-1][current_column+1]){
				visited[current_row-1][current_column+1] = true;
				moves.push(position(current_row-1, current_column+1, number_of_moves));
			}
			
			//Move DOWN - LEFT
			if (current_row+1 < total_rows && current_column-1 >= 0 && !visited[current_row+1][current_column-1]){
				visited[current_row+1][current_column-1] = true;
				moves.push(position(current_row+1, current_column-1, number_of_moves));
			}
			
			//Move DOWN - RIGHT
			if (current_row+1 < total_rows && current_column+1 < total_columns && !visited[current_row+1][current_column+1]){
				visited[current_row+1][current_column+1] = true;
				moves.push(position(current_row+1, current_column+1, number_of_moves));
			}
			
		}
		
		
		
	}
}

int main(void) {
	
	int T;
	char input;
	
	cin >> T;
	
	for (int i = 0; i < T; i++){
		
		result_number_of_moves = 0;
		clear_visited();
		cin >> total_rows >> total_columns;
		
		for (int k = 0; k < total_rows; k++){
			for (int l = 0; l < total_columns; l++){
				
				cin >> input;
				map[k][l] = input;
				
				if (input == 'A'){
					start_row = k;
					start_column = l;
					visited[k][l] = true;
				}
				
				if (input == 'B'){
					end_row = k;
					end_column = l;
				}
				
				if (input == 'Z'){
					visited[k][l] = true;
				}
				
			}
		}
		
		for(int k = 0; k < total_rows; k++){
			for (int l = 0; l < total_columns; l++){
				if (map[k][l] == 'Z'){
					visited[k][l] = true;
					hit_by_horse(k, l);
				}
				
				if(debug){
					cout << map[k][l] << " ";
				}
			}
			if(debug){
				cout << endl;
			}
		}
		if (debug){
			cout << "End of TC" << endl;
			cout << "_______________________________" << endl << endl;
		}
		
		bfs (start_row, start_column, 0);
		
		if (result_number_of_moves == 0){
			cout << "King Peter, you can't go now!" << endl;
		}
		else {
			cout << "Minimal possible length of a trip is " << result_number_of_moves << endl;
		}
		
	}
	
	return 0;
}
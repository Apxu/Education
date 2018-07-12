#include <iostream>
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

char map[33][81];
bool visited[33][81];
int string_length[33];
int case_counter, row_counter, findings_counter, result, best_result;
char fill_char, grid_char;
string input;

void printMap(int row, int string_length[]){
	// Print Map
	for (int i = 0; i < row; i++){
		
		for (int j = 0; j < string_length[i]; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
	// cout << endl;
}

void fill (int row, int column, int max_row, int max_column[], char fill_char){
	
	queue< pair <int,int> > moves;
	moves.push( make_pair(row, column));
	
	while (!moves.empty()){
		
		pair<int, int > coords = moves.front();
		moves.pop();
		int row = coords.first;
		int column = coords.second;
		map[row][column] = fill_char;
		
		// Move Up
		if (row-1 >= 0 && !visited[row-1][column] && map[row-1][column] == ' '){
			moves.push( make_pair(row-1, column));
			visited[row-1][column] = true;
			// cout << "UP" << endl;
		}
		
		//Move Down
		if (row+1 < max_row && !visited[row+1][column] && map[row+1][column] == ' '){
			moves.push( make_pair(row+1, column));
			visited[row+1][column] = true;
			// cout << "DOWN" << endl;
		}
		
		//Move Left
		if (column-1 >= 0 && !visited[row][column-1] && map[row][column-1] == ' '){
			moves.push( make_pair(row, column-1));
			visited[row][column-1] = true;
			// cout << "LEFT" << endl;
		}
		
		//Move Right
		if (column+1 < max_column[row] && !visited[row][column+1] && map[row][column+1] == ' '){
			moves.push( make_pair(row, column+1));
			visited[row][column+1] = true;
			// cout << "RIGHT" << endl;
		}

	}
	
	return;
	
}

int main(void) {

	while(getline(cin,input)){
		
		row_counter = 0;
		grid_char = '_';
		
		for (int i = 0; i < 33; i++){
			string_length[i] = 0;
		}
		
		while(true){
			
			if (input[0] == '_'){
				break;
			}
			
			string_length[row_counter] = input.length();
			
			for (int j = 0; j < input.length(); j++){
				
				map[row_counter][j] = input[j];
				visited[row_counter][j] = false;
				
			}
			row_counter++;
			getline(cin,input);

		}
		
		for (int i = 0; i < row_counter; i++){
			for (int j = 0; j < string_length[i]; j++){
				if (grid_char == '_' && map[i][j] != ' '){
					grid_char = map[i][j];
				}
				if (map[i][j] != grid_char && map[i][j] != ' ' && !visited[i][j]){
					// cout << "Fill char: " << fill_char << endl;
					fill_char = map[i][j];
					fill(i, j, row_counter, string_length, fill_char);
				}
				
			}
		}
		
		printMap(row_counter, string_length);
		cout << input << endl;
	}
	
	return 0;
}
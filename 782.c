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

char map[30][80];
bool visited[30][80];
int row_counter;
int string_length[30];
char edge_char;

void printMap(){

	// Print Map
	for (int i = 0; i < row_counter; i++){
		for (int j = 0; j < string_length[i]; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
}

bool is_paintable(int row, int column){
	
	if ((row-1 >= 0 && map[row-1][column] == edge_char) || 
		(row+1 < row_counter && map[row+1][column] == edge_char) ||
		(column-1 >= 0 && map[row][column-1] == edge_char) ||
		(column+1 < string_length[row] && map[row][column+1] == edge_char)){
			return true;
		}
	return false;
}

void painting (int row, int column){
	queue< pair <int,int> > moves;
	moves.push( make_pair(row, column));
	
	while (!moves.empty()){
		pair <int,int> coords = moves.front();
		moves.pop();
		int row = coords.first;
		int column = coords.second;
		
		if (is_paintable(row, column)){
			map[row][column] = '#';
		}

		//Move UP
		if (row-1 >= 0 && !visited[row-1][column] && map[row-1][column] != edge_char){
			moves.push( make_pair(row-1,column));
			visited[row-1][column] = true;
		}
		
		//Move DOWN
		if (row+1 < row_counter && !visited[row+1][column] && map[row+1][column] != edge_char){
			moves.push( make_pair(row+1, column));
			visited[row+1][column] = true;
		}
		
		//Move LEFT
		if (column-1 >= 0 && !visited[row][column-1] && map[row][column-1] != edge_char){
			moves.push( make_pair(row, column-1));
			visited[row][column-1] = true;
		}
		
		//Moves RIGHT
		if (column+1 < string_length[row] && !visited[row][column+1] && map[row][column+1] != edge_char){
			moves.push( make_pair(row, column+1));
			visited[row][column+1] = true;
		}
	}
}

int main(void) {
	
	int number_of_cases, start_row, start_column;
	string input;
	
	cin >> number_of_cases;
	getline(cin,input);
	
	for (int i = 0; i < number_of_cases; i++){
		
		row_counter = 0;
		start_row = 0;
		start_column = 0;
		
		for (int k = 0; k < 30; k++){
			for (int l = 0; l < 80; l++){
				map[k][l] = ' ';
				visited[k][l] = false;
			}
		}
		
		while (true){
			
			getline(cin, input);
			string_length[row_counter] = input.length();
			
			for (int j = 0; j < string_length[row_counter]; j++){
				map[row_counter][j] = input[j];
				
				if (input[j] != ' ' && input[j] != '*' && input[j] != '_' && input[j] != '#'){
					edge_char = input[j];
				}
				if (input[j] == '*'){
					start_row = row_counter;
					start_column = j;
					map[start_row][start_column] = ' ';
					visited[start_row][start_column] = true;
				}
			}
			
			row_counter++;
			
			if (input[0] == '_'){
				break;
			}

		}
		
		// cout << "Edge char: " << edge_char << endl;
		// cout << "Start row: " << start_row << " Start column: " << start_column << endl;
		painting(start_row, start_column);
		printMap();
		
	}
	
	return 0;
}
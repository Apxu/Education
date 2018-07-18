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

char map[31][81];
bool visited[31][81];
int row_counter;
char edge_char;

void printMap(){

	// Print Map
	for (int i = 0; i < row_counter; i++){
		auto line = string(map[i], map[i] + 81);
		cout << line.substr(0, line.find_last_not_of(' ') + 1) << endl;
	}
}

bool is_paintable(int row, int column){
	if (map[row-1][column] == edge_char || map[row+1][column] == edge_char || map[row][column-1] == edge_char || map[row][column+1] == edge_char){
		return true;
	}
	return false;
}

void inside_painting (int row, int column){
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
			visited[row+1][column];
		}
		
		//Move LEFT
		if (column-1 >= 0 && !visited[row][column-1] && map[row][column-1] != edge_char){
			moves.push( make_pair(row, column-1));
			visited[row][column-1] = true;
		}
		
		//Moves RIGHT
		if (column+1 < 81 && !visited[row][column+1] && map[row][column+1] != edge_char){
			moves.push( make_pair(row, column+1));
			visited[row][column+1] = true;
		}
	}
}

int main(void) {
	
	int number_of_cases;
	string input;
	string breaker;
	bool is_before_edge;
	bool is_inside;
	
	cin >> number_of_cases;
	for (int i = 0; i < number_of_cases; i++){
		
		row_counter = 0;
		
		while (true){
			
			getline(cin, input);
			
			for (int j = 0; j < 81; j++){
				map[row_counter][j] = input[j];
				visited[row_counter][j] = false;
			}
			
			for (int j = input.length(); j < 81; j++){
				map[row_counter][j] = ' ';
			}
			
			row_counter++;
			
			if (input[0] == '_'){
				break;
			}

		}
		
		for (int k = 0; k < row_counter; k++){
			is_before_edge = true;
			for (int l = 0; l < 81; l++){
				
				// cout << "Map char: " << map[k][l] << "   Edge Char: " << edge_char << endl;
				
				if (map[k][l] != '*' && map[k][l] != '#' && map[k][l] != '_' && map[k][l] != ' '){
					edge_char = map[k][l];
				}
				if (map[k][l] == '*'){
					map[k][l] = ' ';
					inside_painting(k, l);
				}
			}
		}
		
		printMap();
		
	}
	
	return 0;
}
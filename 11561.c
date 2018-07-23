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

char map[55][55];
bool visited [55][55];
int row_counter, column_counter, gold_counter, moves_counter;

void printMap(){

	// Print Map
	for (int i = 0; i < row_counter; i++){
		for (int j = 0; j < column_counter; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

bool is_dengerous_near(int row, int column){
	
	// cout << " " << map[row-1][column] << endl;
	// cout << map[row][column-1] << " " << map[row][column+1] << endl;
	// cout << " " << map[row+1][column] << endl;
	
	if (
		(row-1 >= 0 && map[row-1][column] == 'T') ||
		(row+1 < row_counter && map[row+1][column] == 'T') ||
		(column-1 >= 0 && map[row][column-1] == 'T') ||
		(column+1 < column_counter && map[row][column+1] == 'T')
		){
			// cout << "DANGEROUS!" << endl << endl;
			return true;
		}
	// cout << "safe" << endl << endl;
	return false;
}

void searching_treasure(int row, int column){
	
	queue< pair <int, int> > moves;
	moves.push( make_pair (row, column));
	
	while (!moves.empty()){
		
		pair<int, int> coords = moves.front();
		moves.pop();
		row = coords.first;
		column = coords.second;
		
		moves_counter++;
		// map[row][column] = 'o';
		// cout << moves_counter << endl;
		// printMap();
		
		if (map[row][column] == 'G'){
			gold_counter++;
			map[row][column] = '.';
		}
		
		if (!is_dengerous_near(row,column)){
			
			//Move UP
			if (row-1 >=0 && !visited[row-1][column] && map[row-1][column] != '#' && map[row-1][column] != 'T'){
				moves.push( make_pair (row-1, column));
				visited[row-1][column] = true;
			}
		
			//Move DOWN
			if (row+1 < row_counter && !visited[row+1][column] && map[row+1][column] != '#' && map[row+1][column] != 'T'){
				moves.push( make_pair (row+1, column));
				visited[row+1][column] = true;
			}
			
			//Move LEFT
			if (column-1 >= 0 && !visited[row][column-1] && map[row][column-1] != '#' && map[row][column-1] != 'T'){
				moves.push( make_pair (row, column-1));
				visited[row][column-1] = true;
			}
			
			//Move RIGHT
			if (column+1 < column_counter && !visited[row][column+1] && map[row][column+1] != '#' && map[row][column+1] != 'T'){
				moves.push( make_pair (row, column+1));
				visited[row][column+1] = true;
			}
		}
	}
}

int main(void) {
	
	int start_row, start_column;
	char input;
	
	while(cin >> column_counter >> row_counter){
		
		for (int i = 0; i < row_counter; i++){
			for (int j = 0; j < column_counter; j++){
				cin >> input;
				map[i][j] = input;
				visited[i][j] = false;
				if (input == 'P'){
					start_row = i;
					start_column = j;
					map[i][j] = '.';
					visited[i][j] = true;
				}
			}
		}
		
		// cout << "Start position: " << start_row << " " << start_column << endl;
		
		gold_counter = 0;
		moves_counter = 0;
		searching_treasure(start_row, start_column);
		
		// printMap();
		cout << gold_counter << endl;
		
	}
	
	return 0;
}
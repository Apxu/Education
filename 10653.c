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

char map[1005][1005];
bool visited[1005][1005];
int total_row, total_column, destination_row, destination_column;

void printMap(){
	for (int i = 0; i < total_row; i++){
		for (int j = 0; j < total_column; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
}

void clearMap(){
	for (int i = 0; i < total_row; i++){
		for (int j = 0; j < total_column; j++){
			map[i][j] = ' ';
			visited[i][j] = false;
		}
	}
}

void searchingExit(int row, int column, int number_of_moves){
	
	struct coords {
		coords() : row(), column(), number_of_moves() {}
		coords(int row, int column, int number_of_moves)
		: row(row), column(column), number_of_moves(number_of_moves) {}
		
		int row;
		int column;
		int number_of_moves;
	} ;
	
	queue<coords> moves;
	moves.push(coords(row, column, number_of_moves));
	
	while (!moves.empty()){
		
		// struct coords TMP = moves.front();
		// moves.pop();
		
		int row = moves.front().row;
		int column = moves.front().column;
		int number_of_moves = moves.front().number_of_moves;
		map[row][column] = 'o';
		system ("CLS");
		printMap();
		map[row][column] = ' ';
		moves.pop();
		
		if (row == destination_row && column == destination_column){
			cout << number_of_moves << endl;
		}
		else {
			
			number_of_moves++;
			
			//Move UP
			if (row-1 >=0 && !visited[row-1][column] && map[row-1][column] != 'B'){
				moves.push(coords(row-1, column, number_of_moves));
				visited[row-1][column] = true;
				// cout << "1. Number of moves = " << number_of_moves << endl;
				// cout << "2. Number of moves = " << TMP.number_of_moves << endl << endl;
			}
			
			//Move DOWN
			if (row+1 < total_row && !visited[row+1][column] && map[row+1][column] != 'B'){
				moves.push(coords(row+1, column, number_of_moves));
				visited[row+1][column] = true;
				// cout << "1. Number of moves = " << number_of_moves << endl;
				// cout << "2. Number of moves = " << TMP.number_of_moves << endl << endl;
			}
			
			//Move LEFT
			if (column-1 >=0 && !visited[row][column-1] && map[row][column-1] != 'B'){
				moves.push(coords(row, column-1, number_of_moves));
				visited[row][column-1] = true;
				// cout << "1. Number of moves = " << number_of_moves << endl;
				// cout << "2. Number of moves = " << TMP.number_of_moves << endl << endl;
			}
			
			//Moves RIGHT
			if (column+1 < total_column && !visited[row][column+1] && map[row][column+1] != 'B'){
				moves.push(coords(row, column+1, number_of_moves));
				visited[row][column+1] = true;
				// cout << "1. Number of moves = " << number_of_moves << endl;
				// cout << "2. Number of moves = " << TMP.number_of_moves << endl << endl;
			}
		}
	}

	return;
}

int main(void) {
	
	int start_row, start_column, bomb_row_counter, bomb_row, bomb_column, number_of_bombs;
	
	while(true){
		
		cin >> total_row >> total_column;
		if (total_row == 0 && total_column == 0){
			break;
		}
		
		clearMap();
		
		cin >> bomb_row_counter;
		for (int i = 0; i < bomb_row_counter; i++){
			cin >> bomb_row >> number_of_bombs;
			for (int j = 0; j < number_of_bombs; j++){
				cin >> bomb_column;
				map[bomb_row][bomb_column] = 'B';
			}
		}
		
		cin >> start_row >> start_column;
		cin >> destination_row >> destination_column;
		
		map[start_row][start_column] = 'S';
		visited[start_row][start_column] = true;
		map[destination_row][destination_column] = 'D';
		
		searchingExit(start_row, start_column, 0);
		
		// printMap();
		
	}
	
	return 0;
}
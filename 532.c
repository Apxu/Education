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
char map[35][35][35];
bool visited[35][35][35];
bool is_exit;
int L, R, C, end_level, end_row, end_column;

void printmap(){
	for (int i = 0; i < L; i++){
		for (int k = 0; k < R; k++){
			for (int l = 0; l < C; l++){
				cout << map[i][k][l];
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << "_____________" << endl;
}

void searching_exit (int level, int row, int column, int number_of_moves){
	
	struct coords {
		coords() : level(), row(), column(), number_of_moves() {}
		coords(int level, int row, int column, int number_of_moves)
		: level(level), row(row), column(column), number_of_moves(number_of_moves) {}
		
		int level;
		int row;
		int column;
		int number_of_moves;
	} ;
	
	queue<coords> moves;
	moves.push(coords(level, row, column, number_of_moves));
	is_exit = false;
	
	while (!moves.empty()){
		
		int level = moves.front().level;
		int row = moves.front().row;
		int column = moves.front().column;
		int number_of_moves = moves.front().number_of_moves;
		
		moves.pop();
		
		if(debug){
			map[level][row][column] = 'o';
			// system(CLS);
			printmap();
			map[level][row][column] = ' ';
		}

		if (level == end_level && row == end_row && column == end_column){
			if (debug){
				cout << "EXIT FOUND" << endl;
			}
			cout << "Escaped in " << number_of_moves << " minute(s)." << endl;
			is_exit = true;
		}
		else {
			
			number_of_moves++;
			
			//Move UP
			if (level+1 < L && !visited[level+1][row][column] && map[level+1][row][column] != '#'){
				moves.push(coords(level+1, row, column, number_of_moves));
				visited[level+1][row][column] = true;
			}
			
			//Move DOWN
			if (level-1 >= 0 && !visited[level-1][row][column] && map[level-1][row][column] != '#'){
				moves.push(coords(level-1, row, column, number_of_moves));
				visited[level+1][row][column] = true;
			}
			
			//Move FORWARD
			if (row-1 >=0 && !visited[level][row-1][column] && map[level][row-1][column] != '#'){
				moves.push(coords(level, row-1, column, number_of_moves));
				visited[level][row-1][column] = true;
			}
			
			//Move BACKWARD
			if (row+1 < R && !visited[level][row+1][column] && map[level][row+1][column] != '#'){
				moves.push(coords(level, row+1, column, number_of_moves));
				visited[level][row+1][column] = true;
			}
			
			//Move LEFT
			if (column-1 >=0 && !visited[level][row][column-1] && map[level][row][column-1] != '#'){
				moves.push(coords(level, row, column-1, number_of_moves));
				visited[level][row][column-1] = true;
			}
			
			//Move RIGHT
			if (column+1 < C && !visited[level][row][column+1] && map[level][row][column+1] != '#'){
				moves.push(coords(level, row, column+1, number_of_moves));
				visited[level][row][column+1] = true;
			}
			
		}
		
	}
	
	if(debug){
		cout << "Number of moves: " << number_of_moves << endl;
	}
	
	if (!is_exit){
		cout << "Trapped!" << endl;
	}
	
}

int main(void) {
	int start_level, start_row, start_column;
	
	while (true){
		
		cin >> L >> R >> C;
		
		if (L == 0 && R == 0 && C == 0){
			if (debug){
				cout << "The end!" << endl;
			}
			break;
		}
		
		if (debug){
			cout << "Levels: " << L << endl;
			cout << "Rows: " << R << endl;
			cout << "Columns: " << C << endl;
		}
		
		for (int i = 0; i < L; i++){
			for (int k = 0; k < R; k++){
				for (int l = 0; l < C; l++){
					cin >> map[i][k][l];
					
					visited[i][k][l] = false;
					
					if (map[i][k][l] == 'S'){
						start_level = i;
						start_row = k;
						start_column = l;
						
						visited[i][k][l] = true;
					}
					
					if (map[i][k][l] == 'E'){
						end_level = i;
						end_row = k;
						end_column = l;
					}
				}
			}
		}
		
		if(debug){
			cout << "Start position: " << start_level << " " << start_row << " " << start_column << endl;
			cout << "Destination: " << end_level << " " << end_row << " " << end_column << endl;
		}
		
		searching_exit(start_level, start_row, start_column, 0);
		
	}
	
	return 0;
}
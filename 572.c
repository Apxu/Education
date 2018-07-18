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

char map[101][101];
bool visited[101][101];
int findings_counter;

void printMap(int row, int column){
	// Print Map
	for (int i = 0; i < row; i++){
		
		for (int j = 0; j < column; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void mark_oil_deposit(int row, int column, int max_row, int max_column){
	queue< pair <int,int> > moves;
	moves.push( make_pair(row, column));
	
	while (!moves.empty()){
		
		pair<int, int> coords = moves.front();
		moves.pop();
		row = coords.first;
		column = coords.second;
		map[row][column] = '0'+findings_counter;
		
		//Move UP
		if (row-1 >= 0 && map[row-1][column] == '@' && !visited[row-1][column]){
			moves.push( make_pair(row-1, column));
			visited[row-1][column] = true;
		}
		
		//Move DOWN
		if (row+1 < max_row && map[row+1][column] == '@' && !visited[row+1][column]){
			moves.push( make_pair(row+1, column));
			visited[row+1][column] = true;
		}
		
		// Move LEFT
		if (column-1 >= 0 && map[row][column-1] == '@' && !visited[row][column-1]){
			moves.push( make_pair(row, column-1));
			visited[row][column-1] = true;
		}
		
		//Move RIGHT
		if (column+1 < max_column && map[row][column+1] == '@' && !visited[row][column+1]){
			moves.push( make_pair(row, column+1));
			visited[row][column+1] = true;
		}
		
		//Move TOP-LEFT
		if (row-1 >= 0 && column-1 >= 0 && map[row-1][column-1] == '@' && !visited[row-1][column-1]){
			moves.push( make_pair(row-1, column-1));
			visited[row-1][column-1] = true;
		}
		
		//Move TOP-RIGHT
		if (row-1 >= 0 && column+1 < max_column && map[row-1][column+1] == '@' && !visited[row-1][column+1]){
			moves.push( make_pair(row-1, column+1));
			visited[row-1][column+1];
		}
		
		//Move DOWN-LEFT
		if (row+1 < max_row && column-1 >=0 && map[row+1][column-1] == '@' && !visited[row+1][column-1]){
			moves.push( make_pair(row+1, column-1));
			visited[row+1][column-1];
		}
		
		//Move DOWN-RIGHT
		if (row+1 < max_row && column+1 < max_column && map[row+1][column+1] == '@' && !visited[row+1][column+1]){
			moves.push( make_pair(row+1, column+1));
			visited[row+1][column+1] = true;
		}
		
	}
	
	return;
}

int main(void) {
	
	int max_row, max_column, counter;
	char input;
	
	while (true){
		counter = 0;
		findings_counter = 0;
		cin >> max_row >> max_column;
		
		if (max_row == 0){
			break;
		}
		
		for (int i = 0; i < max_row; i++){
			for (int j = 0; j < max_column; j++){
				
				cin >> input;
				map[i][j] = input;
				visited[i][j] = false;
				
			}
		}
		
		// printMap (max_row, max_column);
		
		for (int i = 0; i < max_row; i++){
			for (int j = 0; j < max_column; j++){
				
				if (map[i][j] == '@' && !visited[i][j]){
					mark_oil_deposit(i, j, max_row, max_column);
					counter++;
				}
				
			}
		}
		
		cout << counter << endl;
		
	}
	
	return 0;
}
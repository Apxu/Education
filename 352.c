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
using namespace std;

char map[26][26];
bool visited[26][26];
int war_eagles;

void printMap(int N){
	// Print Map
	cout << "N: " << N << endl;
	cout << " " << "| 0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "_________________________" << endl;
	for (int i = 0; i < N; i++){
		cout << i << "| ";
		for (int j = 0; j < N; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void searching (int row, int column, int N){
	
	queue< pair <int,int> > moves;
	moves.push( make_pair(row, column));
	
	while (!moves.empty()){
		
		pair<int, int > coords = moves.front();
		moves.pop();
		int row = coords.first;
		int column = coords.second;
		visited[row][column] = true;
		map[row][column] = '0'+war_eagles+1;
		
		// Move Up
		if (row-1 >= 0 && !visited[row-1][column] && map[row-1][column] == '1'){
			moves.push( make_pair(row-1, column));
		}
		
		//Move Down
		if (row+1 < N && !visited[row+1][column] && map[row+1][column] == '1'){
			moves.push( make_pair(row+1, column));
		}
		
		//Move Left
		if (column-1 >= 0 && !visited[row][column-1] && map[row][column-1] == '1'){
			moves.push( make_pair(row, column-1));
		}
		
		//Move Right
		if (column+1 < N && !visited[row][column+1] && map[row][column+1] == '1'){
			moves.push( make_pair(row, column+1));
		}
		
		//Move to TopLeft
		if (row-1 >= 0 && column-1 >= 0 && !visited[row-1][column-1] && map[row-1][column-1] == '1'){
			moves.push( make_pair(row-1, column-1));
		}
		
		//Move to TopRight
		if (row-1 >= 0 && column+1 < N && !visited[row-1][column+1] && map[row-1][column+1] == '1'){
			moves.push( make_pair(row-1, column+1));
		}
		
		//Move to BottomLeft
		if (row+1 < N && column-1 >= 0 && !visited[row+1][column-1] && map[row+1][column-1] == '1'){
			moves.push( make_pair(row+1, column-1));
		}
		
		//Move to BottomRight
		if (row+1 >= 0 && column+1 < N && !visited[row+1][column+1] && map[row+1][column+1] == '1'){
			moves.push( make_pair(row+1, column+1));
		}

	}
	
	return;
	
}


int main(void) {
	
	int case_counter = 0;
	int N;
	
	while (cin >> N){
	
		case_counter++;
		war_eagles = 0;
		
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				
				cin >> map[i][j];
				visited[i][j] = false;
				
			}
		}
		
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				
				if (map[i][j] == '1' && !visited[i][j]){

					searching(i, j, N);
					war_eagles++;
					
				}
				
			}
		}
		printMap (N);
		cout << "Image number " << case_counter << " contains " << war_eagles << " war eagles." << endl;
	
	}
	return 0;
}
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

char map[100][100];
bool visited[100][100];
int result, N;

void printMap(int N){
	// Print Map
	for (int i = 0; i < N; i++){
		
		for (int j = 0; j < N; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
	// cout << endl;
}


void mark_ship (int row, int column){
	
	queue< pair <int, int> >moves;
	moves.push( make_pair(row, column));
	
	while(!moves.empty()){
		
		pair<int, int> coords = moves.front();
		moves.pop();
		int row = coords.first;
		int column = coords.second;
		// map[row][column] = '0'+ result;
		
		//Move Up
		if (row+1 < N && (map[row+1][column] == 'x' || map[row+1][column] == '@') && !visited[row+1][column]){
			visited[row+1][column] = true;
			moves.push( make_pair(row+1, column));
		}
		
		//Move Down
		if (row-1 >= 0 && (map[row-1][column] == 'x' || map[row-1][column] == '@') && !visited[row-1][column]){
			visited[row-1][column] = true;
			moves.push( make_pair(row-1, column));
		}
		
		//Move Left
		if(column-1 >=0 && (map[row][column-1] == 'x' || map[row][column-1] == '@') && !visited[row][column-1]){
			visited[row][column-1] = true;
			moves.push( make_pair(row, column-1));
		}
		
		//Move Right
		if(column+1 < N && (map[row][column+1] == 'x' || map[row][column+1] == '@') && !visited[row][column+1]){
			visited[row][column+1] = true;
			moves.push( make_pair(row, column+1));
		}
		
		
	}
	
	
	return;
}

int main(void) {

	int number_of_tests;
	char input;
	
	cin >> number_of_tests;
	for (int i = 0; i < number_of_tests; i++){
		result = 0;
		cin >> N;
		
		for (int k = 0; k < N; k++){
			for (int l = 0; l < N; l++){
				
				cin >> input;
				map[k][l] = input;
				visited[k][l] = false;
				
			}
		}
		for (int k = 0; k < N; k++){
			for (int l = 0; l < N; l++){
				
				if (map[k][l] == 'x' && !visited[k][l]){
					result++;
					visited[k][l] = true;
					mark_ship(k, l);
				}
				
			}
		}
		
		cout << "Case " << i+1 << ": " << result << endl;
		// printMap(N);
		
	}
	
	return 0;
}
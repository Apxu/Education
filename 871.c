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

char map[26][26];
bool visited[26][26];
int case_counter, column_counter, row_counter, findings_counter, result, best_result;
string input;

void printMap(int row, int column){
	// Print Map
	// cout << "Number of rows: " << row << endl;
	// cout << "Number of columns: " << column << endl;
	cout << "  " << "| 0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "_________________________" << endl;
	for (int i = 0; i < row; i++){
		if (i > 9){
			cout << i << "| ";
		}
		else {
			cout << " " << i << "| ";
		}
		
		for (int j = 0; j < column; j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << "_________________________" << endl;
	cout << endl;
}

int searching (int row, int column, int max_row, int max_column){
	
	queue< pair <int,int> > moves;
	moves.push( make_pair(row, column));
	int counter = 0;
	
	while (!moves.empty()){
		
		pair<int, int > coords = moves.front();
		moves.pop();
		int row = coords.first;
		int column = coords.second;
		map[row][column] = '0'+findings_counter;
		// cout << "Moves: row:" << row << " column:" << column << endl;
		counter++;
		
		// Move Up
		if (row-1 >= 0 && !visited[row-1][column] && map[row-1][column] == '1'){
			moves.push( make_pair(row-1, column));
			visited[row-1][column] = true;
			// cout << "Move Up" << endl;
		}
		
		//Move Down
		if (row+1 < max_row && !visited[row+1][column] && map[row+1][column] == '1'){
			moves.push( make_pair(row+1, column));
			visited[row+1][column] = true;
			// cout << "Move Down" << endl;
		}
		
		//Move Left
		if (column-1 >= 0 && !visited[row][column-1] && map[row][column-1] == '1'){
			moves.push( make_pair(row, column-1));
			visited[row][column-1] = true;
			// cout << "Move left" << endl;
		}
		
		//Move Right
		if (column+1 < max_column && !visited[row][column+1] && map[row][column+1] == '1'){
			moves.push( make_pair(row, column+1));
			visited[row][column+1] = true;
		}
		
		//Move to TopLeft
		if (row-1 >= 0 && column-1 >= 0 && !visited[row-1][column-1] && map[row-1][column-1] == '1'){
			moves.push( make_pair(row-1, column-1));
			visited[row-1][column-1] = true;
		}
		
		//Move to TopRight
		if (row-1 >= 0 && column+1 < max_column && !visited[row-1][column+1] && map[row-1][column+1] == '1'){
			moves.push( make_pair(row-1, column+1));
			visited[row-1][column+1] = true;
		}
		
		//Move to BottomLeft
		if (row+1 < max_row && column-1 >= 0 && !visited[row+1][column-1] && map[row+1][column-1] == '1'){
			moves.push( make_pair(row+1, column-1));
			visited[row+1][column-1] = true;
		}
		
		//Move to BottomRight
		if (row+1 >= 0 && column+1 < max_column && !visited[row+1][column+1] && map[row+1][column+1] == '1'){
			moves.push( make_pair(row+1, column+1));
			visited[row+1][column+1] = true;
		}

	}
	
	return counter;
	
}


int main(void) {
	
	cin >> case_counter;
	getline(cin, input);
	getline(cin, input);
	
	for (int i = 0; i < case_counter; i++){
		
		row_counter = 0;
		column_counter = 0;
		findings_counter = 0;
		result = 0;
		best_result = 0;
		
		while (true){

			getline(cin, input);
			
			if (input.empty()){
				// cout << "BREAK" << endl;
				break;
			}
			
			
			column_counter = input.length();
			
			for (int j = 0; j < input.length(); j++){
				
				map[row_counter][j] = input[j];
				visited[row_counter][j] = false;
				
			}
			row_counter++;
			
		}
		
		// cout << "String length: " << column_counter << endl;
		// cout << "Number of strings: " << row_counter << endl;
		
		for (int k = 0; k < row_counter; k++){
			for (int l = 0; l < column_counter; l++){
				
				if (map[k][l] == '1' && !visited[k][l]){
					
					visited[k][l] = true;
					findings_counter++;
					// cout << findings_counter << " - counter: " << endl;
					result = searching(k, l, row_counter, column_counter);
					// cout << endl;
					if (result > best_result){
						best_result = result;
					}

				}
				
			}
		}
		
		// printMap(row_counter, column_counter);
		cout << best_result << endl;
		if (i+1 != case_counter){
			cout << endl;
		}

	}
	
	return 0;
}
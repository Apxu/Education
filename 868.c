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

bool visited [128][128];
int maze [128][128];
int case_number, row, column, start_column, best_result_end_column, best_result_start_column, result_start_column, TEMP;

void print_maze (){
	
	for (int k = 0; k < row; k++){
		for (int l = 0; l < column; l++){
			cout << maze[k][l] << " ";
		}
		cout << endl;
	}
	
}

void recursion (int test_row, int test_column, int step_counter, int step){
	
	if (test_row == row-1){
		
		if(debug){
			print_maze();
			cout << "Step Counter: " << step_counter << endl;
			cout << "Step: " << step << endl;
			cout << "END COLUMN: " << test_column+1 << endl;
			cout << "FINISH!" << endl << endl;
		}
		
		if (best_result_start_column >= start_column){
			best_result_start_column = start_column;
			if (best_result_end_column > test_column){
				best_result_end_column = test_column;
			}
		}
		
		return;
	}
	
	if(debug){
		
		TEMP = maze[test_row][test_column];
		maze[test_row][test_column] = 0;
		print_maze();
		maze[test_row][test_column] = TEMP;
		
		cout << "Step Counter: " << step_counter << endl;
		cout << "Step: " << step << endl;
		cout << "START COLUMN: " << start_column+1 << endl;
		cout << "BEST RESULT START COLUMN: " << best_result_start_column+1 << endl;
		cout << "BEST RESULT END COLUMN: " << best_result_end_column+1 << endl << endl;
		
	}
	
	if (maze[test_row][test_column-1] == step && !visited[test_row][test_column-1]){
		
		visited [test_row][test_column-1] = true;
		
		if(debug){
			cout << "Go LEFT" << endl;
		}
		if (step == step_counter){
			recursion(test_row, test_column-1, step_counter+1, 1);
		}
		else{
			recursion (test_row, test_column-1, step_counter, step+1);
		}
		
		visited[test_row][test_column-1] = false;
		
	}
	
	if (maze[test_row+1][test_column] == step && !visited[test_row+1][test_column]){
		
		visited[test_row+1][test_column] = true;
		
		if(debug){
			cout << "Go DOWN" << endl;
		}
		if (step == step_counter){
			recursion (test_row+1, test_column, step_counter+1, 1);
		}
		else{
			recursion (test_row+1, test_column, step_counter, step+1);
		}
		
		visited[test_row+1][test_column] = false;
		
	}
	
	if (maze[test_row-1][test_column] == step && !visited[test_row-1][test_column]){
		
		visited[test_row-1][test_column] = true;
		
		if(debug){
			cout << "Go UP" << endl;
		}
		if (step == step_counter){
			recursion (test_row-1, test_column, step_counter+1, 1);
		}
		else{
			recursion (test_row-1, test_column, step_counter, step+1);
		}
		
		visited[test_row-1][test_column] = false;
		
	}
	
	if (maze[test_row][test_column+1] == step && !visited[test_row][test_column+1]){
		
		visited[test_row][test_column+1] = true;
		
		if(debug){
			cout << "Go RIGHT" << endl;
		}
		if (step == step_counter){
			recursion (test_row, test_column+1, step_counter+1, 1);
		}
		else{
			recursion (test_row, test_column+1, step_counter, step+1);
		}
		
		visited[test_row][test_column+1] = false;
		
	}
	
}

int main(void) {
	
	cin >> case_number;
		
	for (int i = 0; i < case_number; i++){
		
		if (i > 0){
			cout << endl;
		}
		
		cin >> row >> column;
		
		best_result_end_column = column;
		best_result_start_column = column;
		
		for (int k = 0; k < row; k++){
			for (int l = 0; l < column; l++){
				
				cin >> maze[k][l];
				
			}
		}
		
		// if(i==53){
			// print_maze();
		// }
		
		if(debug){
			cout << "Number of cases: " << case_number << endl;
			cout << "Rows: "  << row << endl;
			cout << "Columns: " << column << endl;
		}
		
		for (int l = 0; l < column; l++){
			if (maze[0][l] == 1){
				start_column = l;
				visited[0][l] = true;
				recursion (0, l, 2, 1);
				visited[0][l] = false;
			}
		}
		
		cout << "1 " << best_result_start_column+1 << endl;
		cout << row << " " << best_result_end_column+1 << endl;
		
	}
	
}
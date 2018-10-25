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
bool maze[110][110];
bool visited[110][110];
int row, column, firstStep, secondStep, even, odd;

void print_maze (){
    for (int k = 0; k < row; k++){
        for (int l = 0; l < column; l++){
            cout << visited[k][l] << " ";
        }
        cout << endl;
    }
}

int possible_moves (int test_row, int test_column, int moves){
	
	if ((test_row + firstStep) < row && (test_column + secondStep) < column && !maze[test_row + firstStep][test_column + secondStep]){
		moves++;
	}
	
	if ((test_row + secondStep) < row && (test_column + firstStep) < column && !maze[test_row + secondStep][test_column + firstStep]){
		moves++;
	}
	
	if ((test_row + firstStep) < row && (test_column - secondStep) >= 0 && !maze[test_row + firstStep][test_column - secondStep]){
		moves++;
	}
	
	if ((test_row + secondStep) < row && (test_column - firstStep) >= 0 && !maze[test_row + secondStep][test_column - firstStep]){
		moves++;
	}
	
	if ((test_row - firstStep) >= 0 && (test_column + secondStep) < column && !maze[test_row - firstStep][test_column + secondStep]){
		moves++;
	}
	
	if ((test_row - secondStep) >= 0 && (test_column + firstStep) < column && !maze[test_row - secondStep][test_column + firstStep]){
		moves++;
	}
	
	if ((test_row - firstStep) >= 0 && (test_column - secondStep) >= 0 && !maze[test_row - firstStep][test_column - secondStep]){
		moves++;
	}
	
	if ((test_row - secondStep) >= 0 && (test_column - firstStep) >= 0 && !maze[test_row - secondStep][test_column - firstStep]){
		moves++;
	}
	
	if(debug){
		cout << "Moves: " << moves << endl;
	}
	
	return moves;
}

void recursion (int test_row, int test_column){
	
	if(debug){
		print_maze();
		cout << endl;
	}
	
	if(possible_moves(test_row, test_column, 0) % 2 == 0){
		even++;
	}
	else {
		odd++;
	}

	if ((test_row + firstStep) < row && (test_column + secondStep) < column){
		if (!visited[test_row + firstStep][test_column + secondStep]){
			visited[test_row + firstStep][test_column + secondStep] = true;
			recursion(test_row + firstStep, test_column + secondStep);
		}
	}
	
	if ((test_row + secondStep) < row && (test_column + firstStep) < column){
		if (!visited[test_row + secondStep][test_column + firstStep]){
			visited[test_row + secondStep][test_column + firstStep] = true;
			recursion(test_row + secondStep, test_column + firstStep);
		}
	}
	
	if ((test_row + firstStep) < row && (test_column - secondStep) >= 0){
		if (!visited[test_row + firstStep][test_column - secondStep]){
			visited[test_row + firstStep][test_column - secondStep] = true;
			recursion(test_row + firstStep, test_column - secondStep);
		}
	}
	
	if ((test_row + secondStep) < row && (test_column - firstStep) >= 0){
		if (!visited[test_row + secondStep][test_column - firstStep]){
			visited[test_row + secondStep][test_column - firstStep] = true;
			recursion(test_row + secondStep, test_column - firstStep);
		}
	}
	
	if ((test_row - firstStep) >= 0 && (test_column + secondStep) < column){
		if (!visited[test_row - firstStep][test_column + secondStep]){
			visited[test_row - firstStep][test_column + secondStep] = true;
			recursion(test_row - firstStep, test_column + secondStep);
		}
	}
	
	if ((test_row - secondStep) >= 0 && (test_column + firstStep) < column){
		if (!visited[test_row - secondStep][test_column + firstStep]){
			visited[test_row - secondStep][test_column + firstStep] = true;
			recursion(test_row - secondStep, test_column + firstStep);
		}
	}
	
	if ((test_row - firstStep) >= 0 && (test_column - secondStep) >= 0){
		if (!visited[test_row - firstStep][test_column - secondStep]){
			visited[test_row - firstStep][test_column - secondStep] = true;
			recursion(test_row - firstStep, test_column - secondStep);
		}
	}
	
	if ((test_row - secondStep) >= 0 && (test_column - firstStep) >= 0){
		if (!visited[test_row - secondStep][test_column - firstStep]){
			visited[test_row - secondStep][test_column - firstStep] = true;
			recursion(test_row - secondStep, test_column - firstStep);
		}
	}

}

int main(void) {
	
	int tc_number, W, x, y;
	
	cin >> tc_number;
	
	if (debug){
		cout << "Number of TC: " << tc_number << endl;
	}
	
	for (int i = 0; i < tc_number; i++){
		
		for (int k = 0; k < 110; k++){
			for (int l = 0; l < 110; l++){
				maze[k][l] = false;
				visited[k][l] = false;
			}
		}
		
		even = 0;
		odd = 0;
		
		cin >> row >> column >> firstStep >> secondStep;
		cin >> W;
		
		if (debug){
			cout << "Maze size: " << row << " " << column << endl;
			cout << "First move: " << firstStep << endl;
			cout << "Seconf move: " << secondStep << endl;
			cout << "Number of 'Water': " << W << endl;
		}

		for (int k = 0; k < W; k++){
			
			cin >> x >> y;
			maze[x][y] = true;
			visited[x][y] = true;
			
			if(debug){
				cout << k+1 << " 'Water' coords: " << x << " " << y << endl;
			}
			
		}
		
		// print_maze();
		visited[0][0] = true;
		recursion(0,0);
		if(debug){
			cout << "Last maze output: " << endl;
			print_maze();
			cout << endl << endl;
		}
		
		cout << "Case " << i+1 << ": " << even << " " << odd << endl;
		
	}
	

	
}
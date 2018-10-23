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

bool debug = true;
bool maze[110][110];
int row, column;

void print_maze (){
    
    for (int k = 0; k < row; k++){
        for (int l = 0; l < column; l++){
            cout << maze[k][l] << " ";
        }
        cout << endl;
    }
    
}

void recursion (int test_row, int test_column){
	
	
	
}

int main(void) {
	
	int tc_number, M, N, W, x, y;
	
	cin >> tc_number;
	
	if (debug){
		cout << "Number of TC: " << tc_number << endl;
	}
	
	for (int i = 0; i < tc_number; i++){
		
		for (int k = 0; k < 110; k++){
			for (int l = 0; l < 110; l++){
				maze[k][l] = false;
			}
		}
		
		cin >> row >> column >> M >> N;
		cin >> W;
		
		if (debug){
			cout << "Maze size: " << row << " " << column << endl;
			cout << "First move: " << M << endl;
			cout << "Seconf move: " << N << endl;
			cout << "Number of 'Water': " << W << endl;
		}

		for (int k = 0; k < W; k++){
			
			cin >> x >> y;
			maze[x][y] = true;
			
			if(debug){
				cout << k+1 << " 'Water' coords: " << x << " " << y << endl;
			}
			
		}
		
		print_maze();
		
		recursion(0,0);
		
	}
	

	
}
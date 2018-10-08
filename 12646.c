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
int maze [30][30];

int main(void) {
	
	while (cin >> case_number){
		
		for (int i = 0; i < case_number; i++){
			
			cin >> row >> column;
			
			for (int k = 0; k < row; k++){
				for (int l = 0; l < column; l++){
					
					cin >> maze[k][l];
					
				}
			}
			
			if(debug){
				cout << "Number of cases: " << case_number << endl;
				cout << "Rows: "  << row << endl;
				cout << "Columns: " << column << endl;
				for (int k = 0; k < row; k++){
					for (int l = 0; l < column; l++){
						cout << maze[k][l] << " ";
					}
					cout << endl;
				}
				cout << endl;
			}
			
		}
		
	}
	
}
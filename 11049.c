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
bool visited[10][10];

struct wall {
		int start_row;
		int start_column;
		int end_row;
		int end_column;
	} ;

wall walls[3];
int start_row, start_column, end_row, end_column;

void clear_visited (){
	for (int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			visited[i][j] = false;
		}
	}
}

bool can_pass(int test_row, int test_column, char direction){
	
	for (int i = 0; i < 3; i++){
		
		if (walls[i].start_row == walls[i].end_row){ // Wall is horizontal
			if(debug){
				cout << "Wall #" << i+1 << " is horizontal" << endl;
				cout << "Test direction: " << direction << endl;
			}
			if (direction == 'N'){
				if (test_row == walls[i].start_row+1){
					if (test_column > walls[i].start_column && test_column <= walls[i].end_column){
						if(debug){
							cout << "You can't pass to NORTH" << endl;
						}
						return false;
					}
				}
			}
			else if (direction == 'S') {
				if (test_row == walls[i].start_row){
					if (test_column > walls[i].start_column && test_column <= walls[i].end_column){
						if(debug){
							cout << "You can't pass to SOUTH" << endl;
						}
						return false;
					}
				}
				
			}
		}
		else if (walls[i].start_column == walls[i].end_column){ // Wall is vertical
			if(debug){
				cout << "Wall #" << i+1 << " is vertical" << endl;
				cout << "Test direction: " << direction << endl;
			}
			if (direction == 'W'){
				if (test_column == walls[i].start_column+1){
					if (test_row > walls[i].start_row && test_row <= walls[i].end_row){
						if(debug){
							cout << "You can't pass to WEST" << endl;
						}
						return false;
					}
				}
			}
			else if (direction == 'E'){
				if (test_column == walls[i].start_column){
					if (test_row > walls[i].start_row && test_row <= walls[i].end_row){
						if(debug){
							cout << "You can't pass to EAST" << endl;
						}
						return false;
					}
				}
			}
		}
		
	}
	return true;
}

void bfs(){
	
	struct one_move {
		one_move() : test_row(), test_column(), direction() {}
		one_move(int test_row, int test_column, deque<char> direction)
		: test_row(test_row), test_column(test_column), direction(direction) {}
		
		int test_row;
		int test_column;
		deque<char> direction;
	} ;
	
	deque<char> direction;
	queue<one_move> moves;
	moves.push(one_move(start_row, start_column, direction));
	
	while(!moves.empty()){
		
		int test_row = moves.front().test_row;
		int test_column = moves.front().test_column;
		direction = moves.front().direction;
		moves.pop();
		
		if(debug){
			cout << endl << "Test coords: " << test_row << " " << test_column << endl;
		}
		
		if (test_row == end_row && test_column == end_column){
			if(debug){
				cout << endl << "FINISH!" <<endl;
			}
			while(!direction.empty()){
				cout << direction.front();
				direction.pop_front();
			}
			cout << endl;
			return;
		}
		else {
			
			//Move UP
			if(test_row-1 >= 1 && !visited[test_row-1][test_column] && can_pass(test_row, test_column, 'N')){
				visited[test_row-1][test_column] = true;
				deque<char> TEMP = direction;
				TEMP.push_back('N');
				moves.push(one_move(test_row-1, test_column, TEMP));
			}
			
			// Move DOWN
			if(test_row+1 <= 6 && !visited[test_row+1][test_column] && can_pass(test_row, test_column, 'S')){
				visited[test_row+1][test_column] = true;
				deque<char> TEMP = direction;
				TEMP.push_back('S');
				moves.push(one_move(test_row+1, test_column, TEMP));
			}
			
			//Move LEFT
			if(test_column-1 >=1 && !visited[test_row][test_column-1] && can_pass(test_row, test_column, 'W')){
				visited[test_row][test_column-1] = true;
				deque<char> TEMP = direction;
				TEMP.push_back('W');
				moves.push(one_move(test_row, test_column-1, TEMP));
			}
			
			//Move Right
			if(test_column+1 <= 6 && !visited[test_row][test_column+1] && can_pass(test_row, test_column, 'E')){
				visited[test_row][test_column+1] = true;
				deque<char> TEMP = direction;
				TEMP.push_back('E');
				moves.push(one_move(test_row, test_column+1, TEMP));
			}
			
		}
		
	}
	
	if(debug){
		cout << "AAAAA!" << endl;
		while(!direction.empty()){
			cout << direction.front();
			direction.pop_front();
		}
	}
	
}

int main(void) {
	
	while(true){
		
		clear_visited();
		
		cin >> start_column >>start_row;
		visited[start_row][start_column] = true;
		
		if(start_row == 0 && start_column == 0){
			break;
		}
		
		cin >> end_column >> end_row;
		
		for (int i = 0; i < 3; i++){
			cin >> walls[i].start_column;
			cin >> walls[i].start_row;
			cin >> walls[i].end_column;
			cin >> walls[i].end_row;
		}

		if(debug){
			cout << "Start: " << start_row << " " << start_column << endl;
			cout << "End: " << end_row << " " << end_column << endl;
			for (int i = 0; i < 3; i++){
				cout << "Wall #" << i+1 << ": " << endl;
				cout << "   " << walls[i].start_row << walls[i].start_column << " - ";
				cout << walls[i].end_row << walls[i].end_column << endl;
			}

		}
		
		bfs();
		
	}

	return 0;
}
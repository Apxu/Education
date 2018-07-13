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

char map[61][61];
char robot; // character wich indicates robot and his facing on map;
int row, column, robot_row, robot_column;

void printMap(int row, int column){
	// Print Map
	for (int i = 0; i < row; i++){
		
		for (int j = 0; j < column; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
	// cout << endl;
}

void robotMoves(char command_input){
	//Rotations to RIGHT
	if (command_input == 'R'){
		if (robot == 'N'){
			robot = 'E';
		}
		else if (robot == 'E'){
			robot = 'S';
		}
		else if (robot == 'S'){
			robot = 'W';
		}
		else if (robot == 'W'){
			robot = 'N';
		}
	}
	
	//Rotations to LEFT
	if (command_input == 'L'){
		if (robot == 'N'){
			robot = 'W';
		}
		else if (robot == 'W'){
			robot = 'S';
		}
		else if (robot == 'S'){
			robot = 'E';
		}
		else if (robot == 'E'){
			robot = 'N';
		}
	}
	
	//Moves FORWARD
	if (command_input == 'F'){
		// cout << "Move forvard: " << endl;
		// cout << "Robot: " << robot << endl;
		// cout << "Robot_row - 1 = " << robot_row-1 << endl;
		// cout << "Robot_row + 1 = " << robot_row+1 << endl;
		// cout << "Robot_column - 1 = " << robot_column-1 << endl;
		// cout << "Robot_column + 1 = " << robot_column+1 << endl;
		// cout << "--------------------------" << endl;
		
		if (robot == 'N' && robot_row-1 > 0 && map[robot_row-1][robot_column] == ' '){
			// cout << "======Move UP" << endl;
			map[robot_row][robot_column] = ' ';
			map[robot_row-1][robot_column] = robot;
			
			robot_row--;
		}
		if (robot == 'E' && robot_column+1 <= column && map[robot_row][robot_column+1] == ' '){
			// cout << "======Move RIGHT" << endl;
			map[robot_row][robot_column] = ' ';
			map[robot_row][robot_column+1] = robot;
			
			robot_column++;
		}
		if (robot == 'S' && robot_row+1 <= row && map[robot_row+1][robot_column] == ' '){
			// cout << "======Move DOWN" << endl;
			map[robot_row][robot_column] = ' ';
			map[robot_row+1][robot_column] = robot;
			
			robot_row++;
		}
		if (robot == 'W' && robot_column-1 > 0 && map[robot_row][robot_column-1] == ' '){
			// cout << "======Move LEFT" << endl;
			map[robot_row][robot_column] = ' ';
			map[robot_row][robot_column-1] = robot;
			
			robot_column--;
		}
		
		// printMap(row, column); //Print map
	}

	// cout << "Robot: " << robot << endl;
	return;
}

int main(void) {

	int number_of_tests;
	string input;
	char command_input;
	
	cin >> number_of_tests;
	// cout << "Number of TC:" << number_of_tests << endl;

	for (int i = 0; i < number_of_tests; i++){

		robot = 'N'; // By default robot facing to North;
		cin >> row >> column;
		getline(cin, input);
		
		for (int k = 0; k < row; k++){
			getline(cin, input);
			for (int l = 0; l < column; l++){
				
				map[k][l] = input[l];
				
			}
		}

		cin >> robot_row >> robot_column;
		// cout << "Start row: " << robot_row << endl;
		// cout << "Start column: " << robot_column << endl;
		robot_row = robot_row - 1;
		robot_column = robot_column - 1;
		map[robot_row][robot_column] = robot;
		
		while (true){
			cin >> command_input;
			if (command_input == 'Q'){
				break;
			}
			// cout << "Command: " << command_input << " " << endl;
			robotMoves(command_input);

			
			
		}
		
		// cout << "Print map:" << endl;
		map[robot_row][robot_column] = robot;
		// printMap(row, column); //Print map
		cout << robot_row+1 << " " << robot_column+1 << " " << robot << endl;
		
		if (i != number_of_tests-1){
			cout << endl;
		}
		
	}
	
	return 0;
}
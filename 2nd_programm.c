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

int M, N, king_row, king_column, landSize, bestLandSize;
char land_character;
char map[21][21];
bool visited[21][21];

int searching (int king_row, int king_column){
	
	int counter = 1;
	queue< pair <int,int> > moves;
	moves.push( make_pair(king_row, king_column));
	
	while (!moves.empty()){
		
		// cout << "Moves queue not empty" << endl;
		
		pair<int, int > coords = moves.front();
		moves.pop();
		int king_row = coords.first;
		int king_column = coords.second;
		visited[king_row][king_column] = true;
		
		// Move Up
		if (king_row-1 >= 0 && !visited[king_row-1][king_column] && map[king_row-1][king_column] == land_character){
			
			visited[king_row-1][king_column] = true;
			counter++;
			moves.push( make_pair(king_row-1, king_column));
			// cout << "Move UP" << endl;
			
		}
		
		//Move Down
		if (king_row+1 < N && !visited[king_row+1][king_column] && map[king_row+1][king_column] == land_character){
			
			visited[king_row+1][king_column] = true;
			counter++;
			moves.push( make_pair(king_row+1, king_column));
			// cout << "Move DOWN" << endl;
			
		}
		
		//Move Left
		if (king_column-1 >= 0 && !visited[king_row][king_column-1] && map[king_row][king_column-1] == land_character){
			
			visited[king_row][king_column-1] = true;
			counter++;
			moves.push( make_pair(king_row, king_column-1));
			// cout << "Move LEFT" << endl;
			
		}
		
		//Move Right
		if (king_column+1 < M && !visited[king_row][king_column+1] && map[king_row][king_column+1] == land_character){
			
			visited[king_row][king_column+1] = true;
			counter++;
			moves.push( make_pair(king_row, king_column+1));
			// cout << "Move RIGHT" << endl;
			
		}
		
		//Move from Right to Left
		// cout << "king_column-1 = " << king_column-1 << endl;
		// cout << "Is it visited? - " << visited[king_row][M-1] << endl;
		// cout << "Character on map[" << king_row << "][" << M-1 << "] = " << map[king_row][M-1] << endl;
		
		if (king_column-1 < 0 && !visited[king_row][M-1] && map[king_row][M-1] == land_character){
			
			visited[king_row][M-1] = true;
			counter++;
			moves.push( make_pair(king_row, M-1));
			// cout << "Jump from LEFT to RIGHT" << endl;
			
		}
		
		//Move from Left to Right
		if (king_column+1 > M && !visited[king_row][0] && map[king_row][0] == land_character){
			
			visited[king_row][0] = true;
			counter++;
			moves.push( make_pair(king_row, 0));
			// cout << "Jump from RIGHT to LEFT" << endl;
			
		}

	}
	
	return counter;
	
}


int main(void) {
	
	while (cin >> N >> M){
	
		bestLandSize = 0;
		
		// cout << "N: " << N << endl;
		// cout << "M: " << M << endl;
		
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				
				cin >> map[i][j];
				visited[i][j] = false;
				
			}
		}
		
		//Print Map
		// for (int i = 0; i < N; i++){
			// for (int j = 0; j < M; j++){
				
				// cout << map[i][j];
				
			// }
			// cout << endl;
		// }
		
		cin >> king_row >> king_column;
		// cout << "King row: " << king_row << endl;
		// cout << "King column: " << king_column << endl;
		land_character = map[king_row][king_column];
		
		// cout << "Land character: " << land_character << endl;
		
		searching(king_row, king_column);
		
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				
				if (map[i][j] == land_character && !visited[i][j]){
					// cout << "Find new start for searching" << endl;
					// cout << "Start searching coordinates: " << i << " " << j << endl;
					landSize = searching(i, j);
					// cout << "Land size: " << landSize << endl;
					
					if (landSize > bestLandSize) {
						bestLandSize = landSize;
					}
					
				}
				
			}
		}
		
		cout << bestLandSize << endl;
	
	}
	return 0;
}
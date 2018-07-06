#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

char maze[8][8];
uint32_t visited[8][8], moves [64];
uint32_t width, height, moves_count;

bool is_coordinates_correct(uint32_t indi_row, uint32_t indi_column){
	
	if (indi_row < 0 || indi_row >= height || indi_column < 0 || indi_column >= width || visited[indi_row][indi_column] != 0){
		return false;
	}
	
	return true;
	
}

bool is_move_correct(uint32_t indi_row, uint32_t indi_column){
	
	char correct_char[] = {'I', 'E', 'H', 'O', 'V', 'A', '#'};
	if (is_coordinates_correct(indi_row, indi_column)){
		for (uint32_t i = 0; i < 7; i += 1){
			if (maze[indi_row][indi_column] == correct_char[i]){
				return true;
			}
		}
		return false;
	}
	return false;
}

void searching_exit (uint32_t indi_row, uint32_t indi_column){
	
//	printf ("Indi current position: %u, %u\n", indi_row, indi_column);
	
	if (maze[indi_row][indi_column] == '#'){
//		printf ("\n\n!!!Exit found!!!\n\n");

		for (uint32_t n = 0; n < moves_count; n +=1){
			
			if (n > 0){
				printf (" ");
			}
			
			if (moves[n] == 4){
				printf ("left");
			}
			else if (moves[n] == 6){
				printf ("right");
			}
			else if (moves[n] == 8){
				printf ("forth");
			}
			
		}
		return;
	}
	
	if (is_move_correct(indi_row, indi_column-1)){
//		printf ("Indi moves to left\n");
		visited[indi_row][indi_column-1] = 1;
		moves[moves_count] = 4;
		moves_count += 1;
		searching_exit (indi_row, indi_column-1);
		moves_count -= 1;
	}
	
	if (is_move_correct(indi_row, indi_column+1)){
//		printf ("Indi moves to right\n");
		visited[indi_row][indi_column+1] = 1;
		moves[moves_count] = 6;
		moves_count += 1;
		searching_exit (indi_row, indi_column+1);
		moves_count -= 1;
	}
	
	if (is_move_correct(indi_row-1, indi_column)){
//		printf ("Indi moves to forth\n");
		visited[indi_row-1][indi_column] = 1;
		moves[moves_count] = 8;
		moves_count += 1;
		searching_exit (indi_row-1, indi_column);
		moves_count -= 1;
	}
	
	return;
}

int main(void) {
	
	uint32_t number_of_cases, indi_row, indi_column;
	
	scanf ("%u\n", &number_of_cases);
	for (uint32_t i = 0; i < number_of_cases; i += 1){
		
		moves_count = 0;
		
		for (uint32_t k = 0; k < 7; k +=1){
			for (uint32_t l = 0; l < 7; l +=1){
				visited[k][l] = 0;
			}
		}
		
		scanf ("%u %u\n", &height, &width);
		
		for (uint32_t row = 0; row < height; row += 1){
			for (uint32_t column = 0; column < width; column += 1){
				
				scanf ("%c", &maze[row][column]);
				if (maze[row][column] == '@'){
					indi_row = row;
					indi_column = column;
				}
				
			}
			scanf ("\n");
		}
	
		searching_exit (indi_row, indi_column);
		if (i != number_of_cases-1){
			printf("\n");
		}
		
	}

}
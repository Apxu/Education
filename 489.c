#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

uint32_t counter;
char used_characters[256];
bool won;

bool is_char_already_used (char guess[], uint32_t guess_string_lenght, uint32_t guess_char_counter){
	
	for (uint32_t i = 0; i < guess_string_lenght-1; i += 1){
		if (guess[guess_char_counter] == used_characters[i]){
			return true;
		}
	}
	return false;
	
}

bool compare_srtings (char puzzle[], char guess[], bool map[], uint32_t puzzle_string_lenght, uint32_t guess_counter, uint32_t guess_string_lenght){
	
	bool check = false;
	
	for (uint32_t i = 0; i < puzzle_string_lenght-1; i += 1){

		if (guess[guess_counter] == puzzle[i]){
			map[i] = true;
			check = true;
		}
		
	}
	
	if ((check == false) & (is_char_already_used(guess, guess_string_lenght, guess_counter) == false)){
		
		counter += 1;
		used_characters[guess_counter] = guess[guess_counter];
	}
	
//	printf ("Character: %c ", guess[guess_counter]);
//	printf ("Counter = %u \n", counter);
	
	for (uint32_t k = 0; k < puzzle_string_lenght-1; k += 1){
		if (map[k] == false){
			return false;
		}
	}
		
	won = true;	
	return true;
		
}

int main(void) {
	
	char puzzle[256];
	char guess[256];
	bool map[256];
	bool result;
	int32_t round;
	uint32_t puzzle_string_lenght, guess_string_lenght;
	
	while (scanf ("%d\n", &round) != EOF){
		
		if (round == -1){
			break;
		}		
		printf ("Round %d\n", round);
		
// Reset counter		
		counter = 0;
		
// Reset won status
		won = false;
	
// Load puzzle string	
		fgets(puzzle, sizeof puzzle, stdin);
		puzzle_string_lenght = strlen(puzzle);
		if (puzzle_string_lenght > 0) {
			puzzle[puzzle_string_lenght - 1] = '\0';
		}
	
// Load guess string	
		fgets(guess, sizeof guess, stdin);
		guess_string_lenght = strlen(guess);
		if (guess_string_lenght > 0) {
			guess[guess_string_lenght - 1] = '\0';
		}
		
//		printf ("puzzle string lenght: %u\n", puzzle_string_lenght);
//		printf ("guess string lenght: %u\n", guess_string_lenght);
		
// Mark mapping as FALSE
		for (uint32_t i = 0; i < puzzle_string_lenght; i += 1){
			map[i] = false;			
		}
		
// Clear Used characters
		for (uint32_t k = 0; k < guess_string_lenght; k +=1){
			used_characters[k] = '0';
		}

		for (uint32_t l = 0; l < guess_string_lenght-1; l += 1){
			result = compare_srtings (puzzle, guess, map, puzzle_string_lenght, l, guess_string_lenght);
			
			if (won == true){
				break;
			}
		}

		if ((result == true) & (counter < 7)){
//			printf ("\nCounter = %u ", counter);
			printf ("You win.\n");
		}
		else if ((result == false) & ((counter < 7))){
//			printf ("\nCounter = %u ", counter);
			printf ("You chickened out.\n");
		}
		else {
//			printf ("\nCounter = %u ", counter);
			printf ("You lose.\n");
		}

//		printf ("Puzzle string - %s\n", puzzle);
//		printf ("Guess string - %s\n", guess);

		
	}
	
}
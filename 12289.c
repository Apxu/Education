#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

bool is_it_one (char input[], uint32_t input_lenght, char correct[]){
//	printf ("check One\n");
	uint32_t counter = 0;
	if (input_lenght-1 == 3){
		for (uint32_t i = 0; i < input_lenght-1; i += 1){
//			printf ("arr[%u]: %c\n", i, input[i]);
			if (input[i] == correct[i]){
				counter +=1;
			}
		}
	}
	if (counter >= 2){
		return true;
	}
	return false;
}

bool is_it_two (char input[], uint32_t input_lenght, char correct[]){
	uint32_t counter = 0;
	if (input_lenght-1 == 3){
		for (uint32_t i = 0; i < input_lenght-1; i += 1){
			if (input[i] == correct[i]){
				counter +=1;
			}
		}
	}
	if (counter >= 2){
		return true;
	}
	return false;
}

bool is_it_three (char input[], uint32_t input_lenght, char correct[]){
	uint32_t counter = 0;
	if (input_lenght-1 == 5){
		for (uint32_t i = 0; i < input_lenght-1; i += 1){
			if (input[i] == correct[i]){
				counter +=1;
			}
		}
	}
	if (counter >= 2){
		return true;
	}
	return false;
}

int main(void) {
	
	char input[256];
	uint32_t round, input_lenght;
	char *correct[] = {
		"one",
		"two",
		"three"
	};
	
	scanf ("%d\n", &round);
		
	for (uint32_t i = 0; i < round; i += 1){
		
		fgets(input, sizeof input, stdin);
		input_lenght = strlen(input);
		if (input_lenght > 0) {
			input[input_lenght - 1] = '\0';
		}
		
		if (is_it_one(input, input_lenght, correct[0])){
			printf ("1\n");
		}
		
		if (is_it_two(input, input_lenght, correct[1])){
			printf ("2\n");
		}
		
		if (is_it_three(input, input_lenght, correct[2])){
			printf("3\n");
		}
		
	}

		
}
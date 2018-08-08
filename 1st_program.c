#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

void solve(long student_level[], int number_of_students){
	
	long output = -150000;
	
	for (int i = 0; i < number_of_students; i++){
		for (int k = 1; k < number_of_students; k++){
			
			// printf("\nI = %i; K = %i\n", i, k);
			// printf("current output: %li\n", output);
			// printf("%li - %li = %li\n\n", student_level[i], student_level[k], student_level[i]-student_level[k]);
			
			if (i < k){
				if (student_level[i] - student_level[k] > output){
					output = student_level[i] - student_level[k];
				}
			}
		}
	}
	
	printf ("%li\n", output);
	
}

int main(void) {
	
	int number_of_tc, number_of_students;
	long student_level[100000], output;
	
	while (scanf ("%i\n", &number_of_tc) != EOF){
		
		for (int i = 0; i < number_of_tc; i++){
			
			scanf ("%i\n", &number_of_students);
			
			for (int k = 0; k < number_of_students; k++){
				
				scanf ("%li\n", &student_level[k]);
			
			}
		
			solve(student_level, number_of_students);
			
		}
	}
}
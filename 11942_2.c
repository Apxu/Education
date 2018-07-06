#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
bool is_sorted (uint32_t input[10], uint32_t index, bool up, bool down);

int main(void){
	
	uint32_t n, result;
	uint32_t input[10];
	scanf ("%u", &n);
	printf ("Lumberjacks:\n");
	
	for (uint32_t i = 0; i < n; i += 1){
		
		bool up = true;
		bool down = true;
		
		for (uint32_t j = 0; j < 10; j +=1){
			
			scanf ("%u", &input[j]);
			
		}
		
		sorted (input, 1, up, down);
		
		if (up == true || down == true){
			printf("Ordered\n");
		}
		else {
			printf("Unordered\n");
		}
		
	}
	
}

uint32_t sorted (uint32_t input[10], uint32_t index, bool up, bool down){
	
	if (index > 9 ){
		return up, down;
	}
	
	if (input[index-1] < input[index]){
		down = false;
	}

	if (input[index-1] > input[index]){
		up = false;
	} 
	
	if (up == false && down == false){
		return up, down;
	}
	
	return sorted (input, index+1, up, down);
	
}


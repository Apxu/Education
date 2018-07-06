#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
uint32_t sorted (uint32_t input[10], uint32_t index, uint32_t result);

int main(void){
	
	uint32_t n, result;
	uint32_t input[10];
	scanf ("%u", &n);
	printf ("Lumberjacks:\n");
	
	for (uint32_t i = 0; i < n; i += 1){
		
		for (uint32_t j = 0; j < 10; j +=1){
			
			scanf ("%u", &input[j]);
			
		}
		
		result = sorted (input, 1, 0);
		
		if (result == 0 || result == 9){
			printf("Ordered\n");
		}
		else {
			printf("Unordered\n");
		}
		
	}
	
}

uint32_t sorted (uint32_t input[10], uint32_t index, uint32_t result){
	
	if (index > 9 ){
		return result;
	}
	
	if (input[index-1] < input[index]){
		result = result;
	}
	else {
		result += 1;
	}
	
	return sorted (input, index+1, result);
	
}


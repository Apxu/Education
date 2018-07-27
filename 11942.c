#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int main(void){
	uint32_t n, a;
	uint32_t input[10];
	scanf ("%u", &n);
	printf ("Lumberjacks:\n");
	
	for  (uint32_t i = 0; i < n; i += 1){
		
		a = 0;
		for (uint32_t j = 0; j < 10; j += 1){
			
			scanf ("%u", &input[j]);
			
			if (j > 0){
				
				if (input[j-1] < input[j]){
					a = a;
				}
				else {
					a += 1;
				}
			}
		}
		
		if (a == 0 || a == 9){
			printf ("Ordered\n");
		}
		else{
			printf ("Unordered\n");
		}

	}
		
}
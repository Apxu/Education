#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int main(void){
	uint32_t t, n, a, b, h, l;
	scanf ("%u", &t);
	
	for (uint32_t i = 0; i < t; i += 1){
		scanf ("%u", &n);
		a = 0;
		
		for (uint32_t j = 0; j < n; j += 1){
			scanf ("%u", &b);
			
			if (a == 0){
				a = b;
			}
			
			if (b > a){
				h +=1;
				a = b;
			}
			else if (b < a){
				l +=1;
				a = b;
			}
			
		}
		
		printf ("Case %u: %u %u\n", i+1, h, l);
		h = 0;
		l = 0;
		
	}
		
} 
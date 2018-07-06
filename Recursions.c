#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
void element_on_line (uint32_t input[], uint32_t idx, uint32_t n);
void reverse_elements (uint32_t input[], uint32_t idx, uint32_t n);
uint32_t zero (uint32_t input[], uint32_t idx, uint32_t n, uint32_t zeroes);
uint32_t sum_of_elements (uint32_t input[], uint32_t idx, uint32_t n, uint32_t sum);
uint32_t min_element (uint32_t input[], uint32_t idx, uint32_t n, uint32_t elem);

int main(void){
	
	uint32_t n, elem;
	scanf ("%u", &n);
	uint32_t input[n];
	uint32_t idx = 0;
	uint32_t zeroes = 0;
	uint32_t sum = 0;
	
	for (uint32_t i = 0; i < n; i +=1){
		scanf ("%u", &input[i]);
	}
	
	printf ("\n1) Print each element on a line:\n\n");
	element_on_line(input, idx, n);
	
	printf ("\n2) Print in reverse order:\n\n");
	reverse_elements (input, idx, n);
	
	printf ("\n3)Number of zeroes:\n\n");
	printf ("%u", zero(input, idx, n, zeroes));
	
	printf ("\n4)Sum of elements:\n\n");
	sum = sum_of_elements(input, idx, n, sum);
	printf ("%u", sum);
	
	elem = sum;
	printf ("\n5)Minimum element:\n\n");
	printf ("%u", min_element (input, idx, n, elem));
	
}

void element_on_line (uint32_t input[], uint32_t idx, uint32_t n){
	
	if (idx == n){
		return;
	}
	printf ("%u\n", input[idx]);
	element_on_line(input, idx + 1, n);
	
}

void reverse_elements (uint32_t input[], uint32_t idx, uint32_t n){

	if (idx == n){
		return;
	}
	
	reverse_elements (input, idx + 1, n);
	printf ("%u\n", input[idx]);
	
}

uint32_t zero (uint32_t input[], uint32_t idx, uint32_t n, uint32_t zeroes){
	
	if (idx == n){
		return zeroes;
	}
	if (input[idx] == 0){
		zeroes += 1;
	}
	return zero (input, idx + 1, n, zeroes);
	
}

uint32_t sum_of_elements (uint32_t input[], uint32_t idx, uint32_t n, uint32_t sum){
	
	if (idx == n){
		return sum;
	}
	sum = input[idx] + sum;
	return sum_of_elements (input, idx + 1, n, sum);
	
}

uint32_t min_element (uint32_t input[], uint32_t idx, uint32_t n, uint32_t elem){
	
	if (idx == n){
		return elem;
	}
	if (input[idx] < elem){
		elem = input[idx];
	}
	return min_element (input, idx + 1, n, elem);
	
}
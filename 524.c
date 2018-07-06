#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

bool prime[32];

bool is_prime (uint32_t n) {

	uint32_t m = 0;
	for (uint32_t i=3; i<=sqrt(n); i+=2){
		if (n%i == 0) {
			m += 1;
		}	
	}
	
	if (m > 0){
		return false;
	}
	else {
		return true;
	}
}

bool is_first_last_prime (uint32_t sum[], uint32_t n) {
	uint32_t first_last = sum[0] + sum [n-1];
	return prime[first_last];
	}
	
bool is_sum_prime (uint32_t sum[], uint32_t idx){
	uint32_t curr_prev = sum[idx] + sum[idx-1];
	return prime[curr_prev];
}

void shuffle (uint32_t sum[], uint32_t n, uint32_t idx, bool used[]){
	
	if (idx == n) {

		if (is_first_last_prime (sum, idx)) {
			for (uint32_t j=0; j<n; j+=1){
				if (j > 0){
					printf (" ");
				}
				printf ("%u", sum[j]);
			}
			printf ("\n");
		}
		return;
	}
	
	sum[0] = 1;
	for (uint32_t k=2; k<n+1; k+=1) {
		
		if (used[k] == false){

			sum[idx] = k;
			used[k] = true;
			
			if (is_sum_prime(sum, idx)){
				shuffle (sum, n, idx+1, used);
			}

			used[k] = false;	
		}
	}
}

int main(void) {
	
	uint32_t n;
	uint32_t case_count = 1;
	uint32_t sum[16];
	bool used[17];
	
	while (scanf ("%u", &n) != EOF){
		if (case_count > 1) {
			printf ("\n");
		}
		
// Mark all numbers as unused		
		for (uint32_t k = 0; k <= n; k += 1){
			used[k] = false;
		}
		
// Mark all numbers as not a prime
		for (uint32_t i = 0; i <= n+n-1; i += 1){
			prime[i] = false;
		}
		
// Mark prime numbers
		for (uint32_t l = 3; l <= n+n-1; l += 2){
			if (is_prime(l)){
				prime[l] = true;
			}
		}

		printf ("Case %u:\n", case_count);
		if (n == 1){
			printf ("1\n");
		}
		else {
			shuffle (sum, n, 1, used);
		}
		
		case_count +=1;
	}
}
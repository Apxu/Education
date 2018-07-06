#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

uint32_t count;

bool is_right (uint32_t queue[], uint32_t queue_lenght, uint32_t max_height, uint32_t from_right, uint32_t right_count, uint32_t from_left){
	
	for (uint32_t k = queue_lenght; k > 0; k -=1){
		
		if (queue[k-1] >= max_height){
			max_height = queue[k-1];
			right_count +=1;
		}
		
		if (right_count > from_right){
			return false;
		}
		
	}
	
	if (right_count == from_right){
		return true;
	}
	
	return false;
	
}

bool is_left (uint32_t queue[], uint32_t queue_lenght, uint32_t max_height, uint32_t from_left, uint32_t left_count, uint32_t from_right){
	
	for (uint32_t k = 0; k < queue_lenght; k +=1){
		
		if (queue[k] >= max_height){
			max_height = queue[k];
			left_count +=1;
		}
		
		if (left_count > from_left){
			return false;
		}
		
	}
	
	if ((left_count == from_left) && (is_right (queue, queue_lenght, 0, from_right, 0, from_left))){
		return true;
	}
	
	return false;
	
}



void shuffle (uint32_t queue_lenght, uint32_t idx, uint32_t queue[], bool used[], uint32_t from_left, uint32_t from_right){

	if (idx == queue_lenght){
		
//		for (uint32_t j = 0; j < queue_lenght; j +=1){			//
//			printf ("%u", queue[j]);							//вывод всех вариантов
//		}														//
//		printf ("\n\n\n");										//
		
		if (is_left (queue, queue_lenght, 0, from_left, 0, from_right)){
			count +=1;
			return;
		}
		else {
			return;
		}
		
	}
	
	for (uint32_t j = 0; j < queue_lenght; j +=1){
		if (used[j] == false){
			
			queue[idx] = j;
			used[j] = true;
			shuffle (queue_lenght, idx+1, queue, used, from_left, from_right);
			used[j] = false;
			
		}
	}
	
}

int main(void) {
	
	uint32_t number_of_cases, queue_lenght, from_right, from_left;
	uint32_t queue[13];
	bool used[13];
	
	scanf ("%u\n", &number_of_cases);
	
	for (uint32_t i = 0; i < number_of_cases; i += 1){
		
		for (uint32_t k=0; k < 13; k +=1){
			used[k] = false;
		}
		
		count = 0;
		scanf ("%u %u %u\n", &queue_lenght, &from_left, &from_right);
		
		shuffle (queue_lenght, 0, queue, used, from_left, from_right);
		
		printf ("Count: %u\n", count);
		
	}
	
}
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

uint32_t result, result_tracks_count;
uint32_t result_tracks[20];

void choose_track (int32_t disc_capacity, uint32_t idx, uint32_t length[], uint32_t number_of_tracks, uint32_t chosen[], uint32_t count);

int main(void){
	uint32_t disc_capacity, number_of_tracks, a, result1, result2;
	uint32_t chosen[20];
	
	while (true){
		
		a = scanf ("%u", &disc_capacity);
		
		if (a == EOF){
			break;
		}
		
		scanf ("%u", &number_of_tracks);
		
		uint32_t length[number_of_tracks];
		
		for (uint32_t i = 0; i < number_of_tracks; i += 1){
			
			scanf ("%u", &length[i]);
			
		}
		
		result = disc_capacity;
		choose_track (disc_capacity, 0, length, number_of_tracks, chosen, 0);
		
		for (uint32_t j = 0; j < result_tracks_count; j +=1){
			printf ("%u ", result_tracks[j]);
		}
		
		printf ("sum:%u\n", disc_capacity - result); 
		
	}
	
}

void choose_track (int32_t disc_capacity, uint32_t idx, uint32_t length[], uint32_t number_of_tracks, uint32_t chosen[], uint32_t count){
	
	if (idx == number_of_tracks) {
		
		if (disc_capacity < result) {
			result = disc_capacity;
			result_tracks_count = count;
			
			for (uint32_t k = 0; k < count; k +=1){
				result_tracks[k] = chosen[k];
			}
			
		}
		return;
	}
	
	if (disc_capacity - length[idx] >= 0) {
		chosen[count] = length[idx];
		choose_track (disc_capacity-length[idx], idx+1, length, number_of_tracks, chosen, count+1);
	}
	choose_track (disc_capacity, idx+1, length, number_of_tracks, chosen, count);
	return;
}
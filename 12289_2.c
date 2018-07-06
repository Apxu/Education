#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
	
	char givenWord[256];
	uint32_t wordsAmount, wordLength;
	
	scanf ("%u\n", &wordsAmount);
		
for(uint32_t i=0; i < wordsAmount; i+=1){

	uint32_t counterOne=0;
	fgets(givenWord, sizeof givenWord, stdin); //where to(destination); max how much (max size); from where(source)
	
	if (strlen(givenWord) > 0) {
		givenWord[strlen(givenWord) - 1] = '\0';
	}
	
	wordLength=strlen(givenWord);

	if(wordLength==3){  
			
			if(givenWord[0]=='o'){counterOne+=1;}
			if(givenWord[1]=='n'){counterOne+=1;}
			if(givenWord[2]=='e'){counterOne+=1;}

			if(counterOne>=2){printf("1\n");}
			else {printf("2\n");}

        }
        else {printf("3\n");}
                        
    }
}
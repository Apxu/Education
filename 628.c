#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

char* outputArray;
const char numbers[] = "0123456789";
char dictionary[256][100], arrayOfRules[256][1000];
int dictionarySize, numberOfarrayOfRules, oneRuleSize[1000];

char* concat(const char *s1, const char *s2){
	
	char *result = (char*)malloc(strlen(s1)+strlen(s2)+1);		//+1 for the null-terminator
	strcpy(result, s1);
	strcat(result, s2);
	return result;
	
}

void solve(int idx, int idx2){
	
	if (idx == oneRuleSize[idx2]){
		printf ("%s\n", outputArray);
		return;
	}

	if (arrayOfRules[idx2][idx] == '#'){
		for (int i = 0; i < dictionarySize; i++){					// for each word from dictionary
			outputArray = concat(outputArray, dictionary[i]);
			solve (idx+1, idx2);
			outputArray[strlen(outputArray) - strlen(dictionary[i])] = '\0';
		}
	}

	if (arrayOfRules[idx2][idx] == '0'){
		for (int i = 0; i < 10; i++){								// for each number from 0 to 9
		    const char tempNumber[] = { numbers[i], '\0' };
			outputArray = concat(outputArray, tempNumber);
			solve (idx+1, idx2);
			outputArray[strlen(outputArray) - 1] = '\0';
		}
	}
}

int main(void) {
	
	while (scanf ("%d\n", &dictionarySize) != EOF){
		
		printf("--\n");
		
		for (int i = 0; i < dictionarySize; i++){
			
			fgets(dictionary[i], sizeof dictionary[i], stdin);
			dictionary[i][strcspn(dictionary[i], "\n")] = 0;
			
		}
		
		scanf("%i\n", &numberOfarrayOfRules);
		
		for (int k = 0; k < numberOfarrayOfRules; k++){
			
			fgets(arrayOfRules[k], sizeof arrayOfRules[k], stdin);
			oneRuleSize[k] = strlen(arrayOfRules[k]);
			arrayOfRules[k][strcspn(arrayOfRules[k], "\n")] = 0;
			oneRuleSize[k] = strlen(arrayOfRules[k]);
			
		}
		
		// check input data
		// printf("Nnumber of words in dictionary: %i\n", dictionarySize);
		// for (int i = 0; i < dictionarySize; i++){
			// printf("Word #%i: %s\n", i+1, dictionary[i]);
		// }
		
		// printf("Number of arrayOfRules: %i\n", numberOfarrayOfRules);
		// for (int k = 0; k < numberOfarrayOfRules; k++){
			// printf("Rule #%i:\n", k+1, arrayOfRules[k]);
			// for (int l = 0; l < oneRuleSize[k]; l++){
				
				// printf("One Rule Size: %i\n", oneRuleSize[k]);
				
				// if (l == oneRuleSize[k]-1){
					// printf("%c", arrayOfRules[k][l]);
				// }
				// else {
					// printf("%c\n", arrayOfRules[k][l]);
				// }
			// }
		// }
		
		outputArray = "";
		
		for (int k = 0; k < numberOfarrayOfRules; k++){									// for each rule
			solve(0, k);
		}
		
		

	}
}
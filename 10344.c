#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i+=1)
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

bool next_permutation(int array[], size_t length) {
    // Find non-increasing suffix
    if (length == 0)
        return false;
    size_t i = length - 1;
    while (i > 0 && array[i - 1] >= array[i])
        i--;
    if (i == 0)
        return false;

    // Find successor to pivot
    size_t j = length - 1;
    while (array[j] <= array[i - 1])
        j--;
    int temp = array[i - 1];
    array[i - 1] = array[j];
    array[j] = temp;

    // Reverse suffix
    j = length - 1;
    while (i < j) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        i++;
        j--;
    }
    return true;
}

int32_t nums[5];
bool possible;

void solve(size_t idx, int32_t n) {
    // TODO: insert your code here

	if (idx == 5){
		if (n == 23){
			possible = true;
		}
		return;
	}
	
	solve(idx+1, n + nums[idx]);
	solve(idx+1, n - nums[idx]);
	solve(idx+1, n * nums[idx]);
	return;
}

int main(void) {
    while (true) {
        possible = false;
        scanf("%d %d %d %d %d", &nums[0], &nums[1], &nums[2], &nums[3], &nums[4]);

        if (nums[0] == 0 && nums[1] == 0 && nums[2] == 0 && nums[3] == 0 && nums[4] == 0)
            break;

        sort(nums, 5);

        do {
            solve(1, nums[0]);

            if (possible)
                break;
        } while (next_permutation(nums, 5));

        if (possible)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }

    return 0;
}
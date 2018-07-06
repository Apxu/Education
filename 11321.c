#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int divider;

bool is_numbers_in_correct_order (int a, int b){
	
	if (a % divider == b % divider){
		if (a % 2 == 0 && b % 2 == 0){
			return a < b;
		}
		else if (a % 2 != 0 && b % 2 != 0){
			return a > b;
		}
		else if (a % 2 != 0 && b % 2 ==0){
			return true;
		}
		else if (a % 2 == 0 && b % 2 != 0){
			return false;
		}
		
	}
	else {
		return a % divider < b % divider;
	}
	
}

int main(void) {
	int numbers, N, M;
	vector<int> nums;
	
	while (true){
		
		nums.clear();
		cin >> numbers >> divider;
		cout << numbers << " " << divider << endl;
		
		if (numbers == 0 && divider == 0){
			break;
		}

		for (int i = 0; i < numbers; i++){
			
			cin >> N;
			nums.push_back(N);

		}
		
		sort (nums.begin(), nums.end(), is_numbers_in_correct_order);
			
		for (int i = 0; i < numbers; i++){
			// cout << nums[i] << " " << nums[i]%divider << endl;
			cout << nums[i] << endl;
			
		}
	}
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <math.h>
using namespace std;

vector<int> nums;

void dividers (int n, int m){
	for (int i=1; i <= sqrt(n); i++) {
		if (n % i == 0){
			if (n/i > m){
				nums.push_back(n/i);
			}
		}		
	}
	int tmp = nums.size();
	for (int i=0; i < tmp; i++){
		if (n%nums[i] == 0){
			if (n/nums[i] > m){
				nums.push_back(n/nums[i]);
			}
		}
	}
}

int main(void) {
	int number_of_cases, cookies, cookies_eaten, cookies_left;
	
	cin >> number_of_cases;
	
	for (int N = 1; N <= number_of_cases; N++){
		
		nums.clear();
		cin >> cookies >> cookies_left;
		
		cookies_eaten = cookies - cookies_left;
		dividers (cookies_eaten, cookies_left);
		
		sort (nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
		nums.resize(distance(nums.begin(),nums.end()));
	
		cout << "Case #" << N <<":";
		if (cookies == cookies_left){
			cout << " 0";
		}
		else {
			for (int i = 0; i < nums.size(); i++){
				cout << " " << nums[i];
			}
		}
		cout << endl;
		
	}
}
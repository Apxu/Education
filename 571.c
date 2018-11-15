#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <numeric>
#include <queue> 
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <sstream>
using namespace std;

bool debug = false;

int A, B, N;
bool visited [1000][1000];
bool completed;
vector<string> result;

void recursion (int test_A, int test_B, int step_counter){
	
	int temp_A, temp_B;
	
	if(debug){
		cout << "Step: " << step_counter << endl;
		cout << test_A << "   " << test_B << endl;
	}
	
	if(completed){
		return;
	}
	
	if (test_B == N || test_A == N){
		
		if(debug){
			cout << "RESULT:" << endl;
		}
		for (int i = 0; i < result.size(); i++){
			cout << result[i] << endl;
		}
		
		cout << "success" << endl;
		completed = true;
		return;
	}
	
	if (!visited[A][test_B]){ // fill A
		if(debug){
			cout << "fill A" << endl;
		}
		
		result.push_back("fill A");
		visited[A][test_B] = true;
		recursion (A, test_B, step_counter+1);
		result.pop_back();
	}
	
	if (!visited[test_A][B]){ // fill B
		if(debug){
			cout << "fill B" << endl;
		}
		
		result.push_back("fill B");
		visited[test_A][B] = true;
		recursion (test_A, B, step_counter+1);
		result.pop_back();
	}
	
	if (test_B != B){ // from A to B
		temp_A = test_A - (B - test_B);
	
		if (temp_A < 0){
			temp_A = 0;
		}
		
		temp_B = test_B + test_A - temp_A;
	
		if (temp_B > B){
			temp_B = B;
		}
		
		if(debug){
			cout << "from A to B" << endl;
		}
		
		if (!visited[temp_A][temp_B]){
			result.push_back("pour A B");
			visited[temp_A][temp_B] = true;
			recursion (temp_A, temp_B, step_counter+1);
			result.pop_back();
		}
	}
	
	if (test_A != A){ // from B to A
		temp_B = test_B - (A - test_A);
		
		if (temp_B < 0){
			temp_B = 0;
		}
		
		temp_A = test_A + test_B - temp_B;
		
		if (temp_A > A){
			temp_A = A;
		}
		
		if(debug){
			cout << "from B to A" << endl;
		}
		
		if (!visited[temp_A][temp_B]){
			result.push_back("pour B A");
			visited[temp_A][temp_B] = true;
			recursion (temp_A, temp_B, step_counter+1);
			result.pop_back();
		}
	}
	
	if (!visited[0][test_B]){
		if(debug){
			cout << "Empty A" << endl;
		}
		
		result.push_back("empty A");
		visited[0][test_B] = true;
		recursion (0, test_B, step_counter+1); // Empty A
		result.pop_back();
	}
	
	if (!visited[test_A][0]){
		if(debug){
			cout << "Empty B" << endl;
		}
		
		result.push_back("empty B");
		visited[test_A][0] = true;
		recursion (test_A, 0, step_counter+1); // Empty B
		result.pop_back();
	}
	
}

int main(void) {
	
	while (cin >> A >> B >> N){
		
		if (debug){
			cout << "1st Jug: " << A << endl;
			cout << "2nd Jug: " << B << endl;
			cout << "Goal: " << N << endl;
		}
		
		for(int i = 0; i < 1000; i++){
			for (int k = 0; k < 1000; k++){
				visited[i][k] = false;
			}
		}
		
		result.clear();
		visited [0][0] = true;
		visited [A][B] = true;
		completed = false;

		recursion(0, 0, 1);

	}
	
}
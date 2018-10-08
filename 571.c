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

bool debug = true;

int A, B, N;
bool visited [1000][1000];

void recursion (int test_A, int test_B){
	
	int temp_A, temp_B;
	
	if (B == N || A == N){
		cout << "success" << endl;
		return;
	}
	
	if (!visited[A][test_B]){ // fill A
		if(debug){
			cout << "fill A" << endl;
		}
		visited[A][test_B] = true;
		recursion (A, test_B);
	}
	
	if (!visited[test_A][B]){ // fill B
		if(debug){
			cout << "fill B" << endl;
		}
		visited[test_A][B] = true;
		recursion (test_A, B);
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
			visited[temp_A][temp_B] = true;
			recursion (temp_A, temp_B);
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
			visited[temp_A][temp_B] = true;
			recursion (temp_A, temp_B);
		}
	}
	
	if (!visited[0][test_B]){
		if(debug){
			cout << "Empty A" << endl;
		}
		
		visited[0][test_B] = true;
		recursion (0, test_B); // Empty A
	}
	
	if (!visited[test_A][0]){
		if(debug){
			cout << "Empty B" << endl;
		}
		
		visited[test_A][0] = true;
		recursion (test_A, 0); // Empty B
	}
	
}

int main(void) {
	
	while (cin >> A >> B >> N){
		
		if (debug){
			cout << "1st Jug: " << A << endl;
			cout << "2nd Jug: " << B << endl;
			cout << "Goal: " << N << endl;
		}
		
		visited [0][0] = true;
		visited [A][B] = true;
		recursion(0, 0);
		
		
	}
	
}
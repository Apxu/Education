#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <numeric>
#include <deque>
#include <stack>
#include <vector>
using namespace std;

deque<int> deck;
deque<int> discarded;
deque<int> train_for_validation;

int main(void) {
	int input, TMP;
	vector< stack<char> >  stacks;

	while (true){
		deck.clear();
		discarded.clear();
		
		cin >> input;
		if (input == 0){
			break;
		}
		
		for (int i = input; i > 0; i--){
			deck.push_back(i);
		}
		
		// for (int i =0; i < deck.size(); i++){
			// cout << deck[i];
		// }
		// cout << endl;
		
		while (deck.size() > 1){
			
			TMP = deck.back();
			deck.pop_back();
			discarded.push_back(TMP);
			
			TMP = deck.back();
			deck.pop_back();
			deck.push_front(TMP);

		}
		
		cout << "Discarded cards:";
		for (int i = 0; i < discarded.size(); i++){
			if (i != discarded.size() - 1){
				cout << " " << discarded[i] << ",";
			}
			else {
				cout << " " << discarded[i];
			}
			
		}
		cout << endl;
		
		cout << "Remaining card: " << deck[0] << endl;
		
	}
}
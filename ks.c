#include <iostream>
#include <set>
#include <queue>
using namespace std;

typedef struct _num {
	int a,b,c,d;
} num;

int convert(num n) {
	return n.a * 1000 + n.b * 100 + n.c * 10 + n.d;
}

int moves[8][4] = {
	{1, 0, 0, 0},
	{-1, 0, 0, 0},
	{0, 1, 0 , 0},
	{0, -1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, -1, 0},
	{0, 0, 0, 1},
	{0, 0, 0, -1}	
};

int next_int(int a, int b) {
	int result = a + b;
	
	if (result == 10) result = 0;
	else if (result == -1) result = 9;
	
	return result;
}

bool equals(num a, num b) {
	return a.a == b.a && a.b == b.b && a.c == b.c && a.d == b.d;
}

int bfs(num start, num end, set<int> restricted) {
	queue< pair<num,int> > q;
	q.push(make_pair(start, 0));
	set<int> visited;
	visited.insert(convert(start));
	
	while (!q.empty()) {
		pair<num,int> tmp = q.front();
		num next;
		q.pop();
		
		if (equals(tmp.first, end)) return tmp.second;
		
		for (int i = 0; i < 8; i++) {
			next.a = next_int(tmp.first.a, moves[i][0]);
			next.b = next_int(tmp.first.b, moves[i][1]);
			next.c = next_int(tmp.first.c, moves[i][2]);
			next.d = next_int(tmp.first.d, moves[i][3]);
			
			int ttt = convert(next);
			
			if (restricted.find(ttt) == restricted.end()) {
				if (visited.find(ttt) == visited.end()) {
					visited.insert(ttt);
					q.push(make_pair(next, tmp.second + 1));
				}
			}
		}
	}
	
	return -1;
}

int main(void) {
	int n, m;
	
	cin >> n;
	
	while (n--) {
		num start, end;
		set<int> r; // restricted
		
		cin >> start.a >> start.b >> start.c >> start.d;
		cin >> end.a >> end.b >> end.c >> end.d;
		
		cin >> m;
		num restricted;
		
		while (m--) {
			cin >> restricted.a >> restricted.b >> restricted.c >> restricted.d;
			r.insert(convert(restricted));
			
		}
		
		int result = bfs(start, end, r);
		
		cout << result << endl;
	}
	
	return 0;
}
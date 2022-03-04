#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1002

using namespace std;
int T;
int L, R, U, D, Dir;
bool MAP[MAX][MAX];
pair<int, int> Cur;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
string Control;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			MAP[i][j] = false;
		}
	}
	L = 500;
	R = 500;
	U = 500;
	D = 500;
	Dir = 0;
}

void Turtle(char Move) {
	if (Move == 'F') {
		int nextY = Cur.first + moveY[Dir];
		int nextX = Cur.second + moveX[Dir];
		Cur = make_pair(nextY, nextX);
		MAP[Cur.first][Cur.second] = true;
	}
	else if (Move == 'B') {
		int nextY = Cur.first - moveY[Dir];
		int nextX = Cur.second - moveX[Dir];
		Cur = make_pair(nextY, nextX);
		MAP[Cur.first][Cur.second] = true;
	}
	else if (Move == 'L') {
		Dir++;
		if (Dir == 4) {
			Dir = 0;
		}
	}
	else if (Move == 'R') {
		Dir--;
		if (Dir == -1) {
			Dir = 3;
		}
	}
	L = min(L, Cur.second);
	R = max(R, Cur.second);
	U = max(U, Cur.first);
	D = min(D, Cur.first);
}

int Area() {
	int W = R - L;
	int B = U - D;
	return (W * B);
}

int main() {
	FIRST
	cin >> T;
	while (T--) {
		init();
		cin >> Control;
		Cur = make_pair(500, 500);
		MAP[Cur.first][Cur.second] = true;
		for (int i = 0; i < Control.size(); i++) {
			Turtle(Control[i]);
		}
		cout << Area() << "\n";
	};

	getchar();
	getchar();
	return 0;
}
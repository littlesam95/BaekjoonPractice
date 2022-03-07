#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 51
#define LL long long
#define INF 1e9

using namespace std;
int R, C, K;
int MAP[MAX][MAX];
bool visited[MAX][MAX][2][2];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };

void Input() {
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < C; j++) {
			if (S[j] == 'U') {
				MAP[i][j] = 0;
			}
			else if (S[j] == 'L') {
				MAP[i][j] = 1;
			}
			else if (S[j] == 'D') {
				MAP[i][j] = 2;
			}
			else if (S[j] == 'R') {
				MAP[i][j] = 3;
			}
		}
	}
}

int Direction_Left(int D) {
	int newD = D + 1;
	if (newD > 3) {
		newD = 0;
	}
	return newD;
}

int Direction_Right(int D) {
	int newD = D - 1;
	if (newD < 0) {
		newD = 3;
	}
	return newD;
}


bool BFS() {
	queue<pair<pair<int, int>, pair<int, int> > > Q;
	visited[0][0][K][K] = true;
	Q.push(make_pair(make_pair(0, 0), make_pair(K, K)));

	while (!Q.empty()) {
		int CurY = Q.front().first.first;
		int CurX = Q.front().first.second;
		int CurLeft = Q.front().second.first;
		int CurRight = Q.front().second.second;
		Q.pop();

		if ((CurY == (R - 1)) && (CurX == (C - 1))) {
			return true;
		}

		int nextY, nextX;
		// 주문서를 사용 안 함
		nextY = CurY + moveY[MAP[CurY][CurX]];
		nextX = CurX + moveX[MAP[CurY][CurX]];
		if ((nextY >= 0) && (nextY < R) && (nextX >= 0) && (nextX < C) && !visited[nextY][nextX][CurLeft][CurRight]) {
			visited[nextY][nextX][CurLeft][CurRight] = true;
			Q.push(make_pair(make_pair(nextY, nextX), make_pair(CurLeft, CurRight)));
		}

		// L 주문서가 있다면 사용함
		if (CurLeft > 0) {
			int nextLeft = Direction_Left(MAP[CurY][CurX]);
			nextY = CurY + moveY[nextLeft];
			nextX = CurX + moveX[nextLeft];
			if ((nextY >= 0) && (nextY < R) && (nextX >= 0) && (nextX < C) && !visited[nextY][nextX][CurLeft - 1][CurRight]) {
				visited[nextY][nextX][CurLeft - 1][CurRight] = true;
				Q.push(make_pair(make_pair(nextY, nextX), make_pair(CurLeft - 1, CurRight)));
			}
		}

		// R 주문서가 있다면 사용함
		if (CurRight > 0) {
			int nextRight = Direction_Right(MAP[CurY][CurX]);
			nextY = CurY + moveY[nextRight];
			nextX = CurX + moveX[nextRight];
			if ((nextY >= 0) && (nextY < R) && (nextX >= 0) && (nextX < C) && !visited[nextY][nextX][CurLeft][CurRight - 1]) {
				visited[nextY][nextX][CurLeft][CurRight - 1] = true;
				Q.push(make_pair(make_pair(nextY, nextX), make_pair(CurLeft, CurRight - 1)));
			}
		}
	};

	return false;
}

void Find_Answer() {
	if (BFS()) {
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
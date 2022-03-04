#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55
#define LL long long
#define INF 1e9

using namespace std;
int N, L, R;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
bool Flag = true;
int answer = 0;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = false;
		}
	}
}

void BFS(int Y, int X) {
	int Sum = 0, Cnt = 0;
	queue<pair<int, int> > Q1, Q2;
	visited[Y][X] = true;
	Q1.push(make_pair(Y, X));
	Q2.push(make_pair(Y, X));

	while (!Q1.empty()) {
		int CurY = Q1.front().first;
		int CurX = Q1.front().second;
		Q1.pop();

		Sum += MAP[CurY][CurX];
		Cnt += 1;
		for (int i = 0; i < 4; i++) {
			int nextY = CurY + moveY[i];
			int nextX = CurX + moveX[i];
			if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < N) && (!visited[nextY][nextX]) 
				&& (abs(MAP[CurY][CurX] - MAP[nextY][nextX]) >= L) && (abs(MAP[CurY][CurX] - MAP[nextY][nextX]) <= R)) {
				visited[nextY][nextX] = true;
				Q1.push(make_pair(nextY, nextX));
				Q2.push(make_pair(nextY, nextX));
			}
		}
	};

	int Val = Sum / Cnt;
	while (!Q2.empty()) {
		int CurY = Q2.front().first;
		int CurX = Q2.front().second;
		Q2.pop();
		MAP[CurY][CurX] = Val;
	};
}

int main() {
	FIRST
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	while (1) {
		Flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					bool Flag2 = false;
					for (int k = 0; k < 4; k++) {
						int nextY = i + moveY[k];
						int nextX = j + moveX[k];
						if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < N) 
							&& (abs(MAP[i][j] - MAP[nextY][nextX]) >= L) && (abs(MAP[i][j] - MAP[nextY][nextX]) <= R)) {
							Flag2 = true;
							break;
						}
					}
					if (Flag2) {
						BFS(i, j);
						Flag = true;
					}
				}
			}
		}
		if (Flag) {
			answer++;
			init();
		}
		else {
			break;
		}
	};

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
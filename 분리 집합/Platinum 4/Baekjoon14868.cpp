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
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define N_MAX 2001
#define K_MAX 100001
#define LL long long
#define INF 2e9

using namespace std;
int N, K, C;
int visited[N_MAX][N_MAX];
queue<pair<int, int> > Q;
queue<pair<int, int> > P;
int parent[K_MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = 0;

void init() {
	for (int i = 0; i < K_MAX; i++) {
		parent[i] = -1;
	}
}

int Find_Group(int X) {
	if (parent[X] == -1) {
		return X;
	}
	return parent[X] = Find_Group(parent[X]);
}

void Union_Group(int X, int Y) {
	X = Find_Group(X);
	Y = Find_Group(Y);
	if (X != Y) {
		parent[X] = Y;
	}
}

bool BFS() {
	while (!Q.empty()) {
		int CurY = Q.front().first;
		int CurX = Q.front().second;
		Q.pop();

		P.push(make_pair(CurY, CurX));

		for (int i = 0; i < 4; i++) {
			int nextY = CurY + moveY[i];
			int nextX = CurX + moveX[i];
			if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= N)) {
				if (visited[nextY][nextX] > 0) {
					int CurN = visited[CurY][CurX];
					int nextN = visited[nextY][nextX];
					if (Find_Group(CurN) != Find_Group(nextN)) {
						Union_Group(CurN, nextN);
						C--;
					}
				}
			}
		}
	};

	if (C == 1) {
		return false;
	}

	while (!P.empty()) {
		int CurY = P.front().first;
		int CurX = P.front().second;
		P.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = CurY + moveY[i];
			int nextX = CurX + moveX[i];
			if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= N)) {
				if (visited[nextY][nextX] == 0) {
					visited[nextY][nextX] = visited[CurY][CurX];
					Q.push(make_pair(nextY, nextX));
				}
			}
		}
	};
	return true;
}

int main() {
	FIRST
	init();
	cin >> N >> K;
	C = K;
	for (int i = 1; i <= K; i++) {
		int X, Y;
		cin >> X >> Y;
		visited[N + 1 - Y][X] = i;
		Q.push(make_pair(N + 1 - Y, X));
	}
	while (1) {
		bool Flag = BFS();
		if (!Flag) {
			break;
		}
		answer++;
	};
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 81
#define INF 1e9+7

using namespace std;
int C, N, M, Blank_Sum;
int MAP[MAX][MAX];
int moveY[4] = { 1,0,-1,-1,0,1 };
int moveX[4] = { -1,-1,-1,1,1,1 };
int WORK[MAX * MAX];
bool visited[MAX * MAX];
vector<int> Graph[MAX * MAX];
int answer = 0;

void init() {
	for (int i = 0; i < (MAX * MAX); i++) {
		WORK[i] = -1;
		Graph[i].clear();
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			MAP[i][j] = 0;
		}
	}
	answer = 0;
	Blank_Sum = 0;
}

bool DFS(int E) {
	for (auto i : Graph[E]) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		if ((WORK[i] == -1) || DFS(WORK[i])) {
			WORK[i] = E;
			return true;
		}
	}
	return false;
}

void Make_Number() {
	int Y, X;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = 0; k < 6; k++) { // (i+1,j-1), (i+1,j+1) 칸과 간선으로 잇지 않는다면 마지막 최대 매칭이 보장되지 않을 수 있다.
				if (MAP[i][j] == 1) {
					Y = i;
					X = j;
					int nextY = i + moveY[k];
					int nextX = j + moveX[k];
					if ((nextY < 1) || (nextY > N) || (nextX < 1) || (nextX > M)) {
						continue;
					}
					if (MAP[nextY][nextX] == 1) {
						Graph[Y * 80 + j].push_back(nextY * 80 + nextX);
					}
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> C;
	while (C--) {
		init();
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				char S;
				cin >> S;
				if (S == 'x') {
					MAP[i][j] = 0;
				}
				else if (S == '.') {
					MAP[i][j] = 1;
					Blank_Sum++;
				}
			}
		}
		Make_Number();
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j += 2) {
				if (MAP[i][j] == 1) {
					memset(visited, false, sizeof visited);
					visited[i * 80 + j] = true;
					if (DFS(i * 80 + j)) {
						answer++;
					}
				}
			}
		}
		cout << Blank_Sum - answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}
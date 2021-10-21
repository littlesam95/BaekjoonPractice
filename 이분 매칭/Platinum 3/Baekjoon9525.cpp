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
#define MAX 101
#define INF 1e9+7

using namespace std;
int N;
int MAP[MAX][MAX];
int Dir_Count[2] = { 0,0 };
int moveY[2] = { 1,0 };
int moveX[2] = { 0,1 };
int Number[MAX][MAX][2];
int WORK[MAX * MAX];
bool visited[MAX * MAX];
set<int> Graph[MAX * MAX];
int answer = 0;

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

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char C;
			cin >> C;
			if (C == 'X') {
				MAP[i][j] = 0;
			}
			else if (C == '.') {
				MAP[i][j] = 1;
			}
		}
	}
	int Y, X;
	// 아랫 방향으로 이동
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j] == 1) { // 빈 칸일 때
				if (Number[i][j][0] == 0) { // i행 j열 아랫 방향일 때 번호가 아직 정해지지 않았을 때
					Y = i;
					X = j;
					Number[Y][X][0] = ++Dir_Count[0]; // 아랫 방향으로 향할 때 i행 j열 칸의 번호를 지정
					while (1) { // 아랫 방향으로 계속 이동하면서 폰에 가로막힐 때까지 동일한 번호를 매긴다.
						Y++;
						if ((Y >= 1) && (Y <= N) && (X >= 1) && (X <= N)) {
							if (MAP[Y][X] == 1) {
								Number[Y][X][0] = Dir_Count[0];
							}
							else {
								break;
							}
						}
						else {
							break;
						}
					};
				}
			}
		}
	}
	// 오른쪽 방향으로 이동
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j] == 1) {
				if (Number[i][j][1] == 0) {
					Y = i;
					X = j;
					Number[Y][X][1] = ++Dir_Count[1];
					while (1) {
						X++;
						if ((Y >= 1) && (Y <= N) && (X >= 1) && (X <= N)) {
							if (MAP[Y][X] == 1) {
								Number[Y][X][1] = Dir_Count[1];
							}
							else {
								break;
							}
						}
						else {
							break;
						}
					};
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j] == 1) { // 룩을 놓을 수 있는 빈 칸일 때
				Graph[Number[i][j][0]].insert(Number[i][j][1] + Dir_Count[0]); // 아랫 방향으로 이동할 때 번호 정점과 윗 방향으로 이동할 때 번호 정점을 간선으로 연결
			}
		}
	}
	memset(WORK, -1, sizeof WORK);
	for (int i = 1; i <= Dir_Count[0]; i++) { // 1번부터 아랫 방향으로 이동하면서 매긴 번호의 최대치까지 탐색
		memset(visited, false, sizeof visited);
		if (DFS(i)) {
			answer++;
		}
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
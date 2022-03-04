#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 31
#define INF 2e9

using namespace std;
int N, M, H;
bool visited[11][MAX]; // i번째 세로선과 i+1번째 세로선이 j번째 가로선에서 만남
int answer = INF;

inline bool PlayGame() { // inline 키워드를 추가하면 시간초과안남
	for (int i = 1; i <= N; i++) {
		int nowN = i;
		for (int j = 1; j <= H; j++) {
			if (visited[nowN][j]) {
				nowN++;
			}
			else if (visited[nowN - 1][j]) {
				nowN--;
			}
		}
		if (nowN != i) {
			return false;
		}
	}
	return true;
}

void DFS(int idx, int depth) {
	if (depth > 3) {
		return;
	}
	if (PlayGame()) {
		answer = min(answer, depth);
		return;
	}

	for (int i = idx; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if ((!visited[j][i]) && (!visited[j - 1][i]) && (!visited[j + 1][i])) {
				visited[j][i] = true;
				DFS(i, depth + 1);
				visited[j][i] = false;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		visited[B][A] = true;
	}
	DFS(1, 0);
	if (answer != INF) {
		cout << answer << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}
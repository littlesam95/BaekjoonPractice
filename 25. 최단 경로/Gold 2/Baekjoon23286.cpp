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
#define MAX 301
#define LL long long
#define INF 1e9

using namespace std;
int N, M, T;
int DP[MAX][MAX];

void Input() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			DP[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int U, V, H;
		cin >> U >> V >> H;
		DP[U][V] = H;
	}
}

void Settings() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				DP[i][j] = min(DP[i][j], max(DP[i][k], DP[k][j]));
			}
		}
	}
}

void Query() {
	for (int i = 0; i < T; i++) {
		int S, E;
		cin >> S >> E;
		if (DP[S][E] == INF) {
			cout << -1 << "\n";
		}
		else {
			cout << DP[S][E] << "\n";
		}
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Query();

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1001

using namespace std;
int N, M;
char arr[MAX][MAX];
int dp[MAX][MAX];
int moveY[3] = { 1,0,-1 };
int moveX[3] = { 1,1,1 };
int answer = -1;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			dp[i][j] = -1;
		}
	}
}

void dfs() {
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++) {
			if (arr[i][j] == '#') {
				continue;
			}
			for (int k = 0; k < 3; k++) {
				int next_y = i - moveY[k];
				int next_x = j - moveX[k];
				if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M) && (dp[next_y][next_x] != -1)) {
					if (arr[next_y][next_x] == 'C') {
						dp[i][j] = max(dp[i][j], 1 + dp[next_y][next_x]);
					}
					else {
						dp[i][j] = max(dp[i][j], dp[next_y][next_x]);
					}
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			arr[i][j] = S[j];
			if (arr[i][j] == 'R') {
				arr[i][j] = '.';
				dp[i][j] = 0;
			}
		}
	}
	dfs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'O') {
				answer = max(answer, dp[i][j]);
			}
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[33][33] = { 0, };
long long dp[33][33][3] = { 0, };

void init() {
	for (int i = 0; i < 33; i++) {
		for (int j = 0; j < 33; j++) {
			for (int k = 0; k < 3; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
}

long long dfs(int y, int x, int state) { // state 가로 0, 세로 1, 대각선 2
	if (dp[y][x][state] != -1) {
		return dp[y][x][state];
	}
	if (y == N && x == N) {
		return 1;
	}

	dp[y][x][state] = 0;
	if (state == 0) {
		if ((y > 0) && (y <= N) && (x + 1 > 0) && (x + 1 <= N)) {
			if (arr[y][x + 1] == 0) {
				dp[y][x][state] = dp[y][x][state] + dfs(y, x + 1, state);
			}
		}
		if ((y + 1 > 0) && (y + 1 <= N) && (x + 1 > 0) && (x + 1 <= N)) {
			if (arr[y + 1][x + 1] == 0 && arr[y][x + 1] == 0 && arr[y + 1][x] == 0) {
				dp[y][x][state] = dp[y][x][state] + dfs(y + 1, x + 1, 2);
			}
		}
	}
	else if (state == 1) {
		if ((y + 1 > 0) && (y + 1 <= N) && (x > 0) && (x <= N)) {
			if (arr[y + 1][x] == 0) {
				dp[y][x][state] = dp[y][x][state] + dfs(y + 1, x, state);
			}
		}
		if ((y + 1 > 0) && (y + 1 <= N) && (x + 1 > 0) && (x + 1 <= N)) {
			if (arr[y + 1][x + 1] == 0 && arr[y][x + 1] == 0 && arr[y + 1][x] == 0) {
				dp[y][x][state] = dp[y][x][state] + dfs(y + 1, x + 1, 2);
			}
		}
	}
	else if (state == 2) {
		if ((y > 0) && (y <= N) && (x + 1 > 0) && (x + 1 <= N)) {
			if (arr[y][x + 1] == 0) {
				dp[y][x][state] = dp[y][x][state] + dfs(y, x + 1, 0);
			}
		}
		if ((y + 1 > 0) && (y + 1 <= N) && (x > 0) && (x <= N)) {
			if (arr[y + 1][x] == 0) {
				dp[y][x][state] = dp[y][x][state] + dfs(y + 1, x, 1);
			}
		}
		if ((y + 1 > 0) && (y + 1 <= N) && (x + 1 > 0) && (x + 1 <= N)) {
			if (arr[y + 1][x + 1] == 0 && arr[y][x + 1] == 0 && arr[y + 1][x] == 0) {
				dp[y][x][state] = dp[y][x][state] + dfs(y + 1, x + 1, state);
			}
		}
	}

	return dp[y][x][state];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	cout << dfs(1, 2, 0) << "\n";

	getchar();
	getchar();
	return 0;
}
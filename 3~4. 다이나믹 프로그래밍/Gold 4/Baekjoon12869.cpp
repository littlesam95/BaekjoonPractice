#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 61

using namespace std;
int N;
int arr[3];
int dp[MAX][MAX][MAX];
int answer;

void init() {
	for (int i = 0; i < 3; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < MAX; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
}

int dfs(int X, int Y, int Z) {
	if (X < 0) {
		X = 0;
	}
	if (Y < 0) {
		Y = 0;
	}
	if (Z < 0) {
		Z = 0;
	}
	if ((X == 0) && (Y == 0) && (Z == 0)) {
		return 0;
	}
	if (dp[X][Y][Z] != -1) {
		return dp[X][Y][Z];
	}
	dp[X][Y][Z] = INT_MAX;
	dp[X][Y][Z] = min(dp[X][Y][Z], dfs(X - 9, Y - 3, Z - 1) + 1);
	dp[X][Y][Z] = min(dp[X][Y][Z], dfs(X - 9, Y - 1, Z - 3) + 1);
	dp[X][Y][Z] = min(dp[X][Y][Z], dfs(X - 3, Y - 9, Z - 1) + 1);
	dp[X][Y][Z] = min(dp[X][Y][Z], dfs(X - 3, Y - 1, Z - 9) + 1);
	dp[X][Y][Z] = min(dp[X][Y][Z], dfs(X - 1, Y - 3, Z - 9) + 1);
	dp[X][Y][Z] = min(dp[X][Y][Z], dfs(X - 1, Y - 9, Z - 3) + 1);
	return dp[X][Y][Z];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cout << dfs(arr[0], arr[1], arr[2]) << "\n";

	getchar();
	getchar();
	return 0;
}
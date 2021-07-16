#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int T;
int arr[1001];
int dp[1001][1001][3] = { 0, };

void init() {
	for (int i = 0; i <= 1000; i++) {
		arr[i] = 0;
	}

	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			for (int k = 0; k <= 2; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
}

int dfs(int left, int right, int turn) {
	if (dp[left][right][turn] != -1) {
		return dp[left][right][turn];
	}
	if (left >= right) {
		if (turn == 1) {
			return dp[left][right][turn] = arr[left];
		}
		else {
			return dp[left][right][turn] = 0;
		}
	}

	if (turn == 1) {
		dp[left][right][turn] = max(arr[left] + dfs(left + 1, right, 2), arr[right] + dfs(left, right - 1, 2));
	}
	else if (turn == 2) {
		dp[left][right][turn] = min(dfs(left + 1, right, 1), dfs(left, right - 1, 1));
	}

	return dp[left][right][turn];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		int N;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		cout << dfs(1, N, 1) << "\n";
	};

	getchar();
	getchar();
	return 0;
}
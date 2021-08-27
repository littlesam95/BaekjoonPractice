#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 10001
#define INF 2e9

using namespace std;
int N, M;
int arr[MAX];
int dp[MAX][300];
int answer;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 300; j++) {
			dp[i][j] = -1;
		}
	}
}

int dfs(int x, int speed) {
	if (x >= N) {
		return 0;
	}
	if (dp[x][speed] != -1) {
		return dp[x][speed];
	}
	dp[x][speed] = INF;
	if (x == 1) {
		dp[x][speed] = min(dp[x][speed], dfs(x + speed, speed) + 1);
	}
	else {
		int next_x = x + speed;
		if ((next_x >= 1) && (next_x <= N) && (arr[next_x] != -1)) {
			dp[x][speed] = min(dp[x][speed], dfs(next_x, speed) + 1);
		}
		next_x = x + speed - 1;
		if (speed - 1 > 0) {
			if ((next_x >= 1) && (next_x <= N) && (arr[next_x] != -1)) {
				dp[x][speed] = min(dp[x][speed], dfs(next_x, speed - 1) + 1);
			}
		}
		next_x = x + speed + 1;
		if ((next_x >= 1) && (next_x <= N) && (arr[next_x] != -1)) {
			dp[x][speed] = min(dp[x][speed], dfs(next_x, speed + 1) + 1);
		}
	}

	return dp[x][speed];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		arr[num] = -1;
	}
	answer = dfs(1, 1);
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
#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N, M;
bool arr[101] = { 0, };
int dp[101][101];

void init() {
	for (int i = 0; i < 101; i++) {
		arr[i] = true;
	}
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dp[i][j] = -1;
		}
	}
}

int dfs(int day, int coupon) {
	if (day >= N + 1) {
		return 0;
	}

	if (dp[day][coupon] != -1) {
		return dp[day][coupon];
	}
	if (!arr[day]) {
		dp[day][coupon] = dfs(day + 1, coupon);
	}
	else {
		dp[day][coupon] = INT_MAX;
		dp[day][coupon] = min(dp[day][coupon], dfs(day + 1, coupon) + 10000);
		dp[day][coupon] = min(dp[day][coupon], dfs(day + 3, coupon + 1) + 25000);
		dp[day][coupon] = min(dp[day][coupon], dfs(day + 5, coupon + 2) + 37000);
		if (coupon >= 3) {
			dp[day][coupon] = min(dp[day][coupon], dfs(day + 1, coupon - 3));
		}
	}

	return dp[day][coupon];
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
		arr[num] = false;
	}
	cout << dfs(1, 0) << "\n";

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int arr[101];
int c[101];
int dp[101][10001] = { 0, };
int sum_cost = 0;
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
		sum_cost += c[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= sum_cost; j++) {
			if (j >= c[i]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - c[i]] + arr[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	for (int i = 1; i <= sum_cost; i++) {
		if (dp[N][i] >= M) {
			answer = i;
			break;
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
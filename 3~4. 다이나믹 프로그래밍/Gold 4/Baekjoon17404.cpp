#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int arr[1001][4];
int dp[1001][4] = { 0, };
int answer = INT_MAX;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][1] >> arr[i][2] >> arr[i][3];
	}
	for (int color = 1; color <= 3; color++) {
		for (int i = 1; i <= 3; i++) {
			if (i == color) {
				dp[1][i] = arr[1][i];
			}
			else {
				dp[1][i] = 1000001;
			}
		}
		for (int i = 2; i <= N; i++) {
			dp[i][1] = min(dp[i - 1][2], dp[i - 1][3]) + arr[i][1];
			dp[i][2] = min(dp[i - 1][1], dp[i - 1][3]) + arr[i][2];
			dp[i][3] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][3];
		}
		for (int i = 1; i <= 3; i++) {
			if (i == color) {
				continue;
			}
			answer = min(answer, dp[N][i]);
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
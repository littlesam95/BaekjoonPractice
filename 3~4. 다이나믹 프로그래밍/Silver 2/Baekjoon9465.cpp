#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		int n;
		int arr[2][10001];
		int dp[2][10001] = { 0, };
		int answer = 0;
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = arr[0][1];
		dp[1][1] = arr[1][1];
		for (int i = 2; i <= n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
		}
		answer = max(dp[0][n], dp[1][n]);
		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}
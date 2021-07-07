#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int arr[1001][1001];
int dp[1001][1001] = { 0, };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	dp[1][1] = arr[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i - 1 >= 1) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
			}
			if (j - 1 >= 1) {
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + arr[i][j]);
			}
			if ((i - 1 >= 1) && (j - 1 >= 1)) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i][j]);
			}
		}
	}

	cout << dp[N][M] << "\n";

	getchar();
	getchar();
	return 0;
}
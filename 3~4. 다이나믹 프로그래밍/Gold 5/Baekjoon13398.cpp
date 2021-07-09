#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[100001];
int dp[100001][2] = { 0, };
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1][0] = arr[1];
	dp[1][1] = arr[1];
	answer = arr[1];
	for (int i = 2; i <= N; i++) {
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
		answer = max(answer, dp[i][0]);
		answer = max(answer, dp[i][1]);
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			cout << dp[j][i] << " ";
		}
		cout << "\n";
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
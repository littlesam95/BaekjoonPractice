#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int n, m;
int arr[1001][1001] = { 0, };
int dp[1001][1001] = { 0, };
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < tmp.size(); j++) {
			arr[i][j + 1] = tmp[j] - '0';
			if (arr[i][j + 1] == 1) {
				dp[i][j + 1] = 1;
				answer = max(answer, dp[i][j + 1]);
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (arr[i][j] == 1) {
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
				answer = max(answer, dp[i][j]);
			}
		}
	}
	cout << answer * answer << "\n";

	getchar();
	getchar();
	return 0;
}
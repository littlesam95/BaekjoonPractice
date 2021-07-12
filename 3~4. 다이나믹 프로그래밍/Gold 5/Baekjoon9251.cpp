#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string str1, str2;
int dp[1002][1001] = { 0, };

// LCS
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str1;
	cin >> str2;
	int N = str1.size();
	int M = str2.size();
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (str2[i - 1] == str1[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	cout << dp[M][N] << "\n";

	getchar();
	getchar();
	return 0;
}
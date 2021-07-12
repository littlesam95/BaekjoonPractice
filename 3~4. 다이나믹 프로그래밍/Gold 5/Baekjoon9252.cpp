#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string str1, str2;
int dp[1001][1001] = { 0, };
string answer = "";

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> str1;
	cin >> str2;
	int N = str1.size();
	int M = str2.size();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	int tmp_n = N;
	int tmp_m = M;
	while ((tmp_n >= 1) && (tmp_m >= 1)) {
		if (dp[tmp_n][tmp_m] == dp[tmp_n - 1][tmp_m]) {
			tmp_n--;
		}
		else if (dp[tmp_n][tmp_m] == dp[tmp_n][tmp_m - 1]) {
			tmp_m--;
		}
		else {
			answer += str1[tmp_n - 1];
			tmp_m--;
			tmp_n--;
		}
	};
	reverse(answer.begin(), answer.end());
	cout << dp[N][M] << "\n";
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
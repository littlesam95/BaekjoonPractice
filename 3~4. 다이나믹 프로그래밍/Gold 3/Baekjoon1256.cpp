#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, K;
long long dp[110][110] = { 0, };
string answer = "";

void dfs(int n, int m, long long len) {
	if (n == 0) {
		for (int i = 0; i < m; i++) {
			answer += 'z';
		}
		return;
	}
	if (m == 0) {
		for (int i = 0; i < n; i++) {
			answer += 'a';
		}
		return;
	}

	if (len <= dp[n - 1][m]) {
		answer = answer + 'a';
		dfs(n - 1, m, len);
	}
	else {
		answer = answer + 'z';
		dfs(n, m - 1, len - dp[n - 1][m]);
	}
	return;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	dp[1][1] = 2;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if ((i == 0) || (j == 0)) {
				dp[i][j] = 1;
				continue;
			}
			long long a = dp[i][j] * (i + j + 1) / (i + 1);
			long long b = dp[i][j] * (i + j + 1) / (j + 1);
			dp[i + 1][j] = (a <= 1000000000) ? a : 1000000001;
			dp[i][j + 1] = (b <= 1000000000) ? b : 1000000001;
		}
	}
	if (K > dp[N][M]) {
		cout << -1 << "\n";
	}
	else {
		dfs(N, M, K);
		cout << answer << "\n";
	}

	getchar();
	getchar();
	return 0;
}

// https://huiung.tistory.com/122 Âü°íÇÔ.
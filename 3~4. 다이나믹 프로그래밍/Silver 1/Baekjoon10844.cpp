#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N;
long long dp[101][10];
long long answer = 0;

void init() {
	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	init();
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= 9; j++) {
			if (j == 9) {
				dp[i][j] = dp[i - 1][j - 1] % 1000000000;
			}
			else {
				dp[i][j] = ((dp[i - 1][j - 1] % 1000000000) + (dp[i - 1][j + 1] % 1000000000)) % 1000000000;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		answer += dp[N][i];
	}
	cout << answer % 1000000000 << "\n";

	getchar();
	getchar();
	return 0;
}
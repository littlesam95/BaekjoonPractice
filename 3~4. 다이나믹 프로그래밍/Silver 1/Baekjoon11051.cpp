#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
unsigned long long dp[1001][1001] = { 0, };
int answer = 0;

void init() {
	for (int i = 1; i <= 1000; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	init();
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			for (int k = j - 1; k < i; k++) {
				dp[i][j] += dp[k][j - 1];
			}
			dp[i][j] %= 10007;
		}
	}

	cout << dp[N][K] << "\n";

	getchar();
	getchar();
	return 0;
}
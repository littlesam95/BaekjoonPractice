#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T;
long long dp[5001] = { 0, };

void init() {
	dp[0] = 1;
	for (int i = 1; i < 5001; i++) {
		for (int j = 0; j < i; j++) {
			dp[i] += (dp[j] * dp[i - j - 1]) % 1000000007;
		}
		dp[i] %= 1000000007;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> T;
	while (T--) {
		int L;
		cin >> L;
		if (L % 2 == 0) {
			cout << dp[L / 2] % 1000000007 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	};

	getchar();
	getchar();
	return 0;
}
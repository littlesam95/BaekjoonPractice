#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int N;
long long dp[101] = { 0, };

void init() {
	for (int i = 1; i <= 6; i++) {
		dp[i] = i;
	}
	for (int i = 7; i < 101; i++) {
		long long big = 0;
		long long n1 = dp[i - 3] * 2;
		long long n2 = dp[i - 4] * 3;
		long long n3 = dp[i - 5] * 4;
		big = max(big, n1);
		big = max(big, n2);
		big = max(big, n3);
		dp[i] = big;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	cout << dp[N] << "\n";

	getchar();
	getchar();
	return 0;
}
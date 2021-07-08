#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[1001];
unsigned long long dp[1001][10] = { 0, };
int answer = 0;

void init() {
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 1; i <= 1000; i++) {
		dp[i][0] = 1;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	init();
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		answer += dp[N][i];
	}
	cout << answer % 10007 << "\n";

	getchar();
	getchar();
	return 0;
}
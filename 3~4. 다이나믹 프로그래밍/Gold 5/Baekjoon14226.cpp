#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int S;
int arr[1001];
int dp[3001] = { 0, };
int answer = 0;

void init() {
	for (int i = 1; i <= 3000; i++) {
		dp[i] = INT_MAX / 2;
	}
	dp[1] = 0;
	for (int i = 1; i <= 1000; i++) {
			for (int j = 2; j * i <= 1000; j++) {
				dp[j * i] = min(dp[j * i], dp[i] + j);
			}
			for (int j = 1000; j >= 2; j--) {
				dp[j] = min(dp[j], dp[j + 1] + 1);
			}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> S;
	cout << dp[S] << "\n";

	getchar();
	getchar();
	return 0;
}
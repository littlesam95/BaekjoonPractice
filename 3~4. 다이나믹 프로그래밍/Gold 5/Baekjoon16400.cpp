#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 40001
#define MOD 123456789

using namespace std;
int N;
int arr[MAX];
long long dp[MAX];

void init() {
	for (int i = 2; i < MAX; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= sqrt(MAX); i++) {
		arr[i * i] = 0;
	}
	for (int i = 2; i < MAX; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = (i * i); j < MAX; j += i) {
			arr[j] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	dp[0] = 1;
	for (int i = 2; i <= N; i++) {
		if (arr[i] != 0) {
			for (int j = i; j <= N; j++) {
				dp[j] = (dp[j - i] + dp[j]) % MOD;
			}
		}
	}

	cout << dp[N] % MOD << "\n";

	getchar();
	getchar();
	return 0;
}
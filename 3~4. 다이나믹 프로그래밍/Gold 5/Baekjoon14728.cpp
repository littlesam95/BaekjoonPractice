#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 10001

using namespace std;
int N, T;
int dp[MAX];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int K, S;
		cin >> K >> S;
		for (int i = T; i >= K; i--) {
			dp[i] = max(dp[i], dp[i - K] + S);
		}
	}
	cout << dp[T] << "\n";

	getchar();
	getchar();
	return 0;
}
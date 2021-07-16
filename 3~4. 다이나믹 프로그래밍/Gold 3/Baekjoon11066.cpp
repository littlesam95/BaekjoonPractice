#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int T;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		int K;
		int arr[501];
		int psum[501] = { 0, };
		int dp[501][501] = { 0, };

		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> arr[i];
			psum[i] = psum[i - 1] + arr[i];
		}
		
		for (int i = 1; i < K; i++) {
			for (int s = 1; s <= K - i; s++) {
				int e = s + i;
				dp[s][e] = INT_MAX;
				for (int mid = s; mid < e; mid++) {
					dp[s][e] = min(dp[s][e], dp[s][mid] + dp[mid + 1][e] + psum[e] - psum[s - 1]);
				}
			}
		}
		cout << dp[1][K] << "\n";
	};

	getchar();
	getchar();
	return 0;
}
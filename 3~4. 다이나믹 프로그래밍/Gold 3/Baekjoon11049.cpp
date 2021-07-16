#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int arr[501][3];
int dp[501][501];

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][1] >> arr[i][2];
	}

	for (int i = 1; i < N; i++) {
		for (int s = 1; s <= N - i; s++) {
			int e = s + i;
			dp[s][e] = INT_MAX;
			for (int mid = s; mid < e; mid++) {
				dp[s][e] = min(dp[s][e], dp[s][mid] + dp[mid + 1][e] + (arr[s][1] * arr[mid][2] * arr[e][2]));
			}
		}
	}
	cout << dp[1][N] << "\n";

	getchar();
	getchar();
	return 0;
}
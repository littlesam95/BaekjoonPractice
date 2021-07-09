#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, K;
int dp[101][100001] = { 0, };
int arr[101][2] = { 0, };

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int i = 1; i <= N; i++) {
		int W = arr[i][0];
		int V = arr[i][1];
		for (int j = 0; j <= K; j++) {
			if (j < arr[i][0]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W] + V);
			}
		}
	}

	cout << dp[N][K] << "\n";

	getchar();
	getchar();
	return 0;
}

// 모르겠어서 https://gumeum.tistory.com/25 참고함.
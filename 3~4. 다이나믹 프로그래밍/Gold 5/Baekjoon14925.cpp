#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1001

using namespace std;
int M, N;
int dp[MAX][MAX];
int answer = 0;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dp[i][j];
			if (dp[i][j] == 0) {
				dp[i][j] = 1;
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	if ((N < 2) || (M < 2)) {
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				if (dp[i][j] == 1) {
					answer = 1;
				}
			}
		}
	}
	else {
		for (int i = 1; i <= M; i++) {
			if (dp[i][1] == 1) {
				answer = 1;
			}
		}
		for (int i = 1; i <= N; i++) {
			if (dp[1][i] == 1) {
				answer = 1;
			}
		}
		for (int i = 2; i <= M; i++) {
			for (int j = 2; j <= N; j++) {
				if (dp[i][j] == 1) {
					dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					answer = max(answer, dp[i][j]);
				}
			}
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
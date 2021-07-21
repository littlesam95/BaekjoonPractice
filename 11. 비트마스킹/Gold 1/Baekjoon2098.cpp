#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int N;
int W[20][20];
int dp[1 << 20][20];
int answer;

void init() {
	for (int i = 0; i < (1 << 20); i++) {
		for (int j = 0; j < 20; j++) {
			dp[i][j] = 0;
		}
	}
}

int dfs(int visited, int S, int start) {
	if (visited == ((1 << N) - 1)) {
		if (W[S][start]) {
			return W[S][start];
		}
		else {
			return MAX;
		}
	}
	if (dp[visited][S] != 0) {
		return dp[visited][S];
	}

	int small = MAX;
	for (int i = 1; i <= N; i++) {
		if (W[S][i] == 0) {
			continue;
		}
		if (!(visited & (1 << (i - 1)))) {
			int tmp = visited | (1 << (i - 1));
			int tmp2 = W[S][i] + dfs(tmp, i, start);
			small = min(small, tmp2);
		}
	}
	if (small < MAX) {
		dp[visited][S] = small;
	}

	return small;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> W[i][j];
		}
	}
	answer = dfs((1 << 0), 1, 1);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
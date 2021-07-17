#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
char arr[501][501];
int dp[501][501] = { 0, };
bool visited[501][501] = { false, };
int answer = 0;

void init() {
	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= 500; j++) {
			dp[i][j] = -1;
		}
	}
}

int dfs(int y, int x) {
	if ((y < 1) || (y > N) || (x < 1) || (x > M)) {
		dp[y][x] = 1;
	}
	if (dp[y][x] != -1) {
		return dp[y][x];
	}
	if (visited[y][x]) {
		dp[y][x] = 0;
	}
	visited[y][x] = true;
	if (arr[y][x] == 'U') {
		dp[y][x] = dfs(y - 1, x);
	}
	else if (arr[y][x] == 'R') {
		dp[y][x] = dfs(y, x + 1);
	}
	else if (arr[y][x] == 'D') {
		dp[y][x] = dfs(y + 1, x);
	}
	else if (arr[y][x] == 'L') {
		dp[y][x] = dfs(y, x - 1);
	}
	visited[y][x] = false;
	return dp[y][x];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = tmp[j - 1];
		}
	}
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			answer += dfs(i, j);
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
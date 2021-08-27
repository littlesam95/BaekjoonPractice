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
int N;
int arr[MAX][MAX];
int dp[MAX][MAX][4];
vector<pair<int, int> > vec;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < 4; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
}

int bfs(int y, int x, int milk) {
	if ((y < 1) || (y > N) || (x < 1) || (x > N)) {
		return 0;
	}
	if (dp[y][x][milk + 1] != -1) {
		return dp[y][x][milk + 1];
	}
	dp[y][x][milk + 1] = 0;
	int next_y = y + 1;
	int next_x = x;
	if ((next_y >= 1) && (next_y <= N) && (next_x >= 1) && (next_x <= N)) {
		if (arr[next_y][next_x] == (milk + 1) % 3) {
			dp[y][x][milk + 1] = max(dp[y][x][milk + 1], bfs(next_y, next_x, (milk + 1) % 3) + 1);
		}
		dp[y][x][milk + 1] = max(dp[y][x][milk + 1], bfs(next_y, next_x, milk));
	}
	next_y = y;
	next_x = x + 1;
	if ((next_y >= 1) && (next_y <= N) && (next_x >= 1) && (next_x <= N)) {
		if (arr[next_y][next_x] == (milk + 1) % 3) {
			dp[y][x][milk + 1] = max(dp[y][x][milk + 1], bfs(next_y, next_x, (milk + 1) % 3) + 1);
		}
		dp[y][x][milk + 1] = max(dp[y][x][milk + 1], bfs(next_y, next_x, milk));
	}

	return dp[y][x][milk + 1];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	if (arr[1][1] == 0) {
		cout << bfs(1, 1, 0) + 1 << "\n";
	}
	else {
		cout << bfs(1, 1, -1) << "\n";
	}

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int arr[17][17] = { 0, };
int answer = 0;

void dfs(int y, int x, int state) { // state 가로 0, 세로 1, 대각선 2
	if (y == N && x == N) {
		answer++;
		return;
	}

	if (state == 0) {
		if (x + 1 <= N) {
			if (arr[y][x + 1] == 0) {
				dfs(y, x + 1, 0);
			}
		}
		if ((x + 1 <= N) && (y + 1 <= N)) {
			if ((arr[y + 1][x] == 0) && (arr[y][x + 1] == 0) && (arr[y + 1][x + 1] == 0)) {
				dfs(y + 1, x + 1, 2);
			}
		}
	}
	else if (state == 1) {
		if (y + 1 <= N) {
			if (arr[y + 1][x] == 0) {
				dfs(y + 1, x, 1);
			}
		}
		if ((x + 1 <= N) && (y + 1 <= N)) {
			if ((arr[y + 1][x] == 0) && (arr[y][x + 1] == 0) && (arr[y + 1][x + 1] == 0)) {
				dfs(y + 1, x + 1, 2);
			}
		}
	}
	else {
		if (x + 1 <= N) {
			if (arr[y][x + 1] == 0) {
				dfs(y, x + 1, 0);
			}
		}
		if (y + 1 <= N) {
			if (arr[y + 1][x] == 0) {
				dfs(y + 1, x, 1);
			}
		}
		if ((x + 1 <= N) && (y + 1 <= N)) {
			if ((arr[y + 1][x] == 0) && (arr[y][x + 1] == 0) && (arr[y + 1][x + 1] == 0)) {
				dfs(y + 1, x + 1, 2);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(1, 2, 0);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
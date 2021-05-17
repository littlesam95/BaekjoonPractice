#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int M, N;
int arr[1001][1001];
int moveX[4] = { 0,1,0,-1 };
int moveY[4] = { 1,0,-1,0 };
queue<pair<int, int> > q;

void bfs() {
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = y + moveY[i];
			int dx = x + moveX[i];
			if ((dx >= 0) && (dx < M) && (dy >= 0) && (dy < N) && (arr[dy][dx] == 0)) {
				arr[dy][dx] = arr[y][x] + 1;
				q.push(make_pair(dy, dx));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	bfs();
	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				count = -1;
				break;
			}
			else if (arr[i][j] > count) {
				count = arr[i][j];
			}
		}
		if (count == -1) {
			break;
		}
	}

	if (count == -1) {
		cout << count << "\n";
	}
	else {
		cout << count - 1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}
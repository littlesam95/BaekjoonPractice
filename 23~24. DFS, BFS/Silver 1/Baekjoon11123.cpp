#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int T, H, W;
char arr[101][101];
bool visited[101][101];
int moveX[4] = { -1, 0, 1, 0 };
int moveY[4] = { 0, 1, 0, -1 };
int res;

void init() {
	res = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visited[i][j] = false;
			arr[i][j] = '.';
		}
	}
}

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	res++;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < H) && (nextX >= 0) && (nextX < W)) {
				if ((!visited[nextY][nextX]) && (arr[nextY][nextX] == '#')) {
					visited[nextY][nextX] = true;
					q.push(make_pair(nextY, nextX));
				}
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;

	while (T--) {
		init();
		cin >> H >> W;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if ((!visited[i][j]) && (arr[i][j] == '#')) {
					bfs(i, j);
				}
			}
		}

		cout << res << "\n";
	};

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int M, N;
int arr[251][251] = { 0, };
bool visited[251][251] = { false, };
int moveX[8] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int moveY[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int res = 0;

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));
	res++;

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < M) && (nextX >= 0) && (nextX < N)) {
				if ((!visited[nextY][nextX]) && (arr[nextY][nextX] == 1)) {
					visited[nextY][nextX] = true;
					q.push(make_pair(nextY, nextX));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if ((!visited[i][j]) && (arr[i][j] == 1)) {
				bfs(i, j);
			}
		}
	}

	cout << res << "\n";

	getchar();
	getchar();
	return 0;
}
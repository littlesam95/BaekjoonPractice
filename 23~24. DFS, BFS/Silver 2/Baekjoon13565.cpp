#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

int M, N;
char arr[1001][1001];
bool visited[1001][1001] = { false, };
int moveX[4] = { -1, 0, 1, 0 };
int moveY[4] = { 0, 1, 0, -1 };

void bfs(int y, int x) {
	queue<pair<int, int> > q;
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + moveY[i];
			int nextX = nowX + moveX[i];
			if ((nextY >= 0) && (nextY < M) && (nextX >= 0) && (nextX < N)) {
				if ((!visited[nextY][nextX]) && (arr[nextY][nextX] == '0')) {
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

	int island = 0;

	for (int i = 0; i < N; i++) {
		if ((!visited[0][i]) && (arr[0][i] == '0')) {
			bfs(0, i);
		}
	}

	bool b = false;
	for (int i = 0; i < N; i++) {
		if (visited[M - 1][i]) {
			b = true;
			break;
		}
	}
	if (b) {
		cout << "YES" << "\n";
	}
	else {
		cout << "NO" << "\n";
	}


	getchar();
	getchar();
	return 0;
}
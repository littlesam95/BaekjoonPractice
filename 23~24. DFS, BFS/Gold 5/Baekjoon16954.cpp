#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
char arr[8][8];
char tmp[8][8][1000000];
bool visited[8][8][10];
int moveY[9] = { 0,-1,0,1,0,1,-1,1,-1 };
int moveX[9] = { 0,0,-1,0,1,1,1,-1,-1 };
int answer = 0;

void init() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < 1000000; k++) {
				tmp[i][j][k] = '.';
			}
		}
	}
}

int bfs(int y, int x) {
	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(y, x), 0));
	visited[y][x][0] = true;

	while (!q.empty()) {
		int now_y = q.front().first.first;
		int now_x = q.front().first.second;
		int now_second = q.front().second;
		q.pop();

		if ((now_y == 0) && (now_x == 7)) {
			return 1;
		}

		for (int i = 0; i < 9; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			int next_second = now_second + 1;
			if ((next_y >= 0) && (next_x < 8) && (next_x >= 0) && (next_x < 8)) {
				if ((!visited[next_y][next_x][next_second]) && (tmp[next_y][next_x][next_second] == '.') && (tmp[next_y][next_x][now_second] == '.')) {
					visited[next_y][next_x][next_second] = true;
					q.push(make_pair(make_pair(next_y, next_x), next_second));
				}
			}
		}
	};

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];
		}
	}
	init();
	for (int second = 0; second < 8; second++) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				tmp[i][j][second] = arr[i - second][j];
			}
		}
	}

	cout << bfs(7, 0) << "\n";

	getchar();
	getchar();
	return 0;
}
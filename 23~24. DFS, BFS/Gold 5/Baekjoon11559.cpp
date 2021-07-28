#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int L, R, C;
char arr[13][7];
bool visited[13][7];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
queue<pair<int, int> > q;
queue <pair<int, int> > breaking;
bool all_breaked = true;
int answer = 0;

void init() {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 7; j++) {
			visited[i][j] = false;
		}
	}
}

bool bfs(int y, int x) {
	bool flag = false;
	char this_block = arr[y][x];
	int block = 1;
	visited[y][x] = true;
	q.push(make_pair(y, x));

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();
		breaking.push(make_pair(now_y, now_x));

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < 12) && (next_x >= 0) && (next_x < 6)) {
				if ((!visited[next_y][next_x]) && (arr[next_y][next_x] == this_block)) {
					visited[next_y][next_x] = true;
					q.push(make_pair(next_y, next_x));
					block++;
				}
			}
		}
	};

	if (block >= 4) {
		while (!breaking.empty()) {
			int block_y = breaking.front().first;
			int block_x = breaking.front().second;
			breaking.pop();
			arr[block_y][block_x] = '.';
		};
		flag = true;
	}
	else {
		while (!breaking.empty()) {
			breaking.pop();
		};
	}

	return flag;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 12; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < 6; j++) {
			arr[i][j] = tmp[j];
		}
	}
	while (1) {
		init();
		all_breaked = false;
		for (int i = 11; i >= 0; i--) {
			for (int j = 0; j < 6; j++) {
				if (arr[i][j] == '.') {
					continue;
				}
				if (!visited[i][j]) {
					if (bfs(i, j)) {
						all_breaked = true;
					}
				}
			}
		}
		if (!all_breaked) {
			break;
		}
		for (int j = 0; j < 6; j++) {
			int dist = 11;
			for (int i = 11; i >= 0; i--) {
				if (arr[i][j] != '.') {
					if (dist == i) {
						dist -= 1;
						continue;
					}
					else {
						arr[dist][j] = arr[i][j];
						arr[i][j] = '.';
						dist -= 1;
					}
				}
			}
		}
		answer++;
	};
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
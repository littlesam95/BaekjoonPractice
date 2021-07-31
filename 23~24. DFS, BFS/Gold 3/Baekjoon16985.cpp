#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
int arr[5][5][5];
bool visited[5][5][5];
int tmp[5][5][5];
int moveY[6] = { -1,0,1,0,0,0 };
int moveX[6] = { 0,-1,0,1,0,0 };
int moveZ[6] = { 0,0,0,0,1,-1 };
int order[5] = { 0,1,2,3,4 };
int cmd[5];
int answer = INT_MAX;

void init() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				visited[i][j][k] = false;
			}
		}
	}
}

void circle_plate(int height, int circle) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (circle == 0) {
				tmp[order[height]][i][j] = arr[height][4 - j][i];
			}
			else if (circle == 1) {
				tmp[order[height]][i][j] = arr[height][4 - i][4 - j];
			}
			else if (circle == 2) {
				tmp[order[height]][i][j] = arr[height][j][4 - i];
			}
			else {
				tmp[order[height]][i][j] = arr[height][i][j];
			}
		}
	}
}

int bfs(int z, int y, int x) {
	if ((!tmp[0][0][0]) || (!tmp[4][4][4])) {
		return INT_MAX;
	}

	queue<pair<pair<int, int>, pair<int, int> > > q;
	visited[z][y][x] = true;
	q.push(make_pair(make_pair(z, y), make_pair(x, 0)));

	while (!q.empty()) {
		int now_z = q.front().first.first;
		int now_y = q.front().first.second;
		int now_x = q.front().second.first;
		int now_dist = q.front().second.second;
		q.pop();

		if ((now_z == 4) && (now_y == 4) && (now_x == 4)) {
			return now_dist;
		}

		for (int i = 0; i < 6; i++) {
			int next_z = now_z + moveZ[i];
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_z >= 0) && (next_z < 5) && (next_y >= 0) && (next_y < 5) && (next_x >= 0) && (next_x < 5)) {
				if ((!visited[next_z][next_y][next_x]) && (tmp[next_z][next_y][next_x])) {
					visited[next_z][next_y][next_x] = true;
					q.push(make_pair(make_pair(next_z, next_y), make_pair(next_x, now_dist + 1)));
				}
			}
		}
	};

	return INT_MAX;
}

void plate_switch(int depth) {
	if (depth == 5) {
		for (int i = 0; i < 5; i++) {
			circle_plate(i, cmd[i]);
		}
		init();
		answer = min(answer, bfs(0, 0, 0));
		return;
	}
	for (int i = 0; i < 4; i++) {
		cmd[depth] = i;
		plate_switch(depth + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int height = 0; height < 5; height++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> arr[height][i][j];
			}
		}
	}

	do {
		plate_switch(0);
	} while (next_permutation(order, order + 5));

	if (answer == INT_MAX) {
		cout << -1 << "\n";
	}
	else {
		cout << answer << "\n";
	}

	getchar();
	getchar();
	return 0;
}
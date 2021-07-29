#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M;
int arr[8][8];
int tmp[8][8];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = 0;

int bfs() {
	int tmp2[8][8];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp2[i][j] = tmp[i][j];
		}
	}
	queue<pair<int, int> > q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp2[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int now_y = q.front().first;
		int now_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M) && (tmp2[next_y][next_x] == 0)) {
				tmp2[next_y][next_x] = 2;
				q.push(make_pair(next_y, next_x));
			}
		}
	};

	int safe_zone = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!tmp2[i][j]) {
				safe_zone++;
			}
		}
	}
	return safe_zone;
}

void wall_make(int depth) {
	if (depth == 3) {
		answer = max(answer, bfs());
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) {
				tmp[i][j] = 1;
				wall_make(depth + 1);
				tmp[i][j] = 0;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < M; l++) {
						tmp[k][l] = arr[k][l];
					}
				}
				tmp[i][j] = 1;
				wall_make(1);
				tmp[i][j] = 0;
			}
		}
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
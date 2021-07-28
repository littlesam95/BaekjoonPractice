#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int L, R, C;
char arr[31][31][31];
bool visited[31][31][31];
int moveL[6] = { 0,0,0,0,1,-1 };
int moveY[6] = { -1,0,1,0,0,0 };
int moveX[6] = { 0,-1,0,1,0,0 };
int start_l, start_y, start_x;

void init() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			for (int k = 0; k < 31; k++) {
				visited[i][j][k] = false;
			}
		}
	}
}

int bfs(int l, int y, int x) {
	queue<pair<pair<int, int>, pair<int, int> > > q;
	visited[l][y][x] = true;
	q.push(make_pair(make_pair(l, 0), make_pair(y, x)));

	while (!q.empty()) {
		int now_l = q.front().first.first;
		int now_y = q.front().second.first;
		int now_x = q.front().second.second;
		int now_minute = q.front().first.second;
		q.pop();

		if (arr[now_l][now_y][now_x] == 'E') {
			return now_minute;
		}

		for (int i = 0; i < 6; i++) {
			int next_l = now_l + moveL[i];
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_l >= 0) && (next_l < L) && (next_y >= 0) && (next_y < R) && (next_x >= 0) && (next_x < C)) {
				if ((!visited[next_l][next_y][next_x]) && (arr[next_l][next_y][next_x] != '#')) {
					visited[next_l][next_y][next_x] = true;
					q.push(make_pair(make_pair(next_l, now_minute + 1), make_pair(next_y, next_x)));
				}
			}
		}
	};

	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		init();
		cin >> L >> R >> C;
		if ((L == 0) && (R == 0) && (C == 0)) {
			break;
		}
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				string tmp;
				cin >> tmp;
				for (int k = 0; k < C; k++) {
					arr[i][j][k] = tmp[k];
					if (arr[i][j][k] == 'S') {
						start_l = i;
						start_y = j;
						start_x = k;
					}
				}
			}
		}
		int answer = bfs(start_l, start_y, start_x);
		if (answer == -1) {
			cout << "Trapped!" << "\n";
		}
		else {
			cout << "Escaped in " << answer << " minute(s)." << "\n";
		}
	};

	getchar();
	getchar();
	return 0;
}
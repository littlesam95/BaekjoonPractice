#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M;
char arr[11][11];
bool visited[11][11][11][11];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int start_ry, start_rx, start_by, start_bx;
int answer = 0;

void bfs(int ry, int rx, int by, int bx) {
	queue<pair<pair<pair<int, int>, pair<int, int> >, int > > q;
	visited[ry][rx][by][bx] = true;
	q.push(make_pair(make_pair(make_pair(ry, rx), make_pair(by, bx)), 0));

	while (!q.empty()) {
		int now_ry = q.front().first.first.first;
		int now_rx = q.front().first.first.second;
		int now_by = q.front().first.second.first;
		int now_bx = q.front().first.second.second;
		int now_dist = q.front().second;
		q.pop();

		if (now_dist >= 10) {
			answer = 0;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int next_ry = now_ry;
			int next_rx = now_rx;
			int next_by = now_by;
			int next_bx = now_bx;
			int red_dist = 0;
			int blue_dist = 0;
			int next_dist = now_dist + 1;
			while ((arr[next_ry + moveY[i]][next_rx + moveX[i]] != '#') && (arr[next_ry][next_rx] != 'O')) {
				next_ry += moveY[i];
				next_rx += moveX[i];
				red_dist++;
			};
			while ((arr[next_by + moveY[i]][next_bx + moveX[i]] != '#') && (arr[next_by][next_bx] != 'O')) {
				next_by += moveY[i];
				next_bx += moveX[i];
				blue_dist++;
			};
			if (arr[next_by][next_bx] == 'O') {
				continue;
			}
			if (arr[next_ry][next_rx] == 'O') {
				answer = 1;
				return;
			}
			if ((next_ry == next_by) && (next_rx == next_bx)) {
				if (red_dist > blue_dist) {
					next_ry -= moveY[i];
					next_rx -= moveX[i];
				}
				else {
					next_by -= moveY[i];
					next_bx -= moveX[i];
				}
			}
			if (!visited[next_ry][next_rx][next_by][next_bx]) {
				visited[next_ry][next_rx][next_by][next_bx] = true;
				q.push(make_pair(make_pair(make_pair(next_ry, next_rx), make_pair(next_by, next_bx)), next_dist));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = tmp[j - 1];
			if (arr[i][j] == 'R') {
				start_ry = i;
				start_rx = j;
			}
			else if (arr[i][j] == 'B') {
				start_by = i;
				start_bx = j;
			}
		}
	}
	bfs(start_ry, start_rx, start_by, start_bx);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
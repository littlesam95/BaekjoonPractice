#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M, T;
int arr[101][101];
bool visited[101][101][2];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = INT_MAX;

void bfs(int y, int x) {
	queue<pair<pair<int, int>, pair<int, bool>> > q;
	visited[y][x][false] = true;
	q.push(make_pair(make_pair(y, x), make_pair(0, false)));

	while (!q.empty()) {
		int now_y = q.front().first.first;
		int now_x = q.front().first.second;
		int now_hour = q.front().second.first;
		bool now_have_sword = q.front().second.second;
		q.pop();

		if ((now_y == N - 1) && (now_x == M - 1)) {
			if (now_hour <= T) {
				answer = min(answer, now_hour);
			}
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M)) {
				if (now_have_sword) {
					if (!visited[next_y][next_x][now_have_sword]) {
						visited[next_y][next_x][now_have_sword] = true;
						q.push(make_pair(make_pair(next_y, next_x), make_pair(now_hour + 1, now_have_sword)));
					}
				}
				else {
					if ((!visited[next_y][next_x][now_have_sword]) && (arr[next_y][next_x] != 1)) {
						visited[next_y][next_x][now_have_sword] = true;
						if (arr[next_y][next_x] == 2) {
							q.push(make_pair(make_pair(next_y, next_x), make_pair(now_hour + 1, true)));
						}
						else {
							q.push(make_pair(make_pair(next_y, next_x), make_pair(now_hour + 1, now_have_sword)));
						}
					}
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	bfs(0, 0);
	if (answer == INT_MAX) {
		cout << "Fail" << "\n";
	}
	else {
		cout << answer << "\n";
	}

	getchar();
	getchar();
	return 0;
}
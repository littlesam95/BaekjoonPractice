#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	int y, x, things, dist;
};

int N, M;
char arr[51][51];
int tmp[51][51];
bool visited[51][51][(1 << 6)];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int start_y, start_x, end_y, end_x;
int X_size = 0;
int answer = INT_MAX;

void bfs() {
	queue<Info> q;
	visited[start_y][start_x][X_size] = true;
	q.push({ start_y,start_x,X_size,0 });

	while (!q.empty()) {
		int now_y = q.front().y;
		int now_x = q.front().x;
		int now_things = q.front().things;
		int now_dist = q.front().dist;
		q.pop();

		if ((arr[now_y][now_x] == 'E') && (now_things == 0)) {
			answer = min(answer, now_dist);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < M) && (next_x >= 0) && (next_x < N)) {
				if ((arr[next_y][next_x] != '#') && (!visited[next_y][next_x][now_things])) {
					if (arr[next_y][next_x] == 'X') {
						int next_things = now_things & ~(1 << tmp[next_y][next_x]);
						visited[next_y][next_x][now_things] = true;
						visited[next_y][next_x][next_things] = true;
						q.push({ next_y,next_x,next_things,now_dist + 1 });
					}
					else {
						visited[next_y][next_x][now_things] = true;
						q.push({ next_y,next_x,now_things,now_dist + 1 });
					}
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int X_count = 1;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < N; j++) {
			arr[i][j] = S[j];
			if (arr[i][j] == 'S') {
				start_y = i;
				start_x = j;
				tmp[i][j] = 0;
			}
			else if (arr[i][j] == 'X') {
				tmp[i][j] = X_count;
				X_count++;
			}
			else if (arr[i][j] == 'E') {
				end_y = i;
				end_x = j;
				tmp[i][j] = 0;
			}
			else if (arr[i][j] == '.') {
				tmp[i][j] = 0;
			}
			else {
				tmp[i][j] = -1;
			}

		}
	}
	for (int i = 1; i < X_count; i++) {
		X_size |= (1 << i);
	}
	bfs();
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
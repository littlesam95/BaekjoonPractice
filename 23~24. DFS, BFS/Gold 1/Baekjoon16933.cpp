#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	int y, x, breaking;
	bool state; // 0ÀÏ ¶§´Â ³·, 1ÀÏ ¶§´Â ¹ã
	int dist;
};
int N, M, K;
int arr[1000][1000];
bool visited[1000][1000][11];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = INT_MAX;

void bfs(int y, int x) {
	queue<Info> q;
	q.push({ y,x,K,false,1 });
	visited[y][x][K] = true;

	while (!q.empty()) {
		int now_y = q.front().y;
		int now_x = q.front().x;
		int now_breaking = q.front().breaking;
		bool now_state = q.front().state;
		int now_dist = q.front().dist;
		q.pop();

		if ((now_y == N - 1) && (now_x == M - 1)) {
			answer = min(answer, now_dist);
			return;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if (visited[next_y][next_x][now_breaking]) {
				continue;
			}
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < M)) {
				if ((arr[next_y][next_x] == 0) && (!visited[next_y][next_x][now_breaking])) {
					visited[next_y][next_x][now_breaking] = true;
					if (now_state) {
						q.push({ next_y,next_x,now_breaking,false,now_dist + 1 });
					}
					else {
						q.push({ next_y,next_x,now_breaking,true,now_dist + 1 });
					}
				}
				else if (arr[next_y][next_x] == 1) {
					if (now_breaking > 0) {
						if (!visited[next_y][next_x][now_breaking - 1]) {
							if (!now_state) {
								visited[next_y][next_x][now_breaking - 1] = true;
								q.push({ next_y,next_x,now_breaking - 1,true,now_dist + 1 });
							}
							else if (now_state) {
								q.push({ now_y,now_x,now_breaking,false,now_dist + 1 });
							}
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

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			arr[i][j] = tmp[j] - '0';
		}
	}
	bfs(0, 0);
	if (answer < INT_MAX) {
		cout << answer << "\n";
	}
	else if (answer == INT_MAX) {
		cout << -1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}
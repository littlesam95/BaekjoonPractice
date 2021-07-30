#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M, K;
char arr[1001][1001];
bool visited[1001][1001][11];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
int answer = -1;

void bfs(int y, int x, int K) {
	queue<pair<pair<int, int>, pair<int, int> > > q;
	visited[y][x][K] = true;
	q.push(make_pair(make_pair(y, x), make_pair(K, 1)));

	while (!q.empty()) {
		int now_y = q.front().first.first;
		int now_x = q.front().first.second;
		int now_wall = q.front().second.first;
		int now_dist = q.front().second.second;
		q.pop();

		if ((now_y == N) && (now_x == M)) {
			answer = now_dist;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if (visited[next_y][next_x][now_wall]) {
				continue;
			}
			if ((next_y > 0) && (next_y <= N) && (next_x > 0) && (next_x <= M)) {
				if (arr[next_y][next_x]) {
					if (now_wall > 0) {
						if (!visited[next_y][next_x][now_wall]) {
							visited[next_y][next_x][now_wall] = true;
							visited[next_y][next_x][now_wall - 1] = true;
							q.push(make_pair(make_pair(next_y, next_x), make_pair(now_wall - 1, now_dist + 1)));
						}
					}
				}
				else if (!arr[next_y][next_x]) {
					visited[next_y][next_x][now_wall] = true;
					q.push(make_pair(make_pair(next_y, next_x), make_pair(now_wall, now_dist + 1)));
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
	for (int i = 1; i <= N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 1; j <= M; j++) {
			arr[i][j] = stoi(tmp.substr(j - 1, 1));
		}
	}
	bfs(1, 1, K);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
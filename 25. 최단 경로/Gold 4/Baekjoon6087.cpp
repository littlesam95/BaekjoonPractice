#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int W, H;
char arr[101][101];
int dist[101][101];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
queue<pair<pair<int, int>, pair<int, int> > > q;
int answer = 0;
int start_y = -1;
int start_x = -1;
int end_y, end_x;

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dist[i][j] = INT_MAX;
		}
	}
}

void dijkstra(int y, int x) {
	for (int i = 0; i < 4; i++) {
		q.push(make_pair(make_pair(y, x), make_pair(0, i)));
	}
	dist[y][x] = 0;

	while (!q.empty()) {
		int now_y = q.front().first.first;
		int now_x = q.front().first.second;
		int now_cost = q.front().second.first;
		int now_dir = q.front().second.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			int next_cost = now_cost;
			if ((next_y >= 0) && (next_y < H) && (next_x >= 0) && (next_x < W)) {
				if (arr[next_y][next_x] != '*') {
					if (now_dir != i) {
						next_cost += 1;
					}
					if (dist[next_y][next_x] >= next_cost) {
						dist[next_y][next_x] = next_cost;
						q.push(make_pair(make_pair(next_y, next_x), make_pair(dist[next_y][next_x], i)));
					}
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < W; j++) {
			arr[i][j] = S[j];
			if ((arr[i][j] == 'C') && (start_y == -1) && (start_x == -1)) {
				start_y = i;
				start_x = j;
			}
			else if ((arr[i][j] == 'C') && (start_y > -1) && (start_x > -1)) {
				end_y = i;
				end_x = j;
			}
		}
	}
	init();
	dijkstra(start_y, start_x);
	cout << dist[end_y][end_x] << "\n";

	getchar();
	getchar();
	return 0;
}
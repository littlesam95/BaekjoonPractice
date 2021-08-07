#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int arr[126][126];
int dist[126][126];
bool visited[126][126];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
priority_queue<pair<int, pair<int, int> > > pq;
int answer;
int idx = 1;

void init() {
	for (int i = 0; i < 126; i++) {
		for (int j = 0; j < 126; j++) {
			arr[i][j] = 0;
			dist[i][j] = INT_MAX;
			visited[i][j] = false;
		}
	}
}

void dijkstra() {
	pq.push(make_pair(0, make_pair(0, 0)));
	dist[0][0] = arr[0][0];

	while (!pq.empty()) {
		int now_cost = -pq.top().first;
		int now_y = pq.top().second.first;
		int now_x = pq.top().second.second;
		pq.pop();

		if (dist[now_y][now_x] < now_cost) {
			continue;
		}
		if (visited[now_y][now_x]) {
			continue;
		}
		visited[now_y][now_x] = true;

		for (int i = 0; i < 4; i++) {
			int next_y = now_y + moveY[i];
			int next_x = now_x + moveX[i];
			if ((next_y >= 0) && (next_y < N) && (next_x >= 0) && (next_x < N)) {
				if (dist[next_y][next_x] > now_cost + arr[next_y][next_x]) {
					dist[next_y][next_x] = now_cost + arr[next_y][next_x];
					pq.push(make_pair(-dist[next_y][next_x], make_pair(next_y, next_x)));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> N;
		if (N == 0) {
			break;
		}
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
				dist[i][j] = INT_MAX;
			}
		}
		dijkstra();
		cout << "Problem " << idx << ": " << dist[0][0] + dist[N - 1][N - 1] << "\n";
		idx++;
	};

	getchar();
	getchar();
	return 0;
}
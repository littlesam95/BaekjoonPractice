#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
struct Info {
	int dest, money, hour;
};

int T;
int N, M, K;
int dist[101][10001];
vector<Info> vec[101];
priority_queue<pair<int, pair<int, int> > > pq;
int answer = 0;

void init1() {
	for (int i = 0; i < 101; i++) {
		vec[i].clear();
	}
	while (!pq.empty()) {
		pq.pop();
	};
}

void init2() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 10001; j++) {
			dist[i][j] = INT_MAX;
		}
	}
}

void dijkstra(int x, int m) {
	init2();
	pq.push(make_pair(0, make_pair(x, m)));
	dist[x][m] = 0;

	while (!pq.empty()) {
		int now_cost = -pq.top().first;
		int now_x = pq.top().second.first;
		int now_money = pq.top().second.second;
		pq.pop();

		if (dist[now_x][now_money] < now_cost) {
			continue;
		}
		for (int i = 0; i < vec[now_x].size(); i++) {
			int next_x = vec[now_x][i].dest;
			int next_cost = vec[now_x][i].hour;
			int next_money = now_money - vec[now_x][i].money;
			if (next_money >= 0) {
				if (dist[next_x][next_money] > now_cost + next_cost) {
					dist[next_x][next_money] = now_cost + next_cost;
					pq.push(make_pair(-dist[next_x][next_money], make_pair(next_x, next_money)));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init1();
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			int u, v, c, d;
			cin >> u >> v >> c >> d;
			vec[u].push_back({ v,c,d });
		}
		dijkstra(1, M);
		int answer = INT_MAX;
		for (int i = 0; i <= M; i++) {
			if (dist[N][i] < INT_MAX) {
				answer = min(answer, dist[N][i]);
			}
		}
		if (answer == INT_MAX) {
			cout << "Poor KCM" << "\n";
		}
		else {
			cout << answer << "\n";
		}
	};

	getchar();
	getchar();
	return 0;
}
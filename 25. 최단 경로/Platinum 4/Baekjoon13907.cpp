#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 9876543210

using namespace std;
struct Info {
	int x, node_count, cost;
};

struct comp {
	bool operator()(Info&A, Info&B) {
		return (A.cost > B.cost);
	}
};

int N, M, K, S, D;
int money_sum = 0;
int dist[1001][1001]; // [각 지점][각 지점까지 도달하는 데 거친 Node의 수]
vector<pair<int, int> > vec[1001];
priority_queue<Info, vector<Info>, comp> pq;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = MAX;
		}
	}
	while (!pq.empty()) {
		pq.pop();
	};
}

void dijkstra(int x) {
	init();
	pq.push({ x,0,0 });
	dist[x][0] = 0;

	while (!pq.empty()) {
		int now_x = pq.top().x;
		int now_node_count = pq.top().node_count;
		int now_cost = pq.top().cost;
		pq.pop();

		if (dist[now_x][now_node_count] < now_cost) {
			continue;
		}

		for (int i = 0; i < vec[now_x].size(); i++) {
			int next_x = vec[now_x][i].first;
			int next_cost = vec[now_x][i].second;
			if (dist[next_x][now_node_count + 1] > now_cost + next_cost) {
				dist[next_x][now_node_count + 1] = now_cost + next_cost;
				pq.push({ next_x,now_node_count + 1,(now_cost + next_cost) });
			}
		}
	};
}

void calc() {
	int answer = MAX;
	for (int i = 1; i < N; i++) {
		int val = dist[D][i] + (i * money_sum);
		answer = min(answer, val);
	}
	cout << answer << "\n";
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	cin >> S >> D;
	for (int i = 0; i < M; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		vec[a].push_back(make_pair(b, w));
		vec[b].push_back(make_pair(a, w));
	}
	dijkstra(S);
	calc();
	for (int i = 0; i < K; i++) {
		int P;
		cin >> P;
		money_sum += P;
		calc();
	}

	getchar();
	getchar();
	return 0;
}
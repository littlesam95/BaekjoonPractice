#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int T, N, D, C;
int dist[10001];
vector<pair<int, int> > vec[10001];
priority_queue<pair<int, int> > pq;
int answer_size, answer_time;

void init() {
	for (int i = 0; i < 10001; i++) {
		dist[i] = INT_MAX;
		vec[i].clear();
	}
	while (!pq.empty()) {
		pq.pop();
	}
	answer_size = 0;
	answer_time = 0;
}

void dijkstra(int start) {
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int now_cost = -pq.top().first;
		int now_computer = pq.top().second;
		pq.pop();

		if (dist[now_computer] < now_cost) {
			continue;
		}
		for (int i = 0; i < vec[now_computer].size(); i++) {
			int next_computer = vec[now_computer][i].first;
			int next_cost = vec[now_computer][i].second;
			if (dist[next_computer] > now_cost + next_cost) {
				dist[next_computer] = now_cost + next_cost;
				pq.push(make_pair(-dist[next_computer], next_computer));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> N >> D >> C;
		init();
		for (int i = 0; i < D; i++) {
			int n1, n2, n3;
			cin >> n1 >> n2 >> n3;
			vec[n2].push_back(make_pair(n1, n3));
		}
		dijkstra(C);
		for (int i = 1; i <= N; i++) {
			if (dist[i] < INT_MAX) {
				answer_size++;
				answer_time = max(dist[i], answer_time);
			}
		}
		cout << answer_size << " " << answer_time << "\n";
	};

	getchar();
	getchar();
	return 0;
}
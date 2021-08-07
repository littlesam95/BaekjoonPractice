#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int V, E, K;
int dist[20005];
vector<pair<int, int> > vec[20005];
priority_queue<pair<int, int> > pq;

void dijkstra() {
	pq.push(make_pair(0, K));
	dist[K] = 0;

	while (!pq.empty()) {
		int now_cost = -pq.top().first;
		int now_vertex = pq.top().second;
		pq.pop();

		for (int i = 0; i < vec[now_vertex].size(); i++) {
			int next_vertex = vec[now_vertex][i].first;
			int next_cost = vec[now_vertex][i].second;
			if (dist[next_vertex] > now_cost + next_cost) {
				dist[next_vertex] = now_cost + next_cost;
				pq.push(make_pair(-dist[next_vertex], next_vertex));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		vec[n1].push_back(make_pair(n2, n3));
	}
	for (int i = 1; i <= V; i++) {
		dist[i] = INT_MAX;
	}
	dijkstra();
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INT_MAX) {
			cout << "INF" << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, E, V1, V2;
int dist[801];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
vector<pair<int, int> > vec[801];
priority_queue<pair<int, int> > pq;
bool flag1 = true;
bool flag2 = true;
int answer1 = INT_MAX;
int answer2 = INT_MAX;
int answer;

void init() {
	for (int i = 1; i <= N; i++) {
		dist[i] = INT_MAX;
	}
}

void dijkstra(int start) {
	init();
	pq.push(make_pair(0, start));
	dist[start] = 0;

	while (!pq.empty()) {
		int now_cost = -pq.top().first;
		int now_vertex = pq.top().second;
		pq.pop();

		if (dist[now_vertex] < now_cost) {
			continue;
		}

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

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		vec[n1].push_back(make_pair(n2, n3));
		vec[n2].push_back(make_pair(n1, n3));
	}
	cin >> V1 >> V2;
	dijkstra(1); // 1 -> V1, V2로 가는 데 걸리는 최단 경로
	answer1 = dist[V1];
	answer2 = dist[V2];
	if (answer1 == INT_MAX) {
		flag1 = false;
	}
	if (answer2 == INT_MAX) {
		flag2 = false;
	}
	dijkstra(V1); // V1 -> V2, N으로 가는 데 걸리는 최단 경로
	if (flag1) {
		answer1 += dist[V2];
	}
	if (flag2) {
		answer2 += dist[V2];
	}
	dijkstra(V2);
	if (flag1) {
		answer1 += dist[N];
	}
	dijkstra(V1); // V2 -> N으로 가는 데 걸리는 최단 경로
	if (flag2) {
		answer2 += dist[N];
	}
	if ((!flag1) && (!flag2)) {
		answer = -1;
	}
	else {
		answer = min(answer1, answer2);
	}
	if (answer == INT_MAX) {
		cout << -1 << "\n";
	}
	else {
		cout << answer << "\n";
	}

	getchar();
	getchar();
	return 0;
}
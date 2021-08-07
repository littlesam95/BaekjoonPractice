#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M, R;
int item[101];
int dist[10001];
vector<pair<int, int> > vec[10001];
priority_queue<pair<int, int> > pq;
int answer = 0;

void init() {
	for (int i = 0; i < 10001; i++) {
		dist[i] = INT_MAX;
	}
	while (!pq.empty()) {
		pq.pop();
	}
}

void dijkstra(int start) {
	int now_answer = 0;
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
	for (int i = 1; i <= N; i++) {
		if (dist[i] <= M) {
			now_answer += item[i];
		}
	}
	answer = max(answer, now_answer);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++) {
		cin >> item[i];
	}
	for (int i = 0; i < R; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		vec[n2].push_back(make_pair(n1, n3));
		vec[n1].push_back(make_pair(n2, n3));
	}
	for (int i = 1; i <= N; i++) {
		init();
		dijkstra(i);
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
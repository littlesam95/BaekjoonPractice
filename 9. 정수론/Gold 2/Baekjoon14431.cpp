#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1000000000

using namespace std;
int N, SY, SX, EY, EX;
int arr[8501];
int dist[4003];
vector<pair<pair<int, int>, int> > vec;
vector<pair<int, int> > edge_info[4003];
priority_queue<pair<int, int> > pq;
int answer = 0;

void init() {
	for (int i = 2; i <= 8500; i++) {
		arr[i] = i;
	}
	for (int i = 2; i <= sqrt(8500); i++) {
		arr[i * i] = 0;
	}
	for (int i = 2; i <= 8500; i++) {
		if (arr[i] != 0) {
			for (int j = (i * i); j <= 8500; j += i) {
				arr[j] = 0;
			}
		}
	}
	for (int i = 0; i < 4003; i++) {
		dist[i] = MAX;
	}
}

void bfs() {
	pq.push(make_pair(0, 0));
	dist[0] = 0;

	while (!pq.empty()) {
		int now_cost = -pq.top().first;
		int now_idx = pq.top().second;
		pq.pop();

		if (dist[now_idx] < now_cost) {
			continue;
		}

		for (int i = 0; i < edge_info[now_idx].size(); i++) {
			int next_idx = edge_info[now_idx][i].first;
			int next_cost = edge_info[now_idx][i].second;
			if (dist[next_idx] > now_cost + next_cost) {
				dist[next_idx] = now_cost + next_cost;
				pq.push(make_pair(-dist[next_idx], next_idx));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> SY >> SX >> EY >> EX;
	cin >> N;
	vec.push_back(make_pair(make_pair(SY, SX), 0));
	for (int i = 1; i <= N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vec.push_back(make_pair(make_pair(n1, n2), i));
	}
	vec.push_back(make_pair(make_pair(EY, EX), N + 1));
	for (int i = 0; i < vec.size(); i++) {
		int now_y = vec[i].first.first;
		int now_x = vec[i].first.second;
		for (int j = 0; j < vec.size(); j++) {
			if (i == j) {
				continue;
			}
			int next_y = vec[j].first.first;
			int next_x = vec[j].first.second;
			int next_idx = vec[j].second;
			int next_cost = sqrt(((now_y - next_y) * (now_y - next_y)) + ((now_x - next_x) * (now_x - next_x)));
			if (arr[next_cost] != 0) {
				edge_info[i].push_back(make_pair(next_idx, next_cost));
			}
		}
	}
	bfs();
	if (dist[N + 1] == MAX) {
		cout << -1 << "\n";
	}
	else {
		cout << dist[N + 1] << "\n";
	}

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M, X;
int dist[1001];
int go_dist[1001];
int re_dist[1001];
vector<pair<int, int> > vec[1001];
vector<pair<int, pair<int, string>> > order_vec;
priority_queue<pair<pair<int, int>, pair<int, string> > > pq;
int answer = 0;
int start_point, end_point;

void init() {
	for (int i = 0; i < 1001; i++) {
		dist[i] = INT_MAX;
	}
	while (!pq.empty()) {
		pq.pop();
	}
}

bool comp(pair<int, pair<int, string>> A, pair<int, pair<int, string>> B) {
	if (A.first == B.first) {
		return (A.second.first < B.second.first);
	}
	return (A.first < B.first);
}

void dijkstra(int x) {
	init();
	pq.push(make_pair(make_pair(0, x), make_pair(1, to_string(x))));
	dist[x] = 0;

	while (!pq.empty()) {
		int now_cost = -pq.top().first.first;
		int now_x = pq.top().first.second;
		int now_city_size = pq.top().second.first;
		string now_order = pq.top().second.second;
		pq.pop();

		if (now_x == end_point) {
			order_vec.push_back(make_pair(now_cost, make_pair(now_city_size, now_order)));
		}
		if (dist[now_x] < now_cost) {
			continue;
		}
		for (int i = 0; i < vec[now_x].size(); i++) {
			int next_x = vec[now_x][i].first;
			int next_cost = vec[now_x][i].second;
			if (dist[next_x] > now_cost + next_cost) {
				dist[next_x] = now_cost + next_cost;
				pq.push(make_pair(make_pair(-dist[next_x], next_x), make_pair(now_city_size + 1, now_order + " " + to_string(next_x))));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		vec[n1].push_back(make_pair(n2, n3));
	}
	cin >> start_point >> end_point;
	dijkstra(start_point);
	sort(order_vec.begin(), order_vec.end(), comp);
	cout << dist[end_point] << "\n";
	cout << order_vec[0].second.first << "\n";
	cout << order_vec[0].second.second << "\n";

	getchar();
	getchar();
	return 0;
}
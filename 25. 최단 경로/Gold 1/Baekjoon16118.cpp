#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

int N, M;
long long dist1[4001];
long long dist2[4001][2]; // 0이면 2배의 속력, 1이면 절반의 속력
vector<pair<int, long long> > vec[4001];
priority_queue<pair<long long, int> > pq1;
priority_queue<pair<long long, pair<int, bool> > > pq2;
int answer = 0;

void init1() {
	for (int i = 0; i < 4001; i++) {
		vec[i].clear();
	}
	while (!pq1.empty()) {
		pq1.pop();
	};
	while (!pq2.empty()) {
		pq2.pop();
	};
}

void init2() {
	for (int i = 0; i < 4001; i++) {
		dist1[i] = INT_MAX;
	}
}

void init3() {
	for (int i = 0; i < 4001; i++) {
		for (int j = 0; j < 2; j++) {
			dist2[i][j] = INT_MAX;
		}
	}
}

void dijkstra1(int x) {
	init2();
	pq1.push(make_pair(0, x));
	dist1[x] = 0;

	while (!pq1.empty()) {
		long long now_cost = -pq1.top().first;
		int now_x = pq1.top().second;
		pq1.pop();

		if (dist1[now_x] < now_cost) {
			continue;
		}
		for (int i = 0; i < vec[now_x].size(); i++) {
			int next_x = vec[now_x][i].first;
			long long next_cost = vec[now_x][i].second * 2;
			if (dist1[next_x] > now_cost + next_cost) {
				dist1[next_x] = now_cost + next_cost;
				pq1.push(make_pair(-dist1[next_x], next_x));
			}
		}
	};
}

void dijkstra2(int x, bool m) {
	init3();
	pq2.push(make_pair(0, make_pair(x, m)));
	dist2[x][m] = 0;

	while (!pq2.empty()) {
		long long now_cost = -pq2.top().first;
		int now_x = pq2.top().second.first;
		bool now_v = pq2.top().second.second;
		pq2.pop();

		if (dist2[now_x][now_v] < now_cost) {
			continue;
		}
		for (int i = 0; i < vec[now_x].size(); i++) {
			int next_x = vec[now_x][i].first;
			long long next_cost = vec[now_x][i].second;
			bool next_v;
			if (!now_v) {
				next_v = true;
				if (dist2[next_x][next_v] > now_cost + next_cost) {
					dist2[next_x][next_v] = now_cost + next_cost;
					pq2.push(make_pair(-dist2[next_x][next_v], make_pair(next_x, next_v)));
				}
			}
			else {
				next_v = false;
				if (dist2[next_x][next_v] > now_cost + (next_cost * 4)) {
					dist2[next_x][next_v] = now_cost + (next_cost * 4);
					pq2.push(make_pair(-dist2[next_x][next_v], make_pair(next_x, next_v)));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init1();
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		vec[a].push_back(make_pair(b, d));
		vec[b].push_back(make_pair(a, d));
	}
	dijkstra1(1);
	dijkstra2(1, false);

	for (int i = 1; i <= N; i++) {
		int wolf = min(dist2[i][false], dist2[i][true]);
		if (dist1[i] < wolf) {
			answer++;
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
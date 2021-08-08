#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;
int N, M, D, E;
int arr[100001];
long long dist1[100001];
long long dist2[100001];
vector<pair<int, long long> > vec[100001];
priority_queue<pair<long long, int> > pq1;
long long answer = LLONG_MIN;

void init1() {
	for (int i = 0; i < 100001; i++) {
		vec[i].clear();
	}
	while (!pq1.empty()) {
		pq1.pop();
	};
}

void init2() {
	for (int i = 0; i < 100001; i++) {
		dist1[i] = LLONG_MAX;
	}
}

void init3() {
	for (int i = 0; i < 100001; i++) {
		dist2[i] = LLONG_MAX;
	}
	while (!pq1.empty()) {
		pq1.pop();
	};
}

void dijkstra1(int x) {
	init2();
	pq1.push(make_pair(0LL, x));
	dist1[x] = 0LL;

	while (!pq1.empty()) {
		long long now_cost = -pq1.top().first;
		int now_x = pq1.top().second;
		pq1.pop();

		if (dist1[now_x] < now_cost) {
			continue;
		}
		for (int i = 0; i < vec[now_x].size(); i++) {
			int next_x = vec[now_x][i].first;
			long long next_cost = vec[now_x][i].second;
			if (arr[next_x] > arr[now_x]) {
				if (dist1[next_x] > now_cost + next_cost) {
					dist1[next_x] = now_cost + next_cost;
					pq1.push(make_pair(-dist1[next_x], next_x));
				}
			}
		}
	};
}

void dijkstra2(int x) {
	init3();
	pq1.push(make_pair(0, x));
	dist2[x] = 0;

	while (!pq1.empty()) {
		long long now_cost = -pq1.top().first;
		int now_x = pq1.top().second;
		pq1.pop();

		if (dist2[now_x] < now_cost) {
			continue;
		}
		for (int i = 0; i < vec[now_x].size(); i++) {
			int next_x = vec[now_x][i].first;
			long long next_cost = vec[now_x][i].second;
			if (arr[next_x] > arr[now_x]) {
				if (dist2[next_x] > now_cost + next_cost) {
					dist2[next_x] = now_cost + next_cost;
					pq1.push(make_pair(-dist2[next_x], next_x));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init1();
	cin >> N >> M >> D >> E;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		vec[a].push_back(make_pair(b, d));
		vec[b].push_back(make_pair(a, d));
	}
	dijkstra1(1);
	dijkstra2(N);
	for (int i = 2; i < N; i++) {
		long long num;
		if ((dist1[i] != LLONG_MAX) && (dist2[i] != LLONG_MAX)) {
			num = ((arr[i] * E) - ((dist1[i] + dist2[i]) * D));
			answer = max(answer, num);
		}
	}
	if (answer != LLONG_MIN) {
		cout << answer << "\n";
	}
	else {
		cout << "Impossible" << "\n";
	}

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int T, n, m, t, s, g, h;
int dist[2001];
int S[2001];
int G[2001];
int H[2001];
vector<pair<int, int> > vec[2001];
vector<int> dest;
priority_queue<pair<int, int> > pq;
int K = 0;

void init() {
	for (int i = 0; i < 2001; i++) {
		dist[i] = INT_MAX;
		S[i] = 0;
		G[i] = 0;
		H[i] = 0;
		vec[i].clear();
	}
	while (!pq.empty()) {
		pq.pop();
	}
	dest.clear();
}

void init2() {
	for (int i = 0; i < 2001; i++) {
		dist[i] = INT_MAX;
	}
}

void dijkstra(int x) {
	init2();
	pq.push(make_pair(0, x));
	dist[x] = 0;

	while (!pq.empty()) {
		int now_cost = -pq.top().first;
		int now_x = pq.top().second;
		pq.pop();

		if (dist[now_x] < now_cost) {
			continue;
		}
		for (int i = 0; i < vec[now_x].size(); i++) {
			int next_x = vec[now_x][i].first;
			int next_cost = vec[now_x][i].second;
			if (dist[next_x] > now_cost + next_cost) {
				dist[next_x] = now_cost + next_cost;
				pq.push(make_pair(-dist[next_x], next_x));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			vec[a].push_back(make_pair(b, d));
			vec[b].push_back(make_pair(a, d));
		}
		for (int i = 0; i < t; i++) {
			int n1;
			cin >> n1;
			dijkstra(s);
			S[g] = dist[g];
			S[h] = dist[h];
			S[n1] = dist[n1];
			dijkstra(g);
			G[s] = dist[s];
			G[h] = dist[h];
			G[n1] = dist[n1];
			dijkstra(h);
			H[s] = dist[s];
			H[g] = dist[g];
			H[n1] = dist[n1];
			if ((S[n1] == S[g] + G[h] + H[n1]) || (S[n1] == S[h] + H[g] + G[n1])) {
				dest.push_back(n1);
			}
		}
		sort(dest.begin(), dest.end());
		for (int i = 0; i < dest.size(); i++) {
			cout << dest[i] << " ";
		}
		cout << "\n";
	};

	getchar();
	getchar();
	return 0;
}
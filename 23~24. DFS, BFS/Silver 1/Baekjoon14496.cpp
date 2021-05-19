#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int a, b, N, M;
vector<list<int> > vec(1001);
int visited[1001];

void init() {
	for (int i = 0; i < 1001; i++) {
		visited[i] = -1;
	}
}

void bfs(int x, int des) {
	int count = 0;
	queue<pair<int, int> > q;
	visited[x] = 0;
	q.push(make_pair(x, 0));

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowCount = q.front().second;
		q.pop();

		for (auto i : vec[nowX]) {
			if (visited[i] == -1) {
				visited[i] = nowCount + 1;
				q.push(make_pair(i, nowCount + 1));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();

	cin >> a >> b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vec[n1].push_back(n2);
		vec[n2].push_back(n1);
	}

	bfs(a, b);

	cout << visited[b] << "\n";

	getchar();
	getchar();
	return 0;
}
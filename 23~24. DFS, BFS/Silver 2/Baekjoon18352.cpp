#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int N, M, K, X;
vector<list<int> > vec(300001);
int visited[300001] = { 0, };
int res[300001] = { 0, };

void bfs(int x) {
	int count = 0;
	queue<pair<int, int> > q;
	visited[x] = -1;
	q.push(make_pair(x, count));

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowCount = q.front().second;
		q.pop();

		for (auto i : vec[nowX]) {
			if (visited[i] == 0) {
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

	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vec[n1].push_back(n2);
	}

	bfs(X);

	for (int i = 1; i <= N; i++) {
		cout << visited[i] << " ";
	}
	cout << "\n";

	int index = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == K) {
			res[index++] = i;
		}
	}
	if (index > 0) {
		sort(res, res + index);
		for (int i = 0; i < index; i++) {
			cout << res[i] << "\n";
		}
	}
	else if (index == 0) {
		cout << -1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, K;
int prev_point[100001];
bool visited[100001];
vector<int> path;

int bfs(int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, 0));
	visited[x] = true;

	while (!q.empty()) {
		int now_point = q.front().first;
		int now_count = q.front().second;
		visited[now_point] = true;
		q.pop();

		if (now_point == K) {
			int idx = now_point;
			while (idx != x) {
				path.push_back(idx);
				idx = prev_point[idx];
			};
			path.push_back(x);
			return now_count;
		}

		if (now_point - 1 >= 0) {
			if (!visited[now_point - 1]) {
				q.push(make_pair(now_point - 1, now_count + 1));
				visited[now_point - 1] = true;
				prev_point[now_point - 1] = now_point;
			}
		}
		if (now_point + 1 <= 100000) {
			if (!visited[now_point + 1]) {
				q.push(make_pair(now_point + 1, now_count + 1));
				visited[now_point + 1] = true;
				prev_point[now_point + 1] = now_point;
			}
		}
		if (now_point * 2 <= 100000) {
			if (!visited[now_point * 2]) {
				q.push(make_pair(now_point * 2, now_count + 1));
				visited[now_point * 2] = true;
				prev_point[now_point * 2] = now_point;
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	cout << bfs(N) << "\n";
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << "\n";

	getchar();
	getchar();
	return 0;
}
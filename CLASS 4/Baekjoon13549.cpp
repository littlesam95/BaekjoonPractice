#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N, K;
bool visited[100001] = { false, };

int bfs(int x) {
	int count = 0;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	// 우선순위 큐를 이용하여 시간이 적게 걸린 순서대로 BFS
	visited[x] = true;
	q.push(make_pair(count, x));

	while (!q.empty()) {
		int nowCount = q.top().first;
		int nowX = q.top().second;
		q.pop();

		if (nowX == K) {
			return nowCount;
		}

		if (nowX * 2 <= 100000) {
			if (!visited[nowX * 2]) {
				visited[nowX * 2] = true;
				q.push(make_pair(nowCount, nowX * 2));
			}
		}
		if (nowX + 1 <= 100000) {
			if (!visited[nowX + 1]) {
				visited[nowX + 1] = true;
				q.push(make_pair(nowCount + 1, nowX + 1));
			}
		}
		if (nowX - 1 >= 0) {
			if (!visited[nowX - 1]) {
				visited[nowX - 1] = true;
				q.push(make_pair(nowCount + 1, nowX - 1));
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

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int N, M, S, E;
vector<list<int> > vec(300001);
bool visited[300001] = { false, };
int moveX[2] = { -1,1 };
int res = 2147483647;

void bfs(int x) {
	int count = 0;
	queue<pair<int, int> > q;
	visited[x] = true;
	q.push(make_pair(x, count));

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowCount = q.front().second;
		q.pop();

		if (nowX == E) {
			res = min(res, nowCount);
		}

		if ((nowX + 1 >= 1) && (nowX + 1 <= N) && (!visited[nowX + 1])) {
			visited[nowX + 1] = true;
			q.push(make_pair(nowX + 1, nowCount + 1));
		}
		if ((nowX - 1 >= 1) && (nowX - 1 <= N) && (!visited[nowX - 1])) {
			visited[nowX - 1] = true;
			q.push(make_pair(nowX - 1, nowCount + 1));
		}
		int size = vec[nowX].size();
		if (size > 0) {
			for (auto i : vec[nowX]) {
				if ((i >= 1) && (i <= N) && (!visited[i])) {
					visited[i] = true;
					q.push(make_pair(i, nowCount + 1));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> S >> E;
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vec[n1].push_back(n2);
		vec[n2].push_back(n1);
	}

	bfs(S);
	cout << res << "\n";

	getchar();
	getchar();
	return 0;
}
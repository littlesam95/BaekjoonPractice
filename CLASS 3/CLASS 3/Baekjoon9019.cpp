#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int T, A, B;
bool visited[10001];
string res;

void init() {
	for (int i = 0; i < 10001; i++) {
		visited[i] = false;
	}
	res = "";
}

void bfs(int x, int des) {
	queue<pair<int, string> > q;
	visited[x] = true;
	q.push(make_pair(x, ""));

	while (!q.empty()) {
		int nowX = q.front().first;
		string nowCount = q.front().second;
		q.pop();

		if (nowX == des) {
			res = nowCount;
			return;
		}

		if (!visited[(nowX * 2) % 10000]) {
			visited[(nowX * 2) % 10000] = true;
			q.push(make_pair((nowX * 2) % 10000, nowCount + "D"));
		}
		// D
		if ((nowX - 1 >= 0)) {
			if (!visited[nowX - 1]) {
				visited[nowX - 1] = true;
				q.push(make_pair(nowX - 1, nowCount + "S"));
			}
		}
		else if (nowX - 1 < 0) {
			if (!visited[9999]) {
				visited[9999] = true;
				q.push(make_pair(9999, nowCount + "S"));
			}
		}
		// S
		if (!visited[(nowX % 1000) * 10 + (nowX / 1000)]) {
			visited[(nowX % 1000) * 10 + (nowX / 1000)] = true;
			q.push(make_pair((nowX % 1000) * 10 + (nowX / 1000), nowCount + "L"));
		}
		// L
		if (!visited[(nowX % 10) * 1000 + (nowX / 10)]) {
			visited[(nowX % 10) * 1000 + (nowX / 10)] = true;
			q.push(make_pair((nowX % 10) * 1000 + (nowX / 10), nowCount + "R"));
		}
		// R
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> A >> B;
		bfs(A, B);
		cout << res << "\n";
	};

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int A, B, N, M;
bool visited[100001];

int bfs(int x) {
	int count = 0;
	queue<pair<int, int> > q;
	visited[x] = true;
	q.push(make_pair(x, count));

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowCount = q.front().second;
		q.pop();

		if (nowX == M) {
			return nowCount;
		}
		nowCount++;
		if ((nowX + 1 >= 0) && (nowX + 1 <= 100000) && (!visited[nowX + 1])) {
			visited[nowX + 1] = true;
			q.push(make_pair(nowX + 1, nowCount));
		}
		if ((nowX - 1 >= 0) && (nowX - 1 <= 100000) && (!visited[nowX - 1])) {
			visited[nowX - 1] = true;
			q.push(make_pair(nowX - 1, nowCount));
		}
		if ((nowX + A >= 0) && (nowX + A <= 100000) && (!visited[nowX + A])) {
			visited[nowX + A] = true;
			q.push(make_pair(nowX + A, nowCount));
		}
		if ((nowX + B >= 0) && (nowX + B <= 100000) && (!visited[nowX + B])) {
			visited[nowX + B] = true;
			q.push(make_pair(nowX + B, nowCount));
		}
		if ((nowX - A >= 0) && (nowX - A <= 100000) && (!visited[nowX - A])) {
			visited[nowX - A] = true;
			q.push(make_pair(nowX - A, nowCount));
		}
		if ((nowX - B >= 0) && (nowX - B <= 100000) && (!visited[nowX - B])) {
			visited[nowX - B] = true;
			q.push(make_pair(nowX - B, nowCount));
		}
		if ((nowX * A >= 0) && (nowX * A <= 100000) && (!visited[nowX * A])) {
			visited[nowX * A] = true;
			q.push(make_pair(nowX * A, nowCount));
		}
		if ((nowX * B >= 0) && (nowX * B <= 100000) && (!visited[nowX * B])) {
			visited[nowX * B] = true;
			q.push(make_pair(nowX * B, nowCount));
		}
	};
	return -1;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> N >> M;

	cout << bfs(N) << "\n";

	getchar();
	getchar();
	return 0;
}
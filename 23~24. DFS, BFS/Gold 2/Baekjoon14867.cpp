#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <climits>
#include <algorithm>

using namespace std;
struct Info {
	int A_water, B_water, dist;
};

int a, b, c, d;
map<pair<int, int>, int> visited;
int answer = INT_MAX;

void bfs() {
	queue<Info> q;
	visited[make_pair(0, 0)] = 0;
	q.push({ 0,0,0 });

	while (!q.empty()) {
		int now_a = q.front().A_water;
		int now_b = q.front().B_water;
		int now_dist = q.front().dist;
		q.pop();

		if ((now_a == c) && (now_b == d)) {
			answer = min(answer, now_dist);
			return;
		}

		if (now_a < a) {
			if (visited.count(make_pair(a, now_b)) == 0) {
				visited[make_pair(a, now_b)] = now_dist + 1;
				q.push({ a,now_b,now_dist + 1 });
			}
		}
		if (now_b < b) {
			if (visited.count(make_pair(now_a, b)) == 0) {
				visited[make_pair(now_a, b)] = now_dist + 1;
				q.push({ now_a,b,now_dist + 1 });
			}
		}
		if (now_a > 0) {
			if (visited.count(make_pair(0, now_b)) == 0) {
				visited[make_pair(0, now_b)] = now_dist + 1;
				q.push({ 0,now_b,now_dist + 1 });
			}
		}
		if (now_b > 0) {
			if (visited.count(make_pair(now_a, 0)) == 0) {
				visited[make_pair(now_a, 0)] = now_dist + 1;
				q.push({ now_a,0,now_dist + 1 });
			}
		}
		// 물통 a -> 물통 b
		int diff = b - now_b; // 물통 b에 남아 있는 빈 공간
		if (now_a <= diff) { // 물통 a에 남아 있는 물의 양이 물통 b에 남아 있는 빈 공간보다 적거나 같다면
			if (visited.count(make_pair(0, now_a + now_b)) == 0) {
				visited[make_pair(0, now_a + now_b)] = now_dist + 1;
				q.push({ 0,now_a + now_b,now_dist + 1 });
			}
		}
		else {
			if (visited.count(make_pair(now_a - diff, b)) == 0) {
				visited[make_pair(now_a - diff, b)] = now_dist + 1;
				q.push({ now_a - diff,b,now_dist + 1 });
			}
		}
		diff = a - now_a;
		if (now_b <= diff) {
			if (visited.count(make_pair(now_a + now_b, 0)) == 0) {
				visited[make_pair(now_a + now_b, 0)] = now_dist + 1;
				q.push({ now_a + now_b,0,now_dist + 1 });
			}
		}
		else {
			if (visited.count(make_pair(a, now_b - diff)) == 0) {
				visited[make_pair(a, now_b - diff)] = now_dist + 1;
				q.push({ a,now_b - diff,now_dist + 1 });
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> a >> b >> c >> d;
	bfs();
	if (answer < INT_MAX) {
		cout << answer << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}
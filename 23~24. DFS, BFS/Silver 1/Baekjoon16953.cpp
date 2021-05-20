#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

long long A, B;
vector<long long> visited;
int res = -1;

bool checkVisit(long long num) {
	auto it = find(visited.begin(), visited.end(), num);
	if (it == visited.end()) {
		return false;
	}
	else {
		return true;
	}
}

void bfs(long long x, long long des) {
	int count = 1;
	queue<pair<long long, int> > q;
	visited.push_back(x);
	q.push(make_pair(x, count));

	while (!q.empty()) {
		long long nowX = q.front().first;
		int nowCount = q.front().second;
		q.pop();

		if (nowX == des) {
			res = nowCount;
			return;
		}
		if ((nowX * 2 >= 1) && (nowX * 2 <= des)) {
			if (!checkVisit(nowX * 2)) {
				visited.push_back(nowX * 2);
				q.push(make_pair(nowX * 2, nowCount + 1));
			}
		}
		if ((nowX * 10 + 1 >= 1) && (nowX * 10 + 1 <= des)) {
			if (!checkVisit(nowX * 10 + 1)) {
				visited.push_back(nowX * 10 + 1);
				q.push(make_pair(nowX * 10 + 1, nowCount + 1));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B;
	bfs(A, B);

	cout << res << "\n";

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
queue<pair<int, int> > q;
bool visit[100001] = { false, };
int N, K;
int res;

bool valid(int N) {
	if ((N < 0) || (N > 100000) || (visit[N])) {
		return false;
	}
	return true;
}

void bfs(int x) {
	while (!q.empty()) {
		int number = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (number == K) {
			res = depth;
			break;
		}
		else {
			if (valid(number - 1)) {
				visit[number - 1] = true;
				q.push(make_pair(number - 1, depth + 1));
			}
			if (valid(number + 1)) {
				visit[number + 1] = true;
				q.push(make_pair(number + 1, depth + 1));
			}
			if (valid(number * 2)) {
				visit[number * 2] = true;
				q.push(make_pair(number * 2, depth + 1));
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	q.push(make_pair(N, 0));
	visit[N] = true;
	bfs(N);
	cout << res;

	getchar();
	getchar();
	return 0;
}
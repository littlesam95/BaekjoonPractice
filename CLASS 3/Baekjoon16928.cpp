#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int arr[101] = { 0, };
int visited[101];
queue<pair<int,int> > q;
int N, M, count;

void init() {
	for (int i = 0; i < 101; i++) {
		visited[i] = 10000000;
	}
}

int bfs() {
	q.push(make_pair(1, 0));
	visited[1] = 0;

	while (!q.empty()) {
		int nowloc, nowcount, nextloc, nextcount;
		nowloc = q.front().first;
		nowcount = q.front().second;
		q.pop();

		if (arr[nowloc] != 0) {
			nextloc = arr[nowloc];
			q.push(make_pair(nextloc, nowcount));
			continue;
		}

		for (int i = 1; i <= 6; i++) {
			nextloc = nowloc + i;
			nextcount = nowcount + 1;

			if (nextloc > 100) {
				continue;
			}
			if (nextcount < visited[nextloc]) {
				visited[nextloc] = nextcount;
				q.push(make_pair(nextloc, nextcount));
			}
		}
	};
	return visited[100];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		arr[start] = end;
	}
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		arr[start] = end;
	}

	init();
	int res = bfs();
	cout << res << "\n";

	getchar();
	getchar();
	return 0;
}
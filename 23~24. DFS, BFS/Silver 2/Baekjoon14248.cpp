#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int n, s;
int arr[100001];
bool visited[100001] = { false, };
int moveX[2] = { -1,1 };

void bfs(int x, int a) {
	queue<pair<int, int> > q;
	visited[x] = true;
	q.push(make_pair(x, a));

	while (!q.empty()) {
		int nowX = q.front().first;
		int nowA = q.front().second;
		q.pop();

		for (int i = 0; i < 2; i++) {
			int nextX = nowX + (moveX[i] * nowA);
			int nextA = arr[nextX];
			if ((nextX >= 1) && (nextX <= n)) {
				if (!visited[nextX]) {
					visited[nextX] = true;
					q.push(make_pair(nextX, nextA));
				}
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> s;
	bfs(s, arr[s]);

	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			count++;
		}
	}

	cout << count << "\n";

	getchar();
	getchar();
	return 0;
}
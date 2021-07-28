#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, K;
int arr[100001];
bool visited[100001];
int small_min = 0;
int answer = 0;

void bfs(int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(x, 0));
	visited[x] = true;

	while (!q.empty()) {
		int now_point = q.front().first;
		int now_count = q.front().second;
		visited[now_point] = true;
		q.pop();

		if ((now_point == K) && (small_min) && (small_min == now_count)) {
			answer++;
		}
		if ((now_point == K) && (!small_min)) {
			small_min = now_count;
			answer++;
		}

		if (now_point - 1 >= 0) {
			if (!visited[now_point - 1]) {
				q.push(make_pair(now_point - 1, now_count + 1));
			}
		}
		if (now_point + 1 <= 100000) {
			if (!visited[now_point + 1]) {
				q.push(make_pair(now_point + 1, now_count + 1));
			}
		}
		if (now_point * 2 <= 100000) {
			if (!visited[now_point * 2]) {
				q.push(make_pair(now_point * 2, now_count + 1));
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	bfs(N);
	cout << small_min << "\n";
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
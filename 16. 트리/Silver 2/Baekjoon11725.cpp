#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int N;
int a, b;
vector<int> vec[100010];
int parent[100010];
bool visited[100010];

void init() {
	for (int i = 0; i < 100010; i++) {
		visited[i] = false;
		parent[i] = 0;
	}
}

void bfs(int S) {
	visited[S] = true;
	queue<int> q;
	q.push(S);

	while (!q.empty()) {
		int now_point = q.front();
		q.pop();

		for (int i = 0; i < vec[now_point].size(); i++) {
			int next_point = vec[now_point][i];
			if (!visited[next_point]) {
				visited[next_point] = true;
				parent[next_point] = now_point;
				q.push(next_point);
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	bfs(1);
	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 2000000000

using namespace std;
int T;
int N, M;
int a, b;
vector<int> vec[1010];
bool visited[1010];
int answer = 0;

void init() {
	N = 0;
	M = 0;
	a = 0; 
	b = 0;
	for (int i = 0; i < 1010; i++) {
		vec[i].clear();
		visited[i] = false;
	}
	answer = 0;
}

void bfs(int S) {
	queue<int> q;
	visited[S] = true;
	q.push(S);

	while (!q.empty()) {
		int now_point = q.front();
		q.pop();

		for (int i = 0; i < vec[now_point].size(); i++) {
			int next_point = vec[now_point][i];
			if (!visited[vec[now_point][i]]) {
				answer++;
				visited[vec[now_point][i]] = true;
				q.push(vec[now_point][i]);
			}
		}
	};
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		init();
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		bfs(1);
		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}
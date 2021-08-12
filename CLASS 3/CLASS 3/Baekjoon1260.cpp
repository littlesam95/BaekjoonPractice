#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
int arr[1001][1001] = { 0, };
bool visitD[1001] = { false, };
bool visitB[1001] = { false, };
int N, M, V;

void dfs(int V) {
	int i = 0;
	cout << V << " ";
	visitD[V] = true;

	for (i = 1; i <= N; i++) {
		if (arr[V][i] && !visitD[i]) {
			dfs(i);
		}
	}
	if (i == N) {
		return;
	}
}

void bfs(int V) {
	queue<int> q;
	int i = 0;
	q.push(V);
	visitB[V] = true;

	while(!q.empty()) {
		int news = q.front();
		visitB[news] = true;
		cout << news << " ";
		q.pop();

		for (i = 1; i <= N; i++) {
			if (arr[news][i] && !visitB[i]) {
				visitB[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;
	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		arr[start][end] = 1;
		arr[end][start] = 1;
	}

	dfs(V);
	cout << "\n";

	bfs(V);
	cout << "\n";

	getchar();
	getchar();
	return 0;
}
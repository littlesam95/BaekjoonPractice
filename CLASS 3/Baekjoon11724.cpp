#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
int arr[1001][1001] = { 0, };
bool visit[1001] = { false, };
int N, M;
int res = 0;

void dfs(int V) {
	int i = 0;
	visit[V] = true;

	for (i = 1; i <= N; i++) {
		if (arr[V][i] && !visit[i]) {
			dfs(i);
		}
	}
	if (i == N) {
		return;
	}
}

int main() {
	cin >> N >> M;
	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		arr[start][end] = 1;
		arr[end][start] = 1;
	}

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			res++;
			dfs(i);
		}
	}

	cout << res;

	getchar();
	getchar();
	return 0;
}
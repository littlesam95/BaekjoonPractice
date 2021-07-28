#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int N, M;
vector<int> vec[2000];
bool visited[2000];
int answer = 0;

void dfs(int x, int depth) {
	visited[x] = true;
	if (depth == 5) {
		answer = 1;
		return;
	}
	for (int i = 0; i < vec[x].size(); i++) {
		if (!visited[vec[x][i]]) {
			dfs(vec[x][i], depth + 1);
		}
	}
	visited[x] = false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		vec[n1].push_back(n2);
		vec[n2].push_back(n1);
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			dfs(i, 1);
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
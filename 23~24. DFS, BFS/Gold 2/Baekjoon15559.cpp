#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
char arr[1001][1001];
int visited[1001][1001];
int level_count = 0;
int answer = 0;

void dfs(int y, int x) {
	if (visited[y][x] == 0) {
		visited[y][x] = level_count;
		if (arr[y][x] == 'N') {
			dfs(y - 1, x);
		}
		else if (arr[y][x] == 'S') {
			dfs(y + 1, x);
		}
		else if (arr[y][x] == 'W') {
			dfs(y, x - 1);
		}
		else if (arr[y][x] == 'E') {
			dfs(y, x + 1);
		}
	}
	else if (visited[y][x] == level_count) {
		answer++;
		return;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < M; j++) {
			arr[i][j] = S[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0) {
				level_count++;
				dfs(i, j);
			}
		}
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
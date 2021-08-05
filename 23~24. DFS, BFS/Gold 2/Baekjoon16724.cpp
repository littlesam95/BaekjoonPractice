#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
char arr[1001][1001];
int visited[1001][1001];
int level = 0;
int answer = 0;

void dfs(int y, int x) {
	if (visited[y][x] == 0) {
		visited[y][x] = level;
		if (arr[y][x] == 'D') {
			dfs(y + 1, x);
		}
		else if (arr[y][x] == 'R') {
			dfs(y, x + 1);
		}
		else if (arr[y][x] == 'U') {
			dfs(y - 1, x);
		}
		else if (arr[y][x] == 'L') {
			dfs(y, x - 1);
		}
	}
	else if (visited[y][x] == level) {
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
				level++;
				dfs(i, j);
			}
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
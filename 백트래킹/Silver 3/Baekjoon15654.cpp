#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 9

using namespace std;
int N, M;
int num_arr[MAX];
bool visited[MAX];
vector<int> answer;

void dfs(int X, int depth) {
	if (depth == M) {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = X; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			answer.push_back(num_arr[i]);
			dfs(1, depth + 1);
			answer.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num_arr[i];
	}
	sort(num_arr + 1, num_arr + N + 1);
	dfs(1, 0);

	getchar();
	getchar();
	return 0;
}
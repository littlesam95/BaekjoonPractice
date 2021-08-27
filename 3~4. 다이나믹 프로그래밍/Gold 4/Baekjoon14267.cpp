#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 100001

using namespace std;
int N, M;
int arr[MAX];
int dp[MAX];
vector<int> vec[MAX];
int answer;

void init() {
	for (int i = 0; i < MAX; i++) {
		dp[i] = 0;
	}
}

void dfs(int X, int Y) {
	for (int i = 0; i < vec[X].size(); i++) {
		dp[vec[X][i]] += Y;
		dfs(vec[X][i], dp[vec[X][i]]);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (i == 1) {
			continue;
		}
		vec[arr[i]].push_back(i);
	}
	for (int i = 0; i < M; i++) {
		int I, W;
		cin >> I >> W;
		dp[I] += W;
	}
	dfs(1, 0);
	for (int i = 1; i <= N; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 5001
#define MOD 100000

using namespace std;
int N, M;
int arr[MAX];
vector<int> vec[MAX];
int dp[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		dp[i] = -1;
	}
}

int dfs(int X) {
	if (dp[X] != -1) {
		return dp[X];
	}
	dp[X] = 0;
	for (int i = 0; i < vec[X].size(); i++) {
		if (arr[X] < arr[vec[X][i]]) {
			dp[X] = max(dp[X], dfs(vec[X][i]) + 1);
		}
	}
	return dp[X];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < M; i++) {
		int X, Y;
		cin >> X >> Y;
		if (arr[X] < arr[Y]) {
			vec[X].push_back(Y);
		}
		else {
			vec[Y].push_back(X);
		}
	}
	for (int i = 1; i <= N; i++) {
		init();
		cout << dfs(i) + 1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}
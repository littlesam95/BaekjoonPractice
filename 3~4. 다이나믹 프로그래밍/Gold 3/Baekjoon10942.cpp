#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
int arr[2001];
int dp[2001][2001] = { 0, };
int answer = 0;

void init() {
	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) {
			dp[i][j] = -1;
		}
	}
}

int dfs(int S, int E) {
	if (S > E) {
		return 1;
	}
	if (dp[S][E] != -1) {
		return dp[S][E];
	}

	if (S == E) {
		dp[S][E] = 1;
	}
	else {
		if (arr[S] != arr[E]) {
			dp[S][E] = 0;
		}
		else {
			dp[S][E] = dfs(S + 1, E - 1);
		}
	}
	
	return dp[S][E];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		cout << dfs(n1, n2) << "\n";
	}

	getchar();
	getchar();
	return 0;
}
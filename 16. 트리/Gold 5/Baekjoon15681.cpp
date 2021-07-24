#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define MAX_NODE 100001

using namespace std;
int N, R, Q;
int parent[MAX_NODE];
bool visited[MAX_NODE];
vector<int> vec[MAX_NODE];
vector<int> dirNode[MAX_NODE];
int dp[MAX_NODE];

void init() {
	for (int i = 0; i < MAX_NODE; i++) {
		visited[i] = false;
		dp[i] = 0;
	}
}

void dfs(int S) {
	visited[S] = true;
	for (int i = 0; i < vec[S].size(); i++) {
		if (!visited[vec[S][i]]) {
			dirNode[S].push_back(vec[S][i]);
			parent[vec[S][i]] = S;
			dfs(vec[S][i]);
		}
	}
}

int find_subtree(int S) {
	if (dp[S] != 0) {
		return dp[S];
	}
	visited[S] = true;
	int ret = 1;
	for (int i = 0; i < dirNode[S].size(); i++) {
		if (!visited[dirNode[S][i]]) {
			ret += find_subtree(dirNode[S][i]);
		}
	}

	dp[S] = ret;
	return dp[S];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> R >> Q;
	for (int i = 0; i < (N - 1); i++) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(R);
	init();
	dp[R] = find_subtree(R);
	for (int i = 0; i < Q; i++) {
		int query;
		cin >> query;
		cout << dp[query] << "\n";
	}

	getchar();
	getchar();
	return 0;
}
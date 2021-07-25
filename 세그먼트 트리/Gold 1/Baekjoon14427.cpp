#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
long long arr[100001];
long long tree[400005];

int find_min(int a, int b) {
	if (a == -1) {
		return b;
	}
	if (b == -1) {
		return a;
	}
	if (arr[a] == arr[b]) {
		return (a < b) ? a : b;
	}
	else {
		return (arr[a] <= arr[b]) ? a : b;
	}
}

int dfs(int S, int E, int node) {
	if (S == E) {
		return tree[node] = S;
	}
	int mid = (S + E) / 2;
	return tree[node] = find_min(dfs(S, mid, node * 2), dfs(mid + 1, E, node * 2 + 1));
}

int update(int S, int E, int node, int idx) {
	if ((idx < S) || (idx > E)) {
		return tree[node];
	}
	if (S == E) {
		return tree[node];
	}
	int mid = (S + E) / 2;
	return tree[node] = find_min(update(S, mid, node * 2, idx), update(mid + 1, E, node * 2 + 1, idx));
}

int query(int S, int E, int node, int left, int right) {
	if ((left > E) || (right < S)) {
		return -1;
	}
	if ((left <= S) && (E <= right)) {
		return tree[node];
	}
	int mid = (S + E) / 2;
	return find_min(query(S, mid, node * 2, left, right), query(mid + 1, E, node * 2 + 1, left, right));
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dfs(1, N, 1);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int i;
			long long v;
			cin >> i >> v;
			arr[i] = v;
			update(1, N, 1, i);
		}
		else if (a == 2) {
			cout << query(1, N, 1, 1, N) << "\n";
		}
	}

	getchar();
	getchar();
	return 0;
}
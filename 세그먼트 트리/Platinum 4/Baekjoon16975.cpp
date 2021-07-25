#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N, M;
long long arr[100001];
long long tree[400004];
long long lazy[400004];

long long dfs(int S, int E, int node) {
	if (S == E) {
		return tree[node] = arr[S];
	}
	int mid = (S + E) / 2;
	return tree[node] = dfs(S, mid, node * 2) + dfs(mid + 1, E, node * 2 + 1);
}

void update_lazy(int S, int E, int node) {
	if (lazy[node] != 0) {
		tree[node] += ((long long)E - S + 1) * lazy[node];
		if (S != E) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update_range(int S, int E, int node, int left, int right, long long num) {
	update_lazy(S, E, node);
	if ((left > E) || (right < S)) {
		return;
	}
	if ((left <= S) && (E <= right)) {
		tree[node] += ((long long)E - S + 1) * num;
		if (S != E) {
			lazy[node * 2] += num;
			lazy[node * 2 + 1] += num;
		}
		return;
	}
	int mid = (S + E) / 2;
	update_range(S, mid, node * 2, left, right, num);
	update_range(mid + 1, E, node * 2 + 1, left, right, num);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int S, int E, int node, int left, int right) {
	update_lazy(S, E, node);
	if ((left > E) || (right < S)) {
		return 0;
	}
	if ((left <= S) && (E <= right)) {
		return tree[node];
	}
	int mid = (S + E) / 2;
	return query(S, mid, node * 2, left, right) + query(mid + 1, E, node * 2 + 1, left, right);
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
		int T;
		cin >> T;
		if (T == 1) {
			int a, b;
			long long K;
			cin >> a >> b >> K;
			update_range(1, N, 1, a, b, K);
		}
		else if (T == 2) {
			int X;
			cin >> X;
			cout << query(1, N, 1, X, X) << "\n";
		}
	}

	getchar();
	getchar();
	return 0;
}
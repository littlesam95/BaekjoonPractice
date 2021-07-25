#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
int N, M, K;
unsigned long long arr[1000001];
unsigned long long tree[4000004];

void init() {
	for (int i = 0; i < 4000004; i++) {
		tree[i] = 1;
	}
}

long long dfs(int S, int E, int node) {
	if (S == E) {
		return tree[node] = arr[S] % 1000000007;
	}
	int mid = (S + E) / 2;
	return tree[node] = (dfs(S, mid, node * 2) * dfs(mid + 1, E, node * 2 + 1)) % 1000000007;
}

unsigned long long find_mul(int S, int E, int node, int left, int right) {
	if ((left > E) || (right < S)) {
		return 1;
	}
	if ((left <= S) && (E <= right)) {
		return tree[node];
	}
	int mid = (S + E) / 2;
	return (find_mul(S, mid, node * 2, left, right) * find_mul(mid + 1, E, node * 2 + 1, left, right)) % 1000000007;
}

unsigned long long update(int S, int E, int node, int idx, unsigned long long num) {
	if ((idx < S) || (idx > E)) {
		return tree[node];
	}
	if (S == E) {
		return tree[node] = num;
	}
	int mid = (S + E) / 2;
	return tree[node] = (update(S, mid, node * 2, idx, num) * update(mid + 1, E, node * 2 + 1, idx, num)) % 1000000007;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dfs(0, N - 1, 1);
	for (int i = 0; i < (M + K); i++) {
		int calc;
		cin >> calc;
		if (calc == 1) {
			int a;
			unsigned long long b;
			cin >> a >> b;
			a--;
			update(0, N - 1, 1, a, b);
		}
		else if (calc == 2) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			cout << find_mul(0, N - 1, 1, a, b) % 1000000007 << "\n";
		}
	}

	getchar();
	getchar();
	return 0;
}
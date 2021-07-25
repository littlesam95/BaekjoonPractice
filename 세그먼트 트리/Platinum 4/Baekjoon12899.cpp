#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
int N;
int tree[8000005];

void update(int S, int E, int node, int idx, int num) {
	if ((idx < S) || (idx > E)) {
		return;
	}
	if (S == E) {
		tree[node] += num;
		return;
	}
	int mid = (S + E) / 2;
	update(S, mid, node * 2, idx, num);
	update(mid + 1, E, node * 2 + 1, idx, num);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int S, int E, int node, int idx) {
	if (S == E) {
		return S;
	}
	int mid = (S + E) / 2;
	if (idx <= tree[node * 2]) {
		return query(S, mid, node * 2, idx);
	}
	else {
		return query(mid + 1, E, node * 2 + 1, idx - tree[node * 2]);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int T, X;
		cin >> T >> X;
		if (T == 1) {
			update(1, 2000001, 1, X, 1);
		}
		else if (T == 2) {
			cout << query(1, 2000001, 1, X) << "\n";
			update(1, 2000001, 1, query(1, 2000001, 1, X), -1);
		}
	}

	getchar();
	getchar();
	return 0;
}
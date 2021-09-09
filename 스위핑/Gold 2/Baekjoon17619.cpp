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
struct Info {
	int S, E, H, idx;
};

int N, Q;
int arr[MAX];
Info tmp;
vector<Info> vec;

bool comp(Info A, Info B) {
	if (A.E == B.E) {
		return (A.S < B.S);
	}
	return (A.E > B.E);
}

void init() {
	for (int i = 0; i < MAX; i++) {
		arr[i] = -1;
	}
}

int find(int X) {
	if (arr[X] < 0) {
		return X;
	}
	int parent = find(arr[X]);
	arr[X] = parent;
	return parent;
}

void union_set(int X, int Y) {
	int P_X = find(X);
	int P_Y = find(Y);
	if (P_X != P_Y) {
		arr[P_X] = P_Y;
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		int X1, X2, Y;
		cin >> X1 >> X2 >> Y;
		tmp.S = X1;
		tmp.E = X2;
		tmp.H = Y;
		tmp.idx = i;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end(), comp);
	int start_point = vec[0].S;
	for (int i = 0; i < N - 1; i++) {
		if (start_point <= vec[i + 1].E) {
			union_set(vec[i].idx, vec[i + 1].idx);
		}
		start_point = min(start_point, vec[i + 1].S);
	}
	for (int i = 0; i < Q; i++) {
		int A, B;
		cin >> A >> B;
		if (find(A) == find(B)) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

	getchar();
	getchar();
	return 0;
}
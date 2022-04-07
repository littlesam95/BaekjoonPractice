#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
int N, Q;
LL A[MAX];
LL Sum[MAX];

void Input() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		int X;
		cin >> X;
		A[i] = A[i - 1] + X;
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		Sum[i] = Sum[i - 1] + A[i - 1] * (A[i] - A[i - 1]);
	}
}

void Find_Answer() {
	while (Q--) {
		int L, R;
		cin >> L >> R;
		if (L == 1) {
			cout << Sum[R] << "\n";
		}
		else {
			cout << Sum[R] - (A[R] - A[L - 1]) * A[L - 1] - Sum[L - 1] << "\n";
		}
	};
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1001
#define LL long long
#define INF 1e9

using namespace std;
int N, Q;
LL MAP[MAX];
LL Sum[MAX];
LL Answer = 0;

void Input() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> MAP[i];
		Sum[i] = Sum[i - 1] + abs(MAP[i] - MAP[i - 1]);
	}
}

void Find_Answer() {
	while (Q--) {
		int L, R;
		cin >> L >> R;
		if ((R - 1) < L) {
			cout << 0 << "\n";
		}
		else {
			cout << Sum[R] - Sum[L] << "\n";
		}
	};
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
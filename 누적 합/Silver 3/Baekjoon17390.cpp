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
#define MAX 300001
#define LL long long
#define INF 1e12

using namespace std;
int N, Q;
vector<int> Vec;
LL Sum[MAX];
LL Answer = 0;

bool Comp(int A, int B) {
	return (A < B);
}

void Input() {
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		Vec.push_back(A);
	}
	sort(Vec.begin(), Vec.end(), Comp);
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		Sum[i] = Sum[i - 1] + Vec[i - 1];
	}
}

void Find_Answer() {
	while (Q--) {
		int L, R;
		cin >> L >> R;
		cout << Sum[R] - Sum[L - 1] << "\n";
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
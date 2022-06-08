#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
LL N, S, D;
LL A[MAX];
vector<LL> Vec;

LL GCD(LL N, LL M) {
	while (1) {
		LL R = N % M;
		if (R == 0) {
			return M;
		}
		N = M;
		M = R;
	};
}

void Input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		Vec.push_back(abs(A[i] - S));
	}
}

void Settings() {
	if (Vec.size() == 1) {
		D = Vec[0];
	}
	else {
		sort(Vec.begin(), Vec.end());
		Vec.erase(unique(Vec.begin(), Vec.end()), Vec.end());
		D = GCD(Vec[1], Vec[0]);
		for (int i = 2; i < Vec.size(); i++) {
			D = GCD(Vec[i], D);
		}
	}
}

void Find_Answer() {
	cout << D << "\n";
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
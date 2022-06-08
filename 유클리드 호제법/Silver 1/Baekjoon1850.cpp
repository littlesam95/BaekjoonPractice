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
LL A, B;

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
	cin >> A >> B;
}

void Settings() {
	if (A < B) {
		swap(A, B);
	}
}

void Find_Answer() {
	LL G = GCD(A, B);
	for (LL i = 0; i < G; i++) {
		cout << 1;
	}
	cout << "\n";
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
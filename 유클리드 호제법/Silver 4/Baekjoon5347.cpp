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
#define MAX 50
#define LL long long
#define INF 1e9

using namespace std;
LL N, A, B;

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

LL LCM(LL N, LL M) {
	return (N * M) / GCD(N, M);
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A >> B;
		cout << LCM(A, B) << "\n";
	}
}

int main() {
	FASTIO
	Input();

	getchar();
	getchar();
	return 0;
}
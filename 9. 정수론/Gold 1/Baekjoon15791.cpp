#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MOD 1000000007LL

using namespace std;
long long N, M;
long long fac[1000001];
long long inv[1000001];
long long answer;

long long power(long long A) {
	long long A1 = A;
	long long A2 = 1;
	long long exponent = MOD - 2;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			A2 *= A1;
			A2 %= MOD;
		}
		A1 *= A1;
		A1 %= MOD;
		exponent /= 2;
	};
	return A2;
}

// 페르마의 소정리
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	fac[0] = 1;
	for (int i = 1; i <= N; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= MOD;
	}
	inv[N] = power(fac[N]);
	for (int i = N - 1; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1);
		inv[i] %= MOD;
	}
	answer = (fac[N] * inv[N - M]);
	answer %= MOD;
	answer *= inv[M];
	answer %= MOD;
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
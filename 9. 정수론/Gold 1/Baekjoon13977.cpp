#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MOD 1000000007LL

using namespace std;
int M;
long long N, R;
long long fac[4004000];
long long inv[4004000];

long long pow(long long A, long long B) { // 분할 정복을 이용한 A^B 구하기
	long long A1 = A;
	long long A2 = 1;
	long long exp = B;
	while (exp) {
		if (exp % 2) {
			A2 *= A1;
			A2 %= MOD;
		}
		A1 *= A1;
		A1 %= MOD;
		exp /= 2;
	};
	return A2;
}

// 페르마의 소정리
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	fac[0] = 1;
	for (int i = 1; i <= 4000000; i++) { // 1 ~ 4000000까지의 팩토리얼 수
		fac[i] = fac[i - 1] * i;
		fac[i] %= MOD;
	}
	inv[4000000] = pow(fac[4000000], MOD - 2); // 페르마의 소정리를 이용한 4000000!의 inverse(역원)
	for (int i = 3999999; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1);
		inv[i] %= MOD;
	}

	cin >> M;
	while (M--) {
		cin >> N >> R;
		long long answer = (fac[N] * inv[N - R]);
		answer %= MOD;
		answer *= inv[R];
		answer %= MOD;
		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MOD 1000000007

using namespace std;
long long N, R;
long long A = 1, B = 1;
long long answer;

// 페르마의 소정리
// 최단경로 뭐시기 하지만 그냥 nCr을 구하라는 것이다.
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> R;
	for (long long i = 1; i <= N; i++) {
		A *= i;
		A %= MOD;
	}
	for (long long i = 1; i <= R; i++) {
		B *= i;
		B %= MOD;
	}
	for (long long i = 1; i <= (N - R); i++) {
		B *= i;
		B %= MOD;
	}
	int exponent = MOD - 2;
	long long B2 = 1;
	while (exponent) {
		if (exponent % 2) {
			B2 *= B;
			B2 %= MOD;
		}
		B *= B;
		B %= MOD;
		exponent /= 2;
	};

	answer = A * B2;
	answer %= MOD;
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
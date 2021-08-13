#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
long long N, R;
long long A = 1, B = 1;
long long answer;

// 페르마의 소정리
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> R;
	// N!
	for (long long i = 1; i <= N; i++) {
		A *= i;
		A %= 1000000007;
	}
	// K!
	for (long long i = 1; i <= R; i++) {
		B *= i;
		B %= 1000000007;
	}
	// K!(N-K)!
	for (long long i = 1; i <= (N - R); i++) {
		B *= i;
		B %= 1000000007;
	}
	long long B2 = 1;
	int exp = 1000000005;
	while (exp > 0) {
		if (exp % 2) {
			B2 *= B;
			B2 %= 1000000007;
		}

		B *= B;
		B %= 1000000007;
		exp /= 2;
	};

	answer = A * B2;
	answer %= 1000000007;
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
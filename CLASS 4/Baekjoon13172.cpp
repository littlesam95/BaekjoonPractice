#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define MOD 1000000007
#define ULL unsigned long long

using namespace std;
ULL M, N, S;
ULL D = MOD - 2;
ULL answer = 0;

ULL Reverse(ULL X) {
	ULL B = 1;
	ULL Digit = 1;
	ULL tmp = X;

	while (Digit <= D) { // MOD-2제곱을 분할하여 곱하는 과정
		if (Digit & D) {
			B = (B * tmp) % MOD; // 비트가 1인 자릿수에서는 B에 tmp를 곱해줌
		}
		tmp = (tmp * tmp) % MOD; // tmp는 계속 제곱해줌으로써 값 유지
		Digit = Digit << 1;
	};
	return B;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M;
	for (int i = 1; i <= M; i++) { // 기약분수를 구하지 않고 각 모듈러 값들을 모듈러 더하기로 구해준다.
		cin >> N >> S;
		answer = (answer + (S * Reverse(N)) % MOD) % MOD;
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
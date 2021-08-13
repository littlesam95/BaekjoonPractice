#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
long long N, K, M;
long long fac[2001];

// 뤼카의 정리 : M이 소수일 경우 nCr mod M을 구할 수 있는 방법
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K >> M;
	fac[0] = 1;
	for (int i = 1; i <= M - 1; i++) { // 1부터 M-1까지의 팩토리얼 수를 구함.
		fac[i] = fac[i - 1] * i;
		fac[i] %= M;
	}

	long long answer = 1;
	while (N && K) {
		int n = N % M; // 팩토리얼 수를 M으로 나눈 나머지를 구함.
		int k = K % M;
		if (n < k) {
			answer = 0;
			break;
		}
		answer *= fac[n]; // N!을 M으로 나눈 나머지 n, K!를 M으로 나눈 나머지 k를 이용하여 페르마의 소정리 이용.
		answer %= M;
		for (int i = 0; i < M - 2; i++) {
			answer *= fac[k];
			answer %= M;
			answer *= fac[n - k];
			answer %= M;
		}
		N /= M;
		K /= M;
	};
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
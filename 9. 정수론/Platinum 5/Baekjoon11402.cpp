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

// ��ī�� ���� : M�� �Ҽ��� ��� nCr mod M�� ���� �� �ִ� ���
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K >> M;
	fac[0] = 1;
	for (int i = 1; i <= M - 1; i++) { // 1���� M-1������ ���丮�� ���� ����.
		fac[i] = fac[i - 1] * i;
		fac[i] %= M;
	}

	long long answer = 1;
	while (N && K) {
		int n = N % M; // ���丮�� ���� M���� ���� �������� ����.
		int k = K % M;
		if (n < k) {
			answer = 0;
			break;
		}
		answer *= fac[n]; // N!�� M���� ���� ������ n, K!�� M���� ���� ������ k�� �̿��Ͽ� �丣���� ������ �̿�.
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
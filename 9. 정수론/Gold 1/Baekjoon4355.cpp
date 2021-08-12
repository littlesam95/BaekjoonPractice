#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;
long long N;

// ���Ϸ� �� �Լ� �˰��� : N�� ���μ��� N �̸��� ���� ���� ã��
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> N;
		if (N == 0) {
			break;
		}
		long long answer = N;
		for (long long i = 2; (i * i) <= N; i++) {
			if (N % i == 0) {
				answer /= i;
				answer *= (i - 1);
			}
			while (N % i == 0) {
				N /= i;
			}
		}
		if (N != 1) {
			answer /= N;
			answer *= (N - 1);
		}
		cout << answer << "\n";
	};

	getchar();
	getchar();
	return 0;
}
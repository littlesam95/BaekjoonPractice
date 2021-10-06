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

	while (Digit <= D) { // MOD-2������ �����Ͽ� ���ϴ� ����
		if (Digit & D) {
			B = (B * tmp) % MOD; // ��Ʈ�� 1�� �ڸ��������� B�� tmp�� ������
		}
		tmp = (tmp * tmp) % MOD; // tmp�� ��� �����������ν� �� ����
		Digit = Digit << 1;
	};
	return B;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> M;
	for (int i = 1; i <= M; i++) { // ���м��� ������ �ʰ� �� ��ⷯ ������ ��ⷯ ���ϱ�� �����ش�.
		cin >> N >> S;
		answer = (answer + (S * Reverse(N)) % MOD) % MOD;
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
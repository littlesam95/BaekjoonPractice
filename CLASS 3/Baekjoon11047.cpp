#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	int coin[10];

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	int count = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (K - coin[i] >= 0) {
			count += (K / coin[i]);
			K -= coin[i] * (K / coin[i]);
		}
	}

	cout << count;

	getchar();
	getchar();
	return 0;
}
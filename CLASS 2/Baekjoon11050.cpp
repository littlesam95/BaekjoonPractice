#include <iostream>

using namespace std;

int main() {
	int N, K;
	do {
		cin >> N >> K;
	} while ((N < 1) || (N > 10) || (K < 0) || (K > N));

	int sum = 1;
	for (int i = 0; i < K; i++) {
		sum *= N;
		N--;
	}
	int tmp = K;
	for (int i = 0; i < K - 1; i++) {
		sum /= tmp;
		tmp--;
	}

	cout << sum;

	getchar();
	getchar();
	return 0;
}
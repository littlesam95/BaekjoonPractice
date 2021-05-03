#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int*W = new int[N];
	int*K = new int[N];
	int*R = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> W[i] >> K[i];
	}

	int rank;
	for (int i = 0; i < N; i++) {
		rank = 1;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if ((W[i] < W[j]) && (K[i] < K[j])) {
				rank++;
			}
		}
		R[i] = rank;
	}

	for (int i = 0; i < N; i++) {
		cout << R[i] << " ";
	}

	getchar();
	getchar();
	return 0;
}
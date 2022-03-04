#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 301

using namespace std;
int N, M, R;
int A[MAX][MAX];

void Rotation() {
	int Count = min(N, M) / 2;
	for (int i = 0; i < Count; i++) {
		int newR = R % (2 * (M - i - i) + 2 * (N - i - i) - 4);
		while (newR--) {
			int Start = A[i][i];
			for (int j = i + 1; j < M - i; j++) {
				A[i][j - 1] = A[i][j];
			}
			for (int j = i + 1; j < N - i; j++) {
				A[j - 1][M - i - 1] = A[j][M - i - 1];
			}
			for (int j = M - i - 2; j >= i; j--) {
				A[N - i - 1][j + 1] = A[N - i - 1][j];
			}
			for (int j = N - i - 2; j >= i + 1; j--) {
				A[j + 1][i] = A[j][i];
			}
			A[i + 1][i] = Start;
		};
	}
}

int main() {
	FIRST
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	Rotation();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define MAX 1000001

using namespace std;
int N;
int DP[MAX];
bool visited[MAX];

void Calc(int X) {
	if (X == 1) {
		DP[X] = 0;
	}
	else if (X >= 2) {
		DP[X] = DP[X - 1] + 1;
		if (X % 2 == 0) {
			DP[X] = min(DP[X], DP[X / 2] + 1);
		}
		if (X % 3 == 0) {
			DP[X] = min(DP[X], DP[X / 3] + 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	DP[0] = -1;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		Calc(i);
	}
	cout << DP[N] << "\n";
	while (N != 0) {
		cout << N << " ";
		if (DP[N] - 1 == DP[N - 1]) {
			N -= 1;
		}
		else if ((N % 2 == 0) && (DP[N] - 1 == DP[N / 2])) {
			N /= 2;
		}
		else if ((N % 3 == 0) && (DP[N] - 1 == DP[N / 3])) {
			N /= 3;
		}
	};
	cout << "\n";

	getchar();
	getchar();
	return 0;
}
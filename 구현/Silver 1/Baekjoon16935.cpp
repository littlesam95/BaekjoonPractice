#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 101

using namespace std;
int N, M, R;
int MAP[MAX][MAX];

void FirstFunc() {
	int Count = N / 2;
	for (int i = 0; i < Count; i++) {
		for (int j = 0; j < M; j++) {
			int tmp = MAP[i][j];
			MAP[i][j] = MAP[N - i - 1][j];
			MAP[N - i - 1][j] = tmp;
		}
	}
}

void SecondFunc() {
	int Count = M / 2;
	for (int i = 0; i < Count; i++) {
		for (int j = 0; j < N; j++) {
			int tmp = MAP[j][i];
			MAP[j][i] = MAP[j][M - i - 1];
			MAP[j][M - i - 1] = tmp;
		}
	}
}

void ThirdFunc() {
	int tmp[MAX][MAX];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[j][N - i - 1] = MAP[i][j];
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			MAP[i][j] = tmp[i][j];
		}
	}
	swap(N, M);
}

void FourthFunc() {
	int tmp[MAX][MAX];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[M - j - 1][i] = MAP[i][j];
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			MAP[i][j] = tmp[i][j];
		}
	}
	swap(N, M);
}

void FifthFunc() {
	int tmp[MAX][MAX];
	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < (M / 2); j++) {
			tmp[i][j + (M / 2)] = MAP[i][j];
		}
	}
	for (int i = 0; i < (N / 2); i++) {
		for (int j = (M / 2); j < M; j++) {
			tmp[i + (N / 2)][j] = MAP[i][j];
		}
	}
	for (int i = (N / 2); i < N; i++) {
		for (int j = (M / 2); j < M; j++) {
			tmp[i][j - (M / 2)] = MAP[i][j];
		}
	}
	for (int i = (N / 2); i < N; i++) {
		for (int j = 0; j < (M / 2); j++) {
			tmp[i - (N / 2)][j] = MAP[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			MAP[i][j] = tmp[i][j];
		}
	}
}

void SixthFunc() {
	int tmp[MAX][MAX];
	for (int i = 0; i < (N / 2); i++) {
		for (int j = 0; j < (M / 2); j++) {
			tmp[i + (N / 2)][j] = MAP[i][j];
		}
	}
	for (int i = (N / 2); i < N; i++) {
		for (int j = 0; j < (M / 2); j++) {
			tmp[i][j + (M / 2)] = MAP[i][j];
		}
	}
	for (int i = (N / 2); i < N; i++) {
		for (int j = (M / 2); j < M; j++) {
			tmp[i - (N / 2)][j] = MAP[i][j];
		}
	}
	for (int i = 0; i < (N / 2); i++) {
		for (int j = (M / 2); j < M; j++) {
			tmp[i][j - (M / 2)] = MAP[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			MAP[i][j] = tmp[i][j];
		}
	}
}

int main() {
	FIRST
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		int Q;
		cin >> Q;
		if (Q == 1) {
			FirstFunc();
		}
		else if (Q == 2) {
			SecondFunc();
		}
		else if (Q == 3) {
			ThirdFunc();
		}
		else if (Q == 4) {
			FourthFunc();
		}
		else if (Q == 5) {
			FifthFunc();
		}
		else if (Q == 6) {
			SixthFunc();
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << MAP[i][j] << " ";
		}
		cout << "\n";
	}

	getchar();
	getchar();
	return 0;
}
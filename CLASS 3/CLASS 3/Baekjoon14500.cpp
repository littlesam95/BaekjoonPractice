#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int N, M;
int arr[501][501];
int res = 0;

void A1(int N, int M, int& res) { // 작대기 세로
	for (int i = 0; i < (N - 3); i++) {
		for (int j = 0; j < M; j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void A2(int N, int M, int& res) { // 작대기 가로
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < (M - 3); j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void B1(int N, int M, int& res) { // 정사각형
	for (int i = 0; i < (N - 1); i++) {
		for (int j = 0; j < (M - 1); j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void C1(int N, int M, int& res) { // ㄴ자 1
	for (int i = 0; i < (N - 2); i++) {
		for (int j = 0; j < (M - 1); j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void C2(int N, int M, int& res) { // ㄴ자 2
	for (int i = 0; i < (N - 1); i++) {
		for (int j = 0; j < (M - 2); j++) {
			int sum = 0;
			sum += arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j + 2];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void C3(int N, int M, int& res) { // ㄴ자 3
	for (int i = 0; i < (N - 2); i++) {
		for (int j = 0; j < (M - 1); j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void C4(int N, int M, int& res) { // ㄴ자 4
	for (int i = 0; i < (N - 1); i++) {
		for (int j = 0; j < (M - 2); j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void C5(int N, int M, int& res) { // ㄴ자 5
	for (int i = 0; i < (N - 2); i++) {
		for (int j = 0; j < (M - 1); j++) {
			int sum = 0;
			sum += arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1] + arr[i + 2][j];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void C6(int N, int M, int& res) { // ㄴ자 6
	for (int i = 0; i < (N - 1); i++) {
		for (int j = 0; j < (M - 2); j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void C7(int N, int M, int& res) { // ㄴ자 7
	for (int i = 0; i < (N - 2); i++) {
		for (int j = 0; j < (M - 1); j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void C8(int N, int M, int& res) { // ㄴ자 8
	for (int i = 0; i < (N - 1); i++) {
		for (int j = 0; j < (M - 2); j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void D1(int N, int M, int& res) { // ㄹ자 1
	for (int i = 0; i < (N - 2); i++) {
		for (int j = 0; j < (M - 1); j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void D2(int N, int M, int& res) { // ㄹ자 2
	for (int i = 0; i < (N - 1); i++) {
		for (int j = 0; j < (M - 2); j++) {
			int sum = 0;
			sum += arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i][j + 2];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void D3(int N, int M, int& res) { // ㄹ자 3
	for (int i = 0; i < (N - 2); i++) {
		for (int j = 0; j < (M - 1); j++) {
			int sum = 0;
			sum += arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j] + arr[i + 2][j];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void D4(int N, int M, int& res) { // ㄹ자 4
	for (int i = 0; i < (N - 1); i++) {
		for (int j = 0; j < (M - 2); j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void E1(int N, int M, int& res) { // ㅗ자 1
	for (int i = 0; i < (N - 1); i++) {
		for (int j = 0; j < (M - 2); j++) {
			int sum = 0;
			sum += arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void E2(int N, int M, int& res) { // ㅗ자 2
	for (int i = 0; i < (N - 2); i++) {
		for (int j = 0; j < (M - 1); j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void E3(int N, int M, int& res) { // ㅗ자 3
	for (int i = 0; i < (N - 1); i++) {
		for (int j = 0; j < (M - 2); j++) {
			int sum = 0;
			sum += arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

void E4(int N, int M, int& res) { // ㅗ자 4
	for (int i = 0; i < (N - 2); i++) {
		for (int j = 0; j < (M - 1); j++) {
			int sum = 0;
			sum += arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			if (res < sum) {
				res = sum;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	A1(N, M, res);
	A2(N, M, res);
	B1(N, M, res);
	C1(N, M, res);
	C2(N, M, res);
	C3(N, M, res);
	C4(N, M, res);
	C5(N, M, res);
	C6(N, M, res);
	C7(N, M, res);
	C8(N, M, res);
	D1(N, M, res);
	D2(N, M, res);
	D3(N, M, res);
	D4(N, M, res);
	E1(N, M, res);
	E2(N, M, res);
	E3(N, M, res);
	E4(N, M, res);

	cout << res;

	getchar();
	getchar();
	return 0;
}
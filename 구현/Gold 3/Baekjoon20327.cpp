#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 150
#define INF 1e9

using namespace std;
int N, Q;
int A_Size;
int A[MAX][MAX];

void First_Operation(int L) {
	int Cnt = 0;
	int tmp[MAX][MAX];
	for (int i = 0; i < A_Size; i++) {
		for (int j = 0; j < A_Size; j++) {
			tmp[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < A_Size; i += L) {
		for (int j = 0; j < A_Size; j += L) {
			int Y = i;
			int X = j;
			for (int k = Y; k < (Y + L); k++) {
				for (int l = X; l < (X + L); l++) {
					A[Y + L - 1 - k + (L * Cnt)][l] = tmp[k][l];
				}
			}
		}
		Cnt++;
		/*
			1번 예제에서 (2, 0)을 좌우 반전하면 (3, 0)이 되는데,
			A[(Y + L - 1) - k][l] = (1, 0)이 되므로, L을 1번 더해주어야
			(3, 0)이 된다. 이 L을 몇 번 더할 건지는 Cnt라는 변수가 정해준다.
		*/
	}
}

void Second_Operation(int L) {
	int Cnt = 0;
	int tmp[MAX][MAX];
	for (int i = 0; i < A_Size; i++) {
		for (int j = 0; j < A_Size; j++) {
			tmp[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < A_Size; i += L) {
		for (int j = 0; j < A_Size; j += L) {
			int Y = i;
			int X = j;
			for (int k = Y; k < (Y + L); k++) {
				for (int l = X; l < (X + L); l++) {
					A[k][X + L - 1 - l + (L * Cnt)] = tmp[k][l];
				}
			}
			Cnt++;
		}
		Cnt = 0;
	}
}

void Third_Operation(int L) {
	int R = 0, C = 0, Cnt = 0;
	int tmp[MAX][MAX];
	for (int i = 0; i < A_Size; i++) {
		for (int j = 0; j < A_Size; j++) {
			tmp[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < A_Size; i += L) {
		for (int j = 0; j < A_Size; j += L) {
			int Y = i;
			int X = j;
			for (int k = Y; k < (Y + L); k++) {
				for (int l = X; l < (X + L); l++) {
					A[l - (L * R) + (L * Cnt)][Y + L - 1 - k + (L * C)] = tmp[k][l];
				}
			}
			R++;
			C++;
		}
		Cnt++;
		R = 0;
		C = 0;
		/*
			마찬가지로 R, C라는 변수를 이용해서 범위 안에서만 회전하도록 해준다.
		*/
	}
}

void Fourth_Operation(int L) {
	int R = 0, C = 0, Cnt = 0;
	int tmp[MAX][MAX];
	for (int i = 0; i < A_Size; i++) {
		for (int j = 0; j < A_Size; j++) {
			tmp[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < A_Size; i += L) {
		for (int j = 0; j < A_Size; j += L) {
			int Y = i;
			int X = j;
			for (int k = Y; k < (Y + L); k++) {
				for (int l = X; l < (X + L); l++) {
					A[X + L - 1 - l + (L * R)][k + (L * C) - (L * Cnt)] = tmp[k][l];
				}
			}
			C++;
		}
		Cnt++;
		R++;
		C = 0;
	}
}

void Fifth_Operation(int L) {
	First_Operation(A_Size); // 전체를 상하반전
	First_Operation(L); // 이후 부분만 다시 상하반전시킨다.
	// 결과적으로 부분을 유지한 채로 전체가 상하반전된다.
}

void Sixth_Operation(int L) {
	Second_Operation(A_Size); // 전체를 좌우반전
	Second_Operation(L); // 이후 부분만 다시 좌우반전시킨다.
	// 결과적으로 부분을 유지한 채로 전체가 좌우반전된다.
}

void Seventh_Operation(int L) {
	Third_Operation(A_Size); // 전체를 시계방향 90도 회전
	Fourth_Operation(L); // 이후 부분만 다시 반시계 방향으로 90도 회전
	// 결과적으로 부분을 유지한 채로 전체가 시계방향으로 90도 회전된다.
}

void Eighth_Operation(int L) {
	Fourth_Operation(A_Size); // 전체를 반시계방향 90도 회전
	Third_Operation(L); // 이후 부분만 다시 시계 방향으로 90도 회전
	// 결과적으로 부분을 유지한 채로 전체가 반시계방향으로 90도 회전된다.
}

int main() {
	FIRST
	cin >> N >> Q;
	A_Size = (1 << N);
	for (int i = 0; i < A_Size; i++) {
		for (int j = 0; j < A_Size; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < Q; i++) {
		int K, L;
		cin >> K >> L;
		int Len = (1 << L);
		if (K == 1) {
			First_Operation(Len);
		}
		else if (K == 2) {
			Second_Operation(Len);
		}
		else if (K == 3) {
			Third_Operation(Len);
		}
		else if (K == 4) {
			Fourth_Operation(Len);
		}
		else if (K == 5) {
			Fifth_Operation(Len);
		}
		else if (K == 6) {
			Sixth_Operation(Len);
		}
		else if (K == 7) {
			Seventh_Operation(Len);
		}
		else if (K == 8) {
			Eighth_Operation(Len);
		}
	}
	for (int i = 0; i < A_Size; i++) {
		for (int j = 0; j < A_Size; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}

	getchar();
	getchar();
	return 0;
}
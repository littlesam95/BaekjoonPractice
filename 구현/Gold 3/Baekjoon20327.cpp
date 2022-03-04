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
			1�� �������� (2, 0)�� �¿� �����ϸ� (3, 0)�� �Ǵµ�,
			A[(Y + L - 1) - k][l] = (1, 0)�� �ǹǷ�, L�� 1�� �����־��
			(3, 0)�� �ȴ�. �� L�� �� �� ���� ������ Cnt��� ������ �����ش�.
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
			���������� R, C��� ������ �̿��ؼ� ���� �ȿ����� ȸ���ϵ��� ���ش�.
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
	First_Operation(A_Size); // ��ü�� ���Ϲ���
	First_Operation(L); // ���� �κи� �ٽ� ���Ϲ�����Ų��.
	// ��������� �κ��� ������ ä�� ��ü�� ���Ϲ����ȴ�.
}

void Sixth_Operation(int L) {
	Second_Operation(A_Size); // ��ü�� �¿����
	Second_Operation(L); // ���� �κи� �ٽ� �¿������Ų��.
	// ��������� �κ��� ������ ä�� ��ü�� �¿�����ȴ�.
}

void Seventh_Operation(int L) {
	Third_Operation(A_Size); // ��ü�� �ð���� 90�� ȸ��
	Fourth_Operation(L); // ���� �κи� �ٽ� �ݽð� �������� 90�� ȸ��
	// ��������� �κ��� ������ ä�� ��ü�� �ð�������� 90�� ȸ���ȴ�.
}

void Eighth_Operation(int L) {
	Fourth_Operation(A_Size); // ��ü�� �ݽð���� 90�� ȸ��
	Third_Operation(L); // ���� �κи� �ٽ� �ð� �������� 90�� ȸ��
	// ��������� �κ��� ������ ä�� ��ü�� �ݽð�������� 90�� ȸ���ȴ�.
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
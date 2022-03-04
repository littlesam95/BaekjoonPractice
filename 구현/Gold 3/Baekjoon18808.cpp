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
#define MAX 45
#define STICKER_MAX 105
#define INF 1e9

using namespace std;
int N, M, K, R, C;
int MAP[MAX][MAX];
int Sticker[MAX][MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			Sticker[i][j] = 0;
		}
	}
}

int Calc_Sum() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			res += MAP[i][j];
		}
	}
	return res;
}

void Rotation() {
	/*
		������ �ð�������� ȸ��
	*/
	int tmp[MAX][MAX];
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			tmp[i][R - 1 - j] = Sticker[j][i];
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			Sticker[i][j] = tmp[i][j];
		}
	}
	swap(R, C);
}

bool Check_Sticking_Able(int Y, int X) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int nextY = i + Y; // ��ƼĿ�� ���� ��ġ(Y��ǥ)
			int nextX = j + X; // ��ƼĿ�� ���� ��ġ(X��ǥ)
			if ((Sticker[i][j] == 1) && (MAP[nextY][nextX] == 1)) {
				// ��ƼĿ�� ���� ��ġ�� �̹� ��ƼĿ�� �ٿ��� �ִٸ� False
				return false;
			}
			// �� ���� ���� True
		}
	}
	return true;
}

void Sticking(int Y, int X) {
	// �̹� Check_Sticking_Able() �Լ��� ��ƼĿ�� ���� �� �ִٰ� �Ǵ��߱� ������ ���� ���� ���̸� �ȴ�.
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int nextY = i + Y;
			int nextX = j + X;
			if (Sticker[i][j] == 1) {
				MAP[nextY][nextX] = Sticker[i][j];
			}
		}
	}
}

bool Sticker_Attach() {
	for (int i = 0; i < (N - R + 1); i++) {
		for (int j = 0; j < (M - C + 1); j++) {
			// ���� �� ĭ�� ���������� �Ͽ�, ���� �� ĭ���� ��ƼĿ�� ���� ��ġ�� ã�´�.
			if (Check_Sticking_Able(i, j)) { // ��ƼĿ�� ���� �� �ִ� �� Ȯ��
				Sticking(i, j); // ��ƼĿ�� ���δ�.
				return true;
			}
		}
	}
	return false;
}

int main() {
	FIRST
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		init();
		// K���� ��ƼĿ���� ������ �Է¹޴´�.
		cin >> R >> C;
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				cin >> Sticker[j][k];
			}
		}
		bool isAttach = Sticker_Attach();
		if (isAttach) {
			continue;
		}
		for (int k = 0; k < 3; k++) {
			Rotation(); // �ð� �������� 90�� ȸ���� ����
			isAttach = Sticker_Attach();
			if (isAttach) {
				break;
			}
		}
	}
	cout << Calc_Sum() << "\n"; // ���� �ִ� ���ڵ��� ��

	getchar();
	getchar();
	return 0;
}
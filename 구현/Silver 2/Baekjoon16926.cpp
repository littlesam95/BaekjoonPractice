#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 301
#define INF 1e9

using namespace std;
int N, M, R;
int MAP[MAX][MAX];

void Rotate() {
	int Count = min(N, M) / 2;
	for (int i = 0; i < Count; i++) {
		int N_MAX = N - i - 1;
		int M_MAX = M - i - 1;
		int start = MAP[i][i];
		// ���� �� �� <- ��
		for (int j = i; j < M_MAX; j++) {
			MAP[i][j] = MAP[i][j + 1];
		}
		// ������ �� �� <- �Ʒ�
		for (int j = i; j < N_MAX; j++) {
			MAP[j][M_MAX] = MAP[j + 1][M_MAX];
		}
		// �Ʒ��� �� �� <- ��
		for (int j = M_MAX; j > i; j--) {
			MAP[N_MAX][j] = MAP[N_MAX][j - 1];
		}
		// ���� �� �Ʒ� <- ��
		for (int j = N_MAX; j > i; j--) {
			MAP[j][i] = MAP[j - 1][i];
		}
		MAP[i + 1][i] = start;
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
	while (R--) {
		Rotate();
	};
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
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
#define MAX 55
#define INF 1e9

using namespace std;
int N, M, T;
int MAP[MAX][MAX];
bool Will_Erase[MAX][MAX];

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			Will_Erase[i][j] = false;
		}
	}
}

void Rotation(int X, int D, int K) {
	/*
		���� ȸ���� ���� ������ �����Ͽ�,
		�ð� �������� ȸ������ ���� Back�� K���� ���ڰ� pop�Ǿ �ٽ� ���� front�� push�ǰ�,
		�ݽð� �������� ȸ������ ���� front�� K���� ���ڰ� pop�Ǿ �ٽ� ���� back���� push�ǰ� �Ͽ���.
		���� ���� ���� �������� �� ���Ƽ� ���� ���� �ʾҰ� �迭�� ����Ͽ���.
	*/
	for (int i = X; i <= N; i += X) {
		if (D == 0) {
			int tmp[MAX];
			for (int j = 1; j <= M; j++) {
				tmp[j] = MAP[i][j];
			}
			for (int j = 1; j <= (M - K); j++) {
				MAP[i][j + K] = tmp[j];
			}
			for (int j = (M - K + 1); j <= M; j++) {
				MAP[i][j - (M - K)] = tmp[j];
			}
		}
		else if (D == 1) {
			int tmp[MAX];
			for (int j = 1; j <= M; j++) {
				tmp[j] = MAP[i][j];
			}
			for (int j = 1; j <= K; j++) {
				MAP[i][j + (M - K)] = tmp[j];
			}
			for (int j = K + 1; j <= M; j++) {
				MAP[i][j - K] = tmp[j];
			}
		}
	}
}

void Erase_Number() {
	init();
	bool Same_Number = false; // ���� ���ڰ� �־� ���ڰ� �������ٸ� true�� �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] == 0) {
				continue;
			}
			int Left = j - 1;
			int Right = j + 1;
			int Top = i + 1;
			int Bottom = i - 1;
			if (Left == 0) { // j�� 1�̶�� ������ ���ڴ� M��° ���ڰ� �� ���̴�.
				Left = M;
			}
			if (Right == M + 1) { // j�� M�̶�� �������� ���ڴ� 1��° ���ڰ� �� ���̴�.
				Right = 1;
			}
			bool Flag = false; // ���� ���ڰ� �ϳ��� �����Ѵٸ� true�� �ʱ�ȭ
			if (MAP[i][j] == MAP[i][Left]) {
				Flag = true;
				Will_Erase[i][Left] = true; // ���� ���ڸ� ��ŷ
			}
			if (MAP[i][j] == MAP[i][Right]) {
				Flag = true;
				Will_Erase[i][Right] = true;
			}
			if (MAP[i][j] == MAP[Top][j]) {
				if (i < N) {
					Flag = true;
					Will_Erase[Top][j] = true;
				}
			}
			if (MAP[i][j] == MAP[Bottom][j]) {
				if (i > 1) {
					Flag = true;
					Will_Erase[Bottom][j] = true;
				}
			}
			if (Flag) {
				Will_Erase[i][j] = true;
				Same_Number = true;
			}
		}
	}
	if (Same_Number) {
		// ���� ���ڰ� �����Ѵٸ� ��ŷ�� ���ڵ��� �����.
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (Will_Erase[i][j]) {
					MAP[i][j] = 0;
				}
			}
		}
	}
	else { // ���� ���ڰ� �������� �ʴ´ٸ�
		int sum = 0;
		int size = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (MAP[i][j] > 0) {
					sum += MAP[i][j];
					size++;
				}
			}
		}
		// ����� ���Ѵ�. �� ��պ��� ���� ���ڴ� -1, ���� ���ڴ� +1�Ѵ�.
		double avg = (double)sum / (double)size;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (MAP[i][j] > 0) {
					if (avg > (double)MAP[i][j]) {
						MAP[i][j]++;
					}
					else if (avg < (double)MAP[i][j]) {
						MAP[i][j]--;
					}
				}
			}
		}
	}
}

int Calc_Sum() {
	// ���ǿ� ���� �ִ� ��� ���ڵ��� ���Ѵ�.
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			res += MAP[i][j];
		}
	}
	return res;
}

int main() {
	FIRST
	cin >> N >> M >> T;
	// ������ ó�� ���� ����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < T; i++) {
		int X, D, K;
		cin >> X >> D >> K;
		// ���� ȸ��
		Rotation(X, D, K);
		// ���� �� �ִ� ���� �����
		Erase_Number();
	}
	cout << Calc_Sum() << "\n"; // ���� �ִ� ���ڵ��� ��

	getchar();
	getchar();
	return 0;
}
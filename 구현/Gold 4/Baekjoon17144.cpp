#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 51
#define INF 2e9

using namespace std;
struct CLEANER {
	int Y, X;
};

int R, C, T;
int MAP[MAX][MAX];
int tmpM[MAX][MAX];
int moveY[4] = { 0,0,1,-1 };
int moveX[4] = { 1,-1,0,0 };
vector<CLEANER> cleaner;
long long answer = 0;

void Copy_MAP(int A[][MAX], int B[][MAX]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			A[i][j] = B[i][j];
		}
	}
}

void Move_Dust() {
	Copy_MAP(tmpM, MAP);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if ((MAP[i][j] != 0) && (MAP[i][j] != -1)) {
				int Dir_Count = 0;
				int Dust_Size = MAP[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int nextY = i + moveY[k];
					int nextX = j + moveX[k];
					if ((nextY < 0) || (nextY >= R) || (nextX < 0) || (nextX >= C) || (MAP[nextY][nextX] == -1)) {
						continue;
					}
					tmpM[nextY][nextX] += Dust_Size;
					Dir_Count++;
				}
				tmpM[i][j] -= (Dust_Size * Dir_Count);
			}
		}
	}
	Copy_MAP(MAP, tmpM);
}

void Operate_Cleaner_Up() {
	// 아래쪽 행
	int tmp1 = MAP[cleaner[0].Y][C - 1];
	for (int i = C - 2; i >= 0; i--) {
		MAP[cleaner[0].Y][i + 1] = MAP[cleaner[0].Y][i];
		if (MAP[cleaner[0].Y][i + 1] == -1) {
			MAP[cleaner[0].Y][i + 1] = 0;
		}
	}
	// 오른쪽 열
	int tmp2 = MAP[0][C - 1];
	for (int i = 1; i <= cleaner[0].Y - 1; i++) {
		MAP[i - 1][C - 1] = MAP[i][C - 1];
	}
	MAP[cleaner[0].Y - 1][C - 1] = tmp1;
	// 위쪽 행
	int tmp3 = MAP[0][0];
	for (int i = 1; i <= C - 2; i++) {
		MAP[0][i - 1] = MAP[0][i];
	}
	MAP[0][C - 2] = tmp2;
	// 왼쪽 열
	for (int i = cleaner[0].Y - 2; i >= 1; i--) {
		MAP[i + 1][0] = MAP[i][0];
	}
	MAP[1][0] = tmp3;
}

void Operate_Cleaner_Down() {
	// 위쪽 행
	int tmp1 = MAP[cleaner[1].Y][C - 1];
	for (int i = C - 2; i >= 0; i--) {
		MAP[cleaner[1].Y][i + 1] = MAP[cleaner[1].Y][i];
		if (MAP[cleaner[1].Y][i + 1] == -1) {
			MAP[cleaner[1].Y][i + 1] = 0;
		}
	}
	// 오른쪽 열
	int tmp2 = MAP[R - 1][C - 1];
	for (int i = R - 2; i >= cleaner[1].Y + 1; i--) {
		MAP[i + 1][C - 1] = MAP[i][C - 1];
	}
	MAP[cleaner[1].Y + 1][C - 1] = tmp1;
	// 아래쪽 행
	int tmp3 = MAP[R - 1][0];
	for (int i = 1; i < C - 1; i++) {
		MAP[R - 1][i - 1] = MAP[R - 1][i];
	}
	MAP[R - 1][C - 2] = tmp2;
	// 왼쪽 열
	for (int i = cleaner[1].Y + 2; i < R; i++) {
		MAP[i - 1][0] = MAP[i][0];
	}
	MAP[R - 2][0] = tmp3;
}

void Count_Dust() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] >= 1) {
				answer += MAP[i][j];
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == -1) {
				cleaner.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i < T; i++) {
		Move_Dust();
		Operate_Cleaner_Up();
		Operate_Cleaner_Down();
	}
	Count_Dust();
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
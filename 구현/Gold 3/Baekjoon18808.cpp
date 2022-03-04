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
		무조건 시계방향으로 회전
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
			int nextY = i + Y; // 스티커를 붙일 위치(Y좌표)
			int nextX = j + X; // 스티커를 붙일 위치(X좌표)
			if ((Sticker[i][j] == 1) && (MAP[nextY][nextX] == 1)) {
				// 스티커를 붙일 위치에 이미 스티커가 붙여져 있다면 False
				return false;
			}
			// 그 외의 경우는 True
		}
	}
	return true;
}

void Sticking(int Y, int X) {
	// 이미 Check_Sticking_Able() 함수로 스티커를 붙일 수 있다고 판단했기 때문에 조건 없이 붙이면 된다.
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
			// 왼쪽 위 칸을 시작점으로 하여, 왼쪽 위 칸부터 스티커를 붙일 위치를 찾는다.
			if (Check_Sticking_Able(i, j)) { // 스티커를 붙일 수 있는 지 확인
				Sticking(i, j); // 스티커를 붙인다.
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
		// K개의 스티커들의 정보를 입력받는다.
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
			Rotation(); // 시계 방향으로 90도 회전을 수행
			isAttach = Sticker_Attach();
			if (isAttach) {
				break;
			}
		}
	}
	cout << Calc_Sum() << "\n"; // 남아 있는 숫자들의 합

	getchar();
	getchar();
	return 0;
}
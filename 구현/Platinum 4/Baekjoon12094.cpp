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
#define MAX 25
#define MAX_N 10005
#define LL long long
#define INF 1e9

using namespace std;
int N;
int MAP[MAX][MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,-1,0,1 };
bool visited[MAX][MAX];
int answer = 0;

// 모든 경우의 수를 따져야 하므로, 맵을 복사해 주는 것이 편할 것이다.
void Copy_MAP(int A[][MAX], int B[][MAX]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = B[i][j];
		}
	}
}

// 현재 보드의 상태와 보드를 움직였을 때의 보드의 상태를 비교한다.
bool Cur_Tmp_Same(int A[][MAX], int B[][MAX]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] != B[i][j]) {
				return false;
			}
		}
	}
	return true;
}

int Board_Move(int Dir, int Tmp_MAP[][MAX]) {
	int Max_Board = 0;
	if (Dir == 0) { // 모든 블록이 위쪽으로 이동
		for (int j = 0; j < N; j++) {
			int Value = -1;
			int H = -1;
			for (int i = 0; i < N; i++) {
				if (Tmp_MAP[i][j] == 0) {
					continue;
				}
				if (Tmp_MAP[i][j] == Value) {
					Tmp_MAP[H][j] *= 2;
					Value = -1;
				}
				else {
					Value = Tmp_MAP[i][j];
					H++;
					Tmp_MAP[H][j] = Tmp_MAP[i][j];
				}
				Max_Board = max(Max_Board, Tmp_MAP[H][j]);
			}
			for (int i = (H + 1); i < N; i++) {
				Tmp_MAP[i][j] = 0;
			}
		}
	}
	else if (Dir == 1) { // 모든 블록이 왼쪽으로 이동
		for (int i = 0; i < N; i++) {
			int Value = -1;
			int W = -1;
			for (int j = 0; j < N; j++) {
				if (Tmp_MAP[i][j] == 0) {
					continue;
				}
				if (Tmp_MAP[i][j] == Value) {
					Tmp_MAP[i][W] *= 2;
					Value = -1;
				}
				else {
					Value = Tmp_MAP[i][j];
					W++;
					Tmp_MAP[i][W] = Tmp_MAP[i][j];
				}
				Max_Board = max(Max_Board, Tmp_MAP[i][W]);
			}
			for (int j = (W + 1); j < N; j++) {
				Tmp_MAP[i][j] = 0;
			}
		}
	}
	else if (Dir == 2) { // 모든 블록이 아래쪽으로 이동
		for (int j = 0; j < N; j++) {
			int Value = -1;
			int H = N;
			for (int i = (N - 1); i >= 0; i--) {
				if (Tmp_MAP[i][j] == 0) {
					continue;
				}
				if (Tmp_MAP[i][j] == Value) {
					Tmp_MAP[H][j] *= 2;
					Value = -1;
				}
				else {
					Value = Tmp_MAP[i][j];
					H--;
					Tmp_MAP[H][j] = Tmp_MAP[i][j];
				}
				Max_Board = max(Max_Board, Tmp_MAP[H][j]);
			}
			for (int i = (H - 1); i >= 0; i--) {
				Tmp_MAP[i][j] = 0;
			}
		}
	}
	else if (Dir == 3) { // 모든 블록이 오른쪽으로 이동
		for (int i = 0; i < N; i++) {
			int Value = -1;
			int W = N;
			for (int j = (N - 1); j >= 0; j--) {
				if (Tmp_MAP[i][j] == 0) {
					continue;
				}
				if (Tmp_MAP[i][j] == Value) {
					Tmp_MAP[i][W] *= 2;
					Value = -1;
				}
				else {
					Value = Tmp_MAP[i][j];
					W--;
					Tmp_MAP[i][W] = Tmp_MAP[i][j];
				}
				Max_Board = max(Max_Board, Tmp_MAP[i][W]);
			}
			for (int j = (W - 1); j >= 0; j--) {
				Tmp_MAP[i][j] = 0;
			}
		}
	}

	return Max_Board;
}

void DFS(int Depth, int Cur_MAP[][MAX], int Max_Board) {
	if (Depth == 10) {
		answer = Max_Board;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int Tmp_MAP[MAX][MAX];
		int Next_Max_Board;

		Copy_MAP(Tmp_MAP, Cur_MAP);
		Next_Max_Board = Board_Move(i, Tmp_MAP);
		if (Cur_Tmp_Same(Cur_MAP, Tmp_MAP)) {
			// 블록들을 이동시켰는데도 변화가 없다면, i방향으로는 Depth번째 이상을 확인해 줄 필요가 없다.
			continue;
		}
		if (answer < (Next_Max_Board * pow(2, 9 - Depth))) {
			// 기댓값이 현재 구한 보드의 숫자의 최댓값보다 크다면 탐색을 더 진행할 가치가 있다.
			DFS(Depth + 1, Tmp_MAP, Next_Max_Board);
		}
	}
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &MAP[i][j]);
			answer = max(answer, MAP[i][j]);
		}
	}
	DFS(0, MAP, answer);
	printf("%d", answer);
	printf("\n");

	getchar();
	getchar();
	return 0;
}
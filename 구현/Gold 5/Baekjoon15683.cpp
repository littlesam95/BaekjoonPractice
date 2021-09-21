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
#define MAX 9
#define INF 2e9

using namespace std;
struct Info {
	int idx, Y, X;
};

int N, M;
int arr[MAX][MAX];
vector<Info> CCTV;
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,1,0,-1 };
int answer = INF;

void Copy_arr(int tmp_arr[][MAX]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp_arr[i][j] = arr[i][j];
		}
	}
}

void Return_arr(int tmp_arr[][MAX]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr[i][j] = tmp_arr[i][j];
		}
	}
}

void DFS(int depth) {
	if (depth == CCTV.size()) {
		int size = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 0) {
					size++;
				}
			}
		}
		answer = min(answer, size);
		return;
	}
	int Y = CCTV[depth].Y;
	int X = CCTV[depth].X;
	int IDX = CCTV[depth].idx;
	if (IDX == 1) {
		for (int i = 0; i < 4; i++) {
			int tmp_arr[MAX][MAX];
			Copy_arr(tmp_arr);
			for (int j = 1; j < MAX; j++) {
				int nextY = Y + moveY[i] * j;
				int nextX = X + moveX[i] * j;
				if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
					break;
				}
				if (arr[nextY][nextX] <= 0) {
					arr[nextY][nextX] = -1;
				}
			}
			DFS(depth + 1);
			Return_arr(tmp_arr);
		}
	}
	else if (IDX == 2) {
		int tmp_arr1[MAX][MAX];
		Copy_arr(tmp_arr1);
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[0] * i;
			int nextX = X + moveX[0] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[2] * i;
			int nextX = X + moveX[2] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		DFS(depth + 1);
		Return_arr(tmp_arr1);
		int tmp_arr2[MAX][MAX];
		Copy_arr(tmp_arr2);
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[1] * i;
			int nextX = X + moveX[1] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[3] * i;
			int nextX = X + moveX[3] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		DFS(depth + 1);
		Return_arr(tmp_arr2);
	}
	else if (IDX == 3) {
		int tmp_arr1[MAX][MAX];
		Copy_arr(tmp_arr1);
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[0] * i;
			int nextX = X + moveX[0] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[1] * i;
			int nextX = X + moveX[1] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		DFS(depth + 1);
		Return_arr(tmp_arr1);
		int tmp_arr2[MAX][MAX];
		Copy_arr(tmp_arr2);
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[1] * i;
			int nextX = X + moveX[1] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[2] * i;
			int nextX = X + moveX[2] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		DFS(depth + 1);
		Return_arr(tmp_arr2);
		int tmp_arr3[MAX][MAX];
		Copy_arr(tmp_arr3);
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[2] * i;
			int nextX = X + moveX[2] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[3] * i;
			int nextX = X + moveX[3] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		DFS(depth + 1);
		Return_arr(tmp_arr3);
		int tmp_arr4[MAX][MAX];
		Copy_arr(tmp_arr4);
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[3] * i;
			int nextX = X + moveX[3] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[0] * i;
			int nextX = X + moveX[0] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		DFS(depth + 1);
		Return_arr(tmp_arr4);
	}
	else if (IDX == 4) {
		int tmp_arr1[MAX][MAX];
		Copy_arr(tmp_arr1);
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[0] * i;
			int nextX = X + moveX[0] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[1] * i;
			int nextX = X + moveX[1] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[2] * i;
			int nextX = X + moveX[2] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		DFS(depth + 1);
		Return_arr(tmp_arr1);
		int tmp_arr2[MAX][MAX];
		Copy_arr(tmp_arr2);
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[1] * i;
			int nextX = X + moveX[1] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[2] * i;
			int nextX = X + moveX[2] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[3] * i;
			int nextX = X + moveX[3] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		DFS(depth + 1);
		Return_arr(tmp_arr2);
		int tmp_arr3[MAX][MAX];
		Copy_arr(tmp_arr3);
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[2] * i;
			int nextX = X + moveX[2] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[3] * i;
			int nextX = X + moveX[3] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[0] * i;
			int nextX = X + moveX[0] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		DFS(depth + 1);
		Return_arr(tmp_arr3);
		int tmp_arr4[MAX][MAX];
		Copy_arr(tmp_arr4);
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[3] * i;
			int nextX = X + moveX[3] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[0] * i;
			int nextX = X + moveX[0] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		for (int i = 1; i < MAX; i++) {
			int nextY = Y + moveY[1] * i;
			int nextX = X + moveX[1] * i;
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
				break;
			}
			if (arr[nextY][nextX] <= 0) {
				arr[nextY][nextX] = -1;
			}
		}
		DFS(depth + 1);
		Return_arr(tmp_arr4);
	}
	else if (IDX == 5) {
		int tmp_arr[MAX][MAX];
		Copy_arr(tmp_arr);
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j < MAX; j++) {
				int nextY = Y + moveY[i] * j;
				int nextX = X + moveX[i] * j;
				if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= M) || (arr[nextY][nextX] == 6)) {
					break;
				}
				if (arr[nextY][nextX] <= 0) {
					arr[nextY][nextX] = -1;
				}
			}
		}
		DFS(depth + 1);
		Return_arr(tmp_arr);
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
			if ((arr[i][j] >= 1) && (arr[i][j] <= 5)) {
				CCTV.push_back({ arr[i][j],i,j });
			}
		}
	}
	DFS(0);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 4
#define INF 2e9

using namespace std;
struct Info {
	int Y, X, dir;
	bool state;
};

int arr[MAX][MAX];
Info fish[17];
int moveY[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int moveX[9] = { 0,0,-1,-1,-1,0,1,1,1 };
// 방향 B = 1이라면 북쪽으로 이동, B가 증가할 때마다 반시계 방향으로 45도만큼 방향이 바뀜.
int answer = 0;

void fish_move() {
	for (int i = 1; i <= (MAX * MAX); i++) { // 1번부터 16번 물고기까지 번호가 작은 순서대로 움직인다.
		if (!fish[i].state) { // i번째 물고기가 죽은 상태라면 움직이지 않는다.
			continue;
		}
		int Y = fish[i].Y;
		int X = fish[i].X;
		int dir = fish[i].dir;
		int nextY = Y + moveY[dir];
		int nextX = X + moveX[dir];
		bool flag = false;
		if ((nextY >= 0) && (nextY < MAX) && (nextX >= 0) && (nextX < MAX)) {
			if (arr[nextY][nextX] == 0) { // 다음 이동할 칸이 빈 칸이다.
				flag = true;
				fish[i].Y = nextY;
				fish[i].X = nextX;
				arr[nextY][nextX] = i;
				arr[Y][X] = 0;
			}
			else if (arr[nextY][nextX] != -1) { // 다음 이동할 칸에 물고기가 있다.
				flag = true;
				int nextIdx = arr[nextY][nextX];
				Info tmp = fish[nextIdx];
				fish[nextIdx].Y = fish[i].Y;
				fish[nextIdx].X = fish[i].X;
				fish[i].Y = tmp.Y;
				fish[i].X = tmp.X;
				swap(arr[Y][X], arr[nextY][nextX]);
			}
		}
		if (!flag) {
			int newDir = dir + 1;
			if (newDir > 8) {
				newDir = 1;
			}
			nextY = Y + moveY[newDir];
			nextX = X + moveX[newDir];
			while (newDir != dir) {
				if ((nextY >= 0) && (nextY < MAX) && (nextX >= 0) && (nextX < MAX)) {
					if (arr[nextY][nextX] == 0) { // 다음 이동할 칸이 빈 칸이다.
						fish[i].Y = nextY;
						fish[i].X = nextX;
						fish[i].dir = newDir;
						arr[nextY][nextX] = i;
						arr[Y][X] = 0;
						break;
					}
					else if (arr[nextY][nextX] != -1) { // 다음 이동할 칸에 물고기가 있다.
						int nextIdx = arr[nextY][nextX];
						Info tmp = fish[nextIdx];
						fish[nextIdx].Y = fish[i].Y;
						fish[nextIdx].X = fish[i].X;
						fish[i].Y = tmp.Y;
						fish[i].X = tmp.X;
						swap(arr[Y][X], arr[nextY][nextX]);
						fish[i].dir = newDir;
						break;
					}
				}
				newDir++;
				if (newDir > 8) {
					newDir = 1;
				}
				nextY = Y + moveY[newDir];
				nextX = X + moveX[newDir];
			};
		}
	}
}

void copy_state(int A[][4], int B[][4], Info C[], Info D[]) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			A[i][j] = B[i][j];
		}
	}
	for (int i = 1; i <= (MAX * MAX); i++) {
		C[i] = D[i];
	}
}

void DFS(int Y, int X, int dir, int sum) {
	answer = max(answer, sum);
	int tmp_arr[MAX][MAX]; // DFS를 통하여 맵이 바뀌므로, 재귀가 끝나면 맵을 다시 원래대로 만들어주기 위하여 임시 맵을 만든다.
	Info tmp_fish[17]; // 마찬가지로 물고기들의 정보 역시 바뀌므로, 임시 Info 배열을 선언해준다.
	copy_state(tmp_arr, arr, tmp_fish, fish);
	fish_move(); // 물고기들이 먼저 이동
	for (int i = 1; i <= 3; i++) { // 최대 3칸까지 이동 가능
		int nextY = Y + moveY[dir] * i;
		int nextX = X + moveX[dir] * i;
		if ((nextY >= 0) && (nextY < MAX) && (nextX >= 0) && (nextX < MAX)) {
			if (arr[nextY][nextX] == 0) {
				continue;
			}
			int fish_idx = arr[nextY][nextX];
			int newDir = fish[fish_idx].dir;
			arr[Y][X] = 0;
			arr[nextY][nextX] = -1;
			fish[fish_idx].state = false;
			DFS(nextY, nextX, newDir, sum + fish_idx);
			arr[Y][X] = -1;
			arr[nextY][nextX] = fish_idx;
			fish[fish_idx].state = true;
		}
		else {
			break;
		}
	}
	copy_state(arr, tmp_arr, fish, tmp_fish);
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < (MAX * MAX); i++) { // 물고기는 4 * 4 총 16마리이므로, 16마리의 물고기 정보를 입력받는다.
		int A, B;
		cin >> A >> B; // A는 물고기의 번호, B는 물고기의 방향을 의미한다.
		int Y = i / MAX;
		int X = i % MAX;
		arr[Y][X] = A; // arr 배열에는 물고기의 번호를 저장한다.
		fish[A] = { Y,X,B,true };
	}
	int first_fish = arr[0][0];
	fish[first_fish].state = false;
	arr[0][0] = -1;
	DFS(0, 0, fish[first_fish].dir, first_fish); // 처음에 상어는 (0, 0)에 있는 물고기를 잡아먹고, 잡아먹은 물고기의 방향을 가진다.
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
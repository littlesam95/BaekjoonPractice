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
// ���� B = 1�̶�� �������� �̵�, B�� ������ ������ �ݽð� �������� 45����ŭ ������ �ٲ�.
int answer = 0;

void fish_move() {
	for (int i = 1; i <= (MAX * MAX); i++) { // 1������ 16�� �������� ��ȣ�� ���� ������� �����δ�.
		if (!fish[i].state) { // i��° ����Ⱑ ���� ���¶�� �������� �ʴ´�.
			continue;
		}
		int Y = fish[i].Y;
		int X = fish[i].X;
		int dir = fish[i].dir;
		int nextY = Y + moveY[dir];
		int nextX = X + moveX[dir];
		bool flag = false;
		if ((nextY >= 0) && (nextY < MAX) && (nextX >= 0) && (nextX < MAX)) {
			if (arr[nextY][nextX] == 0) { // ���� �̵��� ĭ�� �� ĭ�̴�.
				flag = true;
				fish[i].Y = nextY;
				fish[i].X = nextX;
				arr[nextY][nextX] = i;
				arr[Y][X] = 0;
			}
			else if (arr[nextY][nextX] != -1) { // ���� �̵��� ĭ�� ����Ⱑ �ִ�.
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
					if (arr[nextY][nextX] == 0) { // ���� �̵��� ĭ�� �� ĭ�̴�.
						fish[i].Y = nextY;
						fish[i].X = nextX;
						fish[i].dir = newDir;
						arr[nextY][nextX] = i;
						arr[Y][X] = 0;
						break;
					}
					else if (arr[nextY][nextX] != -1) { // ���� �̵��� ĭ�� ����Ⱑ �ִ�.
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
	int tmp_arr[MAX][MAX]; // DFS�� ���Ͽ� ���� �ٲ�Ƿ�, ��Ͱ� ������ ���� �ٽ� ������� ������ֱ� ���Ͽ� �ӽ� ���� �����.
	Info tmp_fish[17]; // ���������� �������� ���� ���� �ٲ�Ƿ�, �ӽ� Info �迭�� �������ش�.
	copy_state(tmp_arr, arr, tmp_fish, fish);
	fish_move(); // �������� ���� �̵�
	for (int i = 1; i <= 3; i++) { // �ִ� 3ĭ���� �̵� ����
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

	for (int i = 0; i < (MAX * MAX); i++) { // ������ 4 * 4 �� 16�����̹Ƿ�, 16������ ����� ������ �Է¹޴´�.
		int A, B;
		cin >> A >> B; // A�� ������� ��ȣ, B�� ������� ������ �ǹ��Ѵ�.
		int Y = i / MAX;
		int X = i % MAX;
		arr[Y][X] = A; // arr �迭���� ������� ��ȣ�� �����Ѵ�.
		fish[A] = { Y,X,B,true };
	}
	int first_fish = arr[0][0];
	fish[first_fish].state = false;
	arr[0][0] = -1;
	DFS(0, 0, fish[first_fish].dir, first_fish); // ó���� ���� (0, 0)�� �ִ� ����⸦ ��Ƹ԰�, ��Ƹ��� ������� ������ ������.
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
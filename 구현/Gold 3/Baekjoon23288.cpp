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
#define INF 1e9

using namespace std;
struct DICE {
	int Top = 1;
	int Bottom = 6;
	int East = 3;
	int West = 4;
	int Front = 5;
	int Back = 2;
	pair<int, int> Pos = make_pair(1, 1);
	int Dir = 1;
};

DICE Dice;
int N, M, K;
int MAP[MAX][MAX];
// �ֻ����� �̵� ����(��, ��, ��, ��)
int moveY[5] = { 0,0,1,0,-1 };
int moveX[5] = { 0,1,0,-1,0 };
bool visited[MAX][MAX];
int answer = 0;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			visited[i][j] = false;
		}
	}
}

void East_Moving() {
	int nextY = Dice.Pos.first + moveY[1];
	int nextX = Dice.Pos.second + moveX[1];
	// �������� �̵� �� �յ޸��� �����ϸ� ������ ���� �ð�������� �̵��Ѵ�.
	int tmp = Dice.Top;
	Dice.Top = Dice.West;
	Dice.West = Dice.Bottom;
	Dice.Bottom = Dice.East;
	Dice.East = tmp;
	Dice.Pos = make_pair(nextY, nextX);
}

void West_Moving() {
	int nextY = Dice.Pos.first + moveY[3];
	int nextX = Dice.Pos.second + moveX[3];
	// �������� �̵� �� �յ޸��� �����ϸ� ������ ���� �ݽð�������� �̵��Ѵ�.
	int tmp = Dice.Top;
	Dice.Top = Dice.East;
	Dice.East = Dice.Bottom;
	Dice.Bottom = Dice.West;
	Dice.West = tmp;
	Dice.Pos = make_pair(nextY, nextX);
}

void South_Moving() {
	int nextY = Dice.Pos.first + moveY[2];
	int nextX = Dice.Pos.second + moveX[2];
	// �������� �̵� �� �� ������ �����ϸ� ������ ���� �������� �̵��Ѵ�.
	int tmp = Dice.Top;
	Dice.Top = Dice.Back;
	Dice.Back = Dice.Bottom;
	Dice.Bottom = Dice.Front;
	Dice.Front = tmp;
	Dice.Pos = make_pair(nextY, nextX);
}

void North_Moving() {
	int nextY = Dice.Pos.first + moveY[4];
	int nextX = Dice.Pos.second + moveX[4];
	// �������� �̵� �� �� ������ �����ϸ� ������ ���� �������� �̵��Ѵ�.
	int tmp = Dice.Top;
	Dice.Top = Dice.Front;
	Dice.Front = Dice.Bottom;
	Dice.Bottom = Dice.Back;
	Dice.Back = tmp;
	Dice.Pos = make_pair(nextY, nextX);
}

int Score_Calc() {
	init();
	int B = MAP[Dice.Pos.first][Dice.Pos.second];
	int C = 1;
	queue<pair<int, int> > Q;
	Q.push(make_pair(Dice.Pos.first, Dice.Pos.second));
	visited[Dice.Pos.first][Dice.Pos.second] = true;

	while (!Q.empty()) {
		int CurY = Q.front().first;
		int CurX = Q.front().second;
		Q.pop();

		for (int i = 1; i <= 4; i++) {
			int nextY = CurY + moveY[i];
			int nextX = CurX + moveX[i];
			if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= M) && (!visited[nextY][nextX]) && (MAP[nextY][nextX] == B)) {
				visited[nextY][nextX] = true;
				C++;
				Q.push(make_pair(nextY, nextX));
			}
		}
	};
	return (B * C);
}

void Dir_Setting() {
	int A = Dice.Bottom;
	int B = MAP[Dice.Pos.first][Dice.Pos.second];
	if (A > B) {
		Dice.Dir++;
		if (Dice.Dir == 5) {
			Dice.Dir = 1;
		}
	}
	else if (A < B) {
		Dice.Dir--;
		if (Dice.Dir == 0) {
			Dice.Dir = 4;
		}
	}
}

int main() {
	FIRST
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int nextY = Dice.Pos.first + moveY[Dice.Dir];
		int nextX = Dice.Pos.second + moveX[Dice.Dir];
		// 1. �ֻ����� �̵� �������� �� ĭ ��������. ����, �̵� ���⿡ ĭ�� ���ٸ�, �̵� ������ �ݴ�� �� ���� �� ĭ ��������.
		if (Dice.Dir == 1) {
			if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= M)) {
				East_Moving();
			}
			else {
				Dice.Dir = 3;
				West_Moving();
			}
		}
		else if (Dice.Dir == 2) {
			if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= M)) {
				South_Moving();
			}
			else {
				Dice.Dir = 4;
				North_Moving();
			}
		}
		else if (Dice.Dir == 3) {
			if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= M)) {
				West_Moving();
			}
			else {
				Dice.Dir = 1;
				East_Moving();
			}
		}
		else if (Dice.Dir == 4) {
			if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= M)) {
				North_Moving();
			}
			else {
				Dice.Dir = 2;
				South_Moving();
			}
		}
		// 2. �ֻ����� ������ ĭ (x, y)�� ���� ������ ȹ���Ѵ�.
		answer += Score_Calc();
		// 3. �ֻ����� �Ʒ��鿡 �ִ� ���� A�� �ֻ����� �ִ� ĭ (x, y)�� �ִ� ���� B�� ���� �̵� ������ �����Ѵ�.
		Dir_Setting();
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 25

using namespace std;
struct DICE {
	int Top = 0;
	int Bottom = 0;
	int East = 0;
	int West = 0;
	int Front = 0;
	int Back = 0;
	pair<int, int> Pos;
};

DICE Dice;
int N, M, X, Y, K;
int MAP[MAX][MAX];
int moveY[5] = { 0,0,0,-1,1 };
int moveX[5] = { 0,1,-1,0,0 };

/*
	�������� �ֻ����� �̵��� ��
	�� �� ���ڴ� ������ �ְ�, ����, ������, �Ʒ���, ���� ���ڰ� �ð� �������� �� ĭ�� �̵�
*/
void East_Moving() {
	int tmp = Dice.Top;
	Dice.Top = Dice.West;
	Dice.West = Dice.Bottom;
	Dice.Bottom = Dice.East;
	Dice.East = tmp;
	int CurY = Dice.Pos.first;
	int CurX = Dice.Pos.second;
	Dice.Pos = make_pair(CurY, CurX + 1);
}

/*
	�������� �ֻ����� �̵��� ��
	�� �� ���ڴ� ������ �ְ�, ����, ������, �Ʒ���, ���� ���ڰ� �ݽð� �������� �� ĭ�� �̵�
*/
void West_Moving() {
	int tmp = Dice.Top;
	Dice.Top = Dice.East;
	Dice.East = Dice.Bottom;
	Dice.Bottom = Dice.West;
	Dice.West = tmp;
	int CurY = Dice.Pos.first;
	int CurX = Dice.Pos.second;
	Dice.Pos = make_pair(CurY, CurX - 1);
}

/*
	�������� �ֻ����� �̵��� ��
	������ ���� ���ڴ� ������ �ְ�, ����, ����, �Ʒ���, ���� ���ڰ� �չ������� �� ĭ�� �̵�
*/
void North_Moving() {
	int tmp = Dice.Top;
	Dice.Top = Dice.Front;
	Dice.Front = Dice.Bottom;
	Dice.Bottom = Dice.Back;
	Dice.Back = tmp;
	int CurY = Dice.Pos.first;
	int CurX = Dice.Pos.second;
	Dice.Pos = make_pair(CurY - 1, CurX);
}

/*
	�������� �ֻ����� �̵��� ��
	������ ���� ���ڴ� ������ �ְ�, ����, ����, �Ʒ���, ���� ���ڰ� �޹������� �� ĭ�� �̵�
*/
void South_Moving() {
	int tmp = Dice.Top;
	Dice.Top = Dice.Back;
	Dice.Back = Dice.Bottom;
	Dice.Bottom = Dice.Front;
	Dice.Front = tmp;
	int CurY = Dice.Pos.first;
	int CurX = Dice.Pos.second;
	Dice.Pos = make_pair(CurY + 1, CurX);
}

/*
	�̵��� ĭ�� ���� �ִ� ���� 0�̸� �ֻ����� �Ʒ����� ���ڰ� ����Ǹ�,
	0�� �ƴ϶�� ĭ�� ���� �ִ� ���� �ֻ����� �Ʒ������� ����ȴ�.
*/
void Copy_Number() {
	int CurY = Dice.Pos.first;
	int CurX = Dice.Pos.second;
	if (MAP[CurY][CurX] == 0) {
		MAP[CurY][CurX] = Dice.Bottom;
	}
	else {
		Dice.Bottom = MAP[CurY][CurX];
		MAP[CurY][CurX] = 0;
	}
}

/*
	�̵��� �����Ѱ� �ľ��ϰ� �����ϴٸ� �̵��� ������ �� 
	�ֻ����� �� �鿡 ���� �ִ� ���� ���
*/
void Dice_Moving(int Dir) {
	int CurY = Dice.Pos.first;
	int CurX = Dice.Pos.second;
	int nextY = CurY + moveY[Dir];
	int nextX = CurX + moveX[Dir];
	if ((nextY >= 0) && (nextY < N) && (nextX >= 0) && (nextX < M)) {
		if (Dir == 1) {
			East_Moving();
		}
		else if (Dir == 2) {
			West_Moving();
		}
		else if (Dir == 3) {
			North_Moving();
		}
		else if (Dir == 4) {
			South_Moving();
		}
		Copy_Number();
		cout << Dice.Top << "\n";
	}
}

int main() {
	FIRST
	cin >> N >> M >> Y >> X >> K;
	// �ֻ����� ó�� ��ġ
	Dice.Pos = make_pair(Y, X);
	// ������ ���� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
	// ��� ����
	for (int i = 0; i < K; i++) {
		int Q;
		cin >> Q;
		Dice_Moving(Q);
	}

	getchar();
	getchar();
	return 0;
}
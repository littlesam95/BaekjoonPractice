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
	동쪽으로 주사위가 이동할 때
	앞 뒤 숫자는 가만히 있고, 위쪽, 오른쪽, 아래쪽, 왼쪽 숫자가 시계 방향으로 한 칸씩 이동
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
	서쪽으로 주사위가 이동할 때
	앞 뒤 숫자는 가만히 있고, 위쪽, 오른쪽, 아래쪽, 왼쪽 숫자가 반시계 방향으로 한 칸씩 이동
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
	북쪽으로 주사위가 이동할 때
	오른쪽 왼쪽 숫자는 가만히 있고, 위쪽, 앞쪽, 아래쪽, 뒤쪽 숫자가 앞방향으로 한 칸씩 이동
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
	남쪽으로 주사위가 이동할 때
	오른쪽 왼쪽 숫자는 가만히 있고, 위쪽, 앞쪽, 아래쪽, 뒤쪽 숫자가 뒷방향으로 한 칸씩 이동
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
	이동한 칸에 쓰여 있는 수가 0이면 주사위의 아래쪽의 숫자가 복사되며,
	0이 아니라면 칸에 쓰여 있는 수가 주사위의 아래쪽으로 복사된다.
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
	이동이 가능한가 파악하고 가능하다면 이동을 실행한 후 
	주사위의 윗 면에 쓰여 있는 수를 출력
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
	// 주사위의 처음 위치
	Dice.Pos = make_pair(Y, X);
	// 지도의 상태 설정
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
	// 명령 실행
	for (int i = 0; i < K; i++) {
		int Q;
		cin >> Q;
		Dice_Moving(Q);
	}

	getchar();
	getchar();
	return 0;
}
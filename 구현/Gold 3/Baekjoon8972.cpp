#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 101
#define INF 1e9

using namespace std;
struct INFO {
	int Y, X;
};

int R, C;
bool isGameWin = true;
int Game_Over;
char MAP[MAX][MAX];
int Arduino_MAP[MAX][MAX];
int Crazy_Arduino_MAP[MAX][MAX];
INFO Arduino;
vector<INFO> Crazy_Arduino;
int moveY[10] = { 0,1,1,1,0,0,0,-1,-1,-1 };
int moveX[10] = { 0,-1,0,1,-1,0,1,-1,0,1 };
string cmd;

bool Arduino_Moving(int Y, int X, int Dir) {
	/*
		1. ����, ������ �Ƶ��̳븦 8���� ����(����,����,�밢��)���� 
		�̵���Ű�ų�, �� ��ġ�� �״�� ���д�.
		2. ������ �Ƶ��̳밡 ��ģ �Ƶ��̳밡 �ִ� ĭ���� �̵��� ��쿡�� 
		������ ������ �Ǹ�, ������ ������ ���� �ȴ�.
	*/
	int nextY = Y + moveY[Dir];
	int nextX = X + moveX[Dir];
	if ((nextY >= 0) && (nextY < R) && (nextX >= 0) && (nextX < C)) {
		if (Crazy_Arduino_MAP[nextY][nextX] > 0) {
			return false;
		}
		Arduino_MAP[Y][X] = 0;
		Arduino_MAP[nextY][nextX] = 1;
		Arduino = { nextY, nextX };
	}
	return true;
}

bool Crazy_Arduino_Moving() {
	/*
		3. ��ģ �Ƶ��̳�� 8���� ���� �߿��� 
		������ �Ƶ��̳�� ���� ����� ���� �������� �� ĭ �̵��Ѵ�. 
		��, ������ ��ġ�� (r1,s1), ��ģ �Ƶ��̳��� ��ġ�� (r2, s2)��� ���� ��, 
		|r1-r2| + |s1-s2|�� ���� �۾����� �������� �̵��Ѵ�.
		4. ��ģ �Ƶ��̳밡 ������ �Ƶ��̳밡 �ִ� ĭ���� �̵��� ��쿡�� 
		������ ������ �ǰ�, ������ ������ ���� �ȴ�.
	*/
	int Y = Arduino.Y;
	int X = Arduino.X;
	for (int i = 0; i < Crazy_Arduino.size(); i++) {
		int CurY = Crazy_Arduino[i].Y;
		int CurX = Crazy_Arduino[i].X;
		int Will_Dir = 0;
		int Final_Len = INF;
		for (int j = 1; j <= 9; j++) {
			if (j == 5) {
				continue;
			}
			int nextY = CurY + moveY[j];
			int nextX = CurX + moveX[j];
			int Len = abs(Y - nextY) + abs(X - nextX);
			if (Final_Len > Len) {
				Final_Len = Len;
				Will_Dir = j;
			}
		}
		int nextY = CurY + moveY[Will_Dir];
		int nextX = CurX + moveX[Will_Dir];
		if ((nextY >= 0) && (nextY < R) && (nextX >= 0) && (nextX < C)) {
			if (Arduino_MAP[nextY][nextX] > 0) {
				return false;
			}
			Crazy_Arduino_MAP[CurY][CurX]--;
			Crazy_Arduino_MAP[nextY][nextX]++;
			Crazy_Arduino[i] = { nextY, nextX };
		}
	}
	return true;
}

void Explosion() {
	/*
		5. 2�� �Ǵ� �� �̻��� ��ģ �Ƶ��̳밡 ���� ĭ�� �ִ� ��쿡�� 
		ū ������ �Ͼ��, �� ĭ�� �ִ� �Ƶ��̳�� ��� �ı��ȴ�.
	*/
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Crazy_Arduino_MAP[i][j] >= 2) {
				Crazy_Arduino_MAP[i][j] = 0;
				for (int k = 0; k < Crazy_Arduino.size(); k++) {
					int CurY = Crazy_Arduino[k].Y;
					int CurX = Crazy_Arduino[k].X;
					if ((CurY == i) && (CurX == j)) {
						Crazy_Arduino.erase(Crazy_Arduino.begin() + k);
						k--;
					}
				}
			}
		}
	}
}

void Drawing_Map() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Arduino_MAP[i][j] == 1) {
				MAP[i][j] = 'I';
			}
			else if (Arduino_MAP[i][j] == 0) {
				MAP[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (Crazy_Arduino_MAP[i][j] != 0) {
				MAP[i][j] = 'R';
			}
		}
	}
}

int main() {
	FIRST
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < C; j++) {
			MAP[i][j] = S[j];
			if (MAP[i][j] == 'I') {
				Arduino_MAP[i][j] = 1;
				Arduino = { i,j };
			}
			else if (S[j] == 'R') {
				Crazy_Arduino_MAP[i][j]++;
				Crazy_Arduino.push_back({ i,j });
			}
		}
	}
	cin >> cmd;
	for (int i = 0; i < cmd.size(); i++) {
		int Dir = cmd[i] - '0';
		bool Flag1 = Arduino_Moving(Arduino.Y, Arduino.X, Dir);
		if (!Flag1) {
			isGameWin = false;
			Game_Over = i + 1;
			break;
		}
		bool Flag2 = Crazy_Arduino_Moving();
		if (!Flag2) {
			isGameWin = false;
			Game_Over = i + 1;
			break;
		}
		Explosion();
		Drawing_Map();
	}
	if (isGameWin) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << MAP[i][j];
			}
			cout << "\n";
		}
	}
	else {
		cout << "kraj " << Game_Over << "\n";
	}

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 100005
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	// ��� ���� ������ ����((30, 30))���� ����
	int Y = 30;
	int X = 30;
	bool Teammate[4] = { false, false, false, false }; // A~D�� ���ų� ���� ������ true, �ƴ϶�� false
	bool isStart = false; // ����� ���¶�� true, �ƴ϶�� false
};

int N;
INFO Horse[2][4]; // 0���� �빮��, 1���� �ҹ���
string MAP[33] = {
"..----..----..----..----..----..",
"..    ..    ..    ..    ..    ..",
"| \\                          / |",
"|  \\                        /  |",
"|   \\                      /   |",
"|    ..                  ..    |",
"..   ..                  ..   ..",
"..     \\                /     ..",
"|       \\              /       |",
"|        \\            /        |",
"|         ..        ..         |",
"|         ..        ..         |",
"..          \\      /          ..",
"..           \\    /           ..",
"|             \\  /             |",
"|              ..              |",
"|              ..              |",
"|             /  \\             |",
"..           /    \\           ..",
"..          /      \\          ..",
"|         ..        ..         |",
"|         ..        ..         |",
"|        /            \\        |",
"|       /              \\       |",
"..     /                \\     ..",
"..   ..                  ..   ..",
"|    ..                  ..    |",
"|   /                      \\   |",
"|  /                        \\  |",
"| /                          \\ |",
"..    ..    ..    ..    ..    ..",
"..----..----..----..----..----.." };  // ������ ���ڿ��� ����
/*
	(0, 0) �޹�   (0, 6) ����   (0, 12) �ް�   (0, 18) �ް�    (0, 24) �޵�      (0, 30) �չ�(��)

	             (5, 5) �޸�                                (5, 25) �ո�
	(6, 0) �                                                                  (6, 30) ��
	                     (10, 10) �޸�                 (10, 20) �ո�

	(12, 0) �                                                                  (6, 30) ��
	                                     (15, 15) ��

	(18, 0) ���                                                                  (6, 30) ��
	                        (10, 20) ����          (20, 20) ���

	(24, 0) ����                                                                  (6, 30) ��
	              (5, 25) �Ӹ�                               (25, 25) ����

	(30, 0) ¿��   (30, 6) ����   (30, 12) ����   (30, 18) ����   (30, 24) ����   (30, 30) ����
*/

void Horse_Move_First_Second(int& Y, int& X, int Team, int Mal, int Cnt) { // 1, 2�� ���(������ �밢�� ����)
	int CurY = Y;
	int CurX = X;
	int CurCnt = Cnt;
	while (CurCnt--) {
		if (((CurY == 0) && (CurX == 0)) || ((CurY == 5) && (CurX == 5)) || ((CurY == 10) && (CurX == 10))
			|| ((CurY == 15) && (CurX == 15)) || ((CurY == 20) && (CurX == 20)) || ((CurY == 25) && (CurX == 25))) {
			// �޹�, �޸�, �޸�, ��, ���, ��� ��ġ�� ��� ���������� �� ĭ�� �̵�
			CurY += 5;
			CurX += 5;
		}
		else if ((CurY == 30) && (CurX == 30)) { // ���翡 ��ġ�� ��� ���ǿ��� ���� ����������.
			CurY = -1;
			CurX = -1;
			break;
		}
	};
	Y = CurY;
	X = CurX;
}

void Horse_Move_Third(int& Y, int& X, int Team, int Mal, int Cnt) { // 3�� ���(�ﰢ��)
	int CurY = Y;
	int CurX = X;
	int CurCnt = Cnt;
	while (CurCnt--) {
		if (((CurY == 0) && (CurX == 30)) || ((CurY == 5) && (CurX == 25)) || ((CurY == 10) && (CurX == 20))
			|| ((CurY == 15) && (CurX == 15)) || ((CurY == 20) && (CurX == 10)) || ((CurY == 25) && (CurX == 5))) {
			// �޹�, �޸�, �޸�, ��, ���, ��� ��ġ�� ��� ���������� �� ĭ�� �̵�
			CurY += 5;
			CurX -= 5;
		}
		else if (((CurY == 30) && (CurX == 0)) || ((CurY == 30) && (CurX == 6))
			|| ((CurY == 30) && (CurX == 12)) || ((CurY == 30) && (CurX == 18)) || ((CurY == 30) && (CurX == 24))) {
			// ¿��, ����, ����, ����, ������ ��ġ�� ��� ���������� �� ĭ�� �̵�
			CurX += 6;
		}
		else if ((CurY == 30) && (CurX == 30)) { // ���翡 ��ġ�� ��� ���ǿ��� ���� ����������.
			CurY = -1;
			CurX = -1;
			break;
		}
	};
	Y = CurY;
	X = CurX;
}

void Horse_Move_Fourth(int& Y, int& X, int Team, int Mal, int Cnt) { // 4�� ���(�簢��)
	int CurY = Y;
	int CurX = X;
	int CurCnt = Cnt;
	while (CurCnt--) {
		if (!Horse[Team][Mal].isStart) { // ���� ��� �� �� ��� ����ϸ鼭 ���� �̵�
			Horse[Team][Mal].isStart = true;
			CurY -= 6;
		}
		else {
			if (((CurY > 0) && (CurY < 30)) && (CurX == 30)) { // ��, ��, ��, ���� ��ġ�� ��� ���� �� ĭ�� �̵�
				CurY -= 6;
			}
			else if ((CurY == 0) && (CurX > 0)) { // �չ�(��), �޵�, �ް�, �ް�, ������ ��ġ�� ��� �������� �� ĭ�� �̵�
				CurX -= 6;
			}
			else if ((CurY < 30) && (CurX == 0)) { // �޹�, �, �, ���, ������ ��ġ�� ��� �Ʒ������� �� ĭ�� �̵�
				CurY += 6;
			}
			else if (CurY == 30) {
				if (CurX < 30) { // ¿��, ����, ����, ����, ������ ��ġ�� ��� ���������� �� ĭ�� �̵�
					CurX += 6;
				}
				else if (CurX >= 30) { // ���翡 ��ġ�� ��� ���ǿ��� ���� ����������.
					CurY = -1;
					CurX = -1;
					break;
				}
			}
		}
	};
	Y = CurY;
	X = CurX;
}

void Make_Teammate(int Y, int X, int Team, int Mal) {
	for (int i = 0; i < 4; i++) {
		if (i == Mal) { // ������ ������ ���� ���� ����.
			continue;
		}
		if ((Horse[Team][i].Y == Y) && (Horse[Team][i].X == X) && (!Horse[Team][Mal].Teammate[i]) && (Horse[Team][i].isStart)) {
			// ������ ����� �Ʊ� ���� ���� ���� ���� ��ġ�� �ִµ� ���� ���� ���� ���
			Horse[Team][Mal].Teammate[i] = true;
			Horse[Team][i].Teammate[Mal] = true;
		}
	}
}

void Delete_Other_Team_Horse(int Y, int X, int Team) {
	if (Team == 0) { // ���� ���� �빮��(0��)���
		for (int i = 0; i < 4; i++) {
			if ((Horse[1][i].Y == Y) && (Horse[1][i].X == X) && (Horse[1][i].isStart)) {
				// ������ ����� 1�� ���� ���� ���� ���� ��ġ�� �ִ� ��� �� ���� ���� �� �ִ�.
				Horse[1][i].Y = 30;
				Horse[1][i].X = 30;
				Horse[1][i].isStart = false;
				// ������ ����ϱ� ������ �ǵ�����.
				for (int j = 0; j < 4; j++) { // ���� ���� �������Ƿ�, ���� ���� �ְų� ���� ���� ����� ���� ���踦 ���´�.
					if (i == j) {
						continue;
					}
					if (Horse[1][i].Teammate[j]) {
						Horse[1][i].Teammate[j] = false;
					}
				}
			}
		}
	}
	else if (Team == 1) { // ���� ���� �ҹ���(1��)���
		for (int i = 0; i < 4; i++) {
			if ((Horse[0][i].Y == Y) && (Horse[0][i].X == X) && (Horse[0][i].isStart)) {
				Horse[0][i].Y = 30;
				Horse[0][i].X = 30;
				Horse[0][i].isStart = false;
				for (int j = 0; j < 4; j++) {
					if (i == j) {
						continue;
					}
					if (Horse[0][i].Teammate[j]) {
						Horse[0][i].Teammate[j] = false;
					}
				}
			}
		}
	}
}

void Remain_Operation(int Y, int X, int Team, int Mal) {
	// N�Ͽ��� ������ ���������� ����� ���� ��ǥ �ٽ� �ʱ�ȭ
	Horse[Team][Mal].Y = Y;
	Horse[Team][Mal].X = X;
	for (int i = 0; i < 4; i++) { // ���� ���� �ְų� ���� ���� ������ ��ǥ ���� �ʱ�ȭ
		if (Mal == i) {
			continue;
		}
		if (Horse[Team][Mal].Teammate[i]) {
			Horse[Team][i].Y = Y;
			Horse[Team][i].X = X;
		}
	}
	if ((Horse[Team][Mal].Y != -1) && (Horse[Team][Mal].X != -1)) { // ���� ���ǿ��� ���������� ���� ���
		Delete_Other_Team_Horse(Horse[Team][Mal].Y, Horse[Team][Mal].X, Team); // ���� �� �ִ� ������ Ž��
		Make_Teammate(Horse[Team][Mal].Y, Horse[Team][Mal].X, Team, Mal); // ���̾��� �� �ִ� ������ Ž��
		for (int i = 0; i < 4; i++) { // ���������� ���� ���� �ְų� ���� ���� ������ ���� �� �ִ� ������ Ž��
			if (Mal == i) {
				continue;
			}
			if (Horse[Team][Mal].Teammate[i]) {
				Make_Teammate(Horse[Team][i].Y, Horse[Team][i].X, Team, i);
			}
		}
	}
}

void Print() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			int Y = Horse[i][j].Y;
			int X = Horse[i][j].X;
			if ((!Horse[i][j].isStart) || ((Y == -1) && (X == -1))) {
				// ������� �ʾҰų� ���� �� ������ �� ���� ���� ���̶�� MAP�� ǥ������ �ʴ´�.
				continue;
			}
			if (j == 0) {
				MAP[Y][X] = (i == 0) ? 'A' : 'a';
			}
			if (j == 1) {
				MAP[Y][X + 1] = (i == 0) ? 'B' : 'b';
			}
			if (j == 2) {
				MAP[Y + 1][X] = (i == 0) ? 'C' : 'c';
			}
			if (j == 3) {
				MAP[Y + 1][X + 1] = (i == 0) ? 'D' : 'd';
			}
		}
	}
	for (int i = 0; i < 32; i++) {
		cout << MAP[i] << "\n";
	}
	cout << "\n";
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		char Mal;
		string Yut;
		cin >> Mal >> Yut;
		// ���� ���� ��ǥ ��������
		int Y, X;
		if ((Mal >= 'A') && (Mal <= 'D')) { // �빮�ڶ�� 0��
			Y = Horse[0][Mal - 'A'].Y;
			X = Horse[0][Mal - 'A'].X;
		}
		else if ((Mal >= 'a') && (Mal <= 'd')) { // �ҹ��ڶ�� 1��
			Y = Horse[1][Mal - 'a'].Y;
			X = Horse[1][Mal - 'a'].X;
		}

		// �� ���� �ո��� ��(F)��ŭ ����
		int Cnt = 0;
		for (int j = 0; j < Yut.size(); j++) {
			if (Yut[j] == 'F') {
				Cnt++;
			}
		}
		Cnt = (Cnt) ? Cnt : 5; // ��� �޸�(B)�̶�� 5ĭ ����

		// �� �����̱�
		if ((Mal >= 'A') && (Mal <= 'D')) { // ���� �빮�ڶ�� 0��
			if (((Y == 0) && (X == 0)) || ((Y == 15) && (X == 15))) {
				// ���� �޹翡�� ����� ������ 2�� ��η� �̵�, �濡�� ����� ������ 1�� ��η� �̵�
				Horse_Move_First_Second(Y, X, 0, Mal - 'A', Cnt);
			}
			else if ((Y == 0) && (X == 30)) {
				// ���� �չ翡�� ����� ������ 3�� ��η� �̵�
				Horse_Move_Third(Y, X, 0, Mal - 'A', Cnt);
			}
			else if ((Y == 30) && (X == 30) && (Horse[0][Mal - 'A'].isStart)) {
				// ���� �̹� ����� ���¿��� ���翡�� ����ϴ� ��쿡�� ���ǿ��� ���������� �ȴ�.
				Y = -1;
				X = -1;
			}
			else if ((Y % 6 == 0) || (X % 6 == 0)) {
				// ���� ��, ��, ��, ��, �޵�, �ް�, �ް�, ����, �, �, ���, ����, ¿��, ����, ����, ����, �������� ����� ������ 4�� ��η� �̵�
				Horse_Move_Fourth(Y, X, 0, Mal - 'A', Cnt);
			}
			else {
				if (Y == X) { // ���� �޸�, �޸�, ���, ����� ����� ������ 2�� ��η� �̵�
					Horse_Move_First_Second(Y, X, 0, Mal - 'A', Cnt);
				}
				else { // ���� �ո�, �ո�, ����, �Ӹ𿡼� ����� ������ 3�� ��η� �̵�
					Horse_Move_Third(Y, X, 0, Mal - 'A', Cnt);
				}
			}
			Remain_Operation(Y, X, 0, Mal - 'A'); // ���� �� ����, �Ʊ� �� ���� �� �߰� �۾�
		}
		else if ((Mal >= 'a') && (Mal <= 'd')) { // ���� �ҹ��ڶ�� 1��
			if (((Y == 0) && (X == 0)) || ((Y == 15) && (X == 15))) {
				Horse_Move_First_Second(Y, X, 1, Mal - 'a', Cnt);
			}
			else if ((Y == 0) && (X == 30)) {
				Horse_Move_Third(Y, X, 1, Mal - 'a', Cnt);
			}
			else if ((Y == 30) && (X == 30) && (Horse[1][Mal - 'a'].isStart)) {
				Y = -1;
				X = -1;
			}
			else if ((Y % 6 == 0) || (X % 6 == 0)) {
				Horse_Move_Fourth(Y, X, 1, Mal - 'a', Cnt);
			}
			else {
				if (Y == X) {
					Horse_Move_First_Second(Y, X, 1, Mal - 'a', Cnt);
				}
				else {
					Horse_Move_Third(Y, X, 1, Mal - 'a', Cnt);
				}
			}
			Remain_Operation(Y, X, 1, Mal - 'a');
		}
	}
	Print();

	getchar();
	getchar();
	return 0;
}
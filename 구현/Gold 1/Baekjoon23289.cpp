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
#define LL long long
#define INF 1e9

using namespace std;
struct BLOWER {
	int Y, X, Dir;
};

int R, C, K, W;
int MAP[MAX][MAX]; // ���� ����
int Wind_MAP[MAX][MAX]; // �ٶ��� ����
int Tmp_MAP[MAX][MAX]; // �ٶ��� ��ȭ�� ���� �ӽ� �迭
bool Wall[MAX][MAX][5]; // ���� ����, (i,j)�� k����(��:1, ��:2, ��:3, ��:4)�� ���� ������ true, ������ false
vector<BLOWER> Blower; // ��ǳ��
vector<pair<int, int> > Investigate; // ������ ��
int moveY[5] = { 0,0,0,-1,1 };
int moveX[5] = { 0,1,-1,0,0 };
int answer = 0; // ���� ���ݸ��� ����

void init() { // �ӽ� �迭�� �ʱ�ȭ��Ű�� �Լ�
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			Tmp_MAP[i][j] = 0;
		}
	}
}

void Copy_Map() { // �ٶ��� ����ġ�� ���� �ٶ��� ���°� ��ȭ��.
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			Wind_MAP[i][j] += Tmp_MAP[i][j];
		}
	}
}

void Make_Wind_East(int Depth, int Y, int X) {
	// ��ǳ�⿡�� �ٶ��� �������� ���� ��
	if (Depth == 0) { // �ٶ��� ���Ⱑ 0�� �Ǹ� �� �̻� �ٶ��� ������ �ʴ´�.
		return;
	}
	Tmp_MAP[Y][X] = Depth;
	int nextY = Y - 1;
	int nextX = X + 1;
	/*
		ĭ (x, y)���� (x-1, y+1)�� �ٶ��� �̵��� �� ��������, 
		(x, y)�� (x-1, y) ���̿� ���� ����� �ϰ�, (x-1, y)�� (x-1, y+1) ���̿��� ���� ����� �Ѵ�.
	*/
	if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (Tmp_MAP[nextY][nextX] == 0) && (!Wall[Y][X][3]) && (!Wall[Y - 1][X][1])) {
		Make_Wind_East(Depth - 1, nextY, nextX);
	}
	nextY = Y;
	nextX = X + 1;
	/*
		(x, y)���� (x, y+1)�� �ٶ��� �̵��� �� �������� (x, y)�� (x, y+1) ���̿� ���� ����� �Ѵ�. 
	*/
	if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (Tmp_MAP[nextY][nextX] == 0) && (!Wall[Y][X][1])) {
		Make_Wind_East(Depth - 1, nextY, nextX);
	}
	nextY = Y + 1;
	nextX = X + 1;
	/*
		(x, y)���� (x+1, y+1)�� �ٶ��� �̵��� �� ��������, (x, y)�� (x+1, y), (x+1, y)�� (x+1, y+1) ���̿� ���� ����� �Ѵ�.
	*/
	if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (Tmp_MAP[nextY][nextX] == 0) && (!Wall[Y][X][4]) && (!Wall[Y + 1][X][1])) {
		Make_Wind_East(Depth - 1, nextY, nextX);
	}
}

void Make_Wind_West(int Depth, int Y, int X) {
	// ��ǳ�⿡�� �ٶ��� �������� ���� ��
	if (Depth == 0) {
		return;
	}
	Tmp_MAP[Y][X] = Depth;
	int nextY = Y - 1;
	int nextX = X - 1;
	/*
		ĭ (x, y)���� (x-1, y-1)�� �ٶ��� �̵��� �� ��������,
		(x, y)�� (x-1, y) ���̿� ���� ����� �ϰ�, (x-1, y)�� (x-1, y-1) ���̿��� ���� ����� �Ѵ�.
	*/
	if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (Tmp_MAP[nextY][nextX] == 0) && (!Wall[Y][X][3]) && (!Wall[Y - 1][X][2])) {
		Make_Wind_West(Depth - 1, nextY, nextX);
	}
	nextY = Y;
	nextX = X - 1;
	/*
		(x, y)���� (x, y-1)�� �ٶ��� �̵��� �� �������� (x, y)�� (x, y-1) ���̿� ���� ����� �Ѵ�.
	*/
	if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (Tmp_MAP[nextY][nextX] == 0) && (!Wall[Y][X][2])) {
		Make_Wind_West(Depth - 1, nextY, nextX);
	}
	nextY = Y + 1;
	nextX = X - 1;
	/*
		(x, y)���� (x+1, y-1)�� �ٶ��� �̵��� �� ��������, (x, y)�� (x+1, y), (x+1, y)�� (x+1, y-1) ���̿� ���� ����� �Ѵ�.
	*/
	if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (Tmp_MAP[nextY][nextX] == 0) && (!Wall[Y][X][4]) && (!Wall[Y + 1][X][2])) {
		Make_Wind_West(Depth - 1, nextY, nextX);
	}
}

void Make_Wind_North(int Depth, int Y, int X) {
	// ��ǳ�⿡�� �ٶ��� �������� ���� ��
	if (Depth == 0) {
		return;
	}
	Tmp_MAP[Y][X] = Depth;
	int nextY = Y - 1;
	int nextX = X - 1;
	/*
		ĭ (x, y)���� (x-1, y-1)�� �ٶ��� �̵��� �� ��������,
		(x, y)�� (x, y-1) ���̿� ���� ����� �ϰ�, (x, y-1)�� (x-1, y-1) ���̿��� ���� ����� �Ѵ�.
	*/
	if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (Tmp_MAP[nextY][nextX] == 0) && (!Wall[Y][X][2]) && (!Wall[Y][X - 1][3])) {
		Make_Wind_North(Depth - 1, nextY, nextX);
	}
	nextY = Y - 1;
	nextX = X;
	/*
		(x, y)���� (x-1, y)�� �ٶ��� �̵��� �� �������� (x, y)�� (x-1, y) ���̿� ���� ����� �Ѵ�.
	*/
	if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (Tmp_MAP[nextY][nextX] == 0) && (!Wall[Y][X][3])) {
		Make_Wind_North(Depth - 1, nextY, nextX);
	}
	nextY = Y - 1;
	nextX = X + 1;
	/*
		(x, y)���� (x-1, y+1)�� �ٶ��� �̵��� �� ��������, (x, y)�� (x, y+1), (x, y+1)�� (x-1, y+1) ���̿� ���� ����� �Ѵ�.
	*/
	if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (Tmp_MAP[nextY][nextX] == 0) && (!Wall[Y][X][1]) && (!Wall[Y][X + 1][3])) {
		Make_Wind_North(Depth - 1, nextY, nextX);
	}
}

void Make_Wind_South(int Depth, int Y, int X) {
	// ��ǳ�⿡�� �ٶ��� �������� ���� ��
	if (Depth == 0) {
		return;
	}
	Tmp_MAP[Y][X] = Depth;
	int nextY = Y + 1;
	int nextX = X - 1;
	/*
		ĭ (x, y)���� (x+1, y-1)�� �ٶ��� �̵��� �� ��������,
		(x, y)�� (x, y-1) ���̿� ���� ����� �ϰ�, (x, y-1)�� (x+1, y-1) ���̿��� ���� ����� �Ѵ�.
	*/
	if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (Tmp_MAP[nextY][nextX] == 0) && (!Wall[Y][X][2]) && (!Wall[Y][X - 1][4])) {
		Make_Wind_South(Depth - 1, nextY, nextX);
	}
	nextY = Y + 1;
	nextX = X;
	/*
		(x, y)���� (x+1, y)�� �ٶ��� �̵��� �� �������� (x, y)�� (x+1, y) ���̿� ���� ����� �Ѵ�.
	*/
	if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (Tmp_MAP[nextY][nextX] == 0) && (!Wall[Y][X][4])) {
		Make_Wind_South(Depth - 1, nextY, nextX);
	}
	nextY = Y + 1;
	nextX = X + 1;
	/*
		(x, y)���� (x+1, y+1)�� �ٶ��� �̵��� �� ��������, (x, y)�� (x, y+1), (x, y+1)�� (x+1, y+1) ���̿� ���� ����� �Ѵ�.
	*/
	if ((nextY >= 1) && (nextY <= R) && (nextX >= 1) && (nextX <= C) && (Tmp_MAP[nextY][nextX] == 0) && (!Wall[Y][X][1]) && (!Wall[Y][X + 1][4])) {
		Make_Wind_South(Depth - 1, nextY, nextX);
	}
}

void Blow_Wind() {
	// 1. ���� �ִ� ��� ��ǳ�⿡�� �ٶ��� �� �� ����
	for (int i = 0; i < Blower.size(); i++) {
		init();
		int Y = Blower[i].Y;
		int X = Blower[i].X;
		int Dir = Blower[i].Dir;
		int nextY = Y + moveY[Dir];
		int nextX = X + moveX[Dir];
		// ���⿡ ���� �ٶ��� ������ ������ �ٸ���.
		if (Dir == 1) {
			Make_Wind_East(5, nextY, nextX);
		}
		else if (Dir == 2) {
			Make_Wind_West(5, nextY, nextX);
		}
		else if (Dir == 3) {
			Make_Wind_North(5, nextY, nextX);
		}
		else if (Dir == 4) {
			Make_Wind_South(5, nextY, nextX);
		}
		Copy_Map();
	}
}

void Temperature_Control() {
	// 2. �µ��� ������
	init();
	// �ϳ��� �࿡�� 1~C������ ��� Ž���ϰ�, �̰��� R�� �ݺ��ϱ� ������ ��, ���� ĭ���� �µ� ������ �� �ʿ䰡 ����.
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			int CurT = Wind_MAP[i][j];
			for (int k = 1; k <= 4; k++) {
				bool Flag = false;
				if ((i + moveY[k] >= 1) && (i + moveY[k] <= R) && (j + moveX[k] >= 1) && (j + moveX[k] <= C)) {
					if (k == 1) {
						Flag = (!Wall[i][j][1] ? true : false); // ĭ (i,j)���� ���ʿ� ���� ������ �ٶ��� ������ �ʴ´�.
					}
					else if (k == 4) {
						Flag = (!Wall[i][j][4] ? true : false); // ĭ (i,j)���� ���ʿ� ���� ������ �ٶ��� ������ �ʴ´�.
					}
				}
				if (!Flag) {
					continue;
				}
				int nextT = Wind_MAP[i + moveY[k]][j + moveX[k]];
				int SubT = abs(CurT - nextT);
				SubT /= 4; // �µ��� ���� ĭ���� ���� ĭ���� (�� ĭ�� �µ��� ����) / 4��ŭ �µ��� �����ȴ�.
				if (CurT > nextT) {
					Tmp_MAP[i][j] -= SubT;
					Tmp_MAP[i + moveY[k]][j + moveX[k]] += SubT; // �µ��� "��ȭ��"�� �ӽ� �迭�� ��Ƽ� ���߿� �Ѳ����� ó���Ѵ�.
				}
				else if (CurT < nextT) {
					Tmp_MAP[i][j] += SubT;
					Tmp_MAP[i + moveY[k]][j + moveX[k]] -= SubT;
				}
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			// �Ѳ����� ó���ϴ� ������ ��� ĭ�� ���ؼ� ���ÿ� �߻��Ѵٰ� �Ͽ��� �����̴�.
			Wind_MAP[i][j] += Tmp_MAP[i][j];
		}
	}
}

void Decrease_Temperature() {
	// 3. �µ��� 1 �̻��� ���� �ٱ��� ĭ�� �µ��� 1�� ����
	// �ٱ��� ĭ�� �ִ� �µ��� 1 �̻��� ��� ĭ�� �µ��� 1�� �����Ѵ�.
	for (int i = 1; i <= C; i++) {
		if (Wind_MAP[1][i] > 0) {
			Wind_MAP[1][i]--;
		}
	}
	for (int i = 1; i <= C; i++) {
		if (Wind_MAP[R][i] > 0) {
			Wind_MAP[R][i]--;
		}
	}
	for (int i = 2; i < R; i++) {
		if (Wind_MAP[i][1] > 0) {
			Wind_MAP[i][1]--;
		}
	}
	for (int i = 2; i < R; i++) {
		if (Wind_MAP[i][C] > 0) {
			Wind_MAP[i][C]--;
		}
	}
}

void Eat_Chocolate() {
	// 4. ���ݸ��� �ϳ� �Դ´�.
	answer++; // ���ݸ��� �Դ´�.
}

bool Check_MAP() {
	// 5. �����ϴ� ��� ĭ�� �µ��� K �̻��� �Ǿ����� �˻�. ��� ĭ�� �µ��� K�̻��̸� �׽�Ʈ�� �ߴ��ϰ�, �ƴϸ� 1���� �ٽ� �����Ѵ�.
	bool Flag = true;
	for (int i = 0; i < Investigate.size(); i++) {
		int Y = Investigate[i].first;
		int X = Investigate[i].second;
		if (Wind_MAP[Y][X] < K) {
			// �ϳ��� ������ ĭ�� �µ��� K�� ��ġġ �� �Ѵٸ� �׽�Ʈ�� ������ �ʴ´�.
			return false;
		}
	}
	return true;
}

void Ability_Test() {
	while (1) {
		Blow_Wind();
		Temperature_Control();
		Decrease_Temperature();
		Eat_Chocolate();
		if (answer > 100) {
			// ���ݸ��� 100�� �Ѱ� ������, ������ 101�� ����� ���̹Ƿ� �׽�Ʈ�� �ߴ��Ѵ�.
			answer = 101;
			break;
		}
		bool Flag = Check_MAP();
		if (Flag) {
			break;
		}
	};
}

int main() {
	FIRST
	cin >> R >> C >> K;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> MAP[i][j];
			if ((MAP[i][j] >= 1) && (MAP[i][j] <= 4)) {
				Blower.push_back({ i,j,MAP[i][j] });
			}
			else if (MAP[i][j] == 5) {
				Investigate.push_back(make_pair(i, j));
			}
		}
	}
	cin >> W;
	for (int i = 0; i < W; i++) {
		int Y, X, T;
		cin >> Y >> X >> T;
		if (T == 0) {
			Wall[Y][X][3] = true;
			Wall[Y - 1][X][4] = true;
		}
		else if (T == 1) {
			Wall[Y][X][1] = true;
			Wall[Y][X + 1][2] = true;
		}
	}
	Ability_Test();
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
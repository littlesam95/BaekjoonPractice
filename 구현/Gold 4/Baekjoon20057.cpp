#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 506
#define INF 2e9

using namespace std;
int N;
int MAP[MAX][MAX];
pair<int, int> Start;
int moveY[4] = { 0,1,0,-1 };
int moveX[4] = { -1,0,1,0 };
/*
	��, ��, ��, �������� �̵��� �� �𷡰� �𳯸��� ���� �� ������ �迭�� ������ش�.
*/
int spreadY[4][10] = { { -1,1,-1,1,-1,1,-2,2,0,0 }, 
					   { 0,0,1,1,2,2,1,1,3,2 },
					   { -1,1,-1,1,-1,1,-2,2,0,0 },
					   { 0,0,-1,-1,-2,-2,-1,-1,-3,-2 } };
int spreadX[4][10] = { { 0,0,-1,-1,-2,-2,-1,-1,-3,-2 },
					   { -1,1,-1,1,-1,1,-2,2,0,0 },
					   { 0,0,1,1,2,2,1,1,3,2 },
					   { -1,1,-1,1,-1,1,-2,2,0,0 } };
int Sand_Percent[9] = { 1,1,7,7,10,10,2,2,5 };
int moveLen = 1; // ó�� �̵� �Ÿ��� 1
int Direction = 0; // ó�� �̵� ������ ����
int Dir_Change = 0; // ������ �ٲ� Ƚ��, 2�� �ٲ�ٸ� �̵� �Ÿ��� 1 ������Ű�� Ƚ���� 0���� �ʱ�ȭ
int answer = 0; // ���� �ٱ����� ���� ���� ��

void Sand_Spread(int Y, int X, int YY, int XX, int Sand, int Dir) {
	int tmp = Sand;
	for (int i = 0; i < 9; i++) { // �ᰡ �����ִ� ĭ�� ������ 9�������� �𳯸� ���� ���� ������ش�.
		int nextY = Y + spreadY[Dir][i];
		int nextX = X + spreadX[Dir][i];
		int Per = Sand_Percent[i];
		int Sand_Part = (tmp * Per) / 100;
		// �𷡰� ���� �ٱ����� �̵��� ���
		if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= N)) {
			answer += Sand_Part;
		}
		else {
			MAP[nextY][nextX] += Sand_Part;
		}
		Sand -= Sand_Part;
		// �𳯸� ���� �縸ŭ ��� ���ָ� �ᰡ �����ִ� ĭ���� �𳯸� ���� �縸 ���� �� ���̴�.
	}
	int nextY = Y + spreadY[Dir][9];
	int nextX = X + spreadX[Dir][9];
	if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= N)) {
		answer += Sand;
	}
	else {
		MAP[nextY][nextX] += Sand;
	}
	MAP[YY][XX] = 0; // �𷡰� �� �𳯸��� ���� Y ĭ�� ���� �𷡴� 0�� �� ���̴�.
}

void Tornado(int Y, int X, int Dir, int Len) {
	int CurY = Y;
	int CurX = X;
	for (int l = 0; l < Len; l++) {
		/*
			����̵��� Len��ŭ �̵��ϸ鼭 �� ĭ �̵��� ������ �𷡰� �𳯸���.
			�̵��ϸ� �𷡰� �𳯸� �� ����̵��� ���� ��ġ�� ��� �ʱ�ȭ�����ش�.
		*/
		int nextY = CurY + moveY[Dir];
		int nextX = CurX + moveX[Dir];
		if (MAP[nextY][nextX] > 0) { 
			int Sand = MAP[nextY][nextX];
			Sand_Spread(CurY, CurX, nextY, nextX, Sand, Dir);
		}
		CurY = nextY;
		CurX = nextX;
	}
	// Dir �������� Len��ŭ�� �̵��� ������ ���� �̵��� ���ؼ� ����̵��� ��������� �ʱ�ȭ�Ѵ�.
	Start = make_pair(CurY, CurX);
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MAP[i][j];
		}
	}
	// ������ ������ ��� ������������ �����Ѵ�.
	Start = make_pair(N / 2, N / 2);
	while (1) {
		// ����̵��� Direction �������� moveLen��ŭ �̵� 
		Tornado(Start.first, Start.second, Direction, moveLen);
		// ���� ��ȯ(�� -> �� -> �� -> ��)
		Direction++; 
		if (Direction == 4) {
			Direction = 0;
		}
		// ������ 2�� �ٲ� ������ ����̵��� �̵� �Ÿ��� 1�� ����
		Dir_Change++;
		if (Dir_Change == 2) {
			Dir_Change = 0;
			moveLen++;
		}
		// ����̵��� N��ŭ �̵��ϴ� ��쿡�� ����̵��� (1, 1)���� �̵��� �� �Ҹ��Ѵٴ� ���̴�.
		if (moveLen == N) {
			Tornado(Start.first, Start.second, Direction, moveLen);
			break;
		}
	};

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
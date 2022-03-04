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
#define MAX 18
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	int Y, X, Dir;
};
int N, K;
int MAP[MAX][MAX]; // ������ ����
vector<int> MAP_Mal[MAX][MAX]; // ���ڿ� ���� ����
vector<INFO> Mal; // K���� ������ ����
int moveY[5] = { 0,0,0,-1,1 };
int moveX[5] = { 0,1,-1,0,0 };
int answer = 0; // ��

void Mal_Move(int I) {
	int Y = Mal[I].Y;
	int X = Mal[I].X;
	int Dir = Mal[I].Dir;
	int nextY = Y + moveY[Dir];
	int nextX = X + moveX[Dir];
	if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= N)) { // �̵��� ĭ�� ���ڸ� ����� �ʴ� ���
		if (MAP[nextY][nextX] == 0) { // ���� ĭ�� ����� ��� ���� ĭ�� �ִ� ��� ������ ���� ĭ���� �̵���Ų��.
			for (int i = 0; i < MAP_Mal[Y][X].size(); i++) {
				MAP_Mal[nextY][nextX].push_back(MAP_Mal[Y][X][i]);
				Mal[MAP_Mal[Y][X][i]].Y = nextY;
				Mal[MAP_Mal[Y][X][i]].X = nextX;
			}
			MAP_Mal[Y][X].clear();
		}
		else if (MAP[nextY][nextX] == 1) { // ���� ĭ�� �������� ��� ���� ĭ�� �ִ� ��� ������ ������ �Ųٷ� �ؼ� ���� ĭ���� �̵���Ų��.
			for (int i = (MAP_Mal[Y][X].size() - 1); i >= 0; i--) {
				MAP_Mal[nextY][nextX].push_back(MAP_Mal[Y][X][i]);
				Mal[MAP_Mal[Y][X][i]].Y = nextY;
				Mal[MAP_Mal[Y][X][i]].X = nextX;
			}
			MAP_Mal[Y][X].clear();
		}
		else if (MAP[nextY][nextX] == 2) { // ���� ĭ�� �������� ���
			// ������ �ݴ�� �Ѵ�.
			if (Mal[I].Dir == 1) {
				Mal[I].Dir = 2;
			}
			else if (Mal[I].Dir == 2) {
				Mal[I].Dir = 1;
			}
			else if (Mal[I].Dir == 3) {
				Mal[I].Dir = 4;
			}
			else if (Mal[I].Dir == 4) {
				Mal[I].Dir = 3;
			}
			Dir = Mal[I].Dir;
			nextY = Y + moveY[Dir];
			nextX = X + moveX[Dir];
			// ���� �ٲ� ������ �̵��� ĭ�� ���ڸ� ����� �ʰ� �Ķ����� �ƴ� ��� ĭ�� �̵���Ű��, ���ڸ� ����ų� �Ķ����̸� ���д�.
			if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= N) && (MAP[nextY][nextX] != 2)) {
				if (MAP[nextY][nextX] == 0) {
					for (int i = 0; i < MAP_Mal[Y][X].size(); i++) {
						MAP_Mal[nextY][nextX].push_back(MAP_Mal[Y][X][i]);
						Mal[MAP_Mal[Y][X][i]].Y = nextY;
						Mal[MAP_Mal[Y][X][i]].X = nextX;
					}
					MAP_Mal[Y][X].clear();
				}
				else if (MAP[nextY][nextX] == 1) {
					for (int i = (MAP_Mal[Y][X].size() - 1); i >= 0; i--) {
						MAP_Mal[nextY][nextX].push_back(MAP_Mal[Y][X][i]);
						Mal[MAP_Mal[Y][X][i]].Y = nextY;
						Mal[MAP_Mal[Y][X][i]].X = nextX;
					}
					MAP_Mal[Y][X].clear();
				}
			}
		}
	}
	else { // ���� ĭ�� ���ڸ� ����� ���, �Ķ������� �̵��ϴ� ���� �Ȱ���.
		if (Mal[I].Dir == 1) {
			Mal[I].Dir = 2;
		}
		else if (Mal[I].Dir == 2) {
			Mal[I].Dir = 1;
		}
		else if (Mal[I].Dir == 3) {
			Mal[I].Dir = 4;
		}
		else if (Mal[I].Dir == 4) {
			Mal[I].Dir = 3;
		}
		Dir = Mal[I].Dir;
		nextY = Y + moveY[Dir];
		nextX = X + moveX[Dir];
		if ((nextY >= 1) && (nextY <= N) && (nextX >= 1) && (nextX <= N) && (MAP[nextY][nextX] != 2)) {
			if (MAP[nextY][nextX] == 0) {
				for (int i = 0; i < MAP_Mal[Y][X].size(); i++) {
					MAP_Mal[nextY][nextX].push_back(MAP_Mal[Y][X][i]);
					Mal[MAP_Mal[Y][X][i]].Y = nextY;
					Mal[MAP_Mal[Y][X][i]].X = nextX;
				}
				MAP_Mal[Y][X].clear();
			}
			else if (MAP[nextY][nextX] == 1) {
				for (int i = (MAP_Mal[Y][X].size() - 1); i >= 0; i--) {
					MAP_Mal[nextY][nextX].push_back(MAP_Mal[Y][X][i]);
					Mal[MAP_Mal[Y][X][i]].Y = nextY;
					Mal[MAP_Mal[Y][X][i]].X = nextX;
				}
				MAP_Mal[Y][X].clear();
			}
		}
	}
}

bool isGameEnd() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP_Mal[i][j].size() >= 4) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	FIRST
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}
	Mal.resize(K + 1);
	for (int i = 1; i <= K; i++) {
		cin >> Mal[i].Y >> Mal[i].X >> Mal[i].Dir;
		MAP_Mal[Mal[i].Y][Mal[i].X].push_back(i);
	}
	while (1) {
		bool Flag = false;
		answer++;
		if (answer > 1000) { // ���� 1000�� ������ ������ �����Ű�� -1�� ����Ѵ�.
			answer = -1;
			break;
		}
		for (int i = 1; i <= K; i++) {
			if (MAP_Mal[Mal[i].Y][Mal[i].X][0] == i) { // ������ ĭ�� �� �ؿ� ���� ��쿡�� �����δ�.
				Mal_Move(i);
			}
			if (isGameEnd()) { // ������ �����̴� ���߿� ĭ �ϳ��� ���� 4�� �̻� �����ϴ� ��� ������ ������.
				Flag = true;
				break;
			}
		}
		if (Flag) {
			break;
		}
	};
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
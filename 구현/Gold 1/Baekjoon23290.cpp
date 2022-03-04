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
#define MAX 4
#define LL long long
#define INF 1e9

using namespace std;
struct FISH {
	int FY, FX, D;
};

int M, S;
vector<FISH> Fish_Map[MAX][MAX]; // ���� ������ ����. i�� j���� ĭ�� �ִ� �������� ������ ��� �ִ�.
vector<FISH> Clone_Map[MAX][MAX]; // ���� ������ �����ϱ� ���� �ʿ��� �ӽ� ����
pair<int, int> Shark; // ����� ��ġ
int Smell[MAX][MAX]; // i�� j���� �ִ� ������� ����
int Tmp_Route[3];
int Shark_Route[3]; // ����� �̵� ���
int Max_Deleted_Fish; // �� �ִ�� ���� �� �ִ� �����
// �������� �̵� ����
int Fish_moveY[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int Fish_moveX[9] = { 0,-1,-1,0,1,1,1,0,-1 };
// ����� �̵� ����
int Shark_moveY[5] = { 0,-1,0,1,0 };
int Shark_moveX[5] = { 0,0,-1,0,1 };

void Copy_Magic() {
	// 1. �� ��� ����⿡�� ���� ������ �����Ѵ�. ���� ������ �ð��� ���� �ɸ��� ������, �Ʒ� 5������ ����Ⱑ �����Ǿ� ĭ�� ��Ÿ����.
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			Clone_Map[i][j] = Fish_Map[i][j];
		}
	}
}

bool isShark(int Y, int X) {
	// ����Ⱑ �̵��ϴ� ���� �� �ִ� ���̶�� false, �װ� �ƴϸ� true
	if ((Y == Shark.first) && (X == Shark.second)) {
		return false;
	}
	return true;
}

void Fish_Moving() {
	/*
		2. ��� ����Ⱑ �� ĭ �̵��Ѵ�. �� �ִ� ĭ, ������� ������ �ִ� ĭ, ������ ������ ����� ĭ���δ� �̵��� �� ����. 
		�� ������ �ڽ��� ������ �ִ� �̵� ������ �̵��� �� �ִ� ĭ�� ���� ������ ������ 45�� �ݽð� ȸ����Ų��. 
		����, �̵��� �� �ִ� ĭ�� ������ �̵��� ���� �ʴ´�. 
		�� ���� ��쿡�� �� ĭ���� �̵��� �Ѵ�. ������� ������ �Ʒ� 3���� �����Ѵ�.
	*/
	vector<FISH> Tmp_Map[MAX][MAX]; // �̵��� �������� ������ ��Ƶδ� ���� �迭
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < Fish_Map[i][j].size(); k++) {
				// i�� j���� �ִ� k��° ������� �̵� ��θ� ���� ���̴�.
				int Y = Fish_Map[i][j][k].FY;
				int X = Fish_Map[i][j][k].FX;
				int Dir = Fish_Map[i][j][k].D;
				int nextY, nextX;
				bool Flag = false;
				for (int l = 0; l < 8; l++) { // 8������ �ݽð� �������� ������ Ȯ���ϸ鼭, ����Ⱑ �� �� �ִ� ���� ã�´�.
					nextY = Y + Fish_moveY[Dir];
					nextX = X + Fish_moveX[Dir];
					if ((nextY >= 0) && (nextY < MAX) && (nextX >= 0) && (nextX < MAX) && (isShark(nextY, nextX)) && (Smell[nextY][nextX] == 0)) {
						Flag = true;
						break;
					}
					Dir--;
					if (Dir == 0) {
						Dir = 8;
					}
				}
				if (Flag) {
					Tmp_Map[nextY][nextX].push_back({ nextY,nextX,Dir });
				}
				else {
					Tmp_Map[Y][X].push_back({ Y,X,Dir });
				}
			}
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			Fish_Map[i][j] = Tmp_Map[i][j];
		}
	}
}

int Shark_Moving_Simulation() {
	bool visited[MAX][MAX] = { false, };
	int Y = Shark.first;
	int X = Shark.second;
	int res = 0;
	for (int i = 0; i < 3; i++) { // ù ��°���� �� ��°������ �� ������ ���
		int Dir = Tmp_Route[i];
		int nextY = Y + Shark_moveY[Dir];
		int nextX = X + Shark_moveX[Dir];
		if ((nextY >= 0) && (nextY < MAX) && (nextX >= 0) && (nextX < MAX)) { // ���ڸ� ����� �� �ȴ�.
			if (!visited[nextY][nextX]) {
				visited[nextY][nextX] = true;
				res += Fish_Map[nextY][nextX].size();
			}
			Y = nextY;
			X = nextX;
		}
		else {
			return -1; // ���ڸ� ����� -1 return
		}
	}
	return res; // �� ���� �� �ִ� ������� ���� �� return
}

void Find_Route(int Depth) {
	// ��Ʈ��ŷ ����� ����Ͽ� ����� ��θ� ã�´�.
	if (Depth == 3) {
		int Ate = Shark_Moving_Simulation();
		if (Max_Deleted_Fish < Ate) {
			Max_Deleted_Fish = Ate;
			for (int i = 0; i < 3; i++) {
				Shark_Route[i] = Tmp_Route[i];
			}
		}
		return;
	}
	for (int i = 1; i <= 4; i++) {
		Tmp_Route[Depth] = i;
		Find_Route(Depth + 1);
		Tmp_Route[Depth] = 0;
	}
}

void Shark_Moving(int Time) {
	/*
		3. �� �����ؼ� 3ĭ �̵��Ѵ�. ���� ���� ĭ���� �����¿�� ������ ĭ���� �̵��� �� �ִ�. 
		�����ؼ� �̵��ϴ� ĭ �߿� ������ ������ ����� ĭ�� ������, �� ����� �Ұ����� �̵� ����̴�. 
		�����ؼ� �̵��ϴ� �߿� �� ����Ⱑ �ִ� ���� ĭ���� �̵��ϰ� �ȴٸ�, �� ĭ�� �ִ� ��� ������ ���ڿ��� ���ܵǸ�, 
		���ܵǴ� ��� ������ ����� ������ �����. 
		������ �̵� ��� �߿��� ���ܵǴ� ������� ���� ���� ���� ������� �̵��ϸ�, 
		�׷��� ����� ���������� ��� ���� ������ ���� �ռ��� ����� �̿��Ѵ�.
	*/
	vector<FISH> Tmp_Map[MAX][MAX];
	Max_Deleted_Fish = -1;
	Find_Route(0);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			Tmp_Map[i][j] = Fish_Map[i][j];
		}
	}
	int Y = Shark.first;
	int X = Shark.second;
	for (int i = 0; i < 3; i++) { // ����� �̵� ��θ� ���� ��
		int Dir = Shark_Route[i];
		int nextY = Y + Shark_moveY[Dir];
		int nextX = X + Shark_moveX[Dir];
		if (Tmp_Map[nextY][nextX].size() != 0) { // ����Ⱑ �ִ� ���̶�� ����⸦ �� �����鼭, ������ ĭ�� ������ �����.
			Smell[nextY][nextX] = Time;
			Tmp_Map[nextY][nextX].clear();
		}
		Y = nextY;
		X = nextX;
		Shark.first = Y;
		Shark.second = X;
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			Fish_Map[i][j] = Tmp_Map[i][j];
		}
	}
}

void Smell_Delete(int Time) {
	// 4. �� �� �� �������� ���� ������� ������ ���ڿ��� �������.
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (Smell[i][j] > 0) {
				if (Time - Smell[i][j] == 2) { // ���� �ϰ� ĭ�� ������ ������ ���� ���̰� 2��� ������ �������.
					Smell[i][j] = 0;
				}
			}
		}
	}
}

void Finish_Magic() {
	// 5. 1���� ����� ���� ������ �Ϸ�ȴ�. ��� ������ ������ 1������ ��ġ�� ������ �״�� ���� �ȴ�.
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < Clone_Map[i][j].size(); k++) {
				Fish_Map[i][j].push_back(Clone_Map[i][j][k]);
			}
		}
	}
}

int Fish_Counting() {
	int res = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			res += Fish_Map[i][j].size();
		}
	}
	return res;
}

int main() {
	FIRST
	cin >> M >> S;
	for (int i = 0; i < M; i++) {
		int FY, FX, D;
		cin >> FY >> FX >> D;
		FY--;
		FX--;
		Fish_Map[FY][FX].push_back({ FY,FX,D });
	}
	cin >> Shark.first >> Shark.second;
	Shark.first--;
	Shark.second--;
	for (int i = 1; i <= S; i++) {
		Copy_Magic();
		Fish_Moving();
		Shark_Moving(i);
		Smell_Delete(i);
		Finish_Magic();
	}
	cout << Fish_Counting() << "\n";

	getchar();
	getchar();
	return 0;
}
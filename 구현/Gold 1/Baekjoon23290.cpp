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
vector<FISH> Fish_Map[MAX][MAX]; // 현재 격자의 상태. i행 j열의 칸에 있는 물고기들의 정보가 들어 있다.
vector<FISH> Clone_Map[MAX][MAX]; // 복제 마법을 시전하기 위해 필요한 임시 격자
pair<int, int> Shark; // 상어의 위치
int Smell[MAX][MAX]; // i행 j열에 있는 물고기의 냄새
int Tmp_Route[3];
int Shark_Route[3]; // 상어의 이동 경로
int Max_Deleted_Fish; // 상어가 최대로 잡을 수 있는 물고기
// 물고기들의 이동 방향
int Fish_moveY[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int Fish_moveX[9] = { 0,-1,-1,0,1,1,1,0,-1 };
// 상어의 이동 방향
int Shark_moveY[5] = { 0,-1,0,1,0 };
int Shark_moveX[5] = { 0,0,-1,0,1 };

void Copy_Magic() {
	// 1. 상어가 모든 물고기에게 복제 마법을 시전한다. 복제 마법은 시간이 조금 걸리기 때문에, 아래 5번에서 물고기가 복제되어 칸에 나타난다.
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			Clone_Map[i][j] = Fish_Map[i][j];
		}
	}
}

bool isShark(int Y, int X) {
	// 물고기가 이동하는 곳이 상어가 있는 곳이라면 false, 그게 아니면 true
	if ((Y == Shark.first) && (X == Shark.second)) {
		return false;
	}
	return true;
}

void Fish_Moving() {
	/*
		2. 모든 물고기가 한 칸 이동한다. 상어가 있는 칸, 물고기의 냄새가 있는 칸, 격자의 범위를 벗어나는 칸으로는 이동할 수 없다. 
		각 물고기는 자신이 가지고 있는 이동 방향이 이동할 수 있는 칸을 향할 때까지 방향을 45도 반시계 회전시킨다. 
		만약, 이동할 수 있는 칸이 없으면 이동을 하지 않는다. 
		그 외의 경우에는 그 칸으로 이동을 한다. 물고기의 냄새는 아래 3에서 설명한다.
	*/
	vector<FISH> Tmp_Map[MAX][MAX]; // 이동한 물고기들의 정보를 담아두는 벡터 배열
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			for (int k = 0; k < Fish_Map[i][j].size(); k++) {
				// i행 j열에 있는 k번째 물고기의 이동 경로를 정할 것이다.
				int Y = Fish_Map[i][j][k].FY;
				int X = Fish_Map[i][j][k].FX;
				int Dir = Fish_Map[i][j][k].D;
				int nextY, nextX;
				bool Flag = false;
				for (int l = 0; l < 8; l++) { // 8방향을 반시계 방향으로 돌리며 확인하면서, 물고기가 갈 수 있는 곳을 찾는다.
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
	for (int i = 0; i < 3; i++) { // 첫 번째부터 세 번째까지의 상어가 선택한 경로
		int Dir = Tmp_Route[i];
		int nextY = Y + Shark_moveY[Dir];
		int nextX = X + Shark_moveX[Dir];
		if ((nextY >= 0) && (nextY < MAX) && (nextX >= 0) && (nextX < MAX)) { // 격자를 벗어나면 안 된다.
			if (!visited[nextY][nextX]) {
				visited[nextY][nextX] = true;
				res += Fish_Map[nextY][nextX].size();
			}
			Y = nextY;
			X = nextX;
		}
		else {
			return -1; // 격자를 벗어나면 -1 return
		}
	}
	return res; // 상어가 잡을 수 있는 물고기의 수의 합 return
}

void Find_Route(int Depth) {
	// 백트래킹 기법을 사용하여 상어의 경로를 찾는다.
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
		3. 상어가 연속해서 3칸 이동한다. 상어는 현재 칸에서 상하좌우로 인접한 칸으로 이동할 수 있다. 
		연속해서 이동하는 칸 중에 격자의 범위를 벗어나는 칸이 있으면, 그 방법은 불가능한 이동 방법이다. 
		연속해서 이동하는 중에 상어가 물고기가 있는 같은 칸으로 이동하게 된다면, 그 칸에 있는 모든 물고기는 격자에서 제외되며, 
		제외되는 모든 물고기는 물고기 냄새를 남긴다. 
		가능한 이동 방법 중에서 제외되는 물고기의 수가 가장 많은 방법으로 이동하며, 
		그러한 방법이 여러가지인 경우 사전 순으로 가장 앞서는 방법을 이용한다.
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
	for (int i = 0; i < 3; i++) { // 상어의 이동 경로를 정한 후
		int Dir = Shark_Route[i];
		int nextY = Y + Shark_moveY[Dir];
		int nextX = X + Shark_moveX[Dir];
		if (Tmp_Map[nextY][nextX].size() != 0) { // 물고기가 있는 곳이라면 물고기를 다 잡으면서, 물고기는 칸에 냄새를 남긴다.
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
	// 4. 두 번 전 연습에서 생긴 물고기의 냄새가 격자에서 사라진다.
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (Smell[i][j] > 0) {
				if (Time - Smell[i][j] == 2) { // 현재 턴과 칸에 냄새가 남겨진 턴의 차이가 2라면 냄새는 사라진다.
					Smell[i][j] = 0;
				}
			}
		}
	}
}

void Finish_Magic() {
	// 5. 1에서 사용한 복제 마법이 완료된다. 모든 복제된 물고기는 1에서의 위치와 방향을 그대로 갖게 된다.
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
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
#define MAX 55
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
int MAP_Number[MAX][MAX]; // (i, j)칸에 적힌 수
int MAP[MAX][MAX]; // (i, j)칸에 있는 구슬의 번호
int Bead_Number[MAX * MAX]; // i번째 칸에 있는 구슬
int tmp[MAX * MAX];
pair<int, int> Shark; // 상어의 위치
bool visited[MAX][MAX];
// 칸의 번호를 매길 때 사용
int moveY[4] = { 0,1,0,-1 };
int moveX[4] = { -1,0,1,0 };
// 블리자드 마법을 시전할 때 사용
int BlizzardY[5] = { 0,-1,1,0,0 };
int BlizzardX[5] = { 0,0,0,-1,1 };
int Bombed_Bead[4] = { 0, }; // i번 구슬이 폭발한 횟수

void init() {
	/*
		격자의 번호를 매기는 함수 구현
	*/
	Shark = make_pair((N + 1) / 2, (N + 1) / 2);
	int Dir = 0;
	int Len = 1;
	int Cnt = 0;
	int Number = 1;
	while (1) {
		for (int i = 0; i < Len; i++) {
			int Y = Shark.first;
			int X = Shark.second;
			int nextY = Y + moveY[Dir];
			int nextX = X + moveX[Dir];
			MAP_Number[nextY][nextX] = Number;
			Number++;
			Shark = make_pair(nextY, nextX);
		}
		Dir++;
		if (Dir == 4) {
			Dir = 0;
		}
		Cnt++;
		if (Cnt == 2) {
			Cnt = 0;
			Len++;
		}
		if (Len == N) {
			for (int i = 0; i < Len; i++) {
				int Y = Shark.first;
				int X = Shark.second;
				int nextY = Y + moveY[Dir];
				int nextX = X + moveX[Dir];
				MAP_Number[nextY][nextX] = Number;
				Number++;
				Shark = make_pair(nextY, nextX);
			}
			break;
		}
	};
	Shark = make_pair((N + 1) / 2, (N + 1) / 2);
}

void Blizzard_Magic(int Dir, int Len) {
	// 블리자드 마법 시전: 방향, 거리에 따라 해당하는 칸에 있는 구슬을 모두 파괴한다.
	int Y = Shark.first;
	int X = Shark.second;
	for (int i = 1; i <= Len; i++) {
		int nextY = Y + BlizzardY[Dir];
		int nextX = X + BlizzardX[Dir];
		MAP[nextY][nextX] = 0;
		Bead_Number[MAP_Number[nextY][nextX]] = 0;
		Y = nextY;
		X = nextX;
	}
}

void Bead_Moving() {
	for (int i = 1; i < (N * N); i++) {
		if (Bead_Number[i] == 0) {
			for (int j = (i + 1); j < (N * N); j++) {
				if (Bead_Number[j] != 0) {
					Bead_Number[i] = Bead_Number[j];
					Bead_Number[j] = 0;
					break;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			MAP[i][j] = Bead_Number[MAP_Number[i][j]];
		}
	}
}

bool Bead_Explosion() {
	// 4개 이상 연속하는 구슬이 있을 때 폭발이 발생한다.
	bool Flag = false;
	int Start = -1;
	int Len = 0;
	for (int i = 1; i < (N * N); i++) {
		if (Bead_Number[i] == 0) {
			break;
		}
		if (Start == -1) {
			Start = i;
			Len = 1;
		}
		else {
			if (Bead_Number[i] == Bead_Number[Start]) {
				Len++;
			}
			else {
				if (Len >= 4) {
					Flag = true;
					for (int j = Start; j < i; j++) {
						Bombed_Bead[Bead_Number[j]]++;
						Bead_Number[j] = 0;
					}
				}
				Start = i;
				Len = 1;
			}
		}
	}
	if ((Start != -1) && (Len >= 4)) {
		Flag = true;
		for (int i = Start; i < (N * N); i++) {
			Bombed_Bead[Bead_Number[i]]++;
			Bead_Number[i] = 0;
		}
	}
	return Flag;
}

void Make_Group() {
	// 그룹을 만들어, 연속하는 구슬의 개수를 세고 개수 A, 구슬의 번호 B를 구슬의 번호로 넣는다.
	int A = 0;
	int B = -1;
	for (int i = 0; i < (MAX * MAX); i++) {
		tmp[i] = 0;
	}
	int IDX = 1;
	bool isFull = false;
	for (int i = 1; i < (N * N); i++) {
		if (Bead_Number[i] == 0) {
			continue;
		}
		if (B == -1) {
			B = Bead_Number[i];
			A = 1;
		}
		else {
			if (Bead_Number[i] == B) {
				A++;
			}
			else {
				if (!isFull) {
					tmp[IDX++] = A;
				}
				if (IDX == (MAX * MAX)) {
					isFull = true;
				}
				if (!isFull) {
					tmp[IDX++] = B;
				}
				if (IDX == (MAX * MAX)) {
					isFull = true;
				}
				B = Bead_Number[i];
				A = 1;
			}
		}
	}
	if (B != -1) {
		if (!isFull) {
			tmp[IDX++] = A;
		}
		if (IDX == (MAX * MAX)) {
			isFull = true;
		}
		if (!isFull) {
			tmp[IDX++] = B;
		}
	}
	for (int i = 1; i < (N * N); i++) {
		Bead_Number[i] = tmp[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			MAP[i][j] = Bead_Number[MAP_Number[i][j]];
		}
	}
}

int Solution() {
	return (Bombed_Bead[1] + (2 * Bombed_Bead[2]) + (3 * Bombed_Bead[3]));
}

int main() {
	FIRST
	cin >> N >> M;
	init();
	// 현재 격자마다 들어 있는 구슬의 번호 입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			Bead_Number[MAP_Number[i][j]] = MAP[i][j];
		}
	}
	// 상어가 총 M번의 블리자드 마법을 시전
	for (int i = 0; i < M; i++) {
		int D, S;
		cin >> D >> S;
		Blizzard_Magic(D, S);
		Bead_Moving();
		while (1) {
			bool isExplosion = Bead_Explosion();
			Bead_Moving();
			if (!isExplosion) {
				break;
			}
		};
		Make_Group();
	}
	cout << Solution() << "\n";

	getchar();
	getchar();
	return 0;
}
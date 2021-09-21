#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 20
#define INF 2e9

using namespace std;
struct Archer {
	int Y, X;
};

struct Enemy{
	int Y, X, Dist;
};

int N, M, D;
int A[MAX][MAX];
vector<Archer> archer;
vector<pair<int, int> > vec;
bool visited[MAX][MAX];
int kill;
int answer = 0;

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			visited[i][j] = false;
		}
	}
	vec.clear();
}

void Copy_Arr(int tmp[][MAX]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			tmp[i][j] = A[i][j];
		}
	}
}

void Return_Arr(int tmp[][MAX]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			A[i][j] = tmp[i][j];
		}
	}
}

int Find_Dist(int A, int B, int C, int D) {
	int res = abs(A - C) + abs(B - D);
	return res;
}

bool Enemy_Empty() {
	bool flag = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (A[i][j] == 1) {
				flag = false;
				vec.push_back(make_pair(i, j));
			}
		}
	}
	return flag;
}

bool comp(Enemy A, Enemy B) {
	if (A.Dist == B.Dist) {
		return (A.X < B.X);
	}
	return (A.Dist < B.Dist);
}

void Shoot_Enemy() {
	pair<int, int> arrow[3];
	for (int i = 0; i < archer.size(); i++) {
		int Y = archer[i].Y;
		int X = archer[i].X;
		vector<Enemy> enemy;
		for (int j = 0; j < vec.size(); j++) {
			int EY = vec[j].first;
			int EX = vec[j].second;
			int Dist = Find_Dist(Y, X, EY, EX);
			if (Dist <= D) {
				enemy.push_back({ EY,EX,Dist });
			}
		}
		int kill_sum = enemy.size();
		if (kill_sum == 0) {
			arrow[i].first = -1;
			arrow[i].second = -1;
		}
		else if (kill_sum == 1) {
			arrow[i].first = enemy[0].Y;
			arrow[i].second = enemy[0].X;
		}
		else if (kill_sum > 1) {
			sort(enemy.begin(), enemy.end(), comp);
			arrow[i].first = enemy[0].Y;
			arrow[i].second = enemy[0].X;
		}
	}
	for (int i = 0; i < 3; i++) {
		int Y = arrow[i].first;
		int X = arrow[i].second;
		if ((Y == -1) && (X == -1)) {
			continue;
		}
		if (!visited[Y][X]) {
			visited[Y][X] = true;
			A[Y][X] = 0;
			kill++;
		}
	}
}

void Move_Enemy() {
	for (int i = N; i >= 2; i--) {
		for (int j = 1; j <= M; j++) {
			A[i][j] = A[i - 1][j];
			A[i - 1][j] = 0;
		}
	}
}

void Archer_Set(int IDX, int depth) {
	if (depth == 3) {
		kill = 0;
		int tmpA[MAX][MAX];
		Copy_Arr(tmpA);
		while (1) {
			init();
			if (Enemy_Empty()) {
				break;
			}
			Shoot_Enemy();
			Move_Enemy();
		};
		answer = max(answer, kill);
		Return_Arr(tmpA);
		return;
	}
	for (int i = IDX + 1; i <= M; i++) {
		if (A[N + 1][i] == 0) {
			A[N + 1][i] = 2;
			archer.push_back({ N + 1,i });
			Archer_Set(i, depth + 1);
			archer.pop_back();
			A[N + 1][i] = 0;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> D;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
	Archer_Set(0, 0);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
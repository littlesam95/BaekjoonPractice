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
#define MAX 21
#define INF 2e9

using namespace std;
struct SHARK {
	int Y, X, Dir;
	bool state = true;
	vector<int> Dir_Priority[5];
};

struct MAP_INFO {
	vector<int> vec;
	int SmellTime;
	int SmellShark;
};

int N, M, K;
MAP_INFO MAP[MAX][MAX];
vector<SHARK> shark;
int moveY[5] = { 0,-1,1,0,0 };
int moveX[5] = { 0,0,0,-1,1 };
int answer = 0;

void Setting_Smell(int Time) {
	for (int i = 1; i <= M; i++) {
		if (!shark[i].state) {
			continue;
		}
		int Y = shark[i].Y;
		int X = shark[i].X;
		MAP[Y][X].SmellTime = K;
		MAP[Y][X].SmellShark = i;
	}
}

void Move_Shark(int Time) {
	for (int i = 1; i <= M; i++) {
		if (!shark[i].state) {
			continue;
		}
		MAP[shark[i].Y][shark[i].X].vec.clear();
	}
	for (int i = 1; i <= M; i++) {
		if (!shark[i].state) {
			continue;
		}
		int otherY = -1;
		int otherX = -1;
		int otherDir = -1;
		bool flag = false;
		int size = shark[i].Dir_Priority[shark[i].Dir].size();
		for (int j = 0; j < size; j++) {
			int newDir = shark[i].Dir_Priority[shark[i].Dir][j];
			int nextY = shark[i].Y + moveY[newDir];
			int nextX = shark[i].X + moveX[newDir];
			if ((nextY < 0) || (nextY >= N) || (nextX < 0) || (nextX >= N)) {
				continue;
			}
			if (MAP[nextY][nextX].SmellTime == 0) {
				flag = true;
				MAP[nextY][nextX].vec.push_back(i);
				shark[i].Y = nextY;
				shark[i].X = nextX;
				shark[i].Dir = newDir;
				break;
			}
			else if (MAP[nextY][nextX].SmellTime > 0) {
				if (MAP[nextY][nextX].SmellShark == i) {
					if (otherY == -1) {
						otherY = nextY;
						otherX = nextX;
						otherDir = newDir;
					}
				}
			}
		}
		if (!flag) {
			MAP[otherY][otherX].vec.push_back(i);
			shark[i].Y = otherY;
			shark[i].X = otherX;
			shark[i].Dir = otherDir;
		}
	}
}

void Arrange_Shark() {
	for (int i = 1; i <= M; i++) {
		if (!shark[i].state) {
			continue;
		}
		int Y = shark[i].Y;
		int X = shark[i].X;
		if (MAP[Y][X].vec.size() >= 2) {
			sort(MAP[Y][X].vec.begin(), MAP[Y][X].vec.end());
			int size = MAP[Y][X].vec.size();
			int First_Shark = MAP[Y][X].vec[0];
			for (int j = 1; j < size; j++) {
				shark[MAP[Y][X].vec[j]].state = false;
			}
			MAP[Y][X].vec.clear();
			MAP[Y][X].vec.push_back(First_Shark);
			MAP[Y][X].SmellShark = First_Shark;
		}
	}
}

void Delete_Smell() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (MAP[i][j].SmellTime > 0) {
				MAP[i][j].SmellTime--;
				if (MAP[i][j].SmellTime == 0) {
					MAP[i][j].SmellShark = 0;
				}
			}
		}
	}
}

bool Check_Shark() {
	for (int i = 2; i <= M; i++) {
		if (shark[i].state) {
			return false;
		}
	}
	return true;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	shark.resize(MAX * MAX + 1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int A;
			cin >> A;
			if (A >= 1) {
				MAP[i][j].vec.push_back(A);
				shark[A].Y = i;
				shark[A].X = j;
				shark[i].state = true;
			}
			MAP[i][j].SmellTime = 0;
			MAP[i][j].SmellShark = 0;
		}
	}
	for (int i = 1; i <= M; i++) {
		cin >> shark[i].Dir;
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < 4; k++) {
				int D;
				cin >> D;
				shark[i].Dir_Priority[j].push_back(D);
			}
		}
	}

	while (1) {
		if (Check_Shark()) {
			break;
		}
		Setting_Smell(answer);
		Move_Shark(answer);
		Arrange_Shark();
		Delete_Smell();
		answer++;
		if (answer > 1000) {
			answer = -1;
			break;
		}
	};

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
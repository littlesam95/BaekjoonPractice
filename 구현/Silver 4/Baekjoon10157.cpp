#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1001

using namespace std;
int C, R, K;
int MAP[MAX][MAX];
int moveY[4] = { -1,0,1,0 };
int moveX[4] = { 0,1,0,-1 };
pair<int, int> answer;

bool Finish() {
	bool res = true;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] == 0) {
				res = false;
				break;
			}
		}
		if (!res) {
			break;
		}
	}
	return res;
}

void setMap() {
	int Dir = 0;
	int Number = 1;
	int curY = R - 1;
	int curX = 0;
	while (1) {
		while (1) {
			MAP[curY][curX] = Number;
			Number++;
			int nextY = curY + moveY[Dir];
			int nextX = curX + moveX[Dir];
			if ((nextY < 0) || (nextY >= R) || (nextX < 0) || (nextX >= C) || (MAP[nextY][nextX] != 0)) {
				Dir++;
				if (Dir == 4) {
					Dir = 0;
				}
				curY += moveY[Dir];
				curX += moveX[Dir];
				break;
			}
			else {
				curY = nextY;
				curX = nextX;
			}
		};
		if (Finish()) {
			break;
		}
	};
}

int main() {
	FIRST;
	cin >> C >> R;
	cin >> K;

	if (R * C < K) {
		cout << 0 << "\n";
	}
	else {
		setMap();
		for (int i = 0; i < R; i++) {
			bool Flag = false;
			for (int j = 0; j < C; j++) {
				if (MAP[i][j] == K) {
					answer = make_pair(i, j);
					Flag = true;
					break;
				}
			}
			if (Flag) {
				break;
			}
		}
		cout << answer.second + 1 << " " << R - answer.first << "\n";
	}

	getchar();
	getchar();
	return 0;
}
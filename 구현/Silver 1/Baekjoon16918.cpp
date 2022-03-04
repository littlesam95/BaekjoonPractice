#include <iostream>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 202

using namespace std;
int R, C, N;
int Sec = 2;
int MAP[MAX][MAX];
int Burst_Time[MAX][MAX];

int main() {
	FIRST
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < C; j++) {
			if (S[j] == '.') {
				MAP[i][j] = -1;
			}
			else if (S[j] == 'O') {
				MAP[i][j] = 0;
				Burst_Time[i][j] = 3;
			}
		}
	}
	while (1) {
		if (Sec > N) {
			break;
		}
		if (Sec % 2 == 1) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (Burst_Time[i][j] == Sec) {
						int Y = i;
						int X = j;
						if ((Y + 1 < R) && (MAP[Y + 1][X] == 0)) {
							MAP[Y + 1][X] = -1;
						}
						if ((X + 1 < C) && (MAP[Y][X + 1] == 0)) {
							MAP[Y][X + 1] = -1;
						}
						if ((Y - 1 >= 0) && (MAP[Y - 1][X] == 0)) {
							MAP[Y - 1][X] = -1;
						}
						if ((X - 1 >= 0) && (MAP[Y][X - 1] == 0)) {
							MAP[Y][X - 1] = -1;
						}
						MAP[i][j] = -1;
						Burst_Time[i][j] = 0;
					}
				}
			}
		}
		else if (Sec % 2 == 0) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					if (MAP[i][j] == -1) {
						MAP[i][j] = 0;
						Burst_Time[i][j] = Sec + 3;
					}
				}
			}
		}
		Sec++;
	};
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (MAP[i][j] == -1) {
				cout << '.';
			}
			else {
				cout << 'O';
			}
		}
		cout << "\n";
	}

	getchar();
	getchar();
	return 0;
}
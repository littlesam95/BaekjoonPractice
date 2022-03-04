#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 101

using namespace std;
int H, W;
int Cur = 0;
int MAP[MAX][MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			MAP[i][j] = -1;
		}
	}
}

int main() {
	FIRST;
	init();
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		string S;
		cin >> S;
		for (int j = 0; j < W; j++) {
			if (S[j] == 'c') {
				MAP[i][j] = 0;
			}
		}
	}

	while (1) {
		bool Flag = false;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if ((MAP[i][j] == Cur) && (MAP[i][j + 1] == -1)) {
					Flag = true;
					MAP[i][j + 1] = MAP[i][j] + 1;
				}
			}
		}
		if (!Flag) {
			break;
		}
		Cur++;
	};

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << MAP[i][j] << " ";
		}
		cout << "\n";
	}

	getchar();
	getchar();
	return 0;
}
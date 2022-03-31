#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 101
#define LL long long
#define INF 1e9

using namespace std;
int N, M, T, K, A, B;
int MAP[MAX][MAX];
int Sum[MAX][MAX];
int Next[MAX][MAX];

void Input() {
	cin >> N >> M >> T;
	cin >> K >> A >> B;
	for (int i = 1; i <= N; i++) {
		string S;
		cin >> S;
		for (int j = 1; j <= M; j++) {
			if (S[j - 1] == '*') {
				MAP[i][j] = 1;
			}
		}
	}
}

void Settings() {
	while (T--) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				Sum[i][j] = MAP[i][j] + Sum[i][j - 1] + Sum[i - 1][j] - Sum[i - 1][j - 1];
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				int Y1 = max(1, i - K);
				int X1 = max(1, j - K);
				int Y2 = min(N, i + K);
				int X2 = min(M, j + K);
				int Cur = Sum[Y2][X2] - Sum[Y1 - 1][X2] - Sum[Y2][X1 - 1] + Sum[Y1 - 1][X1 - 1] - MAP[i][j];
				if (MAP[i][j] == 1) {
					if ((A > Cur) || (B < Cur)) {
						MAP[i][j] = 0;
					}
					else if ((A <= Cur) && (Cur <= B)) {
						MAP[i][j] = 1;
					}
				}
				else {
					if ((A < Cur) && (Cur <= B)) {
						MAP[i][j] = 1;
					}
				}
			}
		}
	};
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] == 1) {
				cout << "*";
			}
			else {
				cout << ".";
			}
		}
		cout << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1001
#define LL long long
#define INF 1e12

using namespace std;
int R, C, Q, W, X, Y, Z;
int K[MAX][MAX];
int Sum[MAX][MAX];

void Settings() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			Sum[i][j] = Sum[i][j - 1] + K[i][j];
		}
	}
}

void Find_Answer() {
	int Bright = 0;
	for (int i = W; i <= Y; i++) {
		Bright += (Sum[i][Z] - Sum[i][X - 1]);
	}
	cout << Bright / ((Y - W + 1) * (Z - X + 1)) << "\n";
}

void Input() {
	cin >> R >> C >> Q;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> K[i][j];
		}
	}
	Settings();
	while (Q--) {
		cin >> W >> X >> Y >> Z;
		Find_Answer();
	};
}

int main() {
	FASTIO
	Input();

	getchar();
	getchar();
	return 0;
}
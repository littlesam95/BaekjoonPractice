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
#define MAX 101
#define INF 2e9

using namespace std;
int N;
int MAP[MAX][MAX];
vector<int> Generation;
int moveY[4] = { 0,-1,0,1 };
int moveX[4] = { 1,0,-1,0 };

int Find_Dragon_Curve() {
	int res = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if ((MAP[i][j] == 1) && (MAP[i + 1][j] == 1) && (MAP[i][j + 1] == 1) && (MAP[i + 1][j + 1] == 1)) {
				res++;
			}
		}
	}

	return res;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int X, Y, D, G;
		cin >> X >> Y >> D >> G;
		Generation.clear();
		MAP[Y][X] = 1;
		Y += moveY[D];
		X += moveX[D];
		MAP[Y][X] = 1;
		Generation.push_back(D);
		for (int j = 0; j < G; j++) {
			int size = Generation.size();
			for (int k = size - 1; k >= 0; k--) {
				int newD = (Generation[k] + 1) % 4;
				Y += moveY[newD];
				X += moveX[newD];
				MAP[Y][X] = 1;
				Generation.push_back(newD);
			}
		}
	}
	cout << Find_Dragon_Curve() << "\n";

	getchar();
	getchar();
	return 0;
}
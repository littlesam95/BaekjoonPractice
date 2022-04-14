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
#define MAX_M 21
#define MAX_N 201
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
int D[MAX_M], P[MAX_M];
int DP[MAX_M][MAX_N];
int Answer = 0;

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> D[i] >> P[i];
	}
}

void Settings() {
	for (int i = 1; i <= M; i++) {
		for (int j = N; j >= 0; j--) {
			if (j - D[i] >= 0) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - D[i]] + P[i]);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
			Answer = max(Answer, DP[i][j]);
		}
	}
}

void Find_Answer() {
	cout << Answer << "\n";
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
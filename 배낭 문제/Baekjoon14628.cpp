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
int N, M, K;
int X[MAX], Y[MAX];
int DP[MAX][MAX];

void Init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			DP[i][j] = INF;
		}
	}
}

void Input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> X[i] >> Y[i];
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			for (int k = j / Y[i]; k >= 0; k--) {
				DP[i][j] = min(DP[i][j], DP[i - 1][j - k * Y[i]] + (X[i] * k) + (K * ((k * (k - 1)) / 2)));
			}
		}
	}
}

void Find_Answer() {
	cout << DP[N][M] << "\n";
}

int main() {
	FASTIO
	Init();
	Input();
	Settings();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
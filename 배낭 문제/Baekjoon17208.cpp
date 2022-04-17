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
#define MAX_N 101
#define MAX_MK 301
#define LL long long
#define INF 1e9

using namespace std;
int N, M, K;
int X[MAX_N], Y[MAX_N];
int DP[MAX_N][MAX_MK][MAX_MK];
int Answer = 0;

void Input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> X[i] >> Y[i];
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		for (int j = M; j >= 0; j--) {
			for (int k = K; k >= 0; k--) {
				if ((j - X[i] >= 0) && (k - Y[i] >= 0)) {
					DP[i][j][k] = max(DP[i - 1][j][k], DP[i - 1][j - X[i]][k - Y[i]] + 1);
				}
				else {
					DP[i][j][k] = DP[i - 1][j][k];
				}
				Answer = max(Answer, DP[i][j][k]);
			}
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
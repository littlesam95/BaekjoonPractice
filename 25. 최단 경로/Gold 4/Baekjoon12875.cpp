#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 51
#define LL long long
#define INF 1e9

using namespace std;
int N, D;
int DP[MAX][MAX];
int answer = 0;

void input() {
	cin >> N;
	cin >> D;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char S;
			cin >> S;
			if (i == j) {
				continue;
			}
			if (S == 'N') {
				DP[i][j] = INF;
			}
			else if (S == 'Y') {
				DP[i][j] = D;
			}
		}
	}
}

void Settings() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (DP[i][j] > DP[i][k] + DP[k][j]) {
					DP[i][j] = DP[i][k] + DP[k][j];
				}
			}
		}
	}
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer = max(answer, DP[i][j]);
		}
	}
	if (answer == INF) {
		cout << -1 << "\n";
	}
	else {
		cout << answer << "\n";
	}
}

int main() {
	FASTIO
	input();
	Settings();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
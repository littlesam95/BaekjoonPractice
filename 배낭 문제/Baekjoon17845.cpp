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
#define MAX_I 100001
#define MAX_T 10001
#define MAX_K 1001
#define LL long long
#define INF 1e9

using namespace std;
int N, K;
LL I[MAX_I], T[MAX_T];
LL DP[MAX_K][MAX_T];
LL Answer = 0;

void Input() {
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		cin >> I[i] >> T[i];
	}
}

void Settings() {
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= N; j++) {
			if (j - T[i] >= 0) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - T[i]] + I[i]);
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
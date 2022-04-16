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
#define MAX_K 100001
#define LL long long
#define INF 1e9

using namespace std;
int N, K;
int C[MAX_N];
int DP[MAX_K];
int Answer = 0;

void Init() {
	for (int i = 0; i < MAX_K; i++) {
		DP[i] = INF;
	}
}

void Input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> C[i];
	}
}

void Settings() {
	Init();
	DP[0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = K; j >= C[i]; j--) {
			if (j - C[i] >= 0) {
				DP[j] = min(DP[j], DP[j - C[i]] + 1);
			}
		}
	}
}

void Find_Answer() {
	if (DP[K] == INF) {
		cout << -1 << "\n";
	}
	else {
		cout << DP[K] << "\n";
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
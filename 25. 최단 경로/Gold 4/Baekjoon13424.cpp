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
#define MAX 101
#define LL long long
#define INF 1e9

using namespace std;
int T, N, M, K, minLen, answer;
int DP[MAX][MAX];
vector<int> Friends;
int MAP[MAX][MAX];

void init() {
	minLen = INF;
	answer = 0;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (i == j) {
				continue;
			}
			DP[i][j] = INF;
		}
	}
	Friends.clear();
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		DP[A][B] = C;
		DP[B][A] = C;
	};
	cin >> K;
	while (K--) {
		int Room;
		cin >> Room;
		Friends.push_back(Room);
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
		int Len = 0;
		for (int j = 0; j < Friends.size(); j++) {
			int F = Friends[j];
			Len += DP[F][i];
		}
		if (minLen > Len) {
			minLen = Len;
			answer = i;
		}
	}
	cout << answer << "\n";
}

int main() {
	FASTIO
	cin >> T;
	while (T--) {
		init();
		input();
		Settings();
		Find_Answer();
	};

	getchar();
	getchar();
	return 0;
}
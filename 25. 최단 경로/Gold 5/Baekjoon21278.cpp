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
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 101
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
int DP[MAX][MAX];
int answerT = INF;
pair<int, int> answerP;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			DP[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		DP[A][B] = 1;
		DP[B][A] = 1;
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
		for (int j = i + 1; j <= N; j++) {
			int Time_Sum = 0;
			for (int k = 1; k <= N; k++) {
				Time_Sum += min(DP[k][i] * 2, DP[k][j] * 2);
			}
			if (answerT > Time_Sum) {
				answerT = Time_Sum;
				answerP = make_pair(i, j);
			}
		}
	}
}

int main() {
	FIRST
	cin >> N >> M;
	init();
	Settings();
	Find_Answer();
	cout << answerP.first << " " << answerP.second << " " << answerT << "\n";

	getchar();
	getchar();
	return 0;
}
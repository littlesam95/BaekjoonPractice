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
#define MAX 201
#define LL long long
#define INF 1e9

using namespace std;
int N, M, K;
int DP[MAX][MAX];
int C[MAX];
int answer = INF;
vector<int> City;

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			DP[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int A, B, T;
		cin >> A >> B >> T;
		DP[A][B] = T;
	}
	cin >> K;
	for (int i = 1; i <= K; i++) {
		cin >> C[i];
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
		int Tmp = 0;
		bool Flag = true;
		for (int j = 1; j <= K; j++) {
			if ((DP[C[j]][i] == INF) || (DP[i][C[j]] == INF)) {
				Flag = false;
				break;
			}
			Tmp = max(Tmp, DP[C[j]][i] + DP[i][C[j]]);
		}
		if (Flag) {
			if (answer > Tmp) {
				answer = Tmp;
				City.clear();
				City.push_back(i);
			}
			else if (answer == Tmp) {
				City.push_back(i);
			}
		}
	}
	for (int i = 0; i < City.size(); i++) {
		cout << City[i] << " ";
	}
	cout << "\n";
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
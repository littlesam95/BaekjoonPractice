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
#define MAX_N 100001
#define MAX_M 101
#define MAX_RB 51
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
int R[MAX_M], B[MAX_M], D[MAX_M];
int DP[MAX_RB][MAX_RB];
vector<pair<int, int> > Answer;

bool Comp(pair<int, int> A, pair<int, int> B) {
	if (A.second == B.second) {
		return (A.first < B.first);
	}
	return (A.second < B.second);
}

void Init() {
	for (int i = 0; i < MAX_RB; i++) {
		for (int j = 0; j < MAX_RB; j++) {
			DP[i][j] = -1;
		}
	}
	DP[0][0] = 0;
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> R[i] >> B[i] >> D[i];
	}
}

void Settings() {
	for (int i = 1; i <= M; i++) {
		for (int j = 50; j >= 0; j--) {
			for (int k = 50; k >= 0; k--) {
				if ((j - R[i] >= 0) && (k - B[i] >= 0) && (DP[j - R[i]][k - B[i]] != -1)) {
					DP[j][k] = max(DP[j][k], DP[j - R[i]][k - B[i]] + D[i]);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int RR, BB;
		cin >> RR >> BB;
		Answer.push_back(make_pair(i, (DP[RR][BB] == -1 ? 0 : DP[RR][BB])));
	}
	sort(Answer.begin(), Answer.end(), Comp);
}

void Find_Answer() {
	for (int i = 0; i < Answer.size(); i++) {
		cout << Answer[i].first << " " << Answer[i].second << "\n";
	}
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
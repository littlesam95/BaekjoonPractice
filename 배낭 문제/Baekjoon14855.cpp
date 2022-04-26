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
#define MAX_N 1001
#define MAX_M 11
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
int A[MAX_M], B[MAX_M], C[MAX_M], D[MAX_M];
int Bound[MAX_M];
int DP[MAX_M * MAX_N][MAX_N];
int IDX = 1;
int Answer = 0;

void Input() {
	cin >> N >> M >> C[0] >> D[0];
	for (int i = 1; i <= M; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
}

void Settings() {
	Bound[0] = N / C[0];
	for (int i = 1; i <= M; i++) {
		Bound[i] = min((A[i] / B[i]), (N / C[i]));
	}
	for (int i = 0; i <= M; i++) {
		for (int j = 1; j <= Bound[i]; j++) {
			for (int k = N; k >= 0; k--) {
				if (k - C[i] >= 0) {
					DP[IDX][k] = max(DP[IDX - 1][k], DP[IDX - 1][k - C[i]] + D[i]);
				}
				else {
					DP[IDX][k] = DP[IDX - 1][k];
				}
				Answer = max(Answer, DP[IDX][k]);
			}
			IDX++;
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
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
#define MAX_K 1000001
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
int W[MAX_N], V[MAX_N], B[MAX_N];
int Most_Weight = 0;
int DP[MAX_N][MAX_K];
int Most_VA;
int Most_WE;
int Answer;

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> B[i];
		Most_Weight = max(Most_Weight, B[i]);
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		for (int j = Most_Weight; j >= 0; j--) {
			if (j - W[i] >= 0) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	Answer = 1;
	Most_WE = B[1];
	for (int i = 1; i <= N; i++) {
		Most_VA = max(Most_VA, DP[i][B[1]]);
	}
	for (int i = 2; i <= M; i++) {
		int VA = 0;
		for (int j = 1; j <= N; j++) {
			VA = max(VA, DP[j][B[i]]);
		}
		if ((LL)Most_VA * (LL)B[i] < (LL)VA * (LL)Most_WE) {
			Most_VA = VA;
			Most_WE = B[i];
			Answer = i;
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
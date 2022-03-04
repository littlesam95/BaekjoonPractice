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
#define MAX 1001
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	bool S;
	int Y, X;
};

int N, T, M;
vector<INFO> Vec;
int DP[MAX][MAX];
int Small = 5000;
vector<int> Candidate;

void init() {
	Vec.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			DP[i][j] = INF;
		}
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				continue;
			}
			if (Vec[i].S && Vec[j].S) {
				DP[i][j] = min(T, abs(Vec[i].Y - Vec[j].Y) + abs(Vec[i].X - Vec[j].X));
			}
			else {
				DP[i][j] = abs(Vec[i].Y - Vec[j].Y) + abs(Vec[i].X - Vec[j].X);
			}
		}
	}
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

int main() {
	FIRST
	cin >> N >> T;
	init();
	for (int i = 1; i <= N; i++) {
		cin >> Vec[i].S >> Vec[i].Y >> Vec[i].X;
	}
	Settings();
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << DP[A][B] << "\n";
	}

	getchar();
	getchar();
	return 0;
}
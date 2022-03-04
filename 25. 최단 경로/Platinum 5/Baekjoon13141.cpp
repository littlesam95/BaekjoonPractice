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
struct INFO {
	int S, E, L;
};

int N, M;
int Ignited[MAX];
int DP[MAX][MAX];
vector<INFO> Edge;
double answer = INF;

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
		int S, E, L;
		cin >> S >> E >> L;
		Edge.push_back({ S,E,L });
		DP[S][E] = min(DP[S][E], L);
		DP[E][S] = min(DP[E][S], L);
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

void init() {
	for (int i = 1; i <= N; i++) {
		Ignited[i] = 0;
	}
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		init();
		double Tmp = 0;
		for (int j = 1; j <= N; j++) {
			Ignited[j] = DP[i][j];
		}
		for (int j = 0; j < Edge.size(); j++) {
			int S = Edge[j].S;
			int E = Edge[j].E;
			int L = Edge[j].L;
			if ((S != i) && (E != i)) {
				L += min(Ignited[S], Ignited[E]);
			}
			double T1 = max(Ignited[S], Ignited[E]);
			double T2 = (double)(L - T1) / (double)2;
			if (T2 < 0) {
				T2 = 0;
			}
			double T = T1 + T2;
			Tmp = max(Tmp, T);
		}
		answer = min(answer, Tmp);
	}
	cout << fixed;
	cout.precision(1);
	cout << answer << "\n";
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
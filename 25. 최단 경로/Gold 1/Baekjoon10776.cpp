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
#define MAX_N 2001
#define MAX_K 201
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	int Dest, Dist, Cost;
};

struct COMP {
	bool operator()(INFO A, INFO B) {
		return (A.Dist > B.Dist);
	}
};

int K, N, M, A, B;
vector<INFO> Edge[MAX_N];
int Cost[MAX_N][MAX_K];
int answer = INF;

void Input() {
	cin >> K >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			Cost[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int A, B, T, H;
		cin >> A >> B >> T >> H;
		Edge[A].push_back({ B,T,H });
		Edge[B].push_back({ A,T,H });
	}
	cin >> A >> B;
}

void Dijkstra() {
	priority_queue<INFO, vector<INFO>, COMP> PQ;
	Cost[A][K] = 0;
	PQ.push({ A,0,K });

	while (!PQ.empty()) {
		int CurD = PQ.top().Dist;
		int CurC = PQ.top().Cost;
		int CurX = PQ.top().Dest;
		PQ.pop();

		if (Cost[CurX][CurC] < CurD) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextD = Edge[CurX][i].Dist;
			int nextC = Edge[CurX][i].Cost;
			int nextX = Edge[CurX][i].Dest;
			if (CurC <= nextC) {
				continue;
			}
			if (Cost[nextX][CurC - nextC] > CurD + nextD) {
				Cost[nextX][CurC - nextC] = CurD + nextD;
				PQ.push({ nextX, Cost[nextX][CurC - nextC], CurC - nextC });
			}
		}
	};
}

void Find_Answer() {
	for (int i = 1; i <= K; i++) {
		answer = min(answer, Cost[B][i]);
	}
	if (answer == INF) {
		cout << -1 << "\n";
	}
	else {
		cout << answer << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Dijkstra();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
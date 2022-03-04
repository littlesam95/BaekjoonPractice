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
#define MAX_N 101
#define MAX_M 10001
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	int Dest, Time, Cost;
};

struct INFO2 {
	int Time, Cost, Here;
};

struct COMP {
	bool operator()(INFO2 A, INFO2 B) {
		return (A.Time > B.Time);
	}
};

int N, T, M, L;
vector<INFO> Edge[MAX_N];
int Cost[MAX_N][MAX_M];
int answer = 0;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < MAX_M; j++) {
			Cost[i][j] = INF;
		}
	}
	cin >> T >> M;
	cin >> L;
	for (int i = 0; i < L; i++) {
		int A, B, C, D;
		cin >> A >> B >> C >> D;
		Edge[A].push_back({ B,C,D });
		Edge[B].push_back({ A,C,D });
	}
}

void Dijkstra() {
	priority_queue<INFO2, vector<INFO2>, COMP> PQ;
	Cost[1][0] = 0;
	PQ.push({ 0,0,1 });

	while (!PQ.empty()) {
		int CurTime = PQ.top().Time;
		int CurCost = PQ.top().Cost;
		int CurX = PQ.top().Here;
		PQ.pop();

		if (Cost[CurX][CurCost] < CurTime) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = CurCost + Edge[CurX][i].Cost;
			if (nextCost > M) {
				continue;
			}
			int nextTime = Edge[CurX][i].Time;
			int nextX = Edge[CurX][i].Dest;
			if (Cost[nextX][nextCost] > CurTime + nextTime) {
				Cost[nextX][nextCost] = CurTime + nextTime;
				PQ.push({ Cost[nextX][nextCost],nextCost,nextX });
			}
		}
	};
}

int Find_Answer() {
	for (int i = 0; i <= M; i++) {
		if (Cost[N][i] <= T) {
			return i;
		}
	}
	return -1;
}

int main() {
	FASTIO
	Input();
	Dijkstra();
	cout << Find_Answer() << "\n";

	getchar();
	getchar();
	return 0;
}
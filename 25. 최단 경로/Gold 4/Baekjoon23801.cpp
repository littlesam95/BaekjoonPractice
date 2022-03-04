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
#define MAX 100001
#define LL long long
#define INF 1e11

using namespace std;
int N, M, X, Z, P;
vector<pair<int, LL> > Edge[MAX];
LL Cost[2][MAX];
LL answer = INF * 2;

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		Cost[0][i] = INF;
		Cost[1][i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int U, V;
		LL W;
		cin >> U >> V >> W;
		Edge[U].push_back(make_pair(V, W));
		Edge[V].push_back(make_pair(U, W));
	}
	cin >> X >> Z;
}

void Dijkstra(int I, int S) {
	priority_queue<pair<LL, int> > PQ;
	Cost[I][S] = 0;
	PQ.push(make_pair(0, S));

	while (!PQ.empty()) {
		LL CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (Cost[I][CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			LL nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (Cost[I][nextX] > CurCost + nextCost) {
				Cost[I][nextX] = CurCost + nextCost;
				PQ.push(make_pair(-Cost[I][nextX], nextX));
			}
		}
	};
}

void Find_Answer() {
	cin >> P;
	for (int i = 0; i < P; i++) {
		int Y;
		cin >> Y;
		if ((Cost[0][Y] != INF) && (Cost[1][Y] != INF)) {
			answer = min(answer, Cost[0][Y] + Cost[1][Y]);
		}
	}
	if (answer != INF * 2) {
		cout << answer << "\n";
	}
	else {
		cout << -1 << "\n";
	}
}

int main() {
	FASTIO
	Input();
	Dijkstra(0, X);
	Dijkstra(1, Z);
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
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
#define MAX_N 100001
#define MAX_P 101
#define LL long long
#define INF 1e11

using namespace std;
int N, M, X, Z, P;
vector<pair<int, LL> > Edge[MAX_N];
vector<int> CheckPoint;
LL Cost[MAX_P][MAX_N];
LL answer = INF * 5;

void Init() {
	for (int i = 0; i < MAX_P; i++) {
		for (int j = 1; j <= N; j++) {
			Cost[i][j] = INF;
		}
	}
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int U, V;
		LL W;
		cin >> U >> V >> W;
		Edge[U].push_back(make_pair(V, W));
		Edge[V].push_back(make_pair(U, W));
	}
	Init();
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

void Settings() {
	Dijkstra(0, X);
	cin >> P;
	for (int i = 1; i <= P; i++) {
		int Y;
		cin >> Y;
		CheckPoint.push_back(Y);
		Dijkstra(i, Y);
	}
}

void Find_Answer() {
	for (int i = 0; i < CheckPoint.size(); i++) {
		for (int j = 0; j < CheckPoint.size(); j++) {
			for (int k = 0; k < CheckPoint.size(); k++) {
				if ((i == j) || (j == k) || (i == k)) {
					continue;
				}
				if ((Cost[0][CheckPoint[i]] != INF) && (Cost[i + 1][CheckPoint[j]] != INF) && (Cost[j + 1][CheckPoint[k]] != INF) && (Cost[k + 1][Z] != INF)) {
					answer = min(answer, Cost[0][CheckPoint[i]] + Cost[i + 1][CheckPoint[j]] + Cost[j + 1][CheckPoint[k]] + Cost[k + 1][Z]);
				}
			}
		}
	}
	if (answer != INF * 5) {
		cout << answer << "\n";
	}
	else {
		cout << -1 << "\n";
	}
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
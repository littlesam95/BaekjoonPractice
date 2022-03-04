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
#define MAX 21
#define LL long long
#define INF 1e9

using namespace std;
int T, N, M;
vector<pair<int, int> > Edge[MAX];
stack<int> ST;
int Cost[MAX];
int Prev[MAX];
int Case = 1;

void Init() {
	for (int i = 0; i < MAX; i++) {
		Edge[i].clear();
		Cost[i] = INF;
		Prev[i] = -1;
	}
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		Edge[X].push_back(make_pair(Y, Z));
		Edge[Y].push_back(make_pair(X, Z));
	}
}

void Dijkstra() {
	priority_queue<pair<int, int> > PQ;
	Cost[0] = 0;
	PQ.push(make_pair(0, 0));

	while (!PQ.empty()) {
		int CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (Cost[CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (Cost[nextX] > CurCost + nextCost) {
				Cost[nextX] = CurCost + nextCost;
				Prev[nextX] = CurX;
				PQ.push(make_pair(-Cost[nextX], nextX));
			}
		}
	};
}

void Find_Answer() {
	if (Cost[M - 1] == INF) {
		cout << "Case #" << Case++ << ": " << -1 << "\n";
	}
	else {
		for (int i = (M - 1); i > 0;) {
			ST.push(i = Prev[i]);
		}
		cout << "Case #" << Case++ << ":";
		while (!ST.empty()) {
			cout << " " << ST.top();
			ST.pop();
		};
		cout << " " << M - 1 << "\n";
	}
}

int main() {
	FASTIO
	cin >> T;
	while (T--) {
		Init();
		Input();
		Dijkstra();
		Find_Answer();
	};

	getchar();
	getchar();
	return 0;
}
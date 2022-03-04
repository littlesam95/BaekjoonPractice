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
#define MAX 10001
#define LL long long
#define INF 3e9

using namespace std;
int V, E, M, X, S, Y;
vector<pair<int, LL> > Edge[MAX];
priority_queue<pair<LL, int> > PQ;
LL Cost[2][MAX];
bool isHouse[MAX];
LL answer = INF * 2;

void Input() {
	cin >> V >> E;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= V; j++) {
			Cost[i][j] = INF;
		}
	}
	for (int i = 0; i < E; i++) {
		int A, B;
		LL C;
		cin >> A >> B >> C;
		Edge[A].push_back(make_pair(B, C));
		Edge[B].push_back(make_pair(A, C));
	}
}

void Dijkstra(int I) {
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
	cin >> M >> X;
	for (int i = 0; i < M; i++) {
		int A;
		cin >> A;
		isHouse[A] = true;
		Cost[0][A] = 0;
		PQ.push(make_pair(0, A));
	}
	Dijkstra(0);
	cin >> S >> Y;
	for (int i = 0; i < S; i++) {
		int A;
		cin >> A;
		isHouse[A] = true;
		Cost[1][A] = 0;
		PQ.push(make_pair(0, A));
	}
	Dijkstra(1);
}

void Find_Answer() {
	for (int i = 1; i <= V; i++) {
		if ((!isHouse[i]) && (Cost[0][i] <= X) && (Cost[1][i] <= Y)) {
			answer = min(answer, Cost[0][i] + Cost[1][i]);
		}
	}
	if (answer == INF * 2) {
		cout << -1 << "\n";
	}
	else {
		cout << answer << "\n";
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
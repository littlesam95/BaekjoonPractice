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
#define MAX 1001
#define LL long long
#define INF 1e12
#define TRANS 1e9

using namespace std;
int N, M;
LL E[MAX][MAX];
int C[MAX];
LL Cost[MAX];

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		Cost[i] = INF;
	}
	for (int i = 0; i < N; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> E[i][j];
		}
	}
}

void Dijkstra() {
	priority_queue<pair<LL, LL> > PQ;
	Cost[0] = 0;
	PQ.push(make_pair(0, 0));

	while (!PQ.empty()) {
		LL CurCost = -PQ.top().first;
		LL CurX = PQ.top().second;
		PQ.pop();

		if (Cost[CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < N; i++) {
			if (E[CurX][i] == 0) {
				continue;
			}
			int nextCost = E[CurX][i];
			int nextX = i;
			if (C[CurX] != C[nextX]) {
				if (Cost[nextX] > CurCost + nextCost + TRANS) {
					Cost[nextX] = CurCost + nextCost + TRANS;
					PQ.push(make_pair(-Cost[nextX], nextX));
				}
			}
			else {
				if (Cost[nextX] > CurCost + nextCost) {
					Cost[nextX] = CurCost + nextCost;
					PQ.push(make_pair(-Cost[nextX], nextX));
				}
			}
		}
	};
}

void Find_Answer() {
	cout << Cost[M] / (LL)TRANS << " " << Cost[M] % (LL)TRANS << "\n";
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
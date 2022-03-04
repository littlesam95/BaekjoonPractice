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
#define INF 1e11

using namespace std;
int V, E, S;
int Yogurt[11];
vector<pair<int, LL> > Edge[MAX];
LL Cost[11][MAX];
LL YCost[11];

void Input() {
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < 11; j++) {
			Cost[j][i] = INF;
		}
	}
	for (int i = 0; i < E; i++) {
		int U, V;
		LL W;
		cin >> U >> V >> W;
		Edge[U].push_back(make_pair(V, W));
		Edge[V].push_back(make_pair(U, W));
	}
	for (int i = 1; i <= 10; i++) {
		cin >> Yogurt[i];
		YCost[i] = INF;
	}
	cin >> S;
}

void Dijkstra(int I, int X) {
	priority_queue<pair<int, int> > PQ;
	Cost[I][X] = 0;
	PQ.push(make_pair(0, X));

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
	int IDX = 1;
	int nextIDX = 2;
	YCost[1] = 0;
	while (1) {
		Dijkstra(nextIDX, Yogurt[IDX]);
		if (Cost[nextIDX][Yogurt[nextIDX]] == INF) {
			nextIDX++;
			if (nextIDX == 11) {
				break;
			}
		}
		else {
			YCost[nextIDX] = Cost[nextIDX][Yogurt[nextIDX]] + YCost[IDX];
			IDX = nextIDX;
			if (IDX == 11) {
				break;
			}
			nextIDX = IDX + 1;
			if (nextIDX == 11) {
				break;
			}
		}
	};
}

int Find_Answer() {
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= 10; j++) {
			if (Yogurt[j] == i) {
				if ((Cost[0][i] == INF) || (YCost[j] == INF)) {
					continue;
				}
				if (Cost[0][i] <= YCost[j]) {
					return i;
				}
			}
		}
	}
	return -1;
}

int main() {
	FASTIO
	Input();
	Dijkstra(0, S);
	Settings();
	cout << Find_Answer() << "\n";

	getchar();
	getchar();
	return 0;
}
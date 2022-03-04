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

using namespace std;
int N, V, E;
vector<pair<int, LL> > Edge[MAX];
int KIST, CRFOOD;
int House[MAX];
LL Cost[MAX];
LL answer = 0;

void Init() {
	for (int i = 1; i <= V; i++) {
		Cost[i] = INF;
	}
}

void Input() {
	cin >> N >> V >> E;
	cin >> KIST >> CRFOOD;
	for (int i = 1; i <= N; i++) {
		cin >> House[i];
	}
	for (int i = 0; i < E; i++) {
		int A, B;
		LL L;
		cin >> A >> B >> L;
		Edge[A].push_back(make_pair(B, L));
		Edge[B].push_back(make_pair(A, L));
	}
}

void Dijkstra() {
	for (int i = 1; i <= N; i++) {
		Init();
		priority_queue<pair<LL, int> > PQ;
		Cost[House[i]] = 0;
		PQ.push(make_pair(0, House[i]));

		while (!PQ.empty()) {
			LL CurCost = -PQ.top().first;
			int CurX = PQ.top().second;
			PQ.pop();

			if (Cost[CurX] < CurCost) {
				continue;
			}

			for (int i = 0; i < Edge[CurX].size(); i++) {
				LL nextCost = Edge[CurX][i].second;
				int nextX = Edge[CurX][i].first;
				if (Cost[nextX] > CurCost + nextCost) {
					Cost[nextX] = CurCost + nextCost;
					PQ.push(make_pair(-Cost[nextX], nextX));
				}
			}
		};
		LL KIST_Cost = Cost[KIST];
		LL CRFOOD_Cost = Cost[CRFOOD];
		if (KIST_Cost == INF) {
			KIST_Cost = -1;
		}
		if (CRFOOD_Cost == INF) {
			CRFOOD_Cost = -1;
		}
		answer += (KIST_Cost + CRFOOD_Cost);
	}
}

void Find_Answer() {
	cout << answer << "\n";
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
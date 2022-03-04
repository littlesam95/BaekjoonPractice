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
#define MAX 20001
#define LL long long
#define INF 1e11

using namespace std;
struct INFO {
	LL Dest, Cost, W;
};

int N, M;
vector<INFO> Edge[MAX];
LL Cost[MAX];

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		Cost[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int A, B, T, W;
		cin >> A >> B >> T >> W;
		Edge[A].push_back({ B,T,W });
	}
}

void Dijkstra() {
	priority_queue<pair<LL, LL> > PQ;
	Cost[1] = 0;
	PQ.push(make_pair(0, 1));

	while (!PQ.empty()) {
		LL CurCost = -PQ.top().first;
		LL CurX = PQ.top().second;
		PQ.pop();

		if (Cost[CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			LL nextCost = Edge[CurX][i].Cost;
			LL nextX = Edge[CurX][i].Dest;
			LL nextW = Edge[CurX][i].W;
			if (CurCost % nextW == 0) {
				if (Cost[nextX] > CurCost + nextCost) {
					Cost[nextX] = CurCost + nextCost;
					PQ.push(make_pair(-Cost[nextX], nextX));
				}
			}
			else {
				LL R = 0;
				for (LL j = 0; j < 10; j++) {
					if ((CurCost + j) % nextW == 0) {
						R = CurCost + j;
						break;
					}
				}
				if (Cost[nextX] > nextCost + R) {
					Cost[nextX] = nextCost + R;
					PQ.push(make_pair(-Cost[nextX], nextX));
				}
			}
		}
	};
}

void Find_Answer() {
	cout << Cost[N] << "\n";
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
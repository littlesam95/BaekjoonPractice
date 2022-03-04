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
#define INF 1e15

using namespace std;
LL N, M, A, B, C;
vector<pair<LL, LL> > Edge[MAX];
LL Cost[MAX];
LL answer = INF;

void Init() {
	for (LL i = 1; i <= N; i++) {
		Cost[i] = INF;
	}
}

void Input() {
	cin >> N >> M >> A >> B >> C;
	for (LL i = 0; i < M; i++) {
		LL U, V, W;
		cin >> U >> V >> W;
		Edge[U].push_back(make_pair(V, W));
		Edge[V].push_back(make_pair(U, W));
	}
}

void Dijkstra(LL X) {
	priority_queue<pair<LL, LL> > PQ;
	Cost[A] = 0;
	PQ.push(make_pair(0, A));

	while (!PQ.empty()) {
		LL CurC = -PQ.top().first;
		LL CurX = PQ.top().second;
		PQ.pop();

		if (Cost[CurX] < CurC) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			LL nextC = Edge[CurX][i].second;
			if (nextC > X) {
				continue;
			}
			LL nextX = Edge[CurX][i].first;
			if ((CurC + nextC <= C) && (Cost[nextX] > CurC + nextC)) {
				Cost[nextX] = CurC + nextC;
				PQ.push(make_pair(-Cost[nextX], nextX));
			}
		}
	};
}

void Find_Answer() {
	LL LO = 1;
	LL HI = C;

	while (LO <= HI) {
		LL MID = (LO + HI) / 2;
		Init();
		Dijkstra(MID);
		if (Cost[B] != INF) {
			answer = MID;
			HI = MID - 1;
		}
		else {
			LO = MID + 1;
		}
	};
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
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
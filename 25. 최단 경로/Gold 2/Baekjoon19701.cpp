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
struct INFO {
	LL Dest, Cost, Eat;
};

struct INFO2 {
	LL Cost, Eat, Here;
};

struct COMP {
	bool operator()(INFO2 A, INFO2 B) {
		return (A.Cost > B.Cost);
	}
};

LL V, E;
vector<INFO> Edge[MAX];
LL Prev[MAX];
LL Cost[MAX][2];

void Input() {
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		Cost[i][0] = INF;
		Cost[i][1] = INF;
	}
	for (int i = 0; i < E; i++) {
		int X, Y, T, K;
		cin >> X >> Y >> T >> K;
		Edge[X].push_back({ Y,T,K });
		Edge[Y].push_back({ X,T,K });
	}
}

void Dijkstra() {
	priority_queue<INFO2, vector<INFO2>, COMP> PQ;
	Cost[1][1] = 0;
	PQ.push({ 0,1,1 });

	while (!PQ.empty()) {
		LL CurCost = PQ.top().Cost;
		LL CurEat = PQ.top().Eat;
		LL CurX = PQ.top().Here;
		PQ.pop();

		if (Cost[CurX][CurEat] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			LL nextCost = Edge[CurX][i].Cost;
			LL nextX = Edge[CurX][i].Dest;
			LL nextEat = Edge[CurX][i].Eat;

			// µ·±î½º¸¦ ¸Ô´Â´Ù
			if (CurEat == 1) {
				if (Cost[nextX][0] > CurCost + nextCost - nextEat) {
					Cost[nextX][0] = CurCost + nextCost - nextEat;
					PQ.push({ Cost[nextX][0],0,nextX });
				}
			}

			// µ·±î½º¸¦ ¾È ¸Ô´Â´Ù
			if (Cost[nextX][CurEat] > CurCost + nextCost) {
				Cost[nextX][CurEat] = CurCost + nextCost;
				PQ.push({ Cost[nextX][CurEat],CurEat,nextX });
			}
		}
	};
}

LL Big_Eat(LL S, LL E) {
	for (int i = 0; i < Edge[S].size(); i++) {
		if (E == Edge[S][i].Dest) {
			return Edge[S][i].Eat;
		}
	}
	return -1;
}

void Find_Answer() {
	for (LL i = 2; i <= V; i++) {
		cout << min(Cost[i][0], Cost[i][1]) << "\n";
	}
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
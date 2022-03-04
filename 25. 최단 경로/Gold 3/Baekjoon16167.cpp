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
#define MAX 101
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	int Cost, X, Vertex;
};

struct COMP {
	bool operator()(INFO A, INFO B) {
		return (A.Cost > B.Cost);
	}
};

int N, R;
vector<pair<int, int> > Edge[MAX];
int Prev[MAX];
int Cost[MAX];

void Input() {
	cin >> N >> R;
	for (int i = 1; i <= N; i++) {
		Cost[i] = INF;
		Prev[i] = INF;
	}
	for (int i = 0; i < R; i++) {
		int A, B, C, D, E;
		cin >> A >> B >> C >> D >> E;
		if (E <= 10) {
			Edge[A].push_back(make_pair(B, C));
		}
		else {
			int Fee = C + (E - 10) * D;
			Edge[A].push_back(make_pair(B, Fee));
		}
	}
}

void Dijkstra() {
	priority_queue<INFO ,vector<INFO>, COMP> PQ;
	Cost[1] = 0;
	PQ.push({ 0,1,1 });

	while (!PQ.empty()) {
		int CurCost = PQ.top().Cost;
		int CurX = PQ.top().X;
		int CurVertex = PQ.top().Vertex;
		PQ.pop();

		if (Cost[CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (Cost[nextX] > CurCost + nextCost) {
				Cost[nextX] = CurCost + nextCost;
				Prev[nextX] = CurVertex + 1;
				PQ.push({ Cost[nextX],nextX,CurVertex + 1 });
			}
			else if (Cost[nextX] == CurCost + nextCost) {
				Prev[nextX] = min(Prev[nextX], CurVertex + 1);
			}
		}
	};
}

void Find_Answer() {
	if (Cost[N] == INF) {
		cout << "It is not a great way.\n";
	}
	else {
		cout << Cost[N] << " " << Prev[N] << "\n";
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
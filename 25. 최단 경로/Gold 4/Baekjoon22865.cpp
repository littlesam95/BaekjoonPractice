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
#define INF 1e9

using namespace std;
int N, M;
int House[3];
vector<pair<int, int> > Edge[MAX];
int Cost[3][MAX];
int Dist = -1;
int answer = 0;

void Input() {
	cin >> N;
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j <= N; j++) {
			Cost[i][j] = INF;
		}
	}
	for (int i = 0; i < 3; i++) {
		cin >> House[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int D, E, L;
		cin >> D >> E >> L;
		Edge[D].push_back(make_pair(E, L));
		Edge[E].push_back(make_pair(D, L));
	}
}

void Dijkstra(int X, int S) {
	priority_queue<pair<int, int> > PQ;
	Cost[X][S] = 0;
	PQ.push(make_pair(0, S));

	while (!PQ.empty()) {
		int CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (Cost[X][CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (Cost[X][nextX] > CurCost + nextCost) {
				Cost[X][nextX] = CurCost + nextCost;
				PQ.push(make_pair(-Cost[X][nextX], nextX));
			}
		}
	};
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		if ((House[0] == i) || (House[1] == i) || (House[2] == i)) {
			continue;
		}
		int Len = min(Cost[0][i], min(Cost[1][i], Cost[2][i]));
		if (Dist < Len) {
			Dist = Len;
			answer = i;
		}
	}
	cout << answer << "\n";
}

int main() {
	FASTIO
	Input();
	for (int i = 0; i < 3; i++) {
		Dijkstra(i, House[i]);
	}
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
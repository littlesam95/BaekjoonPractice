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
#define MAX 11
#define LL long long
#define INF 1e9

using namespace std;
int N, M, A, B, C;
vector<pair<int, int> > Edge[MAX];
int Cost[MAX];
bool visited[MAX];
int answer = INF;

void Input() {
	cin >> N >> M >> A >> B >> C;
	for (int i = 1; i <= N; i++) {
		Cost[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int U, V, E;
		cin >> U >> V >> E;
		Edge[U].push_back(make_pair(V, E));
		Edge[V].push_back(make_pair(U, E));
	}
}

void Settings() {
	priority_queue<pair<int, int> > PQ;
	PQ.push(make_pair(0, A));
	Cost[A] = 0;

	while (!PQ.empty()) {
		int CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if ((Cost[nextX] > C) && (Cost[nextX] > CurCost + nextCost)) {
				Cost[nextX] = CurCost + nextCost;
				PQ.push(make_pair(-Cost[nextX], nextX));
			}
		}
	};
}

void DFS(int Cur, int mCost, int sCost) {
	if (sCost > C) {
		return;
	}
	if (Cur == B) {
		answer = min(answer, mCost);
		return;
	}
	for (int i = 0; i < Edge[Cur].size(); i++) {
		int nextX = Edge[Cur][i].first;
		if (!visited[nextX]) {
			int nextmCost = max(mCost, Edge[Cur][i].second);
			int nextsCost = sCost + Edge[Cur][i].second;
			visited[nextX] = true;
			DFS(nextX, nextmCost, nextsCost);
			visited[nextX] = false;
		}
	}
}

void Find_Answer() {
	visited[A] = true;
	DFS(A, 0, 0);
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
	Settings();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
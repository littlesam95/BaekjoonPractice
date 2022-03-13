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
#define MAX 2001
#define LL long long
#define INF 1e18

using namespace std;
int T, N, M;
vector<pair<int, LL> > Edge[MAX];
int Parent[MAX];
bool visited[MAX];
LL answer;
LL Year_Cost;

void Init1() {
	for (int i = 0; i < N; i++) {
		Edge[i].clear();
	}
	answer = 0;
}

void Init2() {
	for (int i = 0; i < N; i++) {
		Parent[i] = i;
		visited[i] = false;
	}
	Year_Cost = 0;
}

int Find(int X) {
	if (Parent[X] == X) {
		return X;
	}
	return Parent[X] = Find(Parent[X]);
}

void Union(int X, int Y) {
	int PX = Find(X);
	int PY = Find(Y);
	if (PX < PY) {
		Parent[PY] = PX;
	}
	else {
		Parent[PX] = PY;
	}
}

bool Comp(INFO A, INFO B) {
	return (A.Cost < B.Cost);
}

void Settings() {
	priority_queue<pair<LL, int> > PQ;
	for (int i = 0; i < Edge[0].size(); i++) {
		int Next = Edge[0][i].first;
		LL Dist = Edge[0][i].second;
		PQ.push(make_pair(-Dist, Next));
	}

	visited[0] = true;
	while (!PQ.empty()) {
		LL CurC = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (!visited[CurX]) {
			visited[CurX] = true;
			Year_Cost += CurC;
			for (int i = 0; i < Edge[CurX].size(); i++) {
				LL nextC = Edge[CurX][i].second;
				int nextX = Edge[CurX][i].first;
				if (!visited[nextX]) {
					PQ.push(make_pair(-nextC, nextX));
				}
			}
		}
	};
	answer ^= Year_Cost;
}

void Find_Answer() {
	cout << answer << "\n";
}

void Input() {
	cin >> T;
	while (T--) {
		cin >> N >> M;
		Init1();
		for (int i = 1; i <= (N - 1); i++) {
			int U;
			LL C;
			cin >> U >> C;
			Edge[i].push_back(make_pair(U, C));
			Edge[U].push_back(make_pair(i, C));
		}
		for (int i = 0; i < M; i++) {
			Init2();
			int U, V;
			LL W;
			cin >> U >> V >> W;
			Edge[U].push_back(make_pair(V, W));
			Edge[V].push_back(make_pair(U, W));
			Settings();
		}
		Find_Answer();
	};
}

int main() {
	FASTIO
	Input();

	getchar();
	getchar();
	return 0;
}
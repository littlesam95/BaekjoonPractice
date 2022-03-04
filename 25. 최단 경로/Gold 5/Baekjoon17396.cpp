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
#define INF 1e12

using namespace std;
int N, M;
vector<pair<int, LL> > Edge[MAX];
bool Ward[MAX];
LL Cost[MAX];

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		Cost[i] = INF;
		int A;
		cin >> A;
		Ward[i] = (A == 1) ? true : false;
	}
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		if (Ward[A] || Ward[B]) {
			if ((A != N - 1) && (B != N - 1)) {
				continue;
			}
		}
		Edge[A].push_back(make_pair(B, C));
		Edge[B].push_back(make_pair(A, C));
	}
}

void Settings() {
	priority_queue<pair<LL, int> > PQ;
	PQ.push(make_pair(0, 0));
	Cost[0] = 0;

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
}

void Find_Answer() {
	if (Cost[N - 1] == INF) {
		cout << -1 << "\n";
	}
	else {
		cout << Cost[N - 1] << "\n";
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
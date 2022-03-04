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
int N, M, K;
vector<pair<int, LL> > Edge[MAX];
priority_queue<pair<LL, int> > PQ;
LL Cost[MAX];
vector<int> Point;
LL Len = 0;
int answer;

void Input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		Cost[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int U, V;
		LL C;
		cin >> U >> V >> C;
		Edge[V].push_back(make_pair(U, C));
	}
	for (int i = 0; i < K; i++) {
		int City;
		cin >> City;
		Point.push_back(City);
	}
}

void Dijkstra() {
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

void Settings() {
	for (int i = 0; i < Point.size(); i++) {
		Cost[Point[i]] = 0;
		PQ.push(make_pair(0, Point[i]));
	}
	Dijkstra();
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		if ((Cost[i] > 0) && (Cost[i] != INF)) {
			if (Len < Cost[i]) {
				Len = Cost[i];
				answer = i;
			}
		}
	}
	cout << answer << "\n" << Len << "\n";
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
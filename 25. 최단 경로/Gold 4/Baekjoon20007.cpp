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
#define INF 1e9

using namespace std;
int N, M, X, Y;
vector<pair<int, int> > Edge[MAX];
int Cost[MAX];
vector<int> Cost_Vec;
bool Flag = true;
int IDX = 0;
int answer = 0;

void Input() {
	cin >> N >> M >> X >> Y;
	for (int i = 0; i < N; i++) {
		Cost[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		Edge[A].push_back(make_pair(B, C));
		Edge[B].push_back(make_pair(A, C));
	}
}

void Dijkstra() {
	priority_queue<pair<int, int> > PQ;
	Cost[Y] = 0;
	PQ.push(make_pair(0, Y));

	while (!PQ.empty()) {
		int CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (Cost[CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			int nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (Cost[nextX] > CurCost + nextCost) {
				Cost[nextX] = CurCost + nextCost;
				PQ.push(make_pair(-Cost[nextX], nextX));
			}
		}
	};
}

void Find_Answer() {
	for (int i = 0; i < N; i++) {
		if ((Cost[i] * 2 > X) || (Cost[i] == INF)) {
			Flag = false;
			break;
		}
		if (Cost[i] > 0) {
			Cost_Vec.push_back(Cost[i] * 2);
		}
	}
	if (Flag) {
		sort(Cost_Vec.begin(), Cost_Vec.end());
		while (1) {
			answer++;
			int CurX = X;
			while (1) {
				if (CurX < Cost_Vec[IDX]) {
					break;
				}
				CurX -= Cost_Vec[IDX++];
				if (IDX == Cost_Vec.size()) {
					break;
				}
			}
			if (IDX == Cost_Vec.size()) {
				break;
			}
		};
		cout << answer << "\n";
	}
	else {
		cout << -1 << "\n";
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
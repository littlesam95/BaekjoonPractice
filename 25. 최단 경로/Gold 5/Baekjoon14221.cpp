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
#define MAX 5001
#define LL long long
#define INF 1e9

using namespace std;
int N, M, P, Q;
vector<pair<int, int> > Edge[MAX];
vector<int> Conv;
bool House[MAX];
int Cost[MAX];
int SmallCost = INF;
int answer;

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		Cost[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		Edge[A].push_back(make_pair(B, C));
		Edge[B].push_back(make_pair(A, C));
	}
	cin >> P >> Q;
	for (int i = 0; i < P; i++) {
		int X;
		cin >> X;
		House[X] = true;
	}
	for (int i = 0; i < Q; i++) {
		int X;
		cin >> X;
		Conv.push_back(X);
	}
}

void Settings() {
	for (int i = 0; i < Conv.size(); i++) {
		priority_queue<pair<int, int> > PQ;
		PQ.push(make_pair(0, Conv[i]));
		Cost[Conv[i]] = 0;

		while (!PQ.empty()) {
			int CurCost = -PQ.top().first;
			int CurX = PQ.top().second;
			PQ.pop();

			for (int j = 0; j < Edge[CurX].size(); j++) {
				int nextCost = Edge[CurX][j].second;
				int nextX = Edge[CurX][j].first;
				if (Cost[nextX] > CurCost + nextCost) {
					Cost[nextX] = CurCost + nextCost;
					PQ.push(make_pair(-Cost[nextX], nextX));
				}
			}
		};
	}
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		if (House[i]) {
			if (SmallCost > Cost[i]) {
				SmallCost = Cost[i];
				answer = i;
			}
		}
	}
	cout << answer << "\n";
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
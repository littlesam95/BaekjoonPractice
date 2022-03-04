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
#define MAX 200001
#define LL long long
#define INF 1e9

using namespace std;
int N, M, K;
vector<pair<int, int> > Edge[MAX];
priority_queue<pair<int, int> > PQ;
int Cost[2][MAX];
vector<int> Heeler;
vector<int> answer;

void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= N; j++) {
			Cost[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int A, B, T;
		cin >> A >> B >> T;
		Edge[A].push_back(make_pair(B, T));
		Edge[B].push_back(make_pair(A, T));
	}
	for (int i = 0; i < K; i++) {
		int P;
		cin >> P;
		Heeler.push_back(P);
	}
}

void Dijkstra(int I) {
	while (!PQ.empty()) {
		LL CurCost = -PQ.top().first;
		int CurX = PQ.top().second;
		PQ.pop();

		if (Cost[I][CurX] < CurCost) {
			continue;
		}

		for (int i = 0; i < Edge[CurX].size(); i++) {
			LL nextCost = Edge[CurX][i].second;
			int nextX = Edge[CurX][i].first;
			if (Cost[I][nextX] > CurCost + nextCost) {
				Cost[I][nextX] = CurCost + nextCost;
				PQ.push(make_pair(-Cost[I][nextX], nextX));
			}
		}
	};
}

void Settings() {
	Cost[0][1] = 0;
	PQ.push(make_pair(0, 1));
	Dijkstra(0);
	for (int i = 0; i < Heeler.size(); i++) {
		Cost[1][Heeler[i]] = 0;
		PQ.push(make_pair(0, Heeler[i]));
	}
	Dijkstra(1);
}

void Find_Answer() {
	for (int i = 2; i <= N; i++) {
		if (Cost[0][i] < Cost[1][i]) {
			answer.push_back(i);
		}
	}
	if (answer.size() > 0) {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
	}
	else {
		cout << 0;
	}
	cout << "\n";
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
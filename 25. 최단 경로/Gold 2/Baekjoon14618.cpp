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
int N, M, J, K, A, B;
vector<pair<int, int> > Edge[MAX];
priority_queue<pair<int, int> > PQ;
int Cost[3][MAX];
int isHouse[MAX];

void Input() {
	cin >> N >> M;
	for (int i = 1; i < 3; i++) {
		for (int j = 1; j <= N; j++) {
			Cost[i][j] = INF;
		}
	}
	cin >> J;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> A;
		isHouse[A] = 1;
	}
	for (int i = 0; i < K; i++) {
		cin >> B;
		isHouse[B] = 2;
	}
	for (int i = 0; i < M; i++) {
		int X, Y, Z;
		cin >> X >> Y >> Z;
		Edge[X].push_back(make_pair(Y, Z));
		Edge[Y].push_back(make_pair(X, Z));
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
	for (int i = 1; i <= N; i++) {
		if (isHouse[i] == 1) {
			Cost[1][i] = 0;
			PQ.push(make_pair(0, i));
		}
	}
	Dijkstra(1);
	for (int i = 1; i <= N; i++) {
		if (isHouse[i] == 2) {
			Cost[2][i] = 0;
			PQ.push(make_pair(0, i));
		}
	}
	Dijkstra(2);
}

void Find_Answer() {
	if ((Cost[1][J] != INF) && (Cost[2][J] != INF)) {
		if (Cost[1][J] <= Cost[2][J]) {
			cout << "A" << "\n";
			cout << Cost[1][J] << "\n";
		}
		else {
			cout << "B" << "\n";
			cout << Cost[2][J] << "\n";
		}
	}
	else if ((Cost[1][J] == INF) && (Cost[2][J] != INF)) {
		cout << "B" << "\n";
		cout << Cost[2][J] << "\n";
	}
	else if ((Cost[1][J] != INF) && (Cost[2][J] == INF)) {
		cout << "A" << "\n";
		cout << Cost[1][J] << "\n";
	}
	else if ((Cost[1][J] == INF) && (Cost[2][J] == INF)) {
		cout << -1 << "\n";
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
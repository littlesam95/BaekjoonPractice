#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 900
#define INF 1e9+7

using namespace std;
int N, M;
int Source = 0;
int Sink = 1;
int PREV[MAX];
int DIST[MAX];
bool inQueue[MAX];
int CAPACITY[MAX][MAX];
int FLOW[MAX][MAX];
int COST[MAX][MAX];
vector<int> Vertex[MAX];
int Total_Flow = 0;
int Total_Cost = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 2; i < N + 2; i++) {
		int S;
		cin >> S;
		Vertex[0].push_back(i);
		Vertex[i].push_back(0);
		CAPACITY[0][i] = 1;
		while (S--) {
			int A, B;
			cin >> A >> B;
			Vertex[i].push_back(N + 1 + A);
			Vertex[N + 1 + A].push_back(i);
			CAPACITY[i][N + 1 + A] = 1;
			COST[i][N + 1 + A] = B;
			COST[N + 1 + A][i] = -B;
		};
	}
	for (int i = N + 2; i < N + 2 + M; i++) {
		Vertex[i].push_back(1);
		Vertex[1].push_back(i);
		CAPACITY[i][1] = 1;
	}

	while (1) {
		memset(PREV, -1, sizeof PREV);
		memset(DIST, INF, sizeof DIST);
		memset(inQueue, false, sizeof inQueue);
		queue<int> Q;
		Q.push(Source);
		inQueue[Source] = true;
		DIST[Source] = 0;

		while (!Q.empty()) {
			int Cur = Q.front();
			Q.pop();
			inQueue[Cur] = false;

			for (int i = 0; i < Vertex[Cur].size(); i++) {
				int Next = Vertex[Cur][i];
				if ((CAPACITY[Cur][Next] > FLOW[Cur][Next]) && (DIST[Next] > DIST[Cur] + COST[Cur][Next])) {
					DIST[Next] = DIST[Cur] + COST[Cur][Next];
					PREV[Next] = Cur;
					if (!inQueue[Next]) {
						Q.push(Next);
						inQueue[Next] = true;
					}
				}
			}
		};

		if (PREV[Sink] == -1) {
			break;
		}
		int flow = INF;
		for (int i = Sink; i != Source; i = PREV[i]) {
			flow = min(flow, CAPACITY[PREV[i]][i] - FLOW[PREV[i]][i]);
		}
		for (int i = Sink; i != Source; i = PREV[i]) {
			Total_Cost += (flow*COST[PREV[i]][i]);
			FLOW[PREV[i]][i] += flow;
			FLOW[i][PREV[i]] -= flow;
		}
		Total_Flow += flow;
	};
	cout << Total_Flow << "\n";
	cout << Total_Cost << "\n";

	getchar();
	getchar();
	return 0;
}
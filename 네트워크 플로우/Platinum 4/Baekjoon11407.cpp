#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 405
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
		int A;
		cin >> A;
		Vertex[i].push_back(1);
		Vertex[1].push_back(i);
		CAPACITY[i][1] = A;
	}
	for (int i = N + 2; i < N + M + 2; i++) {
		int B;
		cin >> B;
		Vertex[0].push_back(i);
		Vertex[i].push_back(0);
		CAPACITY[0][i] = B;
	}
	for (int i = N + 2; i < N + M + 2; i++) {
		for (int j = 2; j < N + 2; j++) {
			int C;
			cin >> C;
			Vertex[i].push_back(j);
			Vertex[j].push_back(i);
			CAPACITY[i][j] = C;
		}
	}
	for (int i = N + 2; i < N + M + 2; i++) {
		for (int j = 2; j < N + 2; j++) {
			int D;
			cin >> D;
			COST[i][j] = D;
			COST[j][i] = -D;
		}
	}

	while (1) {
		memset(PREV, -1, sizeof PREV);
		memset(DIST, INF, sizeof DIST);
		memset(inQueue, false, sizeof inQueue);
		queue<int> Q;
		DIST[Source] = 0;
		inQueue[Source] = true;
		Q.push(Source);

		while (!Q.empty()) {
			int Here = Q.front();
			Q.pop();
			inQueue[Here] = false;

			for (int i = 0; i < Vertex[Here].size(); i++) {
				int Next = Vertex[Here][i];
				if ((CAPACITY[Here][Next] - FLOW[Here][Next] > 0) && (DIST[Next] > DIST[Here] + COST[Here][Next])) {
					DIST[Next] = DIST[Here] + COST[Here][Next];
					PREV[Next] = Here;
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
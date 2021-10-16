#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 2005
#define INF 2e9

using namespace std;
int N, M, K;
int Source = 0;
int Sink = 1;
int PREV[MAX];
int CAPACITY[MAX][MAX];
int FLOW[MAX][MAX];
vector<int> Vertex[MAX];
int Total_Flow = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	// K 정점(2)를 추가하고, Source(0)과 K(2)를 연결하는 간선을 추가하여 용량을 K로 설정한다.
	Vertex[0].push_back(2);
	Vertex[2].push_back(0);
	CAPACITY[0][2] = K;
	for (int i = 3; i <= N + 2; i++) {// 직원의 번호를 3 ~ N+2번으로 설정한다.
		int P;
		cin >> P;
		// Source와 직원, 직원과 K를 연결하는 간선을 추가하고 용량은 1로 설정한다.
		Vertex[0].push_back(i);
		Vertex[i].push_back(0);
		Vertex[2].push_back(i);
		Vertex[i].push_back(2);
		CAPACITY[0][i] = CAPACITY[2][i] = 1;
		// i번째 직원이 할 수 있는 P개의 일의 정보를 입력한다.
		while (P--) { // 일의 번호는 N+3 ~ N+M+2번으로 설정한다.
			int X;
			cin >> X;
			// i번째 직원과 일을 연결하는 간선을 추가하고 용량은 1로 설정한다.
			Vertex[i].push_back(N + X + 2);
			Vertex[N + X + 2].push_back(i);
			CAPACITY[i][N + X + 2] = 1;
		};
	}
	// M개의 일 각각을 Sink(1)와 연결하는 간선을 추가하고 용량을 1로 설정한다.
	for (int i = N + 3; i < N + 3 + M; i++) {
		Vertex[i].push_back(1);
		Vertex[1].push_back(i);
		CAPACITY[i][1] = 1;
	}
	// BFS를 통하여 정점끼리 연결된 간선의 유량을 확인하면서 탐색한다.
	while (1) {
		memset(PREV, -1, sizeof PREV);
		queue<int> Q;
		Q.push(Source);

		while (!Q.empty() && (PREV[Sink] == -1)) {
			int nowCity = Q.front();
			Q.pop();

			for (int i = 0; i < Vertex[nowCity].size(); i++) {
				int nextCity = Vertex[nowCity][i];
				if (PREV[nextCity] != -1) {
					continue;
				}
				if (CAPACITY[nowCity][nextCity] > FLOW[nowCity][nextCity]) {
					Q.push(nextCity);
					PREV[nextCity] = nowCity;
					if (nextCity == Sink) {
						break;
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
			FLOW[PREV[i]][i] += flow;
			FLOW[i][PREV[i]] -= flow;
		}
		Total_Flow += flow;
	};

	cout << Total_Flow << "\n";

	getchar();
	getchar();
	return 0;
}
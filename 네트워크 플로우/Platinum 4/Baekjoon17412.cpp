#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 401
#define INF 2e9

using namespace std;
int N, P;
int Source = 1;
int Sink = 2;
int PREV[MAX];
int CAPACITY[MAX][MAX]; // i에서 j까지 흐를 때 필요한 간선 용량
int FLOW[MAX][MAX]; // i에서 j까지 흐르는 유량
vector<int> Vertex[MAX]; // 역방향 간선
int Total_Flow = 0;

// 에드먼드-카프 알고리즘(Edmonds-Karp Algorithm)
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> P;
	while (P--) {
		int From, To;
		cin >> From >> To;
		CAPACITY[From][To] = 1;
		Vertex[From].push_back(To);
		Vertex[To].push_back(From);
	};
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
		int flow = 1;
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
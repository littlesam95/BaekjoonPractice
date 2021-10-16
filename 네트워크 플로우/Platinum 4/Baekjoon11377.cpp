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
	// K ����(2)�� �߰��ϰ�, Source(0)�� K(2)�� �����ϴ� ������ �߰��Ͽ� �뷮�� K�� �����Ѵ�.
	Vertex[0].push_back(2);
	Vertex[2].push_back(0);
	CAPACITY[0][2] = K;
	for (int i = 3; i <= N + 2; i++) {// ������ ��ȣ�� 3 ~ N+2������ �����Ѵ�.
		int P;
		cin >> P;
		// Source�� ����, ������ K�� �����ϴ� ������ �߰��ϰ� �뷮�� 1�� �����Ѵ�.
		Vertex[0].push_back(i);
		Vertex[i].push_back(0);
		Vertex[2].push_back(i);
		Vertex[i].push_back(2);
		CAPACITY[0][i] = CAPACITY[2][i] = 1;
		// i��° ������ �� �� �ִ� P���� ���� ������ �Է��Ѵ�.
		while (P--) { // ���� ��ȣ�� N+3 ~ N+M+2������ �����Ѵ�.
			int X;
			cin >> X;
			// i��° ������ ���� �����ϴ� ������ �߰��ϰ� �뷮�� 1�� �����Ѵ�.
			Vertex[i].push_back(N + X + 2);
			Vertex[N + X + 2].push_back(i);
			CAPACITY[i][N + X + 2] = 1;
		};
	}
	// M���� �� ������ Sink(1)�� �����ϴ� ������ �߰��ϰ� �뷮�� 1�� �����Ѵ�.
	for (int i = N + 3; i < N + 3 + M; i++) {
		Vertex[i].push_back(1);
		Vertex[1].push_back(i);
		CAPACITY[i][1] = 1;
	}
	// BFS�� ���Ͽ� �������� ����� ������ ������ Ȯ���ϸ鼭 Ž���Ѵ�.
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
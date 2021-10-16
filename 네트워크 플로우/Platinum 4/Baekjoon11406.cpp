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
#define INF 2e9

using namespace std;
int N, M;
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

	cin >> N >> M;
	for (int i = 2; i <= N + 1; i++) { // N���� ������� 2������ N+1������ ��ȣ�� �ο��ϰ�, Source�� �������� �����ϰ� Capacity�� A[i]�� �����Ѵ�.
		int A;
		cin >> A;
		Vertex[0].push_back(i);
		Vertex[i].push_back(0);
		CAPACITY[0][i] = A;
	}
	for (int i = N + 2; i < N + 2 + M; i++) { // M���� �¶��� �������� N+2������ N+M+1������ ��ȣ�� �ο��ϰ�, Sink�� �������� �����ϰ� Capacity�� B[i]�� �����Ѵ�.
		int B;
		cin >> B;
		Vertex[1].push_back(i);
		Vertex[i].push_back(1);
		CAPACITY[i][1] = B;
	}
	for (int i = N + 2; i < N + 2 + M; i++) {
		for (int j = 2; j <= N + 1; j++) { // i��° �¶��� ������ j��° ����� �������� �����ϰ� Capacity�� C�� �����Ѵ�.
			int C;
			cin >> C;
			Vertex[j].push_back(i);
			Vertex[i].push_back(j);
			CAPACITY[j][i] = C;
		}
	}
	while (1) {
		memset(PREV, -1, sizeof PREV);
		queue<int> Q;
		Q.push(Source);

		while (!Q.empty() && (PREV[Sink] == -1)) {
			int Cur = Q.front();
			Q.pop();

			for (int i = 0; i < Vertex[Cur].size(); i++) {
				int Next = Vertex[Cur][i];
				if (PREV[Next] != -1) {
					continue;
				}
				if (CAPACITY[Cur][Next] > FLOW[Cur][Next]) {
					Q.push(Next);
					PREV[Next] = Cur;
					if (Next == Sink) {
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
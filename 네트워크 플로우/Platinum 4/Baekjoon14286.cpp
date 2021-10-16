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
int N, M, Source, Sink;
int PREV[MAX];
int WORK[MAX];
int CAPACITY[MAX][MAX];
int FLOW[MAX][MAX];
vector<int> Vertex[MAX];
int Total_Flow = 0;

// �ִ� ���� �ּ� ��(Min Cut Max Flow) : Source�� Sink�� �񿬰�Ǵ� �������� ������ �������
void ADD_Edge(int A, int B, int C) {
	Vertex[A].push_back(B);
	Vertex[B].push_back(A);
	CAPACITY[A][B] += C;
	CAPACITY[B][A] += C;
}

int DFS(int Cur, int Total) {
	if (Cur == Sink) {
		return Total;
	}
	for (int &i = WORK[Cur]; i < Vertex[Cur].size(); i++) {
		int Next = Vertex[Cur][i];
		if ((PREV[Next] == PREV[Cur] + 1) && (CAPACITY[Cur][Next] > FLOW[Cur][Next])) {
			int flow = DFS(Next, min(Total, CAPACITY[Cur][Next] - FLOW[Cur][Next]));
			if (flow > 0) {
				FLOW[Cur][Next] += flow;
				FLOW[Next][Cur] -= flow;
				return flow;
			}
		}
	}
	return 0;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) { // ����ġ, �� �뷮�� C��ŭ ���� A�� B�� �մ� ���� �Է�
		int A, B, C;
		cin >> A >> B >> C;
		ADD_Edge(A, B, C);
	}
	cin >> Source >> Sink; // Source�� Sink �� ���� �Է�

	while (1) {
		memset(PREV, -1, sizeof PREV);
		queue<int> Q;
		Q.push(Source);
		PREV[Source] = 0;

		while (!Q.empty()) {
			int Cur = Q.front();
			Q.pop();

			for (int i = 0; i < Vertex[Cur].size(); i++) {
				int Next = Vertex[Cur][i];
				if (PREV[Next] != -1) {
					continue;
				}
				if (CAPACITY[Cur][Next] > FLOW[Cur][Next]) {
					PREV[Next] = PREV[Cur] + 1;
					Q.push(Next);
				}
			}
		};

		if (PREV[Sink] == -1) {
			break;
		}
		memset(WORK, 0, sizeof WORK);
		while (1) {
			int flow = DFS(Source, INF);
			if (flow <= 0) {
				break;
			}
			Total_Flow += flow;
		};
	};
	cout << Total_Flow << "\n";

	getchar();
	getchar();
	return 0;
}
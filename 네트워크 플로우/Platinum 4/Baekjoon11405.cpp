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
bool inQ[MAX];
int CAPACITY[MAX][MAX];
int FLOW[MAX][MAX];
int Cost[MAX][MAX];
vector<int> Vertex[MAX];
int answer = 0;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 2; i < N + 2; i++) { // N���� ����� Sink�� �������� �����ϰ� �뷮�� A(����� ����� �ϴ� å�� ����)�� �ʱ�ȭ��Ų��.
		int A;
		cin >> A;
		Vertex[i].push_back(1);
		Vertex[1].push_back(i);
		CAPACITY[i][1] = A;
	}
	for (int i = N + 2; i < N + M + 2; i++) { // M���� �¶��� ������ Source�� �������� �����ϰ� �뷮�� B(�¶��� ������ ������ �ִ� å�� ����)�� �ʱ�ȭ��Ų��.
		int B;
		cin >> B;
		Vertex[0].push_back(i);
		Vertex[i].push_back(0);
		CAPACITY[0][i] = B;
	}
	for (int i = N + 2; i < N + M + 2; i++) {
		for (int j = 2; j < N + 2; j++) {
			// i��° �¶��� ������ j��° ����� �������� �����ϰ� �뷮�� INF�� �ʱ�ȭ��Ų��.
			// �¶��� ���� i���� ��� j���� �̵��ϴ� ����� C(��ۺ�)�� �ʱ�ȭ��Ű��, �������� -C�� �ʱ�ȭ��Ų��. (�ִ� �Ÿ� �˰��� �̿�)
			int C;
			cin >> C;
			Vertex[i].push_back(j);
			Vertex[j].push_back(i);
			Cost[i][j] = C;
			Cost[j][i] = -C;
			CAPACITY[i][j] = INF;
		}
	}
	while (1) {
		memset(PREV, -1, sizeof PREV);
		memset(DIST, INF, sizeof DIST);
		memset(inQ, false, sizeof inQ);
		queue<int> Q;
		DIST[Source] = 0;
		inQ[Source] = true;
		Q.push(Source);

		while (!Q.empty()) {
			int Cur = Q.front();
			Q.pop();
			inQ[Cur] = false;

			for (int i = 0; i < Vertex[Cur].size(); i++) {
				int Next = Vertex[Cur][i];
				if ((CAPACITY[Cur][Next] > FLOW[Cur][Next]) && (DIST[Next] > DIST[Cur] + Cost[Cur][Next])) {
					DIST[Next] = DIST[Cur] + Cost[Cur][Next];
					PREV[Next] = Cur;
					if (!inQ[Next]) {
						Q.push(Next);
						inQ[Next] = true;
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
			answer += (flow * Cost[PREV[i]][i]);
			FLOW[PREV[i]][i] += flow;
			FLOW[i][PREV[i]] -= flow;
		}
	};

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
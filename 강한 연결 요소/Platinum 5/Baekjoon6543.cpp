#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 5001
#define INF 2e9

using namespace std;
int N, M;
int K; // SCC�� ���� K
vector<int> Vertex[MAX], Edge[MAX], answer, ST;
vector<vector<int> > SCC;
bool visited[MAX];
int SN[MAX];
int SCC_OutDegree[MAX];

void init() {
	K = 0;
	SCC.clear();
	ST.clear();
	answer.clear();
	for (int i = 0; i < MAX; i++) {
		Vertex[i].clear();
		Edge[i].clear();
		SN[i] = 0;
		SCC_OutDegree[i] = 0;
		visited[i] = false;
	}
}

void init2() {
	for (int i = 0; i < MAX; i++) {
		visited[i] = false;
	}
}

// DFS : ���� �׷����� DFS�� �������� ����Ǵ� ������� �ϳ��� stack�� �׾Ƴִ´�. DFS�� ����Ǹ� stack�� top���� �� ó�� DFS�� ������ ������ �ȴ�.
void DFS(int S) {
	visited[S] = true;
	for (int i = 0; i < Vertex[S].size(); i++) {
		if (!visited[Vertex[S][i]]) {
			DFS(Vertex[S][i]);
		}
	}
	ST.push_back(S);
}

// Re_DFS : ������ �׷����� DFS�Ѵ�.
void Re_DFS(int S, int T) {
	visited[S] = true;
	SCC[T].push_back(S); // T��° SCC�� ���� S�� push
	SN[S] = T;
	for (int i = 0; i < Edge[S].size(); i++) {
		if (!visited[Edge[S][i]]) {
			Re_DFS(Edge[S][i], T);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		init();
		cin >> N;
		if (N == 0) {
			break;
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			int V, W;
			cin >> V >> W;
			Vertex[V].push_back(W);
			Edge[W].push_back(V);
		}
		for (int i = 1; i <= N; i++) { // DFS�� �����Ͽ� ����Ǵ� ������� �ϳ��� stack�� �״´�.
			if (!visited[i]) {
				DFS(i);
			}
		}
		init2(); // DFS�� �ٽ� �ϱ� ���Ͽ� �湮 ����� �ʱ�ȭ��Ų��.
		while (ST.size()) { // ������ �׷����� DFS�� �����Ѵ�.
			int S = ST.back();
			ST.pop_back();
			if (visited[S]) {
				continue;
			}
			SCC.resize(K + 1);
			Re_DFS(S, K);
			K++;
		};
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < Vertex[i].size(); j++) { // SCC ������ �ٸ� ��η� �� �� �ִ� ������ �ִٸ� OutDegree�� ������Ų.
				if (SN[i] != SN[Vertex[i][j]]) {
					SCC_OutDegree[SN[i]]++;
				}
			}
		}
		for (int i = 0; i < K; i++) { // OutDegree�� 0�� SCC�� ���ؼ� ��� ������ ����Ѵ�.
			if (SCC_OutDegree[i] == 0) {
				for (int j = 0; j < SCC[i].size(); j++) {
					answer.push_back(SCC[i][j]);
				}
			}
		}
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
	};

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 2003
#define INF 2e9

using namespace std;
int N, M; // 변수의 개수, 절의 개수
int cnt;
vector<int> ST;
vector<vector<int> > Vertex, Edge;
int SCC[MAX];
bool visited[MAX];

// 2-Satisfiability Problem(2-SAT)
void init() {
	cnt = 1;
	ST.clear();
	Vertex.clear();
	Edge.clear();
	for (int i = 0; i < MAX; i++) {
		SCC[i] = 0;
		visited[i] = false;
	}
}

void init2() {
	for (int i = 0; i < MAX; i++) {
		visited[i] = false;
	}
}

inline int notX(int X) {
	return X ^ 1;
}

inline int trueX(int X) {
	return (X << 1);
}

inline int falseX(int X) {
	return ((X << 1) | 1);
}

void DFS(int S) {
	visited[S] = true;
	for (int i = 0; i < Vertex[S].size(); i++) {
		if (!visited[Vertex[S][i]]) {
			DFS(Vertex[S][i]);
		}
	}
	ST.push_back(S);
}

void Re_DFS(int S, int T) {
	visited[S] = true;
	SCC[S] = T;
	for (int i = 0; i < Edge[S].size(); i++) {
		if (!visited[Edge[S][i]]) {
			Re_DFS(Edge[S][i], T);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (scanf("%d %d", &N, &M) > 0) {
		init();
		Vertex.resize((N << 1) + 2);
		Edge.resize((N << 1) + 2);
		for (int i = 0; i < M; i++) {
			int X, Y;
			scanf("%d %d", &X, &Y);
			if (X > 0) {
				X = trueX(X);
			}
			else {
				X = falseX(-X);
			}
			if (Y > 0) {
				Y = trueX(Y);
			}
			else {
				Y = falseX(-Y);
			}
			Vertex[notX(X)].push_back(Y); // 간선 ￢X → Y
			Vertex[notX(Y)].push_back(X); // 간선 ￢Y → X
			// 역방향 간선
			Edge[Y].push_back(notX(X));
			Edge[X].push_back(notX(Y));
		}
		// make SCC
		for (int i = 2; i <= (N * 2) + 1; i++) {
			if (!visited[i]) {
				DFS(i);
			}
		}
		init2();
		for (int i = ST.size() - 1; i >= 0; i--) {
			if (!visited[ST[i]]) {
				Re_DFS(ST[i], cnt);
				cnt++;
			}
		}
		// 식 f를 true로 만들 수 있는 지 확인
		bool Flag = true;
		for (int i = 1; i <= N; i++) {
			if (SCC[trueX(i)] == SCC[falseX(i)]) { // X와 ￢X가 같은 SCC에 속하는 경우가 있다면 식 f를 true로 만들 수 없다.
				Flag = false;
				break;
			}
		}
		if ((Flag) && (SCC[trueX(1)] > SCC[falseX(1)])) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	};

	getchar();
	getchar();
	return 0;
}
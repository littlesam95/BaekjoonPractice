#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 20002
#define INF 2e9

using namespace std;
int N, M; // ������ ����, ���� ����
int cnt = 1;
vector<int> Vertex[MAX], Edge[MAX], ST;
int SCC[MAX];
bool visited[MAX];

// 2-Satisfiability Problem(2-SAT)
void init() {
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

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int X, Y;
		cin >> X >> Y;
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
		Vertex[notX(X)].push_back(Y); // ���� ��X �� Y
		Vertex[notX(Y)].push_back(X); // ���� ��Y �� X
		// ������ ����
		Edge[Y].push_back(notX(X));
		Edge[X].push_back(notX(Y));
	}
	// make SCC
	for (int i = 2; i <= (M * 2) + 1; i++) {
		if (!visited[i]) {
			DFS(i);
		}
	}
	init();
	reverse(ST.begin(), ST.end());
	for (int i = 0; i < ST.size(); i++) {
		if (!visited[ST[i]]) {
			Re_DFS(ST[i], cnt);
			cnt++;
		}
	}
	// �� f�� true�� ���� �� �ִ� �� Ȯ��
	for (int i = 1; i <= M; i++) {
		if (SCC[trueX(i)] == SCC[falseX(i)]) { // X�� ��X�� ���� SCC�� ���ϴ� ��찡 �ִٸ� �� f�� true�� ���� �� ����.
			cout << "OTL" << "\n";
			exit(0);
		}
	}
	cout << "^_^" << "\n";

	getchar();
	getchar();
	return 0;
}
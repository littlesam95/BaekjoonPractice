#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 10001
#define INF 2e9

using namespace std;
int V, E;
int K = 0; // SCC�� ���� K
vector<int> Vertex[MAX], Edge[MAX], answer[MAX]; // ���� �׷���, ������ �׷���, SCC
vector<pair<int, int> > R;
bool visited[MAX];
stack<int> ST; // ���� �׷����� DFS�� �� �ʿ��� stack

// �ڻ����(Kosaraju) �˰���
void init() {
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
	ST.push(S);
}

// Re_DFS : ������ �׷����� DFS�Ѵ�.
void Re_DFS(int S, int T) {
	visited[S] = true;
	answer[T].push_back(S); // T��° SCC�� ���� S�� push
	for (int i = 0; i < Edge[S].size(); i++) {
		if (!visited[Edge[S][i]]) {
			Re_DFS(Edge[S][i], T);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B;
		cin >> A >> B;
		Vertex[A].push_back(B);
		Edge[B].push_back(A);
	}
	for (int i = 1; i <= V; i++) { // DFS�� �����Ͽ� ����Ǵ� ������� �ϳ��� stack�� �״´�.
		if (!visited[i]) {
			DFS(i);
		}
	}
	init(); // DFS�� �ٽ� �ϱ� ���Ͽ� �湮 ����� �ʱ�ȭ��Ų��.
	while (!ST.empty()) { // ������ �׷����� DFS�� �����Ѵ�.
		int S = ST.top();
		ST.pop();
		if (visited[S]) {
			continue;
		}
		Re_DFS(S, K);
		K++;
	};
	cout << K << "\n"; // SCC�� ������ ����Ѵ�.
	for (int i = 0; i < K; i++) { // i��° SCC �� ���� ���� ��ȣ�� ������ i�� pair�� ���� R vector�� ����
		sort(answer[i].begin(), answer[i].end());
		R.push_back(make_pair(answer[i][0], i));
	}
	sort(R.begin(), R.end()); // ���� ��ȣ�� �������� ������������ ����ؾ� �ϹǷ� ����
	for (int i = 0; i < R.size(); i++) { // ������ ��ȣ�� pair�� �̷�� index��° SCC�� ���� �ִ� ������ ��ȣ�� ������������ ����ϸ� ���̴�.
		for (int j = 0; j < answer[R[i].second].size(); j++) {
			cout << answer[R[i].second][j] << " ";
		}
		cout << -1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}
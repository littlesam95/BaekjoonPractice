#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 101
#define INF 2e9

using namespace std;
int N;
int Cost[MAX];
vector<int> Vertex[MAX], Edge[MAX], SCC[MAX], ST;
int answer = 0;
bool visited[MAX];

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
	ST.push_back(S);
}

// Re_DFS : ������ �׷����� DFS�Ѵ�.
int Re_DFS(int S) {
	int res = Cost[S];
	visited[S] = true;
	for (int i = 0; i < Edge[S].size(); i++) {
		if (!visited[Edge[S][i]]) {
			res = min(res, Re_DFS(Edge[S][i]));
		}
	}
	return res;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Cost[i];
	}
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '1') {
				Vertex[i].push_back(j);
				Edge[j].push_back(i);
			}
		}
	}
	for (int i = 0; i < N; i++) { // DFS�� �����Ͽ� ����Ǵ� ������� �ϳ��� stack�� �״´�.
		if (!visited[i]) {
			DFS(i);
		}
	}
	init(); // DFS�� �ٽ� �ϱ� ���Ͽ� �湮 ����� �ʱ�ȭ��Ų��.
	while (ST.size()) { // ������ �׷����� DFS�� �����Ѵ�.
		int S = ST.back();
		ST.pop_back();
		if (visited[S]) {
			continue;
		}
		answer += Re_DFS(S);
	};
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
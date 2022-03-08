#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 30001
#define LL long long
#define INF 1e9

using namespace std;
int T, N, M;
vector<int> Edge[MAX];
int visited[MAX];
bool isCutNode[MAX];
int answer;

void Init() {
	answer = 0;
	for (int i = 0; i < MAX; i++) {
		Edge[i].clear();
		visited[i] = 0;
		isCutNode[i] = false;
	}
}

int DFS(int Parent, int Here, int Order, bool isRoot) {
	visited[Here] = Order;
	int res = visited[Here];
	int Child = 0;

	for (int i = 0; i < Edge[Here].size(); i++) {
		int Next = Edge[Here][i];
		if (Parent == Next) {
			continue;
		}

		if (visited[Next] > 0) {
			res = min(res, visited[Next]);
			continue;
		}

		Child++;
		int Next_Order = DFS(Here, Next, Order + 1, false);
		if (!isRoot && (visited[Here] <= Next_Order)) {
			isCutNode[Here] = true;
		}
		res = min(res, Next_Order);
	}

	if (isRoot && (Child >= 2)) {
		isCutNode[Here] = true;
	}

	return res;
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		sort(Edge[i].begin(), Edge[i].end());
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 0) {
			DFS(0, i, 1, true);
		}
	}
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		if (isCutNode[i]) {
			answer++;
		}
	}
	if (answer == 0) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
}

void Input() {
	cin >> T;
	while (T--) {
		Init();
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int A, B;
			cin >> A >> B;
			Edge[A].push_back(B);
			Edge[B].push_back(A);
		}
		Settings();
		Find_Answer();
	};
}

int main() {
	FASTIO
	Input();

	getchar();
	getchar();
	return 0;
}
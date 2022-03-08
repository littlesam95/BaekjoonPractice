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
#define MAX 10001
#define LL long long
#define INF 1e9

using namespace std;
int V, E;
vector<int> Edge[MAX];
int visited[MAX];
bool answer[MAX];

int DFS(int Parent, int Start, int Order, bool isRoot) {
	int res = Order;
	visited[Start] = Order; // DFS 탐색 순서 지정
	int Child = 0; // 자식 노드 수

	for (int i = 0; i < Edge[Start].size(); i++) {
		int Next = Edge[Start][i]; // 다음 정점
		if (Parent == Next) {
			continue;
		}
		if (visited[Next] == 0) { // 다음 정점이 아직 탐색되지 않은 정점일 때
			int Next_Order = DFS(Start, Next, Order + 1, false); // 다음 정점의 방문 번호를 찾고
			Child++;
			if (!isRoot && (Next_Order >= visited[Start])) {
				/*
					현재 정점이 Root가 아니고, 현재 정점보다 빠른 방문 번호를 가진 정점으로 
					자식 정점들이 갈 수 없다면 현재 정점은 단절점이다. (visited[Next] >= visited[Start])
				*/
				answer[Start] = true;
			}
			res = min(res, Next_Order);
		}
		else { 
			/*
				다음 정점이 이미 DFS에서 탐색된 정점이라면(visited[Next] == true)
				현재 정점의 방문 순서와 탐색된 정점의 방문 순서 중 최솟값을 가진다.
				이렇게 해서 현재 정점에서 자식 정점들이 현재 정점을 거치지 않고
				현재 정점보다 빠른 방문 번호를 가진 정점으로 갈 수 없는 경우를 찾을 수 있다.
			*/
			res = min(res, visited[Next]);
		}
	}

	if (isRoot && (Child >= 2)) { // 그런데 현재 정점이 Root고, 자식 정점을 2개 이상 가진다면
		answer[Start] = true; // 현재 정점은 단절점이다.
	}

	return res;
}

void Input() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int A, B;
		cin >> A >> B;
		Edge[A].push_back(B);
		Edge[B].push_back(A);
	}
}

void Settings() {
	for (int i = 1; i <= V; i++) {
		sort(Edge[i].begin(), Edge[i].end());
	}
	for (int i = 1; i <= V; i++) {
		if (visited[i] == 0) {
			DFS(0, i, 1, true);
		}
	}
}

void Find_Answer() {
	int res = 0;
	for (int i = 1; i <= V; i++) {
		if (answer[i]) {
			res++;
		}
	}
	cout << res << "\n";
	for (int i = 1; i <= V; i++) {
		if (answer[i]) {
			cout << i << " ";
		}
	}
	cout << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
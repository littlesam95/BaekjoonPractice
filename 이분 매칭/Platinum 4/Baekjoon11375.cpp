#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1001
#define INF 1e9+7

using namespace std;
int N, M;
int WORK[MAX];
bool visited[MAX];
vector<int> Graph[MAX];
int answer = 0;

bool DFS(int E) {
	for (int i = 0; i < Graph[E].size(); i++) {
		int Next = Graph[E][i];
		if (!visited[Next]) {
			visited[Next] = true;
			if ((WORK[Next] == 0) || DFS(WORK[Next])) {
				WORK[Next] = E;
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int S;
		cin >> S;
		while (S--) {
			int X;
			cin >> X;
			Graph[i].push_back(X);
		};
	}
	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof visited);
		if (DFS(i)) {
			answer++;
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
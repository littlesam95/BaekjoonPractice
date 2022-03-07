#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 10005
#define LL long long
#define INF 2e9

using namespace std;
int N, M, S, E;
vector<int> Vec[MAX];
int Path[MAX];
int visited[MAX];
int answer = 0;

int BFS(int A, int B) {
	queue<pair<int, int> > Q;
	visited[A] = true;
	Q.push(make_pair(A, 0));

	while (!Q.empty()) {
		int CurX = Q.front().first;
		int CurCost = Q.front().second;
		Q.pop();

		for (int i = 0; i < Vec[CurX].size(); i++) {
			int nextX = Vec[CurX][i];
			if (!visited[nextX]) {
				visited[nextX] = true;
				Path[nextX] = CurX;
				Q.push(make_pair(nextX, CurCost + 1));
			}
			if (nextX == B) {
				return CurCost + 1;
			}
		}
	};

	return 0;
}

void init() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}
	int K = Path[E];
	while (1) {
		visited[K] = true;
		K = Path[K];
		if (K == 0) {
			break;
		}
	};
}

int main() {
	FIRST
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int X, Y;
		cin >> X >> Y;
		Vec[X].push_back(Y);
		Vec[Y].push_back(X);
	}
	for (int i = 1; i <= N; i++) {
		sort(Vec[i].begin(), Vec[i].end());
	}
	cin >> S >> E;
	answer += BFS(S, E);
	init();
	answer += BFS(E, S);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
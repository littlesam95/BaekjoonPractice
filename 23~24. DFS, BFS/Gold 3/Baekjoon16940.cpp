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
#define MAX 100005
#define LL long long
#define INF 2e9

using namespace std;
int N, T;
vector<int> Vec[MAX];
bool visited[MAX];
int Order[MAX];
int BFS_Order[MAX];

bool Comp(int A, int B) {
	return (Order[A] < Order[B]);
}

void BFS() {
	queue<int> Q;
	visited[1] = true;
	int IDX = 1;
	Q.push(1);

	while (!Q.empty()) {
		int CurX = Q.front();
		Q.pop();

		BFS_Order[CurX] = IDX++;

		for (int i = 0; i < Vec[CurX].size(); i++) {
			int nextX = Vec[CurX][i];
			if (!visited[nextX]) {
				visited[nextX] = true;
				Q.push(nextX);
			}
		}
	};
}

bool isSameOrder() {
	for (int i = 1; i <= N; i++) {
		if (Order[i] != BFS_Order[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	FIRST
	cin >> N;
	for (int i = 0; i < (N - 1); i++) {
		int X, Y;
		cin >> X >> Y;
		Vec[X].push_back(Y);
		Vec[Y].push_back(X);
	}
	for (int i = 1; i <= N; i++) {
		int X;
		cin >> X;
		Order[X] = i;
	}
	for (int i = 1; i <= N; i++) {
		sort(Vec[i].begin(), Vec[i].end(), Comp);
	}
	BFS();
	if (isSameOrder()) {
		cout << 1 << "\n";
	}
	else {
		cout << 0 << "\n";
	}

	getchar();
	getchar();
	return 0;
}
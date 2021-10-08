#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1001

using namespace std;
int N, M, K;
int parent[MAX];
vector<pair<int, pair<int, int> > > Edge;
int answer = 0;

void init() {
	for (int i = 0; i < MAX; i++) {
		parent[i] = i;
	}
}

int Find(int X) {
	if (parent[X] == -1) {
		return -1;
	}
	else if (parent[X] == X) {
		return X;
	}
	return parent[X] = Find(parent[X]);
}

void Union_Set(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (P_X != P_Y) {
		parent[P_Y] = P_X;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int X;
		cin >> X;
		parent[X] = -1;
	}
	for (int i = 0; i < M; i++) {
		int U, V, W;
		cin >> U >> V >> W;
		Edge.push_back(make_pair(W, make_pair(U, V)));
	}
	sort(Edge.begin(), Edge.end());
	for (int i = 0; i < Edge.size(); i++) {
		int U = Edge[i].second.first;
		int V = Edge[i].second.second;
		int W = Edge[i].first;
		int parent_U = Find(U);
		int parent_V = Find(V);
		if (parent_U != parent_V) {
			if (parent_U == -1) {
				parent[parent_V] = parent_U;
			}
			else if (parent_V == -1) {
				parent[parent_U] = parent_V;
			}
			else {
				parent[parent_V] = parent_U;
			}
			answer += W;
		}
	}

	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
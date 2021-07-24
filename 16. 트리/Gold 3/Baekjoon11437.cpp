#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory.h>
#include <algorithm>
#define MAX_NODE 100001

using namespace std;
int N, M;
int a, b;
int depth[MAX_NODE];
int ac[MAX_NODE][20];
int parent[MAX_NODE];
vector<int> vec[MAX_NODE];
bool visited[MAX_NODE];
int max_level;

void init() {
	N = 0;
	a = 0;
	b = 0;
	for (int i = 0; i < MAX_NODE; i++) {
		depth[i] = 0;
		parent[i] = 0;
		vec[i].clear();
		for (int j = 0; j < 20; j++) {
			ac[i][j] = 0;
		}
	}
}

void init2() {
	for (int i = 0; i < MAX_NODE; i++) {
		visited[i] = false;
	}
}

void find_parent(int S) {
	visited[S] = true;
	for (int i = 0; i < vec[S].size(); i++) {
		if (!visited[S]) {
			parent[vec[S][i]] = S;
			find_parent(vec[S][i]);
		}
	}
}

void make_tree(int S, int parent) {
	depth[S] = depth[parent] + 1;
	ac[S][0] = parent;
	max_level = (int)floor(log2(MAX_NODE));
	for (int i = 1; i <= max_level; i++) {
		int tmp = ac[S][i - 1];
		ac[S][i] = ac[tmp][i - 1];
	}
	int len = vec[S].size();
	for (int i = 0; i < len; i++) {
		int there = vec[S][i];
		if (there != parent) {
			make_tree(there, S);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	init2();
	find_parent(1);
	depth[0] = -1;
	make_tree(1, 0);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b]) {
				int tmp;
				tmp = a;
				a = b;
				b = tmp;
			}
			for (int i = max_level; i >= 0; i--) {
				if (depth[a] <= depth[ac[b][i]]) {
					b = ac[b][i];
				}
			}
		}

		int answer = a;
		if (a != b) {
			for (int i = max_level; i >= 0; i--) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				answer = ac[a][i];
			}
		}

		cout << answer << "\n";
	}

	getchar();
	getchar();
	return 0;
}
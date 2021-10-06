#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#define MAX 100001

using namespace std;
int N, M;
int parent[MAX];
vector<pair<int, pair<int, int> > > vec;
vector<int> cost_vec;
int answer = 0;

void init() {
	for (int i = 1; i <= N; i++) {
		parent[i] = -1;
	}
}

int Find(int X) {
	if (parent[X] < 0) {
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

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		vec.push_back(make_pair(C, make_pair(A, B)));
	}
	sort(vec.begin(), vec.end());
	init();
	int E = N - 2;
	for (int i = 0; i < M; i++) {
		int A = vec[i].second.first;
		int B = vec[i].second.second;
		int C = vec[i].first;
		if (Find(A) != Find(B)) {
			Union_Set(A, B);
			answer += vec[i].first;
			E--;
		}
		if (E == 0) {
			break;
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
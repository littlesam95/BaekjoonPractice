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
int N, M;
int parent[MAX];
bool Univ_State[MAX];
vector<pair<int, pair<int, int> > > vec;
int answer;

void init() {
	for (int i = 0; i < MAX; i++) {
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

bool comp(pair<int, pair<int, int> > A, pair<int, pair<int, int> > B) {
	if (A.first == B.first) {
		return (A.second.first < B.second.first);
	}
	return (A.first > B.first);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		char State;
		cin >> State;
		if (State == 'M') {
			Univ_State[i] = true;
		}
		else if (State == 'W') {
			Univ_State[i] = false;
		}
	}
	for (int i = 0; i < M; i++) {
		int U, V, D;
		cin >> U >> V >> D;
		if (Univ_State[U] != Univ_State[V]) {
			vec.push_back(make_pair(D, make_pair(U, V)));
		}
	}
	sort(vec.begin(), vec.end());
	init();
	int E = 0;
	bool flag = false;
	for (int i = 0; i < vec.size(); i++) {
		int A = vec[i].second.first;
		int B = vec[i].second.second;
		int C = vec[i].first;
		if (Find(A) != Find(B)) {
			Union_Set(A, B);
			E++;
			answer += C;
		}
		if (E == N - 1) {
			flag = true;
			break;
		}
	}
	if (flag) {
		cout << answer << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	getchar();
	getchar();
	return 0;
}
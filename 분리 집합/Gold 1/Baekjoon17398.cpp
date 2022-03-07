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
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
int N, M, Q;
int Parent[MAX];
LL Cnt[MAX];
bool visited[MAX];
stack<int> S;
vector<pair<int, int> > Line;
LL answer = 0;

void Init() {
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
		Cnt[i] = 1;
	}
}

int Find(int X) {
	if (Parent[X] == X) {
		return X;
	}
	return Parent[X] = Find(Parent[X]);
}

void Union(int X, int Y) {
	int PX = Find(X);
	int PY = Find(Y);
	if (PX < PY) {
		Parent[PY] = PX;
		Cnt[PX] += Cnt[PY];
		Cnt[PY] = 0;
	}
	else {
		Parent[PX] = PY;
		Cnt[PY] += Cnt[PX];
		Cnt[PX] = 0;
	}
}

void Input() {
	cin >> N >> M >> Q;
	Init();
	for (int i = 0; i < M; i++) {
		int X, Y;
		cin >> X >> Y;
		Line.push_back(make_pair(X, Y));
	}
	for (int i = 0; i < Q; i++) {
		int A;
		cin >> A;
		visited[A - 1] = true;
		S.push(A - 1);
	}
}

void Settings() {
	for (int i = 0; i < Line.size(); i++) {
		if (!visited[i]) {
			int X = Line[i].first;
			int Y = Line[i].second;
			if (Find(X) != Find(Y)) {
				Union(X, Y);
			}
		}
	}
	while (!S.empty()) {
		int A = S.top();
		S.pop();
		int X = Line[A].first;
		int Y = Line[A].second;
		int PX = Find(X);
		int PY = Find(Y);
		if (PX != PY) {
			answer += (Cnt[PX] * Cnt[PY]);
			Union(X, Y);
		}
	};
}

void Find_Answer() {
	cout << answer << "\n";
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
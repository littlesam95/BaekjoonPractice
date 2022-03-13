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
#define INF 1e18

using namespace std;
struct INFO {
	int Start, End;
	LL Cost;
};

int T, N, M, P, Q;
vector<INFO> Edge;
int Parent[MAX];
bool Flag;
LL answer;

void Init() {
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}
	Edge.clear();
	Flag = false;
	answer = 0;
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
	}
	else {
		Parent[PX] = PY;
	}
}

bool Comp(INFO A, INFO B) {
	return (A.Cost < B.Cost);
}

void Settings() {
	sort(Edge.begin(), Edge.end(), Comp);
	for (int i = 0; i < Edge.size(); i++) {
		int U = Edge[i].Start;
		int V = Edge[i].End;
		LL C = Edge[i].Cost;
		if (Find(U) != Find(V)) {
			Union(U, V);
			answer += C;
			if (((P == U) && (Q == V)) || ((P == V) && (Q == U))) {
				Flag = true;
			}
		}
	}
}

void Find_Answer() {
	if (Flag) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
}

void Input() {
	cin >> T;
	while (T--) {
		cin >> N >> M >> P >> Q;
		Init();
		for (int i = 0; i < M; i++) {
			int U, V;
			LL W;
			cin >> U >> V >> W;
			Edge.push_back({ U,V,W });
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
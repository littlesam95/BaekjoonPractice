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
#define MAX 250005
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	int Start, End, Cost;
};

int T, R, C;
vector<INFO> Edge;
int Parent[MAX];
int answer;

void Init() {
	for (int i = 0; i < (R * C); i++) {
		Parent[i] = i;
	}
	Edge.clear();
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
	for (int i = 0; i < Edge.size(); i++) {
		int S = Edge[i].Start;
		int E = Edge[i].End;
		int Cost = Edge[i].Cost;
		if (Find(S) != Find(E)) {
			Union(S, E);
			answer += Cost;
		}
	}
}

void Find_Answer() {
	cout << answer << "\n";
}

void Input() {
	cin >> T;
	while (T--) {
		cin >> R >> C;
		Init();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C - 1; j++) {
				int Cost;
				cin >> Cost;
				int S = (i * C) + j;
				int E = (i * C) + j + 1;
				Edge.push_back({ S,E,Cost });
			}
		}
		for (int i = 0; i < (R - 1); i++) {
			for (int j = 0; j < C; j++) {
				int Cost;
				cin >> Cost;
				int S = (i * C) + j;
				int E = ((i + 1) * C) + j;
				Edge.push_back({ S,E,Cost });
			}
		}
		sort(Edge.begin(), Edge.end(), Comp);
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
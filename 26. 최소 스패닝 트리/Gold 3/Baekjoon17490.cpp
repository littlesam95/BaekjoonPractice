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
#define MAX 1000002
#define LL long long
#define INF 1e9

using namespace std;
struct INFO {
	int Start, End, Cost;
};

int N, M;
LL K;
vector<INFO> Edge;
bool isEdge[MAX];
int Parent[MAX];
LL answer = 0;

void Init() {
	for (int i = 1; i <= (N + 1); i++) {
		Parent[i] = i;
	}
}

bool Comp(INFO A, INFO B) {
	return (A.Cost < B.Cost);
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
	if (PY == N + 1) {
		Parent[PY] = PX;
	}
	else {
		if ((PX == N) && (PY == 1)) {
			Parent[PX] = PY;
		}
		else {
			Parent[PY] = PX;
		}
	}
}

bool isConnected() {
	for (int i = 2; i <= N; i++) {
		if (Find(i) != Find(1)) {
			return false;
		}
	}
	return true;
}

void Input() {
	cin >> N >> M >> K;
	Init();
	for (int i = 1; i <= N; i++) {
		int S;
		cin >> S;
		Edge.push_back({ i,N + 1,S });
	}
	for (int i = 0; i < M; i++) {
		int I, J;
		cin >> I >> J;
		if ((I == N) && (J == 1)) {
			isEdge[I] = true;
		}
		else if ((I == 1) && (J == N)) {
			isEdge[J] = true;
		}
		else {
			if (I < J) {
				isEdge[I] = true;
			}
			else {
				isEdge[J] = true;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (!isEdge[i]) {
			if (i < N) {
				Union(i, i + 1);
			}
			else if (i == N) {
				Union(N, 1);
			}
		}
	}
}

void Settings() {
	if (!isConnected()) {
		sort(Edge.begin(), Edge.end(), Comp);
		for (int i = 0; i < Edge.size(); i++) {
			int S = Edge[i].Start;
			int E = Edge[i].End;
			int C = Edge[i].Cost;
			if (Find(S) != Find(E)) {
				Union(S, E);
				answer += C;
			}
		}
	}
}

void Find_Answer() {
	if (isConnected()) {
		if (answer <= K) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	else {
		cout << "NO\n";
	}
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
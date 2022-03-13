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
#define MAX 1001
#define LL long long
#define INF 1e18

using namespace std;
struct INFO {
	int Start, End;
	LL Cost;
};

struct INFO2 {
	int Dest;
	LL Cost;
	bool checked;
};

int N, M, Q;
vector<INFO> Edge;
vector<INFO2> Vec[MAX];
int Parent[MAX];
LL Far[MAX][MAX];
bool visited[MAX];
LL answer = 0;

void Init1() {
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}
}

void Init2() {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
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
			for (int j = 0; j < Vec[U].size(); j++) {
				if (Vec[U][j].Dest == V) {
					Vec[U][j].checked = true;
					break;
				}
			}
			for (int j = 0; j < Vec[V].size(); j++) {
				if (Vec[V][j].Dest == U) {
					Vec[V][j].checked = true;
					break;
				}
			}
		}
	}
}

void BFS(int X) {
	queue<int> Q;
	visited[X] = true;
	Q.push(X);

	while (!Q.empty()) {
		int Cur = Q.front();
		Q.pop();

		for (int i = 0; i < Vec[Cur].size(); i++) {
			int Next = Vec[Cur][i].Dest;
			LL nCost = Vec[Cur][i].Cost;
			bool checked = Vec[Cur][i].checked;
			if (!visited[Next] && checked) {
				visited[Next] = true;
				Far[X][Next] = max({ Far[X][Next], Far[X][Cur], nCost });
				Q.push(Next);
			}
		}
	};
}

void Find_Answer() {
	while (Q--) {
		int X, Y;
		cin >> X >> Y;
		cout << answer - Far[X][Y] << "\n";
	};
}

void Input() {
	cin >> N >> M;
	Init1();
	for (int i = 0; i < M; i++) {
		int A, B;
		LL C;
		cin >> A >> B >> C;
		Edge.push_back({ A,B,C });
		Vec[A].push_back({ B,C,false });
		Vec[B].push_back({ A,C,false });
	}
	Settings();
	for (int i = 1; i <= N; i++) {
		Init2();
		BFS(i);
	}
	cin >> Q;
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
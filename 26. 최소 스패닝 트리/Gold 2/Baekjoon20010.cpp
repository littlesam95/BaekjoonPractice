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
#define INF 1e9

using namespace std;
struct INFO {
	int Start, End;
	LL Cost;
};

int N, K;
int Parent[MAX];
vector<pair<int, LL> > Vec[MAX];
vector<INFO> Edge;
bool visited[MAX];
LL answer = 0;
LL Big = 0;
int CenterNode;

void Init() {
	for (int i = 0; i < N; i++) {
		Parent[i] = i;
	}
}

void Init2() {
	for (int i = 0; i < N; i++) {
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

void DFS(int X, LL Sum) {
	if (Big < Sum) {
		Big = Sum;
		CenterNode = X;
	}
	for (int i = 0; i < Vec[X].size(); i++) {
		int Next = Vec[X][i].first;
		if (!visited[Next]) {
			visited[Next] = true;
			DFS(Next, Sum + Vec[X][i].second);
		}
	}
}

void Input() {
	cin >> N >> K;
	Init();
	for (int i = 0; i < K; i++) {
		int A, B;
		LL C;
		cin >> A >> B >> C;
		Edge.push_back({ A,B,C });
	}
}

void Settings() {
	sort(Edge.begin(), Edge.end(), Comp);
	for (int i = 0; i < Edge.size(); i++) {
		int S = Edge[i].Start;
		int E = Edge[i].End;
		LL C = Edge[i].Cost;
		if (Find(S) != Find(E)) {
			Union(S, E);
			answer += C;
			Big = max(Big, C);
			Vec[S].push_back(make_pair(E, C));
			Vec[E].push_back(make_pair(S, C));
		}
	}
	visited[0] = true;
	DFS(0, 0);
	Init2();
	visited[CenterNode] = true;
	DFS(CenterNode, 0);
}

void Find_Answer() {
	cout << answer <<"\n" << Big << "\n";
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
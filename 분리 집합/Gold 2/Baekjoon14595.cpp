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
#define MAX 1000001
#define LL long long
#define INF 1e9

using namespace std;
int N, M;
int Parent[MAX];
bool visited[MAX];
int Last_Break = 0;
vector<pair<int, int> > Vec;
int answer = 0;

void Init() {
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
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
	if (PX != PY) {
		Parent[PY] = PX;
	}
}

void Input() {
	cin >> N >> M;
	Init();
	for (int i = 0; i < M; i++) {
		int X, Y;
		cin >> X >> Y;
		Vec.push_back(make_pair(X, Y));
	}
}

void Settings() {
	sort(Vec.begin(), Vec.end());
	for (int i = 0; i < Vec.size(); i++) {
		int S = Vec[i].first;
		int E = Vec[i].second;
		S = max(S, Last_Break);
		for (int i = S; i <= E; i++) {
			Union(S, i);
		}
		Last_Break = max(Last_Break, E);
	}
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		int P = Find(i);
		if (!visited[P]) {
			visited[P] = true;
			answer++;
		}
	}
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
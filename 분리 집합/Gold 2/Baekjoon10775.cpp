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
int G, P, g;
int Parent[MAX];
vector<int> Vec;
int answer = 0;

void Init() {
	for (int i = 1; i <= G; i++) {
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
	cin >> G;
	Init();
	cin >> P;
	for (int i = 0; i < P; i++) {
		cin >> g;
		Vec.push_back(g);
	}
}

void Find_Answer() {
	for (int i = 0; i < P; i++) {
		int f = Find(Vec[i]);
		if (f != 0) {
			Union(f - 1, f);
			answer++;
		}
		else {
			break;
		}
	}
	cout << answer << "\n";
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
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
int N, M;
int Planet[MAX];
int Parent[MAX];
set<int> S;

void Init() {
	for (int i = 0; i < MAX; i++) {
		Parent[i] = i;
	}
}

int Find(int X) {
	if (Parent[X] == X) {
		return X;
	}
	return Parent[X] = Find(Parent[X]);
}

int Union_Group(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (P_X < P_Y) {
		Parent[P_Y] = P_X;
		Planet[P_X] += Planet[P_Y];
		Planet[P_Y] = 0;
		return Planet[P_X];
	}
	else {
		Parent[P_X] = P_Y;
		Planet[P_Y] += Planet[P_X];
		Planet[P_X] = 0;
		return Planet[P_Y];
	}
	return 0;
}

void Input() {
	Init();
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> Planet[i];
	}
}

void Find_Answer() {
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		if (Find(A) != Find(B)) {
			cout << Union_Group(A, B) << "\n";
		}
		else {
			cout << max(Planet[Find(A)], Planet[Find(B)]) << "\n";
		}
	}
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
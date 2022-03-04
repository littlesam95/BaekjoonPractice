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
int Parent[MAX];
int answer = 0;
int Cycle = 0;

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

void Union_Group(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (P_X != P_Y) {
		Parent[P_Y] = P_X;
	}
}

void Input() {
	Init();
	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int U, V;
		scanf_s("%d %d", &U, &V);
		if (Find(U) != Find(V)) {
			Union_Group(U, V);
		}
		else {
			Cycle++;
		}
	}
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		if (Find(i) == i) {
			answer++;
		}
	}
	printf("%d\n", answer - 1 + Cycle);
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
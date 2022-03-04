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
int N, M, K;
LL Cnt[MAX];
int Parent[MAX];
int Left = 0, Right = 0;
LL answer = 0;

void Init() {
	for (int i = 0; i < MAX; i++) {
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

void Union_Group(int X, int Y) {
	int P_X = Find(X);
	int P_Y = Find(Y);
	if (P_X < P_Y) {
		Parent[P_Y] = P_X;
		Cnt[P_X] += Cnt[P_Y];
		Cnt[P_Y] = 0;
	}
	else {
		Parent[P_X] = P_Y;
		Cnt[P_Y] += Cnt[P_X];
		Cnt[P_X] = 0;
	}
}

void Input() {
	Init();
	cin >> N >> M >> K;
	for (int i = 1; i <= M; i++) {
		int U, V;
		cin >> U >> V;
		if (i == K) {
			continue;
		}
		if (Find(U) != Find(V)) {
			Union_Group(U, V);
		}
	}
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		if (Find(i) == i) {
			if (Left == 0) {
				Left = i;
			}
			else {
				Right = i;
			}
		}
	}
	if ((Left != 0) && (Right != 0)) {
		answer = Cnt[Find(Left)] * Cnt[Find(Right)];
	}
	else {
		answer = 0;
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
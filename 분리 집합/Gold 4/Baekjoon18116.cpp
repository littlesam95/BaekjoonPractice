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
int N;
int Parts[MAX];
int Parent[MAX];

void Init() {
	for (int i = 0; i < MAX; i++) {
		Parent[i] = i;
		Parts[i] = 1;
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
		Parts[P_X] += Parts[P_Y];
		Parts[P_Y] = 0;
	}
	else {
		Parent[P_X] = P_Y;
		Parts[P_Y] += Parts[P_X];
		Parts[P_X] = 0;
	}
}

void Input() {
	Init();
	cin >> N;
}

void Find_Answer() {
	for (int i = 0; i < N; i++) {
		char I;
		cin >> I;
		if (I == 'I') {
			int A, B;
			cin >> A >> B;
			if (Find(A) != Find(B)) {
				Union_Group(A, B);
			}
		}
		else if (I == 'Q') {
			int C;
			cin >> C;
			cout << Parts[Find(C)] << "\n";
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
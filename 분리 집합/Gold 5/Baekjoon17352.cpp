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
#define MAX 300001
#define LL long long
#define INF 1e9

using namespace std;
int N;
int Parent[MAX];
pair<int, int> answer;

void Init() {
	for (int i = 0; i < MAX; i++) {
		Parent[i] = -1;
	}
}

int Find(int X) {
	if (Parent[X] == -1) {
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
	cin >> N;
	for (int i = 0; i < (N - 2); i++) {
		int U, V;
		cin >> U >> V;
		Union_Group(U, V);
	}
}

void Find_Answer() {
	for (int i = 1; i <= N; i++) {
		if (i == Find(i)) {
			if (answer.first == 0) {
				answer.first = i;
			}
			else {
				answer.second = i;
				break;
			}
		}
	}
	cout << answer.first << " " << answer.second << "\n";
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
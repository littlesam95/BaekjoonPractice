#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 250001
#define LL long long
#define INF 1e12

using namespace std;
int N, X;
int Sum[MAX];
int Answer_V, Answer_D;

void Input() {
	cin >> N >> X;
	for (int i = 1; i <= N; i++) {
		int A;
		cin >> A;
		Sum[i] = Sum[i - 1] + A;
	}
}

void Settings() {
	for (int i = X; i <= N; i++) {
		int Tmp = Sum[i] - Sum[i - X];
		if (Answer_V < Tmp) {
			Answer_V = Tmp;
			Answer_D = 1;
		}
		else if (Answer_V == Tmp) {
			Answer_D++;
		}
	}
}

void Find_Answer() {
	if (Answer_V > 0) {
		cout << Answer_V << "\n" << Answer_D << "\n";
	}
	else {
		cout << "SAD\n";
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
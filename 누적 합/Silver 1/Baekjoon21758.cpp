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
#define MAX 100001
#define LL long long
#define INF 1e9

using namespace std;
int N;
int Honey[MAX];
int Sum[MAX];
int Answer = 0;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Honey[i];
		Sum[i] = Sum[i - 1] + Honey[i];
	}
}

void Settings() {
	// 1. 国 - 曹烹 - 国
	for (int i = 2; i < N; i++) {
		int Cur = (Sum[i] - Sum[1]) + (Sum[N - 1] - Sum[i - 1]);
		Answer = max(Answer, Cur);
	}

	// 2. 国 - 国 - 曹烹
	for (int i = 2; i < N; i++) {
		int Cur = (Sum[N] - Sum[1] - Honey[i]) + (Sum[N] - Sum[i]);
		Answer = max(Answer, Cur);
	}

	// 3. 曹烹 - 国 - 国
	for (int i = 2; i < N; i++) {
		int Cur = (Sum[N - 1] - Honey[i]) + Sum[i - 1];
		Answer = max(Answer, Cur);
	}
}

void Find_Answer() {
	cout << Answer << "\n";
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
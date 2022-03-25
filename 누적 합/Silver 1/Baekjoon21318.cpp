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
int N, Q, X, Y;
int Knote[MAX];
int Sum[MAX];

void Settings() {
	for (int i = 1; i <= N; i++) {
		Sum[i] = Sum[i - 1] + (Knote[i - 1] > Knote[i] ? 1 : 0);
	}
}

void Find_Answer() {
	cout << Sum[Y] - Sum[X] << "\n";
}

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> Knote[i];
	}
	Settings();
	cin >> Q;
	while (Q--) {
		cin >> X >> Y;
		Find_Answer();
	};
}

int main() {
	FASTIO
	Input();

	getchar();
	getchar();
	return 0;
}
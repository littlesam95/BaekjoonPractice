#include <iostream>
#include <string>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <ctime>
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
int N, Q;
vector<int> P;
LL Sum[MAX];

void Input() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		int X;
		cin >> X;
		P.push_back(X);
	}
}

void Settings() {
	sort(P.begin(), P.end());
	for (int i = 1; i <= N; i++) {
		Sum[i] = Sum[i - 1] + P[i - 1];
	}
}

void Find_Answer() {
	while (Q--) {
		LL X;
		cin >> X;
		int Cnt = lower_bound(P.begin(), P.end(), X) - P.begin();
		LL Small = Sum[Cnt];
		LL SP = (X * Cnt) - Small;
		LL Big = Sum[N] - Small;
		LL BP = Big - (X * (N - Cnt));
		cout << BP + SP << "\n";
	};
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
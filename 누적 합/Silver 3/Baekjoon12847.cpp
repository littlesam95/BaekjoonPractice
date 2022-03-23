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
#define INF 1e12

using namespace std;
int N, M;
LL Sum[MAX];
LL Answer = 0;

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int T;
		cin >> T;
		Sum[i] = Sum[i - 1] + T;
	}
}

void Settings() {
	for (int i = M; i <= N; i++) {
		LL Tmp = Sum[i] - Sum[i - M];
		if (Answer < Tmp) {
			Answer = Tmp;
		}
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
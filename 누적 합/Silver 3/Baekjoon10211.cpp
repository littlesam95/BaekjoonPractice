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
#define MAX 1001
#define LL long long
#define INF 1e12

using namespace std;
int T, N;
LL X[MAX];
LL Sum[MAX];
LL Answer;

void Settings() {
	Answer = -INF;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			Answer = max(Answer, Sum[j] - Sum[i - 1]);
		}
	}
}

void Find_Answer() {
	cout << Answer << "\n";
}

void Input() {
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> X[i];
			Sum[i] = Sum[i - 1] + X[i];
		}
		Settings();
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
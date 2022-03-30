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
#define MAX 301
#define LL long long
#define INF 1e9

using namespace std;
int N;
int MAP[MAX][MAX];
int Sum[MAX][MAX];
int Answer = -INF;

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}
}

void Settings() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Sum[i][j] = MAP[i][j] + Sum[i][j - 1] + Sum[i - 1][j] - Sum[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int X = min(N - i, N - j);
			for (int k = 0; k <= X; k++) {
				int Cur = Sum[i + k][j + k] - Sum[i - 1][j + k] - Sum[i + k][j - 1] + Sum[i - 1][j - 1];
				Answer = max(Answer, Cur);
			}
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
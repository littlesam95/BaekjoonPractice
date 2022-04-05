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
int N, Q;
int Sum[MAX][MAX][11];

void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int A;
			cin >> A;
			for (int k = 1; k <= 10; k++) {
				Sum[i][j][k] = Sum[i - 1][j][k] + Sum[i][j - 1][k] - Sum[i - 1][j - 1][k] + (k == A ? 1 : 0);
			}
		}
	}
	cin >> Q;
}

void Find_Answer() {
	while (Q--) {
		int X1, Y1, X2, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;
		int Answer = 0;
		for (int i = 1; i <= 10; i++) {
			int Cur = Sum[X2][Y2][i] - Sum[X2][Y1 - 1][i] - Sum[X1 - 1][Y2][i] + Sum[X1 - 1][Y1 - 1][i];
			if (Cur != 0) {
				Answer++;
			}
		}
		cout << Answer << "\n";
	};
}

int main() {
	FASTIO
	Input();
	Find_Answer();

	getchar();
	getchar();
	return 0;
}
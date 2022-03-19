#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 1000001
#define INF 2e9

using namespace std;
int T;
long long DP[MAX];

void init() {
	DP[1] = 1;
	for (int i = 2; i < MAX; i++) {
		for (int j = 1; (j * i) < MAX; j++) {
			DP[i * j] += i;
		}
		DP[i] += (DP[i - 1] + 1);
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	init();
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << DP[N] << "\n";
	};

	getchar();
	getchar();
	return 0;
}
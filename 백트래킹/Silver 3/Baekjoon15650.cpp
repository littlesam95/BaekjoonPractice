#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 9

using namespace std;
int N, M;
bool arr[MAX];

void dfs(int X, int depth) {
	if (depth == M) {
		for (int i = 1; i <= N; i++) {
			if (arr[i]) {
				cout << i << " ";
			}
		}
		cout << "\n";
		return;
	}
	for (int i = X + 1; i <= N; i++) {
		if (!arr[i]) {
			arr[i] = true;
			dfs(i, depth + 1);
			arr[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	dfs(0, 0);

	getchar();
	getchar();
	return 0;
}
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 16
#define INF 2e9

using namespace std;
int N, L, R, X;
int arr[MAX];
bool visited[MAX];
int answer = 0;

void dfs(int A, int size, int sum, int hard, int easy) {
	if (size >= 2) {
		if ((sum >= L) && (sum <= R) && (hard - easy >= X)) {
			answer++;
		}
	}
	for (int i = A + 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i, size + 1, sum + arr[i], max(hard, arr[i]), min(easy, arr[i]));
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> L >> R >> X;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dfs(0, 0, 0, -INF, INF);
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
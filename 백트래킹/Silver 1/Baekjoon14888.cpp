#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 12
#define INF 2e9

using namespace std;
int N;
int num_arr[MAX];
int op_arr[4];
int answer_min = INF;
int answer_max = -INF;

int calc(int A, int B, int op) {
	if (op == 0) {
		return (A + B);
	}
	else if (op == 1) {
		return (A - B);
	}
	else if (op == 2) {
		return (A * B);
	}
	else if (op == 3) {
		if (A < 0) {
			A = -A;
			return -(A / B);
		}
		else {
			return (A / B);
		}
	}
	else {
		return -1;
	}
}

void dfs(int X, int sum) {
	if (X == N + 1) {
		answer_min = min(answer_min, sum);
		answer_max = max(answer_max, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op_arr[i] > 0) {
			op_arr[i]--;
			dfs(X + 1, calc(sum, num_arr[X], i));
			op_arr[i]++;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num_arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op_arr[i];
	}
	dfs(2, num_arr[1]);
	cout << answer_max << "\n";
	cout << answer_min << "\n";

	getchar();
	getchar();
	return 0;
}
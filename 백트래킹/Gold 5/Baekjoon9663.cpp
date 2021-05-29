#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int N;
int queen[15];
int res = 0;

bool comp(int depth) {
	for (int i = 0; i < depth; i++) {
		if ((queen[depth] == queen[i]) || (depth - i == abs(queen[depth] - queen[i]))) {
			return false;
		}
	}
	return true;
}

void dfs(int depth) {
	if (depth == N) {
		res++;
		return;
	}

	for (int i = 0; i < N; i++) {
		queen[depth] = i;
		if (comp(depth)) {
			dfs(depth + 1);
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	dfs(0);

	cout << res << "\n";

	getchar();
	getchar();
	return 0;
}
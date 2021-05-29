#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;
int k;
int arr[13];
int res[13];

void dfs(int start, int depth) {
	if (depth == 6) { // 고른 수가 6개가 되면
		for (int i = 0; i < 6; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return; // 출력하고 빠져나온다.
	}

	for (int i = start; i < k; i++) { // 백트래킹
		res[depth] = arr[i];
		dfs(i + 1, depth + 1);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (1) {
		cin >> k;
		if (k == 0) {
			break;
		}
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		dfs(0, 0);
		cout << "\n";
	};

	getchar();
	getchar();
	return 0;
}
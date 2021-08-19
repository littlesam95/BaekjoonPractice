#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
#define MAX 500001

using namespace std;
int N, M;
int arr[MAX];
int answer = 0;

void init() {
	for (int i = 0; i <= N; i++) {
		arr[i] = -1;
	}
}

int find(int x) {
	if (arr[x] < 0) {
		return x;
	}
	int parent = find(arr[x]);
	arr[x] = parent;
	return parent;
}

bool union_set(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) {
		return false;
	}
	arr[y] = x;
	return true;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	init();
	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		bool flag = union_set(x, y);
		if ((!flag) && (answer == 0)) {
			answer = i;
		}
	}
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}
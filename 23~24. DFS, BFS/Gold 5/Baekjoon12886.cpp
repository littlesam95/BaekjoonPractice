#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
int A, B, C;
bool visited[1501][1501];

void bfs(int x, int y) {
	if (visited[x][y]) {
		return;
	}
	visited[x][y] = true;
	int arr[3] = { x,y,(A + B + C) - x - y };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i] < arr[j]) {
				int b[3] = { x,y,(A + B + C) - x - y };
				b[i] += arr[i];
				b[j] -= arr[i];
				bfs(b[0], b[1]);
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> A >> B >> C;
	if ((A + B + C) % 3 != 0) {
		cout << 0 << "\n";
	}
	else {
		bfs(A, B);
		if (visited[(A + B + C) / 3][(A + B + C) / 3]) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

	getchar();
	getchar();
	return 0;
}
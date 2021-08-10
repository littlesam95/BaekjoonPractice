#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <algorithm>
#define MAX 500000000

using namespace std;
int N, K;
int dist[11][11];
int route[11][11];
bool visited[11];
int answer = MAX;

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = MAX;
			}
		}
	}
}

void find_route(int now_point, int hour, int depth) {
	if (depth == (pow(2, N) - 1)) {
		answer = min(answer, hour);
		return;
	}

	for (int i = 1; i <= N; i++) {
		int tmp = depth;
		if (!visited[i]) {
			visited[i] = true;
			tmp |= (1 << (i - 1));
			find_route(i, hour + dist[now_point][i], tmp);
			visited[i] = false;
		}
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	init();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> dist[i][j];
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) {
					continue;
				}
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	int idx = 0;
	visited[K + 1] = true;
	idx |= (1 << K);
	for (int i = 1; i <= N; i++) {
		int tmp = idx;
		if (!visited[i]) {
			visited[i] = true;
			tmp |= (1 << (i - 1));
			find_route(i, dist[K + 1][i], tmp);
			visited[i] = false;
		}
	}
	visited[K + 1] = false;
	cout << answer << "\n";

	getchar();
	getchar();
	return 0;
}